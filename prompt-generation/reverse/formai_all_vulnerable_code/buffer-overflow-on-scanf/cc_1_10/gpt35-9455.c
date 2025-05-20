//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10

int main() 
{ 
    int voters[MAX_VOTERS]={0}; 
    int candidates[MAX_CANDIDATES]={0}; 
    char candidateNames[MAX_CANDIDATES][20];
    int numOfVoters=0, numOfCandidates=0, vote, i, x, max=0, winner=0;

    printf("Welcome to the Electronic Voting System!\n\n");
    
    printf("Enter the number of voters: ");
    scanf("%d", &numOfVoters);
    if(numOfVoters>MAX_VOTERS) 
        printf("Error! Maximum number of voters exceeded!\n");
    else {
        printf("\nEnter the names of candidates:\n");
        for(i=0;i<numOfCandidates;i++) {
            printf("Candidate number %d: ", i+1);
            scanf("%s", candidateNames[i]);
            candidates[i]=0;
        }
        numOfCandidates=i;
        
        printf("\nLet the voting begin!\n");
        for(i=0;i<numOfVoters;i++) {
            printf("Voter number %d, please enter your vote (from 1 to %d): ", i+1, numOfCandidates);
            scanf("%d", &vote);
            if(vote>=1 && vote<=numOfCandidates) {
                voters[i]=vote-1;
                candidates[voters[i]]++;
            }
            else {
                printf("Error! Invalid vote!\n");
                i--;
            }
        }
        
        printf("\nVoting is now closed!\n");
        printf("\nResults:\n");
        for(i=0;i<numOfCandidates;i++) {
            printf("%s: %d votes\n", candidateNames[i], candidates[i]);
            if(candidates[i]>max) {
                max=candidates[i];
                winner=i;
            }
        }

        printf("\nThe winner is %s, with %d votes!\n", candidateNames[winner], max);
    }

    return 0; 
}