//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct candidate{
    char name[50];
    int voteCount;
}Candidate;

typedef struct voter{
    char name[50];
    int voted;
}Voter;

int main(){
    int i, j, numCandidates, numVoters, electionOver = 0, winner;
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    Candidate candidates[numCandidates];
    for(i=0; i<numCandidates; i++){
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", &candidates[i].name);
        candidates[i].voteCount = 0;
    }

    printf("\nEnter the number of voters: ");
    scanf("%d", &numVoters);

    Voter voters[numVoters];
    for(i=0; i<numVoters; i++){
        printf("Enter the name of voter %d: ", i+1);
        scanf("%s", &voters[i].name);
        voters[i].voted = 0;
    }

    while(!electionOver){
        printf("\nVoting Menu:\n");
        for(i=0; i<numCandidates; i++){
            printf("%d. %s\n", i+1, candidates[i].name);
        }
        printf("%d. End voting\n", i+1);
        printf("Enter the candidate number you wish to vote for: ");
        int choice;
        scanf("%d", &choice);

        if(choice == i){
            electionOver = 1;
        }
        else if(choice<1 || choice>numCandidates){
            printf("Invalid choice! Please try again.\n");
        }
        else{
            for(j=0; j<numVoters; j++){
                if(!voters[j].voted){
                    candidates[choice-1].voteCount++;
                    voters[j].voted = 1;
                    printf("You have successfully voted for %s. Thank you!\n", candidates[choice - 1].name);
                    break;
                }
            }
            if(j == numVoters){
                printf("All voters have already voted.\n");
            }
        }
    }

    winner = 0;
    for(i=1; i<numCandidates; i++){
        if(candidates[i].voteCount > candidates[winner].voteCount){
            winner = i;
        }
    }

    printf("\n\nElection Results\n");
    printf("The winner is %s with %d votes!\n", candidates[winner].name, candidates[winner].voteCount);

    return 0;
}