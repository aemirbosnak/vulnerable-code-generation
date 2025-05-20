//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidate {
    char *name;
    int votes;
} candidate;

int main() {
    // Initialize the candidates
    candidate candidates[] = {
        {"Homer Simpson", 0},
        {"Donald Trump", 0},
        {"Barack Obama", 0},
        {"Vladimir Putin", 0},
        {"Kim Jong-un", 0},
    };

    // Get the number of voters
    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Get the votes from each voter
    for (int i = 0; i < num_voters; i++) {
        // Get the voter's name
        char name[100];
        printf("Enter your name: ");
        scanf("%s", name);

        // Get the voter's vote
        int vote;
        printf("Enter the number of your favorite candidate (1-%d): ", sizeof(candidates) / sizeof(candidate));
        scanf("%d", &vote);

        // Increment the vote count for the selected candidate
        candidates[vote - 1].votes++;
    }

    // Find the winner
    int max_votes = 0;
    int winner_index = 0;
    for (int i = 0; i < sizeof(candidates) / sizeof(candidate); i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    // Print the winner
    printf("The winner is: %s\n", candidates[winner_index].name);

    return 0;
}