//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Claude Shannon
#include <stdio.h>

#define MAX_CANDIDATES 20
#define MAX_VOTERS 100

int main()
{
    int num_candidates, num_voters, i, j, candidate_num, max_votes;
    char candidate_name[MAX_CANDIDATES][50];
    int candidate_votes[MAX_CANDIDATES];
    char voter_name[MAX_VOTERS][50];
    int voter_choice[MAX_VOTERS];

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (i = 0; i < num_candidates; i++)
    {
        printf("Enter candidate name: ");
        scanf("%s", candidate_name[i]);
        candidate_votes[i] = 0;
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    for (i = 0; i < num_voters; i++)
    {
        printf("Enter voter name: ");
        scanf("%s", voter_name[i]);

        printf("Enter candidate number you want to vote for: \n");
        for (j = 0; j < num_candidates; j++)
        {
            printf("%d) %s\n", j + 1, candidate_name[j]);
        }
        scanf("%d", &candidate_num);
        voter_choice[i] = candidate_num - 1;
        candidate_votes[candidate_num - 1]++;
    }

    printf("-----Election Results-----\n");
    for (i = 0; i < num_candidates; i++)
    {
        printf("%s: %d\n", candidate_name[i], candidate_votes[i]);
        if (i == 0 || candidate_votes[i] > max_votes)
        {
            max_votes = candidate_votes[i];
        }
    }

    printf("--------------------------\n");
    printf("Winner(s): ");
    for (i = 0; i < num_candidates; i++)
    {
        if (candidate_votes[i] == max_votes)
        {
            printf("%s ", candidate_name[i]);
        }
    }
    printf("\n");

    return 0;
}