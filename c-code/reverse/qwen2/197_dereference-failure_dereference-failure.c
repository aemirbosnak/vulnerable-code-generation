#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 50

int main() {
    int num_candidates, num_voters;
    int votes[MAX_CANDIDATES] = {0};

    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &num_candidates);

    if (num_candidates <= 0 || num_candidates > MAX_CANDIDATES) {
        printf("Invalid number of candidates.\n");
        return 1;
    }

    printf("Enter the number of voters (max %d): ", MAX_VOTERS);
    scanf("%d", &num_voters);

    if (num_voters <= 0 || num_voters > MAX_VOTERS) {
        printf("Invalid number of voters.\n");
        return 1;
    }

    printf("Voting...\n");
    for (int i = 0; i < num_voters; i++) {
        int candidate;
        printf("Voter %d, choose your candidate (1-%d): ", i + 1, num_candidates);
        scanf("%d", &candidate);

        if (candidate < 1 || candidate > num_candidates) {
            printf("Invalid candidate choice.\n");
            i--; // Re-prompt this voter
            continue;
        }

        votes[candidate - 1]++;
    }

    printf("\nResults:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("Candidate %d: %d votes\n", i + 1, votes[i]);
    }

    return 0;
}
