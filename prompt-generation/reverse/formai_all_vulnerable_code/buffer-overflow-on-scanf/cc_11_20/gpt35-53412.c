//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int voters = 1000;
    int candidate1_votes = 0;
    int candidate2_votes = 0;
    int candidate3_votes = 0;
    int candidate4_votes = 0;

    printf("\n\nWelcome to the Electronic Voting System!\n\n");

    while (voters > 0)
    {
        int choice;

        printf("Please select your candidate:\n");
        printf("1. Candidate 1\n");
        printf("2. Candidate 2\n");
        printf("3. Candidate 3\n");
        printf("4. Candidate 4\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                candidate1_votes++;
                break;
            case 2:
                candidate2_votes++;
                break;
            case 3:
                candidate3_votes++;
                break;
            case 4:
                candidate4_votes++;
                break;
            default:
                printf("Invalid selection. Please choose again.\n");
                voters++;
                break;
        }

        voters--;
        printf("Thank you for voting!\n");
    }

    printf("\n\nVoting has ended!\n\n");

    printf("Candidate 1 received %d votes.\n", candidate1_votes);
    printf("Candidate 2 received %d votes.\n", candidate2_votes);
    printf("Candidate 3 received %d votes.\n", candidate3_votes);
    printf("Candidate 4 received %d votes.\n", candidate4_votes);

    if (candidate1_votes > candidate2_votes && candidate1_votes > candidate3_votes && candidate1_votes > candidate4_votes)
    {
        printf("\n\nCandidate 1 is the winner!\n\n");
    }
    else if (candidate2_votes > candidate1_votes && candidate2_votes > candidate3_votes && candidate2_votes > candidate4_votes)
    {
        printf("\n\nCandidate 2 is the winner!\n\n");
    }
    else if (candidate3_votes > candidate1_votes && candidate3_votes > candidate2_votes && candidate3_votes > candidate4_votes)
    {
        printf("\n\nCandidate 3 is the winner!\n\n");
    }
    else if (candidate4_votes > candidate1_votes && candidate4_votes > candidate2_votes && candidate4_votes > candidate3_votes)
    {
        printf("\n\nCandidate 4 is the winner!\n\n");
    }
    else
    {
        printf("\n\nThere is a tie between two or more candidates.\n\n");
    }

    return 0;
}