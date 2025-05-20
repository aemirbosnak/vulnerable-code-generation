//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sherlock's Voting System
typedef struct {
    char name[32];
    int votes;
} Candidate;

// Elementary, my dear Watson!
Candidate candidates[] = {
    {"Sherlock Holmes", 0},
    {"John Watson", 0},
    {"Irene Adler", 0},
    {"Moriarty", 0},
    {"Mycroft Holmes", 0}
};

int main() {
    // Initialize the voting system
    char input[32];
    int vote;
    int total_votes = 0;

    // Watson, fetch the votes!
    printf("Enter the candidate's name to vote for (or 'exit' to finish): ");
    while (strcmp(input, "exit") != 0) {
        scanf("%s", input);

        // Check if the candidate is valid
        int found = 0;
        for (int i = 0; i < sizeof(candidates) / sizeof(candidates[0]); i++) {
            if (strcmp(input, candidates[i].name) == 0) {
                found = 1;
                candidates[i].votes++;
                total_votes++;
                break;
            }
        }

        // Elementary, my dear Watson. The candidate is not valid.
        if (!found) {
            printf("Invalid candidate. Please try again: ");
        }
    }

    // The game is afoot! Calculate the results.
    printf("\nThe results are in, my dear Watson:\n");
    for (int i = 0; i < sizeof(candidates) / sizeof(candidates[0]); i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Watson, the case is closed. Determine the winner.
    int max_votes = 0;
    int winner = -1;
    for (int i = 0; i < sizeof(candidates) / sizeof(candidates[0]); i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner = i;
        }
    }

    if (winner == -1) {
        printf("\nIt's a draw, my dear Watson! Nobody wins.");
    } else {
        printf("\nThe winner is: %s with %d votes!\n", candidates[winner].name, candidates[winner].votes);
    }

    return 0;
}