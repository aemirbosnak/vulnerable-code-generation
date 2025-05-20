//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int votes;
} candidate;

int main() {
    // Define the candidates
    candidate candidates[] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Carol", 0},
        {"Dave", 0},
        {"Eve", 0},
    };

    // Get the number of voters
    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Get the votes from each voter
    for (int i = 0; i < num_voters; i++) {
        char name[20];
        printf("Enter the name of the candidate you want to vote for: ");
        scanf("%s", name);

        // Find the candidate with the given name
        candidate *candidate = NULL;
        for (int j = 0; j < sizeof(candidates) / sizeof(candidate); j++) {
            if (strcmp(candidates[j].name, name) == 0) {
                candidate = &candidates[j];
                break;
            }
        }

        // If the candidate was not found, print an error message
        if (candidate == NULL) {
            printf("Invalid candidate name.\n");
        } else {
            // Increment the candidate's vote count
            candidate->votes++;
        }
    }

    // Find the winning candidate
    candidate *winner = NULL;
    for (int i = 0; i < sizeof(candidates) / sizeof(candidate); i++) {
        if (winner == NULL || candidates[i].votes > winner->votes) {
            winner = &candidates[i];
        }
    }

    // Print the winner's name
    printf("The winner is %s with %d votes.\n", winner->name, winner->votes);

    return 0;
}