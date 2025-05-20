//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: accurate
#include<stdio.h>
#include<stdlib.h>

void vote(int option, int voteCount[], int *maxVotes);

int main()
{
    int numCandidates, numVoters, i, j;
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);
    int candidateCodes[numCandidates];
    char candidateNames[numCandidates][20];
    int voteCount[numCandidates];
    int maxVotes=0, winnerCode=-1;
    printf("Enter the candidate codes and names:\n");
    for(i=0; i<numCandidates; i++)
    {
        scanf("%d", &candidateCodes[i]);
        scanf("%s", candidateNames[i]);
        voteCount[i] = 0;
    }
    printf("Enter the voter choices:\n");
    for(i=0; i<numVoters; i++)
    {
        int option;
        scanf("%d", &option);
        vote(option, voteCount, &maxVotes);
    }
    printf("Results:\n");
    printf("Candidate Code\t\tCandidate Name\t\tVotes\n");
    for(i=0; i<numCandidates; i++)
    {
        printf("%d\t\t\t%s\t\t\t%d\n", candidateCodes[i], candidateNames[i], voteCount[i]);
        if(voteCount[i] > maxVotes)
        {
            winnerCode = candidateCodes[i];
            maxVotes = voteCount[i];
        }
        else if(voteCount[i] == maxVotes)
        {
            winnerCode = -1;
        }
    }
    if(winnerCode == -1)
    {
        printf("The election was tied.\n");
    }
    else
    {
        printf("The winner is candidate with code %d.\n", winnerCode);
    }
    return 0;
}

void vote(int option, int voteCount[], int *maxVotes)
{
    int index = option-1;
    voteCount[index]++;
    if(voteCount[index] > *maxVotes)
    {
        *maxVotes = voteCount[index];
    }
}