//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: careful
#include <stdio.h>

// function to display the menu
void displayMenu() {
    printf("\nWelcome to the Electronic Voting System\n");
    printf("1. Candidate 1\n");
    printf("2. Candidate 2\n");
    printf("3. Candidate 3\n");
    printf("4. Exit\n\n");
}

int main() {
    int choice, candidate1Votes = 0, candidate2Votes = 0, candidate3Votes = 0;

    do {
        // display the menu
        displayMenu();

        // get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // process the user's choice
        switch (choice) {
            case 1:
                candidate1Votes++;
                printf("You have voted for Candidate 1.\n");
                break;

            case 2:
                candidate2Votes++;
                printf("You have voted for Candidate 2.\n");
                break;

            case 3:
                candidate3Votes++;
                printf("You have voted for Candidate 3.\n");
                break;

            case 4:
                printf("Thank you for using the Electronic Voting System.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    // display the final results
    printf("\nFinal Results:\n");
    printf("Candidate 1: %d votes\n", candidate1Votes);
    printf("Candidate 2: %d votes\n", candidate2Votes);
    printf("Candidate 3: %d votes\n", candidate3Votes);

    return 0;
}