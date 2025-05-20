//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int vote;
} Voter;

typedef struct {
    char name[50];
    int votes;
} Candidate;

void generate_candidates(Candidate candidates[], int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        sprintf(candidates[i].name, "Candidate %d", i + 1);
        candidates[i].votes = 0;
    }
}

void generate_voters(Voter voters[], int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        sprintf(voters[i].name, "Voter %d", i + 1);
        voters[i].vote = -1;
    }
}

int compare_candidates(const void *a, const void *b) {
    return (*(Candidate*)b).votes - (*(Candidate*)a).votes;
}

int main() {
    srand(time(NULL));

    int num_candidates, num_voters;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    Candidate candidates[MAX_CANDIDATES];
    generate_candidates(candidates, num_candidates);

    Voter voters[MAX_VOTERS];
    generate_voters(voters, num_voters);

    int votes_cast = 0;
    while (votes_cast < num_voters) {
        int voter_index = rand() % num_voters;
        if (voters[voter_index].vote == -1) {
            int candidate_index = rand() % num_candidates;
            voters[voter_index].vote = candidate_index;
            candidates[candidate_index].votes++;
            votes_cast++;
        }
    }

    qsort(candidates, num_candidates, sizeof(Candidate), compare_candidates);

    printf("\nElection Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}