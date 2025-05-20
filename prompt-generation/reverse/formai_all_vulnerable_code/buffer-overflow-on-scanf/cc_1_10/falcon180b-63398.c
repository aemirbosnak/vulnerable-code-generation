//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes[MAX_CANDIDATES];
} Voter;

int main() {
    int num_candidates, num_voters;
    char input[100];
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

    printf("Enter the votes for each voter:\n");
    for (int i = 0; i < num_voters; i++) {
        for (int j = 0; j < num_candidates; j++) {
            scanf("%d", &voters[i].votes[j]);
        }
    }

    printf("The results of the election are:\n");
    for (int i = 0; i < num_candidates; i++) {
        int total_votes = 0;
        for (int j = 0; j < num_voters; j++) {
            total_votes += voters[j].votes[i];
        }
        printf("%s: %d votes\n", candidates[i].name, total_votes);
    }

    return 0;
}