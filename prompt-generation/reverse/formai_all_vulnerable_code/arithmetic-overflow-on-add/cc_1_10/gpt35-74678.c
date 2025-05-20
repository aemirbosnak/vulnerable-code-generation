//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate {
    int id;
    char name[50];
    int votes;
};

struct voter {
    int id;
    char name[50];
    int hasVoted;
};

int main() {
    int numCandidates, numVoters, i, j, candidateChoice, voterChoice;
    
    printf("Enter the number of candidates:");
    scanf("%d", &numCandidates);
    
    struct candidate candidates[numCandidates];
    
    for(i=0; i<numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", &candidates[i].name);
        candidates[i].id = i+1;
        candidates[i].votes = 0;
    }
    
    printf("\nEnter the number of voters: ");
    scanf("%d", &numVoters);
    
    struct voter voters[numVoters];
    
    for(i=0; i<numVoters; i++) {
        printf("\nEnter the name of voter %d: ", i+1);
        scanf("%s", &voters[i].name);
        voters[i].id = i+1;
        voters[i].hasVoted = 0;
    }
    
    while(1) {
        printf("\n1. Cast Vote");
        printf("\n2. View Total Votes");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &voterChoice);
        
        if(voterChoice == 1) {
            int voterId, candidateId;
            
            printf("\nEnter your voter id: ");
            scanf("%d", &voterId);
            
            if(voters[voterId-1].hasVoted) {
                printf("\nYou have already cast your vote.");
            } else {
                printf("\nSelect a candidate:\n");
                for(i=0; i<numCandidates; i++) {
                    printf("%d. %s\n", candidates[i].id, candidates[i].name);
                }
                
                scanf("%d", &candidateId);
                candidates[candidateId-1].votes++;
                
                printf("\nThank you for casting your vote!");
                voters[voterId-1].hasVoted = 1;
            }
        } else if(voterChoice == 2) {
            printf("\nCandidate votes:\n");
            for(i=0; i<numCandidates; i++) {
                printf("%s: %d\n", candidates[i].name, candidates[i].votes);
            }
        } else if(voterChoice == 3) {
            printf("\nGoodbye!");
            break;
        } else {
            printf("\nInvalid input. Try again.\n");
        }
    }
    
    return 0;
}