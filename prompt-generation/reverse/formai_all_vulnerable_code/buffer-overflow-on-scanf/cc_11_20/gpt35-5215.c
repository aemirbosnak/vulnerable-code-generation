//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int numCandidates, numVoters, i, j;
    char candidate[10][20], voter[20];
    int vote[10] = {0};
    int highestVotes = -1, winnerIndex, voteCount = 0, invalidCount = 0;
    char ch;

    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    printf("Enter the name of candidates:\n");

    for(i=0; i<numCandidates; i++)
    {
        scanf("%s",candidate[i]);
    }

    printf("\nEnter the number of voters: ");
    scanf("%d", &numVoters);

    for(i=0; i<numVoters; i++)
    {
        printf("\nEnter the name of voter: ");
        scanf("%s",voter);

        printf("\n\nChoose your candidate: \n");

        for(j=0; j<numCandidates; j++)
        {
            printf("%d. %s\n",j+1,candidate[j]);
        }
        printf("\nEnter your choice: ");
        scanf("%d",&vote[i]);

        if(vote[i]<1 || vote[i]>numCandidates)
        {
            printf("\nInvalid choice!\n");
            invalidCount++;
        }

        printf("\nThank you for casting your vote!");
        printf("\nDo you want to continue voting? (y/n): ");
        scanf(" %c",&ch);

        if(ch=='n' || ch=='N')
            break;
    }

    printf("\n\nCandidates and their votes:\n");

    for(i=0; i<numCandidates; i++)
    {
        printf("%s: ",candidate[i]);

        for(j=0; j<numVoters; j++)
        {
            if(vote[j]==i+1)
            {
                voteCount++;
            }
        }

        printf("%d\n",voteCount);

        if(voteCount>highestVotes)
        {
            highestVotes = voteCount;
            winnerIndex = i;
        }

        voteCount = 0;
    }

    printf("\nThe winner of the election is: %s!\n",candidate[winnerIndex]);
    printf("\nInvalid votes: %d\n",invalidCount);

    return 0;
}