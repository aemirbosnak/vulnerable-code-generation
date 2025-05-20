//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, totalVotes = 0, invalidVotes = 0;
    int candidate1 = 0, candidate2 = 0, candidate3 = 0;
    char confirm;

    printf("Welcome to the Electronic Voting System!\n\n");
    printf("Enter the number of voters: ");
    scanf("%d", &n);

    printf("\nVoting options:\n1 - Candidate A\n2 - Candidate B\n3 - Candidate C\n\n");

    for (i = 1; i <= n; i++)
    {
        int vote;
        printf("Voter %d, please enter your vote (1-3): ", i);
        scanf("%d", &vote);

        if (vote >= 1 && vote <= 3) {
            totalVotes++;

            switch (vote) {
                case 1:
                    candidate1++;
                    break;
                case 2:
                    candidate2++;
                    break;
                case 3:
                    candidate3++;
                    break;
            }

            printf("You have voted for candidate %d.\n\n", vote);
        } else {
            invalidVotes++;
            printf("Invalid vote! Please try again.\n\n");
        }
    }

    printf("Total votes: %d\n", totalVotes);
    printf("Number of invalid votes: %d\n\n", invalidVotes);
    printf("Candidate A: %d votes\n", candidate1);
    printf("Candidate B: %d votes\n", candidate2);
    printf("Candidate C: %d votes\n\n", candidate3);

    printf("Are you sure you want to proceed with the results? (Y/N): ");
    scanf(" %c", &confirm);

    if (confirm == 'Y' || confirm == 'y') {
        if (candidate1 > candidate2 && candidate1 > candidate3) {
            printf("Candidate A wins with %d votes!\n", candidate1);
        } else if (candidate2 > candidate1 && candidate2 > candidate3) {
            printf("Candidate B wins with %d votes!\n", candidate2);
        } else if (candidate3 > candidate1 && candidate3 > candidate2) {
            printf("Candidate C wins with %d votes!\n", candidate3);
        } else {
            printf("It's a tie!\n");
        }
    } else {
        printf("Results not confirmed.\n");
    }

    return 0;
}