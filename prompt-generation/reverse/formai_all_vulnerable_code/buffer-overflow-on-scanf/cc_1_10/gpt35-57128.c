//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate
{
    char name[50];
    int votes;
};
// Function to display the candidates' names
void displayCandidates(struct Candidate candidates[], int numCandidates)
{
    printf("\nList of Candidates: \n");
    for(int i=0; i<numCandidates; i++)
    {
        printf("%d. %s\n", (i+1), candidates[i].name);
    }
}

int main()
{
    int numVoters, numCandidates;
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);
    // Allocate memory for the candidates array
    struct Candidate *candidates = (struct Candidate*) malloc(numCandidates * sizeof(struct Candidate));
    // Populate the candidates' names
    for(int i=0; i<numCandidates; i++)
    {
        printf("Enter candidate %d's name: ", (i+1));
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    // Display the candidates' names
    displayCandidates(candidates, numCandidates);
    // Allow each voter to cast their vote
    for(int i=0; i<numVoters; i++)
    {
        printf("\nVoter %d, please enter your vote: ", (i+1));
        int vote;
        scanf("%d", &vote);
        candidates[vote-1].votes++;
        printf("Thank you for voting!\n");
    }
    // Display the final results
    printf("\nFinal Results: \n");
    for(int i=0; i<numCandidates; i++)
    {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
    }
    free(candidates);
    return 0;
}