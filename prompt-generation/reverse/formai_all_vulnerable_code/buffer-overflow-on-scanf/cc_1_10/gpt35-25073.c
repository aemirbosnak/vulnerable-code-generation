//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int candidate1 = 0, candidate2 = 0, candidate3 = 0, candidate4 = 0, candidate5 = 0;
    int vote;

    printf("Welcome to the Electronic Voting System!\n");

    do {
        printf("\nPlease select a candidate (1-5) or enter 0 to end the voting process: ");
        scanf("%d", &vote);

        switch(vote) {
            case 1:
                candidate1++;
                printf("\nYou have selected Candidate 1.\n");
                break;
            case 2:
                candidate2++;
                printf("\nYou have selected Candidate 2.\n");
                break;
            case 3:
                candidate3++;
                printf("\nYou have selected Candidate 3.\n");
                break;
            case 4:
                candidate4++;
                printf("\nYou have selected Candidate 4.\n");
                break;
            case 5:
                candidate5++;
                printf("\nYou have selected Candidate 5.\n");
                break;
            case 0:
                printf("\nThank you for using the Electronic Voting System!\n");
                break;
            default:
                printf("\nInvalid selection. Please choose a valid option.\n");
                break;
        }
    } while(vote != 0);

    printf("\nCandidate 1: %d votes\n", candidate1);
    printf("Candidate 2: %d votes\n", candidate2);
    printf("Candidate 3: %d votes\n", candidate3);
    printf("Candidate 4: %d votes\n", candidate4);
    printf("Candidate 5: %d votes\n", candidate5);

    return 0;
}