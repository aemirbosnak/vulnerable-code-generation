//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a candidate structure
typedef struct Candidate{
    char* name;
    int votes;
}Candidate;

// Declare a function to display the menu
void displayMenu(){
    printf("\nWelcome to the E-Voting System\n");
    printf("1. Add a Candidate\n");
    printf("2. Vote for a Candidate\n");
    printf("3. Display Results\n");
    printf("4. Exit\n");
}

// Declare a function to add a candidate
void addCandidate(Candidate* candidates, int* numCandidates){
    printf("\nEnter the name of the candidate: ");
    candidates[*numCandidates].name = (char*)malloc(sizeof(char)*20);
    scanf("%s", candidates[*numCandidates].name);
    candidates[*numCandidates].votes = 0;
    printf("%s has been added to the list of candidates.\n", candidates[*numCandidates].name);
    (*numCandidates)++;
}

// Declare a function to cast a vote
void castVote(Candidate* candidates, int numCandidates){
    char candidateName[20];
    int i, flag = 0;
    printf("\nEnter the name of the candidate you want to vote for: ");
    scanf("%s", candidateName);
    for(i = 0; i < numCandidates; i++){
        if(strcmp(candidateName, candidates[i].name) == 0){
            candidates[i].votes++;
            printf("You have successfully voted for %s.\n", candidates[i].name);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Error: No such candidate found.\n");
    }
}

// Declare a function to display the results
void displayResults(Candidate* candidates, int numCandidates){
    int i, maxVotes = 0, maxIndex;
    printf("\nResults:\n");
    for(i = 0; i < numCandidates; i++){
        printf("%s: %d\n", candidates[i].name, candidates[i].votes);
        if(candidates[i].votes > maxVotes){
            maxVotes = candidates[i].votes;
            maxIndex = i;
        }
    }
    if(numCandidates > 0){
        printf("\n%s has won the election with %d votes!\n", candidates[maxIndex].name, candidates[maxIndex].votes);
    }
    else{
        printf("\nNo candidates have been added yet.\n");
    }
}

int main(){
    Candidate candidates[10];
    int numCandidates = 0, choice;
    while(1){
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addCandidate(candidates, &numCandidates);
                break;
            case 2:
                castVote(candidates, numCandidates);
                break;
            case 3:
                displayResults(candidates, numCandidates);
                break;
            case 4:
                printf("\nThank you for using the E-Voting System!\n");
                exit(0);
            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    }
    return 0;
}