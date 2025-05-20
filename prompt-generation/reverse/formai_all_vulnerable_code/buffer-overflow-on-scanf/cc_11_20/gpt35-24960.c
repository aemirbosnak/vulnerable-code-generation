//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    int candidate1_votes = 0;
    int candidate2_votes = 0;
    int candidate3_votes = 0;

    for(int i=1; i<=num_voters; i++)
    {
        printf("Vote for Candidate 1, 2, or 3 (enter 1, 2, or 3): ");
        int vote_choice;
        scanf("%d", &vote_choice);

        switch(vote_choice)
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
            default:
                printf("Invalid vote choice.\n");
                i--;
                break;
        }
    }

    printf("Candidate 1: %d votes\n", candidate1_votes);
    printf("Candidate 2: %d votes\n", candidate2_votes);
    printf("Candidate 3: %d votes\n", candidate3_votes);

    if(candidate1_votes > candidate2_votes && candidate1_votes > candidate3_votes)
        printf("Candidate 1 wins!\n");
    else if(candidate2_votes > candidate1_votes && candidate2_votes > candidate3_votes)
        printf("Candidate 2 wins!\n");
    else if(candidate3_votes > candidate1_votes && candidate3_votes > candidate2_votes)
        printf("Candidate 3 wins!\n");
    else
        printf("There is a tie.\n");

    return 0;
}