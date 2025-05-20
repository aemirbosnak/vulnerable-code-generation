//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 10

/* Structure to store candidate information */
struct Candidate{
    char name[20];
    int votes;
};

/* Structure to store voter information */
struct Voter{
    char name[20];
    int hasVoted;
};

int main(){
    struct Candidate candidates[MAX_CANDIDATES]; // candidate array
    struct Voter voters[MAX_VOTERS]; // voter array
    int numCandidates, numVoters, voteCount=0, i=0, j=0, k=0, candidateNum;
    char input[10], candidateName[20], voterName[20];

    // Get number of candidates from user
    printf("Enter number of candidates (maximum %d): ",MAX_CANDIDATES);
    scanf("%d",&numCandidates);
    getchar();

    // Get candidate information from user
    for(i=0;i<numCandidates;i++){
        printf("Enter candidate name: ");
        fgets(candidates[i].name,sizeof(candidates[i].name),stdin);
        candidates[i].name[strcspn(candidates[i].name,"\n")]='\0'; // remove newline character
        candidates[i].votes=0;
    }

    // Get number of voters from user
    printf("Enter number of voters (maximum %d): ",MAX_VOTERS);
    scanf("%d",&numVoters);
    getchar();

    // Get voter information from user
    for(i=0;i<numVoters;i++){
        printf("Enter voter name: ");
        fgets(voters[i].name,sizeof(voters[i].name),stdin);
        voters[i].name[strcspn(voters[i].name,"\n")]='\0'; // remove newline character
        voters[i].hasVoted=0;
    }

    // Loop until all voters have cast their votes
    while(voteCount<numVoters){
        printf("Enter voter name to cast vote: ");
        fgets(voterName,sizeof(voterName),stdin);
        voterName[strcspn(voterName,"\n")]='\0'; // remove newline character

        // Check if voter has already voted
        for(i=0;i<numVoters;i++){
            if(strcmp(voterName,voters[i].name)==0 && voters[i].hasVoted==1){
                printf("Error: Voter has already cast a vote.\n");
                goto end;
            }
        }

        // Check if voter is valid
        for(i=0;i<numVoters;i++){
            if(strcmp(voterName,voters[i].name)==0){
                voters[i].hasVoted=1;
                break;
            }
        }
        if(i==numVoters){
            printf("Error: Invalid voter name.\n");
            goto end;
        }

        printf("Candidates:\n");
        for(i=0;i<numCandidates;i++){
            printf("%d. %s\n",i+1,candidates[i].name);
        }
        printf("Enter candidate number to vote: ");
        scanf("%d",&candidateNum);

        // Check if candidate number is valid
        if(candidateNum<1 || candidateNum>numCandidates){
            printf("Error: Invalid candidate number.\n");
            goto end;
        }

        // Increment candidate's vote count
        candidates[candidateNum-1].votes++;

        printf("Vote casted successfully!\n");
        voteCount++;

        end:
        printf("Press Enter to continue.\n");
        fgets(input,sizeof(input),stdin);
    }

    // Display vote count for each candidate
    printf("\nVote count:\n");
    for(i=0;i<numCandidates;i++){
        printf("%s: %d\n",candidates[i].name,candidates[i].votes);
    }

    return 0;
}