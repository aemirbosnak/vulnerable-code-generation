//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: calm
#include <stdio.h>

// Declare global variables
int candidates;
int voters;
int votes[10];

// Function to initialize votes
void initializeVotes() {
    for (int i = 0; i < candidates; i++) {
        votes[i] = 0;
    }
}

// Function to display menu and get inputs
void displayMenu() {
    printf("Electronic Voting System\n");
    printf("Enter the number of candidates: ");
    scanf("%d", &candidates);
    printf("Enter the number of voters: ");
    scanf("%d", &voters);
}

// Function to cast individual vote
void vote() {
    int choice;
    printf("\nEnter the candidate number you want to vote for: ");
    scanf("%d", &choice);
    if (choice <= candidates) {
        printf("Your vote has been cast for candidate %d\n", choice);
        votes[choice - 1]++;
    } else {
        printf("Invalid candidate number. Please try again.\n");
        vote();
    }
}

// Function to count and display votes
void countVotes() {
    int maxVotes = 0;
    int winner = -1;
    printf("\nCandidate   Votes\n");
    printf("------------------\n");
    for (int i = 0; i < candidates; i++) {
        printf("%d           %d\n", i+1, votes[i]);
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winner = i;
        }
    }
    printf("------------------\n");
    printf("The winner is candidate %d with %d votes\n", winner+1, maxVotes);
}

// Main function
int main() {
    // Display menu and get inputs
    displayMenu();
    initializeVotes();
    // Loop to capture all votes
    for (int i = 1; i <= voters; i++) {
        printf("\nVoter %d\n", i);
        vote();
    }
    // Count and display votes
    countVotes();
    return 0;
}