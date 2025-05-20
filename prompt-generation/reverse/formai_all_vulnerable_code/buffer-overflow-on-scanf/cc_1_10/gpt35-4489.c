//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Constants for number of candidates and number of voters
#define NUM_CANDIDATES 4
#define NUM_VOTERS 7

// Enum for the candidates
enum candidate {
    CANDIDATE_A,
    CANDIDATE_B,
    CANDIDATE_C,
    CANDIDATE_D
};

// Array to hold the candidate names
const char* candidateNames[NUM_CANDIDATES] = {
    "Candidate A",
    "Candidate B",
    "Candidate C",
    "Candidate D"
};

// Array to hold the number of votes for each candidate
int votes[NUM_CANDIDATES] = {0};

// Function to print the menu and get the user's choice
int getMenuChoice() {
    int choice;
    printf("\nVOTING MENU\n");
    printf("1. Vote for Candidate A\n");
    printf("2. Vote for Candidate B\n");
    printf("3. Vote for Candidate C\n");
    printf("4. Vote for Candidate D\n");
    printf("5. Display results\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to get the user's vote
void getVote() {
    int candidateChoice;
    printf("\nEnter the candidate number you wish to vote for: ");
    scanf("%d", &candidateChoice);
    // Check if the choice is valid
    if (candidateChoice < 1 || candidateChoice > NUM_CANDIDATES) {
        printf("\nInvalid candidate choice.\n");
    } else {
        votes[candidateChoice - 1]++;
        printf("\nVote recorded for %s.\n", candidateNames[candidateChoice - 1]);
    }
}

// Function to display the voting results
void displayResults() {
    printf("\nVOTING RESULTS\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidateNames[i], votes[i]);
    }
}

// Main function
int main() {
    printf("WELCOME TO THE ELECTRONIC VOTING SYSTEM\n");
    int choice;
    // Loop until user chooses to exit
    do {
        choice = getMenuChoice();
        switch (choice) {
            case 1:
                getVote();
                break;
            case 2:
                getVote();
                break;
            case 3:
                getVote();
                break;
            case 4:
                getVote();
                break;
            case 5:
                displayResults();
                break;
            case 6:
                printf("\nExiting the system...\n");
                break;
            default:
                printf("\nInvalid menu choice.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}