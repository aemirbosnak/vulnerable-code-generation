//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void vote(char, int);
void tally(int);

int main()
{
    char vote_choice;
    int vote_count = 0, candidate_id = 1;

    // Initialize the clock
    time_t start_time = time(NULL);

    // Start the voting process
    while (time(NULL) - start_time < 60)
    {
        // Get the voter's choice
        printf("Enter your vote (A, B, C): ");
        scanf("%c", &vote_choice);

        // Validate the vote
        if (vote_choice != 'A' && vote_choice != 'B' && vote_choice != 'C')
        {
            printf("Invalid vote. Please try again.\n");
            continue;
        }

        // Record the vote
        vote(vote_choice, candidate_id);

        // Increment the vote count
        vote_count++;

        // Print a confirmation message
        printf("Thank you for voting. Your vote has been recorded.\n");
    }

    // Tally the votes
    tally(vote_count);

    return 0;
}

void vote(char vote_choice, int candidate_id)
{
    // Create a file to store the votes
    FILE *fp = fopen("votes.txt", "a");

    // Write the vote to the file
    fprintf(fp, "%c, %d\n", vote_choice, candidate_id);

    fclose(fp);
}

void tally(int vote_count)
{
    // Create a file to store the tallies
    FILE *fp = fopen("tallies.txt", "w");

    // Write the tallies to the file
    fprintf(fp, "Total votes: %d\n", vote_count);

    fclose(fp);
}