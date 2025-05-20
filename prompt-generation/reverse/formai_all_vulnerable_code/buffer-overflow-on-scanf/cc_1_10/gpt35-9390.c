//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numOfCandidates = 0, numOfVoters = 0, option = 0, i, j, k;
    
    // Get the number of candidates to contest in the election
    printf("Enter the number of candidates: ");
    scanf("%d", &numOfCandidates);
    
    // Get the names of the candidates
    char candidates[numOfCandidates][50];
    for (i = 0; i < numOfCandidates; i++)
    {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i]);
    }
    
    // Get the number of voters
    printf("Enter the number of voters: ");
    scanf("%d", &numOfVoters);
    
    // Create an array to keep track of the number of votes for each candidate
    int votes[numOfCandidates];
    for (i = 0; i < numOfCandidates; i++)
    {
        votes[i] = 0;
    }
    
    // Get votes from the voters
    char voterName[50];
    for (i = 0; i < numOfVoters; i++)
    {
        printf("Voter %d, enter your name: ", i + 1);
        scanf("%s", voterName);
        
        printf("Please select a candidate:\n");
        for (j = 0; j < numOfCandidates; j++)
        {
            printf("%d - %s\n", j + 1, candidates[j]);
        }
        
        scanf("%d", &option);
        
        // Record the vote
        if (option > 0 && option <= numOfCandidates)
        {
            votes[option - 1]++;
            printf("Vote recorded successfully.\n");
        }
        else
        {
            printf("Invalid option selected.\n");
        }
    }
    
    // Print the voting results
    printf("\nVoting Summary:\n");
    for (i = 0; i < numOfCandidates; i++)
    {
        printf("%s - %d votes\n", candidates[i], votes[i]);
    }
    
    // Determine the winner
    int maxVotes = votes[0];
    int winnerIndex = 0;
    for (i = 1; i < numOfCandidates; i++)
    {
        if (votes[i] > maxVotes)
        {
            maxVotes = votes[i];
            winnerIndex = i;
        }
    }
    
    printf("\nThe winner of the election is %s with %d votes.\n", candidates[winnerIndex], maxVotes);
    
    return 0;
}