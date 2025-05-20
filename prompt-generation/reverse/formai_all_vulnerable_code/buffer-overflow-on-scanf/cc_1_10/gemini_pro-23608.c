//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 100
#define MAX_VOTES 1000

typedef struct {
    char name[50];
    int votes;
} candidate;

int main() {
    int num_candidates, num_voters;
    candidate candidates[MAX_CANDIDATES];
    int votes[MAX_VOTES];

    // Read input
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);

        printf("Enter the number of votes for candidate %d: ", i + 1);
        scanf("%d", &candidates[i].votes);
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    for (int i = 0; i < num_voters; i++) {
        printf("Enter the vote for voter %d: ", i + 1);
        scanf("%d", &votes[i]);
    }

    // Sort candidates in decreasing order of votes
    for (int i = 0; i < num_candidates - 1; i++) {
        for (int j = i + 1; j < num_candidates; j++) {
            if (candidates[i].votes < candidates[j].votes) {
                candidate temp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp;
            }
        }
    }

    // Find the winner
    int max_votes = candidates[0].votes;
    int winner_index = 0;
    for (int i = 1; i < num_candidates; i++) {
        if (candidates[i].votes == max_votes) {
            winner_index = i;
        }
    }

    // Print the winner
    printf("The winner is: %s\n", candidates[winner_index].name);

    return 0;
}