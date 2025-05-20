//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10

typedef struct{
    char name[50];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int numCandidates;
int voterIDs[MAX_VOTERS];
int numVoters;

int isValidID(int ID){
    for(int i=0;i<numVoters;i++){
        if(voterIDs[i] == ID){
            return 0;
        }
    }
    return 1;
}

void castVote(int ID, int candidateIndex){
    if(isValidID(ID)){
        candidates[candidateIndex].votes++;
        voterIDs[numVoters] = ID;
        numVoters++;
        printf("Vote cast successfully!\n");
    }
    else{
        printf("Invalid voter ID. Vote not cast.\n");
    }
}

void printResults(){
    printf("Election Results:\n");
    for(int i=0;i<numCandidates;i++){
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void addCandidate(){
    if(numCandidates < MAX_CANDIDATES){
        Candidate candidate;
        printf("Enter candidate name: ");
        scanf("%s", candidate.name);
        candidate.votes = 0;
        candidates[numCandidates] = candidate;
        numCandidates++;
        printf("Candidate added successfully!\n");
    }
    else{
        printf("Max number of candidates reached. Candidate not added.\n");
    }
}

int main(){
    int choice;
    do{
        printf("Electoral Commission Menu:\n");
        printf("1. Cast vote\n");
        printf("2. Print election results\n");
        printf("3. Add candidate\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                {
                    int ID, candidateIndex;
                    printf("Enter voter ID: ");
                    scanf("%d", &ID);
                    printf("Enter candidate index: ");
                    scanf("%d", &candidateIndex);
                    if(candidateIndex >=0 && candidateIndex < numCandidates){
                        castVote(ID, candidateIndex);
                    }
                    else{
                        printf("Invalid candidate index.\n");
                    }
                }
                break;

            case 2:
                {
                    printResults();
                }
                break;

            case 3:
                {
                    addCandidate();
                }
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }while(choice != 4);

    printf("Exiting program.\n");
    return 0;
}