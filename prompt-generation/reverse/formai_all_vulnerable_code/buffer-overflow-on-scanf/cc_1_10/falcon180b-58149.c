//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_VOTES_PER_VOTER 10

typedef struct {
    char name[50];
    int votes[MAX_CANDIDATES];
} Candidate;

typedef struct {
    char name[50];
    int vote;
} Voter;

int main() {
    int num_candidates, num_voters;
    scanf("%d %d", &num_candidates, &num_voters);

    Candidate candidates[MAX_CANDIDATES];
    for (int i = 0; i < num_candidates; i++) {
        scanf("%s", candidates[i].name);
    }

    Voter voters[MAX_VOTERS];
    for (int i = 0; i < num_voters; i++) {
        scanf("%s", voters[i].name);
        for (int j = 0; j < MAX_VOTES_PER_VOTER; j++) {
            scanf("%d", &voters[i].vote);
        }
    }

    int total_votes = 0;
    for (int i = 0; i < num_voters; i++) {
        for (int j = 0; j < MAX_VOTES_PER_VOTER; j++) {
            for (int k = 0; k < num_candidates; k++) {
                if (voters[i].vote == k + 1) {
                    candidates[k].votes[total_votes]++;
                    total_votes++;
                }
            }
        }
    }

    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes[0]);
    }

    return 0;
}