//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numOfVoters, numOfCandidates, i, j, choice, option, winner, maxVotes;
    printf("Welcome to the Electronic Voting System!\n");

    printf("Enter the number of voters: ");
    scanf("%d",&numOfVoters);

    printf("Enter the number of candidates: ");
    scanf("%d",&numOfCandidates);

    char **candidates = malloc(numOfCandidates * sizeof(char*));
    for(i=0; i<numOfCandidates; i++)
        candidates[i] = malloc(40 * sizeof(char));

    printf("Enter the names of the candidates:\n");
    for(i=0; i<numOfCandidates; i++)
        scanf("%s", candidates[i]);

    int **votes = malloc(numOfVoters * sizeof(int *));
    for(i=0; i<numOfVoters; i++)
        votes[i] = malloc(numOfCandidates * sizeof(int));

    for(i=0; i<numOfVoters; i++)
    {
        printf("\nVoter %d, choose your candidate:\n", i+1);
        for(j=0; j<numOfCandidates; j++)
            printf("%d) %s\n", j+1, candidates[j]);
        scanf("%d", &choice);
        votes[i][choice-1] = 1;
    }

    printf("\n\nPress 1 to display voting results\nPress 2 to exit\n");
    scanf("%d",&option);

    while(option!=2)
    {
        if(option == 1)
        {
            printf("\nElection Results:\n");
            for(i=0; i<numOfCandidates; i++)
            {
                int candidateVotes = 0;
                for(j=0; j<numOfVoters; j++)
                    candidateVotes += votes[j][i];
                printf("%s: %d\n", candidates[i], candidateVotes);
                if(i==0)
                    winner = i, maxVotes = candidateVotes;
                else if(candidateVotes > maxVotes)
                    winner = i, maxVotes = candidateVotes;
            }

            printf("*** The Winner is %s ***\n", candidates[winner]);
            printf("\n\nPress 1 to display voting results\nPress 2 to exit\n");
            scanf("%d",&option);
        }
        else
        {
            printf("\nInvalid Option, try again.\n");
            printf("\n\nPress 1 to display voting results\nPress 2 to exit\n");
            scanf("%d",&option);
        }
    }

    for(i=0; i<numOfCandidates; i++)
        free(candidates[i]);

    free(candidates);

    for(i=0; i<numOfVoters; i++)
        free(votes[i]);

    free(votes);

    return 0;
}