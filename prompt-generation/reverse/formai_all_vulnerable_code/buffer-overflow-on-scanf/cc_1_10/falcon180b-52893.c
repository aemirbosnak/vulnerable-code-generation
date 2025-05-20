//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50
#define MAX_VOTE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int vote[MAX_CANDIDATES];
} Voter;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

void read_candidates(Candidate candidates[], int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d's name: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void read_voters(Voter voters[], int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        printf("Enter voter %d's name: ", i + 1);
        scanf("%s", voters[i].name);
        for (int j = 0; j < MAX_CANDIDATES; j++) {
            voters[i].vote[j] = -1;
        }
    }
}

void count_votes(Candidate candidates[], Voter voters[], int num_candidates, int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        int valid_votes = 0;
        for (int j = 0; j < MAX_CANDIDATES; j++) {
            if (voters[i].vote[j] >= 0 && voters[i].vote[j] < num_candidates) {
                candidates[voters[i].vote[j]].votes++;
                valid_votes++;
            }
        }
        if (valid_votes == 0) {
            printf("Invalid vote from voter %s\n", voters[i].name);
        }
    }
}

void print_results(Candidate candidates[], int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    int num_candidates, num_voters;

    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);

    printf("Enter number of voters: ");
    scanf("%d", &num_voters);

    read_candidates(candidates, num_candidates);
    read_voters(voters, num_voters);

    printf("Enter votes:\n");
    for (int i = 0; i < num_voters; i++) {
        for (int j = 0; j < MAX_CANDIDATES; j++) {
            printf("Voter %d's vote for candidate %d: ", i + 1, j + 1);
            scanf("%d", &voters[i].vote[j]);
        }
    }

    count_votes(candidates, voters, num_candidates, num_voters);

    printf("\nResults:\n");
    print_results(candidates, num_candidates);

    return 0;
}