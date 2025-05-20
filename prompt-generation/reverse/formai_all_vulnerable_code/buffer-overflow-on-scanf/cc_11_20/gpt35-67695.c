//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10

int main()
{
    int num_voters;
    int num_candidates;
    int ballot[MAX_VOTERS][MAX_CANDIDATES];
    int candidate_votes[MAX_CANDIDATES] = {0};

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    printf("Enter the ballot for each voter:\n");
    for(int i=0; i<num_voters; i++)
    {
        printf("Ballot for voter %d: ", i+1);
        for(int j=0; j<num_candidates; j++)
        {
            scanf("%d", &ballot[i][j]);
        }
    }

    printf("The candidates are:\n");
    for(int i=0; i<num_candidates; i++)
    {
        printf("Candidate %d\n", i+1);
    }

    for(int i=0; i<num_voters; i++)
    {
        for(int j=0; j<num_candidates; j++)
        {
            candidate_votes[ballot[i][j]-1]++;
            break;
        }
    }

    printf("\n");
    printf("The vote count for each candidate is:\n");
    for(int i=0; i<num_candidates; i++)
    {
        printf("Candidate %d: %d votes\n", i+1, candidate_votes[i]);
    }

    int max_votes = -1;
    int winner_candidate = -1;
    for(int i=0; i<num_candidates; i++)
    {
        if(candidate_votes[i] > max_votes)
        {
            max_votes = candidate_votes[i];
            winner_candidate = i;
        }
    }

    if(max_votes == num_voters)
    {
        printf("Candidate %d has won the election with all %d votes\n", winner_candidate+1, max_votes);
    }
    else if(max_votes > (num_voters/2))
    {
        printf("Candidate %d has won the election with %d votes out of %d\n", winner_candidate+1, max_votes, num_voters);
    }
    else
    {
        printf("No candidate has won the election with majority votes\n");
    }

    return 0;
}