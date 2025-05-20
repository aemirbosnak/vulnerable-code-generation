//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int i, j, n, m, count = 0;
    char ch;
    char name[20], vote[20];
    char candidates[5][20] = {"Candidate 1", "Candidate 2", "Candidate 3", "Candidate 4", "NOTA"};
    int votes[5] = {0,0,0,0,0};

    printf("\n\n\t\t E-VOTING SYSTEM \n");

    printf("\nEnter the number of voters: ");
    scanf("%d", &n);

    printf("\n\n\t\tCANDIDATES: ");
    for (i = 0; i < 5; i++)
    {
        printf("\n\t\t%d. %s", i+1, candidates[i]);
    }

    for(i = 0; i < n; i++)
    {
        printf("\n\nVoter %d:\n", i+1);
        printf("\nEnter your name: ");
        scanf("%s", name);

        printf("\nCandidates: ");
        for (j = 0; j < 5; j++)
        {
            printf("\n%d. %s", j+1, candidates[j]);
        }
        printf("\nEnter your vote: ");
        scanf("%s", vote);

        for (m = 0; m < 5; m++)
        {
            if(strcmp(candidates[m], vote) == 0)
            {
                votes[m]++;
                count++;
            }
        }

        printf("\n\nThank you for voting, %s.", name);
        printf("\n\n\n");
    }

    printf("\n\nTotal number of votes cast: %d", count);
    printf("\n\n\t\tELECTION RESULTS: ");
    for (i = 0; i < 5; i++)
    {
        printf("\n%s: %d votes", candidates[i], votes[i]);
    }

    printf("\n\n");

    return 0;
}