//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Candidate structure
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Voter structure
typedef struct {
    char name[50];
    int voted;
} Voter;

// Initialize candidates and voters
Candidate candidates[] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Carol", 0}
};
int num_candidates = sizeof(candidates) / sizeof(candidates[0]);

Voter voters[] = {
    {"John", 0},
    {"Mary", 0},
    {"Tom", 0}
};
int num_voters = sizeof(voters) / sizeof(voters[0]);

// Main function
int main() {
    // Print welcome message
    printf("Welcome to the Electronic Voting System!\n");

    // Get voter input
    char voter_name[50];
    printf("Enter your name: ");
    scanf("%s", voter_name);

    // Check if voter has already voted
    int voter_index = -1;
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(voter_name, voters[i].name) == 0) {
            voter_index = i;
            break;
        }
    }

    if (voter_index == -1) {
        printf("Voter not found.\n");
        return 1;
    } else if (voters[voter_index].voted) {
        printf("You have already voted.\n");
        return 1;
    }

    // Print candidate list
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    // Get voter choice
    int choice;
    printf("Enter your choice (1-%d): ", num_candidates);
    scanf("%d", &choice);

    // Check if choice is valid
    if (choice < 1 || choice > num_candidates) {
        printf("Invalid choice.\n");
        return 1;
    }

    // Increment vote count for selected candidate
    candidates[choice - 1].votes++;

    // Mark voter as having voted
    voters[voter_index].voted = 1;

    // Print voting confirmation
    printf("Thank you for voting!\n");

    // Print election results
    printf("Election results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Find winner
    int max_votes = 0;
    int winner_index = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    // Print winner
    printf("The winner is: %s\n", candidates[winner_index].name);

    return 0;
}