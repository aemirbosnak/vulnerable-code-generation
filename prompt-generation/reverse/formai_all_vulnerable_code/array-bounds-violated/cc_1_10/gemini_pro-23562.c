//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int votes;
} Candidate;

int main() {
    Candidate candidates[] = {
        {"John Smith", 0},
        {"Jane Doe", 0},
        {"Bill Jones", 0},
        {"Mary Brown", 0},
        {NULL, 0}
    };

    char input[100];
    int voteCount = 0;

    while (voteCount < 5) {
        printf("Enter the name of the candidate you wish to vote for: ");
        fgets(input, sizeof(input), stdin);

        // Remove the newline character from the input
        input[strlen(input) - 1] = '\0';

        // Find the candidate with the matching name
        Candidate *candidate = NULL;
        for (int i = 0; candidates[i].name != NULL; i++) {
            if (strcmp(input, candidates[i].name) == 0) {
                candidate = &candidates[i];
                break;
            }
        }

        // If a candidate was found, increment their vote count
        if (candidate != NULL) {
            candidate->votes++;
            voteCount++;
        } else {
            printf("Invalid candidate name. Please try again.\n");
        }
    }

    // Find the winner of the election
    Candidate *winner = NULL;
    for (int i = 0; candidates[i].name != NULL; i++) {
        if (winner == NULL || candidates[i].votes > winner->votes) {
            winner = &candidates[i];
        }
    }

    // Print the results of the election
    printf("The winner of the election is %s with %d votes.\n", winner->name, winner->votes);

    return 0;
}