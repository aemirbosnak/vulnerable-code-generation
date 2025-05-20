//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define a custom data type for votes
typedef struct {
    int candidate;
    int count;
} Vote;

// Declare global variables
int num_candidates, num_voters;
Vote *votes;
int *candidates;

// Function prototypes
void print_menu();
void cast_vote();
void print_results();
void cleanup();

int main() {
    // User input for number of candidates and voters
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Allocate memory for votes and candidate array
    votes = (Vote *) malloc(num_voters * sizeof(Vote));
    candidates = (int *) calloc(num_candidates, sizeof(int));

    // Check for successful memory allocation
    if (votes == NULL || candidates == NULL) {
        printf("Memory allocation failed, program terminating.\n");
        cleanup();
        return 1;
    }

    // Print main menu and handle user input
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: cast_vote(); break;
            case 2: print_results(); break;
            case 3: cleanup(); return 0;
            default: printf("Invalid choice, choose again.\n"); break;
        }
    } while (1);

    return 0;
}

void print_menu() {
    printf("\n1. Cast Vote\n");
    printf("2. View Results\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void cast_vote() {
    // Get user input for candidate choice
    int candidate_choice;
    printf("\nEnter your candidate choice (1-%d): ", num_candidates);
    scanf("%d", &candidate_choice);

    // Validate candidate choice
    if (candidate_choice < 1 || candidate_choice > num_candidates) {
        printf("Invalid candidate choice.\n");
        return;
    }

    // Add vote to votes array and increment candidate count
    votes[num_voters - 1].candidate = candidate_choice;
    candidates[candidate_choice - 1]++;
    votes[num_voters - 1].count = candidates[candidate_choice - 1];

    // Update number of voters and print confirmation message
    num_voters--;
    printf("\nVote successfully cast for candidate %d.\n", candidate_choice);
}

void print_results() {
    // Print header for results table
    printf("\nCandidate\tVotes Received\tPercentage\n");

    // Calculate total number of votes
    int total_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        total_votes += candidates[i];
    }

    // Calculate and print results for each candidate
    for (int i = 0; i < num_candidates; i++) {
        float percentage = (candidates[i] / (float) total_votes) * 100;
        printf("%d\t\t%d\t\t%.2f%%\n", i + 1, candidates[i], percentage);
    }
}

void cleanup() {
    // Free memory allocated for votes and candidates
    free(votes);
    free(candidates);

    // Print exit message
    printf("Thank you for using the Electronic Voting System.\n");
}