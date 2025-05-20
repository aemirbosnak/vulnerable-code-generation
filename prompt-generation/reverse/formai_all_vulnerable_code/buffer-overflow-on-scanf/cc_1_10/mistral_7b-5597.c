//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CANDIDATES 3
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES] = {
    {"John Doe", 0},
    {"Jane Doe", 0},
    {"Mike Doe", 0}
};

void vote(int voter_id, int candidate_id) {
    if (voter_id < 1 || voter_id > MAX_VOTERS || candidate_id < 1 || candidate_id > MAX_CANDIDATES) {
        printf("Invalid voter or candidate ID.\n");
        return;
    }

    candidates[candidate_id - 1].votes++;
}

void print_candidates() {
    printf("\n--- CANDIDATES ---\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d. %s - %d votes\n", i + 1, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int voters[MAX_VOTERS] = {0}, voter_id;
    int candidate_id;

    printf("\n--- WELCOME TO THE ELECTRONIC VOTING SYSTEM ---\n");

    // Voting phase
    for (int i = 0; i < MAX_VOTERS; i++) {
        printf("\nVoter %d, please enter your candidate ID (1 to %d): ", i + 1, MAX_CANDIDATES);
        scanf("%d", &candidate_id);

        vote(i + 1, candidate_id);
        voters[i] = candidate_id;
    }

    // Vote counting phase
    printf("\n--- VOTE COUNTING ---\n");
    print_candidates();

    int total_votes = 0;
    for (int i = 0; i < MAX_VOTERS; i++) {
        total_votes++;
        vote(i + 1, voters[i]);
    }

    printf("\nTotal votes casted: %d\n", total_votes);

    return 0;
}