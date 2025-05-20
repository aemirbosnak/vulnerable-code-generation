#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 100
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

int main() {
    int num_candidates, num_voters;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    if (num_candidates <= 0 || num_candidates > MAX_CANDIDATES) {
        printf("Invalid number of candidates.\n");
        return 1;
    }

    Candidate candidates[MAX_CANDIDATES];
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d name: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    if (num_voters <= 0 || num_voters > MAX_VOTERS) {
        printf("Invalid number of voters.\n");
        return 1;
    }

    int votes[MAX_VOTERS];
    for (int i = 0; i < num_voters; i++) {
        printf("Voter %d, enter your choice (1-%d): ", i + 1, num_candidates);
        scanf("%d", &votes[i]);
        if (votes[i] < 1 || votes[i] > num_candidates) {
            printf("Invalid vote.\n");
            i--; // Re-prompt this voter
            continue;
        }
        candidates[votes[i] - 1].votes++;
    }

    printf("\nElection Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}
