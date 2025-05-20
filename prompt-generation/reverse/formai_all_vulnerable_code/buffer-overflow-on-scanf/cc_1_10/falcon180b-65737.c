//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

//Number of candidates
#define CANDIDATES 5

//Structure for candidate information
typedef struct {
    char name[50];
    int votes;
} Candidate;

//Function to display menu
void displayMenu() {
    printf("\nElectronic Voting System\n");
    printf("1. Vote\n");
    printf("2. View Results\n");
    printf("3. Exit\n");
}

//Function to get user choice
int getChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

//Function to cast vote
void vote() {
    int choice;
    Candidate candidates[CANDIDATES] = {{"Candidate 1", 0}, {"Candidate 2", 0}, {"Candidate 3", 0}, {"Candidate 4", 0}, {"Candidate 5", 0}};
    printf("\nEnter the number of the candidate you want to vote for:\n");
    for (int i = 0; i < CANDIDATES; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
    scanf("%d", &choice);
    candidates[choice-1].votes++;
}

//Function to display results
void viewResults() {
    Candidate candidates[CANDIDATES] = {{"Candidate 1", 0}, {"Candidate 2", 0}, {"Candidate 3", 0}, {"Candidate 4", 0}, {"Candidate 5", 0}};
    printf("\nElection Results:\n");
    for (int i = 0; i < CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

//Main function
int main() {
    int choice;
    do {
        system("clear");
        displayMenu();
        choice = getChoice();
        switch (choice) {
            case 1:
                vote();
                break;
            case 2:
                viewResults();
                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice!= 3);
    return 0;
}