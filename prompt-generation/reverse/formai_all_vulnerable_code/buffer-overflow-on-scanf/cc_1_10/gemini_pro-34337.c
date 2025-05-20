//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Array of candidate names
char *candidates[] = {"Alice", "Bob", "Carol", "Dave", "Eve"};

// Array of votes for each candidate
int votes[5] = {0, 0, 0, 0, 0};

// Function to print the voting menu
void printMenu() {
    printf("Electronic Voting System\n");
    printf("------------------------\n");
    printf("1. Cast a vote\n");
    printf("2. View results\n");
    printf("3. Exit\n");
    printf("------------------------\n");
    printf("Enter your choice: ");
}

// Function to cast a vote
void castVote() {
    int choice;
    printf("Enter the candidate number you want to vote for: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > 5) {
        printf("Invalid candidate number. Please try again.\n");
        return;
    }
    votes[choice - 1]++;
    printf("Your vote has been cast.\n");
}

// Function to view the results
void viewResults() {
    printf("Election Results\n");
    printf("------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: %d votes\n", candidates[i], votes[i]);
    }
    printf("------------------------\n");
}

// Main function
int main() {
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                castVote();
                break;
            case 2:
                viewResults();
                break;
            case 3:
                printf("Thank you for voting. Goodbye.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}