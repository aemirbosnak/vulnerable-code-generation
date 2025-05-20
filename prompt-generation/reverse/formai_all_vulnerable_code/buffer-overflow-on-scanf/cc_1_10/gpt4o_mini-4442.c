//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5

typedef struct {
    char name[50];
    int votes;
} Candidate;

int totalVotes = 0;
Candidate candidates[MAX_CANDIDATES];

// Function prototypes
void initializeCandidates();
void castVote();
void displayResults();
void displayMenu();

int main() {
    int choice;

    // Initialize candidates for the voting
    initializeCandidates();

    // Main loop for the voting system
    do {
        displayMenu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                castVote();
                break;
            case 2:
                displayResults();
                break;
            case 3:
                printf("Exiting the voting system. Thank you for participating!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to initialize the candidates
void initializeCandidates() {
    strcpy(candidates[0].name, "Alice");
    candidates[0].votes = 0;

    strcpy(candidates[1].name, "Bob");
    candidates[1].votes = 0;

    strcpy(candidates[2].name, "Charlie");
    candidates[2].votes = 0;

    strcpy(candidates[3].name, "Diana");
    candidates[3].votes = 0;

    strcpy(candidates[4].name, "Eli");
    candidates[4].votes = 0;
}

// Function to cast a vote
void castVote() {
    int choice;

    printf("\n--- Cast Your Vote ---\n");
    printf("Please choose a candidate:\n");
    
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    
    printf("Enter the candidate number (1-%d): ", MAX_CANDIDATES);
    scanf("%d", &choice);

    if (choice >= 1 && choice <= MAX_CANDIDATES) {
        candidates[choice - 1].votes++;
        totalVotes++;
        printf("Thank you for voting for %s!\n", candidates[choice - 1].name);
    } else {
        printf("Invalid candidate number! Please try again.\n");
    }
}

// Function to display the results
void displayResults() {
    printf("\n--- Election Results ---\n");
    if (totalVotes == 0) {
        printf("No votes have been cast yet.\n");
        return;
    }

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d vote(s) (%.2f%%)\n", 
               candidates[i].name, 
               candidates[i].votes, 
               (candidates[i].votes / (float)totalVotes) * 100);
    }
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Electronic Voting System ---\n");
    printf("1. Cast a Vote\n");
    printf("2. Display Results\n");
    printf("3. Exit\n");
}