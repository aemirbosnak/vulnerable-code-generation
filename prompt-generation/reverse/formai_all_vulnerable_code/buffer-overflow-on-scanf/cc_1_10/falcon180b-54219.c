//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 10000
#define MAX_VOTE_LENGTH 50

struct candidate {
    char name[MAX_VOTE_LENGTH];
    int votes;
};

struct voter {
    char name[MAX_VOTE_LENGTH];
    int voter_id;
};

struct vote {
    int voter_id;
    int candidate_id;
};

int main() {
    struct candidate candidates[MAX_CANDIDATES];
    struct voter voters[MAX_VOTERS];
    struct vote votes[MAX_VOTERS];
    int num_candidates = 0, num_voters = 0;
    int i, j, k, choice;
    char buffer[MAX_VOTE_LENGTH];
    time_t now;

    // Initialize random seed
    time(&now);
    srand(now);

    // Add candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    for (i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Add voters
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    for (i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);
        voters[i].voter_id = i + 1;
    }

    // Voting
    printf("Voting has started...\n");
    for (i = 0; i < num_voters; i++) {
        printf("Voter %d is voting...\n", voters[i].voter_id);
        do {
            printf("Enter your choice (1-%d): ", num_candidates);
            scanf("%d", &choice);
        } while (choice < 1 || choice > num_candidates);
        votes[i].voter_id = voters[i].voter_id;
        votes[i].candidate_id = choice - 1;
        candidates[choice - 1].votes++;
    }

    // Display results
    printf("Voting has ended...\n");
    for (i = 0; i < num_candidates; i++) {
        printf("Candidate %s got %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}