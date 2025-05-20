//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTER_NAME_LENGTH 50
#define MAX_CANDIDATE_NAME_LENGTH 50

typedef struct {
    char name[MAX_CANDIDATE_NAME_LENGTH];
    int votes;
} candidate_t;

typedef struct {
    char name[MAX_VOTER_NAME_LENGTH];
    int vote;
} voter_t;

int main() {
    candidate_t candidates[MAX_CANDIDATES];
    voter_t voters[MAX_VOTERS];
    int num_candidates, num_voters;
    int i, j, k;

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    printf("Enter the names of the candidates:\n");
    for (i = 0; i < num_candidates; i++) {
        scanf(" %s", candidates[i].name);
    }

    printf("Enter the names of the voters:\n");
    for (i = 0; i < num_voters; i++) {
        scanf(" %s", voters[i].name);
    }

    printf("Enter the votes for each candidate:\n");
    for (i = 0; i < num_candidates; i++) {
        for (j = 0; j < num_voters; j++) {
            scanf(" %d", &voters[j].vote);
            if (voters[j].vote == i+1) {
                candidates[i].votes++;
            }
        }
    }

    printf("The results of the election are:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}