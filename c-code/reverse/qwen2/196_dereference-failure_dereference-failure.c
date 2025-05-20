#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

int main() {
    int num_candidates, num_voters;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    if (num_candidates <= 0) {
        printf("Invalid number of candidates.\n");
        return 1;
    }

    Candidate *candidates = malloc(num_candidates * sizeof(Candidate));
    if (candidates == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    if (num_voters <= 0) {
        printf("Invalid number of voters.\n");
        free(candidates);
        return 1;
    }

    for (int i = 0; i < num_voters; i++) {
        int vote;
        printf("Voter %d, please enter your choice (1-%d): ", i + 1, num_candidates);
        scanf("%d", &vote);
        if (vote > 0 && vote <= num_candidates) {
            candidates[vote - 1].votes++;
        } else {
            printf("Invalid vote.\n");
        }
    }

    int max_votes = 0;
    int winner_index = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    if (winner_index != -1) {
        printf("The winner is %s with %d votes.\n", candidates[winner_index].name, max_votes);
    } else {
        printf("No winner.\n");
    }

    free(candidates);
    return 0;
}
