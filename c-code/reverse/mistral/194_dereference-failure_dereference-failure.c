#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

int votes[MAX_CANDIDATES];
int num_candidates, num_voters;

void initialize() {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        votes[i] = 0;
    }
}

void cast_vote(int candidate) {
    if (candidate < 0 || candidate >= num_candidates) {
        printf("Invalid candidate.\n");
        return;
    }
    votes[candidate]++;
}

int main() {
    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);

    if (num_candidates > MAX_CANDIDATES) {
        printf("Too many candidates. Max allowed is %d.\n", MAX_CANDIDATES);
        return 1;
    }

    initialize();

    printf("Enter number of voters: ");
    scanf("%d", &num_voters);

    if (num_voters > MAX_VOTERS) {
        printf("Too many voters. Max allowed is %d.\n", MAX_VOTERS);
        return 1;
    }

    for (int i = 0; i < num_voters; i++) {
        int candidate;
        printf("Enter candidate for voter %d: ", i + 1);
        scanf("%d", &candidate);

        cast_vote(candidate);
    }

    for (int i = 0; i < num_candidates; i++) {
        printf("Candidate %d received %d votes.\n", i + 1, votes[i]);
    }

    return 0;
}
