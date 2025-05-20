//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_VOTES_PER_VOTER 10
#define MAX_VOTE_LENGTH 100

typedef struct {
    char name[MAX_VOTE_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_VOTE_LENGTH];
    int votes[MAX_CANDIDATES];
} Voter;

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int num_candidates = 0, num_voters = 0;
    char input[MAX_VOTE_LENGTH];

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);

        printf("Enter the votes for %s:\n", voters[i].name);

        for (int j = 0; j < MAX_VOTES_PER_VOTER; j++) {
            scanf("%s", input);

            int vote_found = 0;
            for (int k = 0; k < num_candidates; k++) {
                if (strcmp(input, candidates[k].name) == 0) {
                    candidates[k].votes++;
                    vote_found = 1;
                    break;
                }
            }

            if (!vote_found) {
                printf("Invalid vote: %s\n", input);
            }
        }
    }

    printf("Results:\n");

    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}