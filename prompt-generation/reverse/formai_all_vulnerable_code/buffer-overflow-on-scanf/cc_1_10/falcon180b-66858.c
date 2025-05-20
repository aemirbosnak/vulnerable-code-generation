//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_CANDIDATE_NAME_LENGTH 100
#define MAX_VOTER_NAME_LENGTH 100

typedef struct {
    char name[MAX_CANDIDATE_NAME_LENGTH];
    int votes;
} candidate;

typedef struct {
    char name[MAX_VOTER_NAME_LENGTH];
    int age;
} voter;

int main() {
    int num_candidates, num_voters;
    candidate candidates[MAX_CANDIDATES];
    voter voters[MAX_VOTERS];
    int i, j, k;

    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);

    for (i = 0; i < num_candidates; i++) {
        printf("Enter candidate name %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Enter number of voters: ");
    scanf("%d", &num_voters);

    for (i = 0; i < num_voters; i++) {
        printf("Enter voter name %d: ", i+1);
        scanf("%s", voters[i].name);
        printf("Enter age of voter %d: ", i+1);
        scanf("%d", &voters[i].age);
    }

    printf("Enter your vote (candidate number): ");
    int vote = 0;
    scanf("%d", &vote);

    candidates[vote-1].votes++;

    printf("\nResults:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}