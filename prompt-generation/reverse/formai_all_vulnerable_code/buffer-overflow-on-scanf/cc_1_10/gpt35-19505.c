//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int count, v1, v2;
    int candidate_1 = 0, candidate_2 = 0, spoilt_vote = 0;

    printf("Enter the number of voters: ");
    scanf("%d", &count);

    printf("\nEnter the number associated with each candidate: \n");
    printf("1 - Candidate 1\n");
    printf("2 - Candidate 2\n");

    for (int i = 0; i < count; i++)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &v1);

        if (v1 == 1)
        {
            candidate_1++;
        }
        else if (v1 == 2)
        {
            candidate_2++;
        }
        else
        {
            spoilt_vote++;
        }
    }

    printf("\n\nVoting Result:\n");
    printf("\n===================================\n");
    printf("\nCandidate 1 - %d votes\n", candidate_1);
    printf("\nCandidate 2 - %d votes\n", candidate_2);
    printf("\nSpoilt Votes - %d\n", spoilt_vote);
    printf("\n===================================\n");

    if (candidate_1 > candidate_2)
    {
        printf("\n\tCandidate 1 is the winner\n");
    }
    else if (candidate_2 > candidate_1)
    {
        printf("\n\tCandidate 2 is the winner\n");
    }
    else
    {
        printf("\n\tIt's a tie\n");
    }
    
    return 0;
}