//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

typedef struct{
    char name[20];
    int votes;
} Candidate;

int count = 0;
Candidate candidates[MAX_CANDIDATES];
int voters[MAX_VOTERS][MAX_CANDIDATES];

// function to add a candidate to the system
void addCandidate(char *name){
    if(count >= MAX_CANDIDATES){
        printf("Error: Maximum number of candidates reached.\n");
        return;
    }
    Candidate c;
    strcpy(c.name, name);
    c.votes = 0;
    candidates[count++] = c;
    printf("%s added as a candidate successfully.\n", name);
}

// function to display the list of candidates
void displayCandidates(){
    printf("List of candidates:\n");
    for(int i=0; i < count; i++){
        printf("%d. %s\n", (i+1), candidates[i].name);
    }
}

// function to validate the vote
bool validateVote(int *vote){
    int sum = 0;
    for(int i=0; i < count; i++){
        sum += vote[i];
    }
    if(sum != 1){
        printf("Error: Invalid vote.\n");
        return false;
    }
    return true;
}

// function to cast a vote
void castVote(int *vote){
    if(!validateVote(vote)){
        return;
    }
    for(int i=0; i < count; i++){
        if(vote[i] == 1){
            candidates[i].votes++;
            voters[candidates[i].votes][i] = 1;
            printf("Vote cast for %s successfully.\n", candidates[i].name);
            return;
        }
    }
}

// function to display the result of the election
void displayResult(){
    printf("Result of the election:\n");
    printf("Candidate     Votes     % Votes\n");
    for(int i=0; i < count; i++){
        float percent = (float)candidates[i].votes / (float)MAX_VOTERS * 100;
        printf("%-13s %-9d %.2f%%\n", candidates[i].name, candidates[i].votes, percent);
    }
    printf("\n");
    if(candidates[0].votes == candidates[1].votes){
        printf("There is a tie between %s and %s.\n", candidates[0].name, candidates[1].name);
    }else{
        printf("%s has won the election with %d votes.\n", candidates[0].name, candidates[0].votes);
    }
}

int main(){
    int option;
    char name[20];
    int vote[MAX_CANDIDATES];

    while(true){
        printf("Welcome to the Electronic Voting System.\n");
        printf("1. Add candidate\n2. Display candidates\n3. Cast vote\n4. Display result\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Enter the name of the candidate: ");
                scanf("%s", name);
                addCandidate(name);
                break;
            case 2:
                displayCandidates();
                break;
            case 3:
                displayCandidates();
                for(int i=0; i < count; i++){
                    printf("Enter 1 to vote for %s: ", candidates[i].name);
                    scanf("%d", &vote[i]);
                }
                castVote(vote);
                break;
            case 4:
                displayResult();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    }
    
    return 0;
}