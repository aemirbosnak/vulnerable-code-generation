//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    system("clear");
    system("figlet -f Pixel -c \"Electronic Voting System\"");

    // Voting system variables
    char candidate_names[3][20] = {"John Doe", "Jane Doe", "Peter Pan"};
    int votes[3] = {0, 0, 0};
    char current_voter_id[20];

    // Generate a random voter ID
    sprintf(current_voter_id, "V%04d", rand() % 1000);

    // Display the voter ID
    printf("Your Voter ID: %s\n", current_voter_id);

    // Display the candidate names
    printf("Please select a candidate:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d. %s\n", i + 1, candidate_names[i]);
    }

    // Get the candidate selection
    int candidate_selection = 0;
    printf("Enter the number of your selection: ");
    scanf("%d", &candidate_selection);

    // Validate the candidate selection
    if (candidate_selection < 1 || candidate_selection > 3)
    {
        printf("Invalid selection. Please try again.\n");
        return 1;
    }

    // Record the vote
    votes[candidate_selection - 1]++;

    // Display the vote confirmation
    printf("Your vote has been recorded. Thank you for voting!\n");

    // Display the vote results
    printf("Vote results:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s: %d votes\n", candidate_names[i], votes[i]);
    }

    return 0;
}