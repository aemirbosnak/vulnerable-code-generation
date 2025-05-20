//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Candidate
{
    char name[50];
    int votes;
};

int main()
{
    // Create a struct to store candidate details
    struct Candidate candidates[10];

    // Initialize candidate details
    for (int i = 0; i < 10; i++)
    {
        strcpy(candidates[i].name, "Candidate");
        candidates[i].votes = 0;
    }

    srand(time(NULL));  // Seed random number generator

    // Get the number of voters
    int voters;
    printf("Enter the number of voters: ");
    scanf("%d", &voters);

    for (int i = 0; i < voters; i++)
    {
        // Randomize the candidate selected by the voter
        int randomIndex = rand() % 10;

        printf("Voter %d selected: %s\n", i+1, candidates[randomIndex].name);

        // Increase the votes for the selected candidate
        candidates[randomIndex].votes++;
    }

    // Print the total votes
    printf("Total votes: %d\n", voters);

    // Print the candidates with their votes
    printf("Candidate\tVotes\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s\t\t%d\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}