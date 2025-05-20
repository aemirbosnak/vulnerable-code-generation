//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} candidate_t;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int voter_id;
} voter_t;

int main() {

    candidate_t candidates[MAX_CANDIDATES];
    voter_t voters[MAX_VOTERS];
    int num_candidates = 0, num_voters = 0;

    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Enter number of voters: ");
    scanf("%d", &num_voters);

    for (int i = 0; i < num_voters; i++) {
        printf("Enter voter name: ");
        scanf("%s", voters[i].name);
        voters[i].voter_id = i + 1;
    }

    printf("Voting begins...\n");

    for (int i = 0; i < num_voters; i++) {
        printf("Voter %d is voting...\n", voters[i].voter_id);
        printf("Enter candidate number to vote for: ");
        scanf("%d", &candidates[voters[i].voter_id - 1].votes);
    }

    printf("Voting complete!\n");

    printf("Election results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}