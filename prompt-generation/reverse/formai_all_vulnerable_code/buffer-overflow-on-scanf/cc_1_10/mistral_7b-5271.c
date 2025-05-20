//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define VOTERS 100
#define CANDIDATES 10
#define BIT_PER_VOTE (sizeof(int) * CHAR_BIT)

typedef struct {
    char name[50];
    int vote_count;
} Candidate;

typedef struct {
    Candidate candidates[CANDIDATES];
    int votes[VOTERS][BIT_PER_VOTE];
    int registered_voters;
} VotingSystem;

void register_voter(VotingSystem *system) {
    if (system->registered_voters < VOTERS) {
        system->registered_voters++;
        memset(system->votes[system->registered_voters - 1], 0, BIT_PER_VOTE);
    } else {
        printf("Error: Maximum number of registered voters reached.\n");
    }
}

void cast_vote(VotingSystem *system, int voter_index, int candidate_index) {
    if (voter_index >= 0 && voter_index < system->registered_voters &&
        candidate_index >= 0 && candidate_index < CANDIDATES) {
        int bit_position = candidate_index * BIT_PER_VOTE + (BIT_PER_VOTE / 8) * voter_index;
        system->votes[voter_index][bit_position / 8] |= (1 << (bit_position % 8));
        system->candidates[candidate_index].vote_count++;
    } else {
        printf("Error: Invalid voter or candidate index.\n");
    }
}

void print_results(VotingSystem *system) {
    int total_votes = 0;
    for (int i = 0; i < CANDIDATES; i++) {
        total_votes += system->candidates[i].vote_count;
        printf("Candidate %s: %d votes (%d%%)\n", system->candidates[i].name, system->candidates[i].vote_count,
               (int)(100.0 * system->candidates[i].vote_count / total_votes));
    }
}

int main() {
    VotingSystem system;
    for (int i = 0; i < CANDIDATES; i++) {
        scanf("%s", system.candidates[i].name);
    }

    int num_voters, voter, candidate;
    printf("Enter the number of registered voters: ");
    scanf("%d", &num_voters);

    for (int i = 0; i < num_voters; i++) {
        printf("Registered voter %d. Enter your candidate choice (0-%d): ", i + 1, CANDIDATES - 1);
        scanf("%d", &candidate);
        register_voter(&system);
        cast_vote(&system, system.registered_voters - 1, candidate);
    }

    printf("\nPrinting the results:\n");
    print_results(&system);

    return 0;
}