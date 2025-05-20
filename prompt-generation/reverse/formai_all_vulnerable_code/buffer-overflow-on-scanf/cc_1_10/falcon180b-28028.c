//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CANDIDATES 5
#define NUM_VOTERS 10
#define VOTE_LENGTH 10

typedef struct {
    char name[VOTE_LENGTH];
    int vote;
} Voter;

typedef struct {
    char name[VOTE_LENGTH];
    int votes;
} Candidate;

void init_candidates(Candidate* candidates) {
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        sprintf(candidates[i].name, "Candidate %d", i + 1);
        candidates[i].votes = 0;
    }
}

void init_voters(Voter* voters) {
    for (int i = 0; i < NUM_VOTERS; i++) {
        sprintf(voters[i].name, "Voter %d", i + 1);
        voters[i].vote = 0;
    }
}

int main() {
    Candidate candidates[NUM_CANDIDATES];
    Voter voters[NUM_VOTERS];

    init_candidates(candidates);
    init_voters(voters);

    int votes_cast = 0;

    while (votes_cast < NUM_VOTERS) {
        printf("\n");
        for (int i = 0; i < NUM_CANDIDATES; i++) {
            printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        }

        int choice = 0;
        printf("\nEnter your choice (1-%d): ", NUM_CANDIDATES);
        scanf("%d", &choice);

        if (choice >= 1 && choice <= NUM_CANDIDATES) {
            candidates[choice - 1].votes++;
            for (int i = 0; i < NUM_VOTERS; i++) {
                if (voters[i].vote == 0) {
                    voters[i].vote = choice;
                    votes_cast++;
                    break;
                }
            }
        } else {
            printf("Invalid choice.\n");
        }
    }

    printf("\nElection results:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}