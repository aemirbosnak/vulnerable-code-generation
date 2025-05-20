//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10

int main()
{
    int num_of_candidates, num_of_voters;

    printf("Enter the number of candidates: ");
    scanf("%d", &num_of_candidates);

    if(num_of_candidates > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %d. Please try again.\n", MAX_CANDIDATES);
        return 0;
    }

    printf("\nEnter the number of voters: ");
    scanf("%d", &num_of_voters);

    int i, j, vote;
    int candidates[MAX_CANDIDATES] = {0};

    for (i = 0; i < num_of_voters; i++)
    {
        printf("\nVote for candidate (1 - %d): ", num_of_candidates);
        scanf("%d", &vote);

        if(vote > num_of_candidates || vote <= 0)
        {
            printf("\nInvalid candidate choice. Please choose a candidate from 1 - %d\n", num_of_candidates);
            continue;
        }

        candidates[vote - 1]++;
    }

    printf("\n\n-------VOTING SUMMARY-------\n\n");
    printf("Candidate \t| Votes Received\n");
    printf("----------------|--------------\n");
    for(j = 0; j < num_of_candidates; j++)
    {
        printf("Candidate %d \t| %d\n", j + 1, candidates[j]);
    }

    printf("----------------|--------------\n");
    printf("Total Votes \t| %d\n", num_of_voters);

    int max_votes = candidates[0];
    int max_index = 0;
    for(i = 1; i < num_of_candidates; i++)
    {
        if(candidates[i] > max_votes)
        {
            max_votes = candidates[i];
            max_index = i;
        }
    }

    printf("\n\n Winner of the election: Candidate %d \n", max_index + 1);

    return 0;
}