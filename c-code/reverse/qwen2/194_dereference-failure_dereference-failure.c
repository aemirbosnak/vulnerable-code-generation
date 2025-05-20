#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_candidates, num_voters;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    if (num_candidates <= 0 || num_voters <= 0) {
        printf("Invalid input. Number of candidates and voters must be greater than zero.\n");
        return 1;
    }

    int *votes = (int *)malloc(num_candidates * sizeof(int));
    if (votes == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < num_candidates; i++) {
        votes[i] = 0;
    }

    for (int i = 0; i < num_voters; i++) {
        int candidate;
        printf("Voter %d, enter your choice (1-%d): ", i + 1, num_candidates);
        scanf("%d", &candidate);
        if (candidate < 1 || candidate > num_candidates) {
            printf("Invalid vote. Please choose a valid candidate.\n");
            i--; // Retry the current voter's vote
            continue;
        }
        votes[candidate - 1]++;
    }

    printf("\nVote results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("Candidate %d: %d votes\n", i + 1, votes[i]);
    }

    free(votes);
    return 0;
}
