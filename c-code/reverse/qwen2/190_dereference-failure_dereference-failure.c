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
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    if (num_candidates <= 0) {
        printf("Invalid number of candidates.\n");
        return 1;
    }

    Candidate candidates[MAX_CANDIDATES];
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter name for candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    int vote;
    while (1) {
        printf("Enter your vote (0 to stop): ");
        scanf("%d", &vote);
        if (vote == 0) break;
        if (vote > 0 && vote <= num_candidates) {
            candidates[vote - 1].votes++;
        } else {
            printf("Invalid vote.\n");
        }
    }

    int max_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
        }
    }

    printf("Winner(s):\n");
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes == max_votes) {
            printf("%s\n", candidates[i].name);
        }
    }

    return 0;
}
