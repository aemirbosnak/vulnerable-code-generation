//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
/* Romeo and Juliet E-Voting System */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define candidate struct
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Define function prototypes
void displayMenu();
void vote(Candidate candidates[], int numCandidates);
void viewResults(Candidate candidates[], int numCandidates);
void clearVotes(Candidate candidates[], int numCandidates);

int main() {
    // Initialize candidate array
    Candidate candidates[5];
    strcpy(candidates[0].name, "Romeo");
    candidates[0].votes = 0;
    strcpy(candidates[1].name, "Juliet");
    candidates[1].votes = 0;
    strcpy(candidates[2].name, "Paris");
    candidates[2].votes = 0;
    strcpy(candidates[3].name, "Mercutio");
    candidates[3].votes = 0;
    strcpy(candidates[4].name, "Tybalt");
    candidates[4].votes = 0;
    
    // Initialize variables
    int choice;
    int numCandidates = 5;
    bool running = true;
    
    while (running) {
        displayMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                vote(candidates, numCandidates);
                break;
            case 2:
                viewResults(candidates, numCandidates);
                break;
            case 3:
                clearVotes(candidates, numCandidates);
                break;
            case 4:
                running = false;
                break;
            default:
                printf("Invalid input. Please try again.\n");
        }
    }
    
    return 0;
}

// Display the menu options
void displayMenu() {
    printf("*** Romeo and Juliet E-Voting System ***\n");
    printf("1. Vote for a candidate\n");
    printf("2. View election results\n");
    printf("3. Clear all votes\n");
    printf("4. Exit the program\n");
    printf("Enter your choice: ");
}

// Allow user to vote for a candidate
void vote(Candidate candidates[], int numCandidates) {
    printf("Candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
    int choice;
    printf("Enter the number of your choice: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > numCandidates) {
        printf("Invalid input. Please try again.\n");
    } else {
        candidates[choice-1].votes++;
        printf("You have successfully voted for %s.\n", candidates[choice-1].name);
    }
}

// Display the election results
void viewResults(Candidate candidates[], int numCandidates) {
    printf("Election results:\n");
    printf("%-10s %s\n", "Candidate", "Votes");
    for (int i = 0; i < numCandidates; i++) {
        printf("%-10s %d\n", candidates[i].name, candidates[i].votes);
    }
}

// Clear all votes
void clearVotes(Candidate candidates[], int numCandidates) {
    for (int i = 0; i < numCandidates; i++) {
        candidates[i].votes = 0;
    }
    printf("All votes have been cleared.\n");
}