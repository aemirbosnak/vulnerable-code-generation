//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct {
    char name[32];
    int votes;
} candidate_t;

candidate_t candidates[MAX_CANDIDATES];
int num_candidates;
int num_votes;

void print_candidates() {
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

int main() {
    // Get the number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Get the names of the candidates
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
    }

    // Get the number of votes
    printf("Enter the number of votes: ");
    scanf("%d", &num_votes);

    // Get the votes
    for (int i = 0; i < num_votes; i++) {
        int vote;
        printf("Enter the vote for candidate %d: ", i + 1);
        scanf("%d", &vote);
        candidates[vote - 1].votes++;
    }

    // Print the results
    printf("\nResults:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Find the winner
    int max_votes = 0;
    int winner = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner = i;
        }
    }

    // Print the winner
    printf("\nThe winner is: %s\n", candidates[winner].name);

    return 0;
}