//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 20
#define MAX_PARTY_LENGTH 20
#define MAX_VOTES 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    char party[MAX_PARTY_LENGTH];
    int votes;
} Candidate;

int main() {
    int num_candidates = 0;
    Candidate candidates[MAX_VOTES];

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d's name: ", i + 1);
        scanf("%s", candidates[i].name);

        printf("Enter candidate %d's party: ", i + 1);
        scanf("%s", candidates[i].party);

        candidates[i].votes = 0;
    }

    printf("Enter the number of votes: ");
    scanf("%d", &num_candidates);

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter vote %d for candidate: ", i + 1);
        scanf("%s", candidates[i].name);

        candidates[i].votes++;
    }

    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > 0) {
            printf("%s (%s) has %d votes\n", candidates[i].name, candidates[i].party, candidates[i].votes);
        }
    }

    return 0;
}