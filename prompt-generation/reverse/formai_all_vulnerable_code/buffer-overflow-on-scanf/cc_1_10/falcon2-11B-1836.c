//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Initialize variables
    int candidates[3] = {1, 2, 3}; // candidate numbers
    char names[3][20] = {"John", "Jane", "Jack"}; // candidate names
    int votes[3] = {0, 0, 0}; // number of votes for each candidate

    // Display the candidate names and numbers
    printf("ELECTRONIC VOTING SYSTEM\n\n");
    printf("------------------------------\n");
    printf("Candidate Name      Candidate Number\n");
    printf("------------------------------\n");
    for (int i = 0; i < 3; i++) {
        printf("%s %d\n", names[i], candidates[i]);
    }
    printf("------------------------------\n");
    printf("To vote, enter the candidate number followed by ENTER\n");

    // Get votes from the user
    while (1) {
        char vote[20];
        printf("Enter your vote: ");
        scanf("%s", vote);
        if (strcmp(vote, "1") == 0) {
            votes[0]++;
        } else if (strcmp(vote, "2") == 0) {
            votes[1]++;
        } else if (strcmp(vote, "3") == 0) {
            votes[2]++;
        } else {
            printf("Invalid vote. Please try again.\n");
        }
    }

    // Display the results
    printf("\n------------------------------\n");
    printf("Election Results\n");
    printf("------------------------------\n");
    printf("Candidate Name      Candidate Number      Votes\n");
    printf("------------------------------\n");
    for (int i = 0; i < 3; i++) {
        printf("%s %d %d\n", names[i], candidates[i], votes[i]);
    }
    printf("------------------------------\n");

    // Print the winner
    int max_votes = votes[0];
    int winner_index = 0;
    for (int i = 1; i < 3; i++) {
        if (votes[i] > max_votes) {
            max_votes = votes[i];
            winner_index = i;
        }
    }
    printf("\n------------------------------\n");
    printf("Congratulations to Candidate %d for winning the election!\n", winner_index + 1);
    printf("------------------------------\n");

    return 0;
}