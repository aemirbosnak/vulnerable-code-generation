//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

struct candidate{
    int id;
    char name[50];
    int votes;
};

struct voter{
    int id;
    char name[50];
    int votedFor;
};

struct candidate candidates[MAX_CANDIDATES];
struct voter voters[MAX_VOTERS];

int numCandidates = 0, numVoters = 0;

void addCandidate(char* name){
    candidates[numCandidates].id = numCandidates;
    strcpy(candidates[numCandidates].name, name);
    candidates[numCandidates].votes = 0;
    numCandidates++;
}

void printAllCandidates(){
    printf("ID\tName\n");
    for (int i = 0; i < numCandidates; i++){
        printf("%d\t%s\n", candidates[i].id, candidates[i].name);
    }
    printf("\n");
}

void addVoter(char* name){
    voters[numVoters].id = numVoters;
    strcpy(voters[numVoters].name, name);
    voters[numVoters].votedFor = -1;
    numVoters++;
}

void castVote(int voterID, int candidateID){
    if (voters[voterID].votedFor == -1){
        candidates[candidateID].votes++;
        voters[voterID].votedFor = candidateID;
        printf("%s voted for %s\n\n", voters[voterID].name, candidates[candidateID].name);
    }
    else{
        printf("%s has already voted!\n\n", voters[voterID].name);
    }
}

void printResults(){
    printf("ID\tName\tVotes\n");
    for (int i = 0; i < numCandidates; i++){
        printf("%d\t%s\t%d\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
    printf("\n");
}

int main(){
    int choice, voterID, candidateID;
    char name[50];
    printf("Welcome to the Electronic Voting System!\n\n");
    do{
        printf("Enter your choice:\n");
        printf("1 - Add Candidate\n");
        printf("2 - View Candidates\n");
        printf("3 - Add Voter\n");
        printf("4 - Cast Vote\n");
        printf("5 - Print Results\n");
        printf("0 - Exit\n");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 0:
                printf("Thank you for using the Electronic Voting System!\n");
                break;
            case 1:
                printf("Enter Candidate Name: ");
                scanf("%s", name);
                addCandidate(name);
                printf("Candidate added successfully!\n\n");
                break;
            case 2:
                printAllCandidates();
                break;
            case 3:
                printf("Enter Voter Name: ");
                scanf("%s", name);
                addVoter(name);
                printf("Voter added successfully!\n\n");
                break;
            case 4:
                printf("Enter Voter ID: ");
                scanf("%d", &voterID);
                printf("Enter Candidate ID: ");
                scanf("%d", &candidateID);
                castVote(voterID, candidateID);
                break;
            case 5:
                printResults();
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice != 0);
    return 0;
}