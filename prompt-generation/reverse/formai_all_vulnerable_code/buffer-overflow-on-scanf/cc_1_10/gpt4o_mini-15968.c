//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold information about a knight candidate
typedef struct {
    char name[50];
    int votes;
} Knight;

// Function to display the menu
void displayMenu() {
    printf("\n=== Kingdom of Codehaven ===\n");
    printf("1. Cast a Vote\n");
    printf("2. View Election Results\n");
    printf("3. Exit\n");
    printf("============================\n");
    printf("Enter your choice: ");
}

// Function to cast a vote
void castVote(Knight knights[], int knightCount) {
    int choice;
    printf("\nChoose your knight:\n");
    for (int i = 0; i < knightCount; i++) {
        printf("%d. %s\n", i + 1, knights[i].name);
    }
    printf("Enter the number of your choice: ");
    scanf("%d", &choice);

    if (choice > 0 && choice <= knightCount) {
        knights[choice - 1].votes++;
        printf("You have successfully cast your vote for %s!\n", knights[choice - 1].name);
    } else {
        printf("Invalid choice! Please try again.\n");
    }
}

// Function to display the results of the election
void displayResults(Knight knights[], int knightCount) {
    printf("\n=== Election Results ===\n");
    for (int i = 0; i < knightCount; i++) {
        printf("%s received %d votes.\n", knights[i].name, knights[i].votes);
    }
    printf("=========================\n");
}

int main() {
    Knight knights[3] = {
        {"Sir Lancelot", 0},
        {"Sir Galahad", 0},
        {"Sir Bedevere", 0}
    };
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                castVote(knights, 3);
                break;
            case 2:
                displayResults(knights, 3);
                break;
            case 3:
                printf("Farewell, noble citizen!\n");
                exit(0);
            default:
                printf("Thou hast entered an invalid choice. Please try again.\n");
        }
    }

    return 0;
}