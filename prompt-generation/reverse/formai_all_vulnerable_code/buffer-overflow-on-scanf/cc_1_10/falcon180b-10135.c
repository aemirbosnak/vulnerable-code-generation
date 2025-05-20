//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTE_LENGTH 100

typedef struct {
    char name[MAX_VOTE_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_VOTE_LENGTH];
    int vote;
} Voter;

int main() {
    int num_candidates, num_voters;
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    printf("Enter the names of the candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        scanf("%s", candidates[i].name);
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    printf("Enter the names of the voters:\n");
    for (int i = 0; i < num_voters; i++) {
        scanf("%s", voters[i].name);
    }

    printf("Enter the votes for each candidate:\n");
    for (int i = 0; i < num_voters; i++) {
        printf("Voter %s:\n", voters[i].name);
        for (int j = 0; j < num_candidates; j++) {
            printf("%s - ", candidates[j].name);
        }
        scanf("%d", &voters[i].vote);
    }

    printf("Election results:\n");
    for (int i = 0; i < num_candidates; i++) {
        candidates[i].votes = 0;
    }
    for (int i = 0; i < num_voters; i++) {
        candidates[voters[i].vote - 1].votes++;
    }
    for (int i = 0; i < num_candidates; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}