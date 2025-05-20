//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define NUM_CANDIDATES 4
#define NUM_VOTERS 10

// Define functions
void printMenu();
void printResults(char *candidates[], int *votes);

int main()
{
    // Initialize variables
    int i, j, choice;
    int *votes = (int*)calloc(NUM_CANDIDATES, sizeof(int));
    char *candidates[NUM_CANDIDATES] = {"Candidate A", "Candidate B", "Candidate C", "Candidate D"};
    char name[50];
    char password[20];
    int authenticated = 0;

    // Prompt for password and authenticate user
    printf("Welcome to the Electronic Voting System.\n");
    printf("Please enter the password to continue: ");
    scanf("%s", password);

    // Authenticate user
    if (strcmp(password, "password123") == 0) {
        authenticated = 1;
        printf("Authentication successful!\n");
    } else {
        printf("Incorrect password. Exiting...\n");
        return 0;
    }

    // Main loop for user interaction
    while (authenticated) {
        // Print menu
        printMenu();

        // Get user input
        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user input
        switch (choice) {
            case 1:
                printf("Enter your name to vote: ");
                scanf("%s", name);

                // Check if voter has already voted
                for (i = 0; i < NUM_VOTERS; i++) {
                    if (strcmp(name, candidates[i]) == 0) {
                        printf("You have already voted. Exiting...\n");
                        break;
                    }
                }

                // Get candidate choice and cast vote
                printf("Please select a candidate:\n");
                for (i = 0; i < NUM_CANDIDATES; i++) {
                    printf("%d) %s\n", i+1, candidates[i]);
                }
                scanf("%d", &choice);
                votes[choice-1]++;

                // Print confirmation message
                printf("Thank you for voting, %s!\n", name);
                break;

            case 2:
                printResults(candidates, votes);
                break;

            case 3:
                printf("Exiting...\n");
                authenticated = 0;
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void printMenu() {
    printf("\n=== Electronic Voting System ===\n");
    printf("1) Vote\n");
    printf("2) View Results\n");
    printf("3) Exit\n");
}

// Function to print election results
void printResults(char *candidates[], int *votes) {
    int i;
    printf("\n=== Election Results ===\n");
    for (i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d\n", candidates[i], votes[i]);
    }
}