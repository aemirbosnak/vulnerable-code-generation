//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES 10

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
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate name: ");
        scanf("%s", &candidates[i].name);
    }

    printf("Enter number of voters: ");
    scanf("%d", &num_voters);

    for (int i = 0; i < num_voters; i++) {
        printf("Enter voter name: ");
        scanf("%s", &voters[i].name);

        for (int j = 0; j < num_candidates; j++) {
            printf("Enter vote for candidate %s: ", candidates[j].name);
            scanf("%d", &voters[i].vote);
            candidates[j].votes[i] = voters[i].vote;
        }
    }

    printf("\nVotes:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: ", candidates[i].name);
        for (int j = 0; j < num_voters; j++) {
            printf("%d ", candidates[i].votes[j]);
        }
        printf("\n");
    }

    return 0;
}