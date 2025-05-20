//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Global Variables for Candidates and Votes
char candidates[10][50];
int votes[10];

//Function prototypes
bool isAlreadyExists(char *candidateName, int count);
void castVote();
void displayVotes();

int main()
{
    int choice;
    int totalCandidates;

    //Getting the number of candidates from user
    printf("\nEnter the total number of candidates: ");
    scanf("%d", &totalCandidates);

    //Getting Candidate Names from user
    printf("\nEnter the candidate names: \n");
    for(int i=0; i<totalCandidates; i++) {
        char candidateName[50];
        printf("\nCandidate %d: ", i+1);
        scanf("%s", candidateName);
        if(isAlreadyExists(candidateName, i)) {
            printf("\nCandidate Name already exists. Please enter a unique candidate name!");
            i--;
        }
        else {
            strcpy(candidates[i], candidateName);
            votes[i] = 0;
        }
    }

    //Showing Main Menu
    while(true) {
        printf("\n\nEnter your choice:\n");
        printf("1. Cast Vote\n");
        printf("2. Display Votes\n");
        printf("3. Exit\n\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: castVote();
                    break;
            case 2: displayVotes();
                    break;
            case 3: printf("\n***** Thank you for using Electronic Voting System *****\n");
                    exit(0);
            default: printf("\nInvalid choice. Please select a valid option.");
        }
    }

    return 0;
}

//Function to Check if the candidate name already exists
bool isAlreadyExists(char *candidateName, int count) {
    for(int i=0; i<count; i++) {
        if(strcmp(candidates[i], candidateName) == 0) {
            return true;
        }
    }
    return false;
}

//Function to Cast Vote
void castVote() {
    char candidateName[50];
    printf("\nEnter the candidate name you want to cast vote: ");
    scanf("%s", candidateName);

    bool isFound = false;
    for(int i=0; i<10; i++) {
        if(strcmp(candidates[i], candidateName) == 0) {
            isFound = true;
            votes[i]++;
            printf("\nVote casted to %s successfully!", candidateName);
            break;
        }
    }

    if(!isFound) {
        printf("\nInvalid Candidate Name! Please check the spelling and try again...");
    }
}

//Function to Display Votes
void displayVotes() {
    printf("\nVotes Status:\n");
    for(int i=0; i<10; i++) {
        if(strlen(candidates[i]) > 0) {
            printf("%s - %d votes\n", candidates[i], votes[i]);
        }
    }
}