//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidate{
    char name[50];
    int votes;
} Candidate;

typedef struct voter{
    char name[50];
    int hasVoted;
} Voter;

int main(){
    int candidatesCount, votersCount;

    // Get the total number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &candidatesCount);
    Candidate candidates[candidatesCount];

    // Get the names of the candidates
    for(int i=0; i<candidatesCount; i++){
        printf("Enter the name of the candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
    }

    // Get the total number of voters
    printf("\nEnter the number of voters: ");
    scanf("%d", &votersCount);
    Voter voters[votersCount];

    // Get the names of the voters
    for(int i=0; i<votersCount; i++){
        printf("Enter the name of the voter %d: ", i+1);
        scanf("%s", voters[i].name);
        voters[i].hasVoted = 0;
    }

    // Start the voting process
    int voterId, candidateId;
    while(1){
        printf("\nEnter the name of the voter who wants to vote: ");
        char voterName[50];
        scanf("%s", voterName);

        // Check if the voter has already voted
        voterId = -1;
        for(int i=0; i<votersCount; i++){
            if(strcmp(voters[i].name, voterName) == 0){
                if(voters[i].hasVoted == 1){
                    printf("Sorry, this voter has already voted.\n");
                    voterId = -2;
                    break;
                }
                else{
                    voterId = i;
                    break;
                }
            }
        }

        if(voterId < 0) continue;

        // Get the candidate who the voter wants to vote for
        printf("\nEnter the name of the candidate who the voter wants to vote for: ");
        char candidateName[50];
        scanf("%s", candidateName);

        candidateId = -1;
        for(int i=0; i<candidatesCount; i++){
            if(strcmp(candidates[i].name, candidateName) == 0){
                candidateId = i;
                break;
            }
        }

        if(candidateId < 0){
            printf("Sorry, the candidate name entered is invalid.\n");
            continue;
        }

        // Add the vote of the voter to the candidate
        candidates[candidateId].votes++;
        voters[voterId].hasVoted = 1;

        printf("\nThank you for voting!\n");
    }

    return 0;
}