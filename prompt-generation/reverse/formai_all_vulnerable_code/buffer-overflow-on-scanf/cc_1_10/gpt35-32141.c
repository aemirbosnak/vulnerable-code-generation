//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidate {
    int number;
    char name[50];
    int votes;
} Candidate;

int main() {
    int num_candidates, num_voters;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    Candidate candidates[num_candidates];

    int i;
    for (i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
        candidates[i].number = i+1;
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    int j;
    for (j = 0; j < num_voters; j++) {
        int vote;
        printf("Vote %d: ", j+1);
        scanf("%d", &vote);

        if (vote <= 0 || vote > num_candidates) {
            printf("Invalid vote.\n");
        } else {
            candidates[vote-1].votes++;
        }
    }

    printf("Results:\n");
    int max_votes = 0;
    int winner_index = -1;

    for (i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    if (winner_index != -1) {
        printf("%s wins!\n", candidates[winner_index].name);
    } else {
        printf("No winner.\n");
    }

    return 0;
}