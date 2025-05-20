//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a candidate
struct candidate {
    char name[20];
    int votes;
};

// Define a function to display the menu
void display_menu() {
    printf("Electronic Voting System\n");
    printf("=======================\n");
    printf("1. Add candidate\n");
    printf("2. Display candidates\n");
    printf("3. Vote\n");
    printf("4. Display results\n");
    printf("5. Exit\n");
}

int main() {
    // Define variables
    int option, num_candidates = 0, num_votes = 0;
    struct candidate candidates[10];

    // Display the menu
    display_menu();

    // Main loop
    while (1) {
        // Get user input
        printf("> ");
        scanf("%d", &option);

        // Process user input
        switch (option) {
            case 1: // Add candidate
                printf("Enter candidate name: ");
                scanf("%s", candidates[num_candidates].name);
                candidates[num_candidates].votes = 0;
                num_candidates++;
                printf("Candidate added.\n");
                break;
            case 2: // Display candidates
                printf("Candidates:\n");
                for (int i = 0; i < num_candidates; i++) {
                    printf("%s\n", candidates[i].name);
                }
                printf("\n");
                break;
            case 3: // Vote
                if (num_candidates == 0) {
                    printf("No candidates yet.\n\n");
                    break;
                }
                printf("Enter candidate number to vote for: ");
                int choice;
                scanf("%d", &choice);
                if (choice < 1 || choice > num_candidates) {
                    printf("Invalid candidate number.\n\n");
                    break;
                }
                candidates[choice - 1].votes++;
                num_votes++;
                printf("Vote recorded.\n\n");
                break;
            case 4: // Display results
                if (num_candidates == 0) {
                    printf("No candidates yet.\n\n");
                    break;
                }
                printf("Results:\n");
                for (int i = 0; i < num_candidates; i++) {
                    printf("%s: %d votes (%0.2f%%)\n", candidates[i].name, candidates[i].votes, candidates[i].votes * 100.0 / num_votes);
                }
                printf("\n");
                break;
            case 5: // Exit
                printf("Goodbye.\n");
                exit(0);
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}