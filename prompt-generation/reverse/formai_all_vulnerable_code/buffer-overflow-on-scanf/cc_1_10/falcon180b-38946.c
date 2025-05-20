//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} candidate_t;

candidate_t candidates[MAX_CANDIDATES];

int main() {
    int num_candidates, num_voters, i, j;
    char input[MAX_NAME_LENGTH];
    candidate_t* winner = NULL;

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    for (i = 0; i < num_voters; i++) {
        printf("Enter the vote of voter %d: ", i+1);
        scanf("%s", input);
        for (j = 0; j < num_candidates; j++) {
            if (strcmp(candidates[j].name, input) == 0) {
                candidates[j].votes++;
                break;
            }
        }
    }

    winner = &candidates[0];
    for (i = 1; i < num_candidates; i++) {
        if (winner->votes < candidates[i].votes) {
            winner = &candidates[i];
        }
    }

    printf("The winner is %s with %d votes.\n", winner->name, winner->votes);

    return 0;
}