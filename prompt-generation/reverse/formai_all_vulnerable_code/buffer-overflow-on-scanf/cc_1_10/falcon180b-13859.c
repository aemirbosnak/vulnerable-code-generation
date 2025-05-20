//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES 100

typedef struct {
    char name[50];
    int votes;
} candidate;

typedef struct {
    char name[50];
    int vote[MAX_CANDIDATES];
} voter;

void read_candidates(candidate candidates[], int num_candidates) {
    printf("Enter the names of the candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        scanf("%s", candidates[i].name);
    }
}

void read_voters(voter voters[], int num_voters) {
    printf("Enter the names of the voters:\n");
    for (int i = 0; i < num_voters; i++) {
        scanf("%s", voters[i].name);
    }
}

int main() {
    int num_candidates, num_voters;

    printf("Enter the number of candidates:\n");
    scanf("%d", &num_candidates);

    printf("Enter the number of voters:\n");
    scanf("%d", &num_voters);

    candidate candidates[num_candidates];
    read_candidates(candidates, num_candidates);

    voter voters[num_voters];
    read_voters(voters, num_voters);

    printf("Enter the votes:\n");
    for (int i = 0; i < num_voters; i++) {
        for (int j = 0; j < num_candidates; j++) {
            scanf("%d", &voters[i].vote[j]);
        }
    }

    printf("Election results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, 0);
    }

    for (int i = 0; i < num_voters; i++) {
        for (int j = 0; j < num_candidates; j++) {
            candidates[j].votes += voters[i].vote[j];
        }
    }

    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}