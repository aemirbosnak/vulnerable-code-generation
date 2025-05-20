//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Declare global variables
char candidates[5][20] = {"Candidate 1", "Candidate 2", "Candidate 3", "Candidate 4", "Candidate 5"};
int votes[5] = {0, 0, 0, 0, 0};

// Declare functions
void display_menu();
bool validate_vote(int);
void cast_vote(int);

int main()
{
    int choice, voter_id;
    bool valid_voter = false;

    // Simulate voter ID validation
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter your voter ID: ");
    scanf("%d", &voter_id);

    // Validate voter ID
    if (voter_id >= 1000 && voter_id <= 9999) {
        valid_voter = true;
        printf("Thank you! You are a valid voter.\n");
    } else {
        printf("Error: Invalid voter ID.\n");
        exit(0); // Exit program
    }

    // Display the voting menu if voter ID is valid
    if (valid_voter) {
        do {
            display_menu();
            scanf("%d", &choice);
            if (validate_vote(choice)) {
                cast_vote(choice);
            } else {
                printf("Error: Invalid choice.\n");
                continue;
            }
        } while (choice != 0);
    }

    // Display final results
    printf("Voting has ended. Final results:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: %d votes\n", candidates[i], votes[i]);
    }

    return 0;
}

void display_menu()
{
    printf("=============================\n");
    printf("      Electronic Voting\n");
    printf("=============================\n");
    printf("      Candidates list:\n");
    for (int i = 0; i < 5; i++) {
        printf("        %d. %s\n", i + 1, candidates[i]);
    }
    printf("\n");
    printf("Enter the number of your choice (0 to exit): ");
}

bool validate_vote(int choice)
{
    if (choice >= 0 && choice <= 5) {
        return true;
    } else {
        return false;
    }
}

void cast_vote(int choice)
{
    printf("You have voted for %s.\n", candidates[choice - 1]);
    votes[choice - 1]++;
}