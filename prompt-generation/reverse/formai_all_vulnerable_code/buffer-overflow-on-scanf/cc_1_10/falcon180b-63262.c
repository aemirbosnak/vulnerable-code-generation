//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 50

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char name[50];
    int voted;
    Candidate candidates[MAX_CANDIDATES];
} Voter;

int main() {
    int num_candidates;
    int num_voters;
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    printf("Enter the names of the candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    printf("Enter the names of the voters:\n");
    for (int i = 0; i < num_voters; i++) {
        scanf("%s", voters[i].name);
        voters[i].voted = 0;
        for (int j = 0; j < num_candidates; j++) {
            voters[i].candidates[j].votes = 0;
        }
    }

    srand(time(NULL));
    for (int i = 0; i < num_voters; i++) {
        if (!voters[i].voted) {
            printf("%s is voting...\n", voters[i].name);
            int candidate_index = rand() % num_candidates;
            voters[i].candidates[candidate_index].votes++;
            candidates[candidate_index].votes++;
            voters[i].voted = 1;
        }
    }

    printf("\nElection results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}