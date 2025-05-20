//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num_of_candidates, num_of_voters, i, j, k;
    int **votes;
    srand(time(NULL));

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the number of candidates: ");
    scanf("%d", &num_of_candidates);
    printf("Please enter the number of voters: ");
    scanf("%d", &num_of_voters);

    votes = malloc(num_of_voters * sizeof(int *));
    for (i = 0; i < num_of_voters; i++)
    {
        votes[i] = malloc(num_of_candidates * sizeof(int));
    }

    printf("Voters can now cast their votes!\n");

    for (i = 0; i < num_of_voters; i++)
    {
        printf("Voter %d, please select a candidate by entering their number (1-%d): ", i + 1, num_of_candidates);
        scanf("%d", &votes[i][0]);
        for (j = 1; j < num_of_candidates; j++)
        {
            k = rand() % num_of_candidates + 1;
            while (votes[i][k-1] != 0)
            {
                k = rand() % num_of_candidates + 1;
            }
            votes[i][k-1] = j+1;
        }
        printf("Voter %d, your vote has been recorded.\n", i + 1);
    }

    int *votes_count = malloc(num_of_candidates * sizeof(int));
    for (i = 0; i < num_of_candidates; i++)
    {
        votes_count[i] = 0;
    }

    for (j = 0; j < num_of_candidates; j++)
    {
        for (i = 0; i < num_of_voters; i++)
        {
            if (votes[i][j] == 1)
            {
                votes_count[j]++;
                break;
            }
        }
    }

    printf("The results are in!\n");
    for (i = 0; i < num_of_candidates; i++)
    {
        printf("Candidate %d received %d votes.\n", i + 1, votes_count[i]);
    }

    int winner = 1;
    int max_votes = votes_count[0];
    for (i = 1; i < num_of_candidates; i++)
    {
        if (votes_count[i] > max_votes)
        {
            max_votes = votes_count[i];
            winner = i + 1;
        }
    }

    printf("The winner is candidate %d with %d votes!\n", winner, max_votes);

    free(votes_count);
    for (i = 0; i < num_of_voters; i++)
    {
        free(votes[i]);
    }
    free(votes);

    return 0;
}