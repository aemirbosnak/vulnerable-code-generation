//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES 10

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char name[50];
    int vote[MAX_CANDIDATES];
} Voter;

int main() {
    int num_candidates, num_voters;
    scanf("%d %d", &num_candidates, &num_voters);

    Candidate candidates[MAX_CANDIDATES];
    for (int i = 0; i < num_candidates; i++) {
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    Voter voters[MAX_VOTERS];
    for (int i = 0; i < num_voters; i++) {
        scanf("%s", voters[i].name);
        for (int j = 0; j < num_candidates; j++) {
            voters[i].vote[j] = 0;
        }
    }

    printf("Enter votes for each candidate:\n");
    for (int i = 0; i < num_candidates; i++) {
        scanf("%s", candidates[i].name);
        for (int j = 0; j < num_voters; j++) {
            scanf("%d", &voters[j].vote[i]);
        }
    }

    Candidate winner;
    winner.name[0] = '\0';
    winner.votes = 0;

    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > winner.votes) {
            winner.votes = candidates[i].votes;
            strcpy(winner.name, candidates[i].name);
        }
    }

    printf("The winner is %s with %d votes.\n", winner.name, winner.votes);

    return 0;
}