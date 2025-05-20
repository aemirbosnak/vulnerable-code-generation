//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#define CANDIDATES 4

//function prototypes
void registerVote();
void displayResult();
void addCandidate();
void removeCandidate();

struct candidate{
    char name[50];
    int votes;
} candidates[CANDIDATES];

int main(){
    int option;

    //initialize candidates
    for(int i=0; i<CANDIDATES; i++){
        candidates[i].votes = 0;
    }

    while(1){
        printf("\n------------------------\n");
        printf("Electronic Voting System\n");
        printf("------------------------\n");
        printf("1. Register a Vote\n");
        printf("2. Display Results\n");
        printf("3. Add a Candidate\n");
        printf("4. Remove a Candidate\n");
        printf("5. Exit\n");
        printf("Enter an option: ");
        scanf("%d",&option);

        switch(option){
            case 1: registerVote(); break;
            case 2: displayResult(); break;
            case 3: addCandidate(); break;
            case 4: removeCandidate(); break;
            case 5: exit(0);
            default: printf("Invalid Option!\n"); break;
        }
    }
    return 0;
}

void registerVote(){
    int candidateNumber;
    printf("Enter Candidate Number (1-4): ");
    scanf("%d",&candidateNumber);
    if(candidateNumber<1 || candidateNumber>CANDIDATES){
        printf("Invalid Candidate Number!\n");
    }else{
        //increment candidate's votes
        candidates[candidateNumber-1].votes++;
        printf("Vote Registered Successfully!\n");
    }
}

void displayResult(){
    printf("Candidate\tVotes\n");
    printf("------------------------\n");
    for(int i=0; i<CANDIDATES; i++){
        printf("%s\t\t%d\n",candidates[i].name,candidates[i].votes);
    }
}

void addCandidate(){
    int emptyIndex = -1;
    for(int i=0; i<CANDIDATES; i++){
        if(candidates[i].votes == 0){
            emptyIndex = i;
            break;
        }
    }
    if(emptyIndex == -1){
        printf("Candidate List is Full!\n");
    }else{
        printf("Enter Candidate Name: ");
        scanf("%s",candidates[emptyIndex].name);
        printf("Candidate Added Successfully!\n");
    }
}

void removeCandidate(){
    int candidateNumber;
    printf("Enter Candidate Number (1-4): ");
    scanf("%d",&candidateNumber);
    if(candidateNumber<1 || candidateNumber>CANDIDATES){
        printf("Invalid Candidate Number!\n");
    }else{
        //remove candidate by setting votes to -1
        candidates[candidateNumber-1].votes = -1;
        printf("Candidate Removed Successfully!\n");
    }
}