//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

struct candidate {
    char name[MAX_NAME_LENGTH];
    int votes;
};

struct voter {
    char name[MAX_NAME_LENGTH];
    int vote;
};

int main() {
    int num_candidates, num_voters;
    struct candidate candidates[MAX_CANDIDATES];
    struct voter voters[MAX_VOTERS];

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
    }

    printf("Enter the votes:\n");
    for (int i = 0; i < num_voters; i++) {
        printf("Voter %s's vote: ", voters[i].name);
        scanf("%d", &voters[i].vote);
    }

    for (int i = 0; i < num_candidates; i++) {
        printf("Candidate %s got %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}