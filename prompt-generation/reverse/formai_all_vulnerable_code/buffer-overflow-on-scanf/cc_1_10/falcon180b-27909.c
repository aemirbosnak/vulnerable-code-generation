//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES_PER_CANDIDATE 1000

typedef struct {
    char name[50];
    int votes[MAX_CANDIDATES];
} voter;

typedef struct {
    char name[50];
    int votes;
} candidate;

void read_candidates(candidate candidates[], int num_candidates) {
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void read_voters(voter voters[], int num_voters) {
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);

        for (int j = 0; j < MAX_CANDIDATES; j++) {
            voters[i].votes[j] = 0;
        }
    }
}

void print_candidates(candidate candidates[], int num_candidates) {
    printf("The candidates are:\n");

    for (int i = 0; i < num_candidates; i++) {
        printf("%s (%d votes)\n", candidates[i].name, candidates[i].votes);
    }
}

void count_votes(voter voters[], candidate candidates[], int num_voters, int num_candidates) {
    for (int i = 0; i < num_voters; i++) {
        for (int j = 0; j < num_candidates; j++) {
            if (voters[i].votes[j] == 1) {
                candidates[j].votes++;
            }
        }
    }
}

int main() {
    candidate candidates[MAX_CANDIDATES];
    voter voters[MAX_VOTERS];

    read_candidates(candidates, MAX_CANDIDATES);
    read_voters(voters, MAX_VOTERS);

    count_votes(voters, candidates, MAX_VOTERS, MAX_CANDIDATES);

    print_candidates(candidates, MAX_CANDIDATES);

    return 0;
}