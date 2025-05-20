#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

int main() {
    int num_candidates, i, vote;
    Candidate candidates[MAX_CANDIDATES];

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    if (num_candidates > MAX_CANDIDATES) {
        printf("Too many candidates.\n");
        return 1;
    }

    for (i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d name: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    while (1) {
        printf("\nEnter your vote (0 to exit): ");
        scanf("%d", &vote);

        if (vote == 0) break;

        if (vote < 1 || vote > num_candidates) {
            printf("Invalid vote.\n");
            continue;
        }

        candidates[vote - 1].votes++;
    }

    int max_votes = 0;
    for (i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
        }
    }

    printf("\nThe winner(s) is/are:\n");
    for (i = 0; i < num_candidates; i++) {
        if (candidates[i].votes == max_votes) {
            printf("%s with %d votes\n", candidates[i].name, candidates[i].votes);
        }
    }

    return 0;
}
