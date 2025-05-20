//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} candidate_t;

candidate_t candidates[MAX_CANDIDATES];

int main() {
    int num_candidates, num_voters, i, j;
    char input[100];

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (i = 0; i < num_candidates; i++) {
        printf("Please enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Please enter the number of voters: ");
    scanf("%d", &num_voters);

    for (i = 0; i < num_voters; i++) {
        printf("Please enter the name of voter %d: ", i + 1);
        scanf("%s", input);

        for (j = 0; j < num_candidates; j++) {
            if (strcmp(candidates[j].name, input) == 0) {
                candidates[j].votes++;
                break;
            }
        }
    }

    printf("\nElection Results:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}