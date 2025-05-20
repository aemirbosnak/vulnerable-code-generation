//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_SIZE 50

typedef struct {
    char name[MAX_NAME_SIZE];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_SIZE];
    int vote;
} Voter;

void read_candidates(Candidate candidates[], int num_candidates) {
    printf("Enter the names of the candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        scanf("%s", candidates[i].name);
    }
}

void read_voters(Voter voters[], int num_voters) {
    printf("Enter the names of the voters:\n");
    for (int i = 0; i < num_voters; i++) {
        scanf("%s", voters[i].name);
    }
}

int main() {
    int num_candidates, num_voters;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    Candidate candidates[MAX_CANDIDATES];
    read_candidates(candidates, num_candidates);

    Voter voters[MAX_VOTERS];
    read_voters(voters, num_voters);

    int votes[MAX_CANDIDATES] = {0};
    for (int i = 0; i < num_voters; i++) {
        printf("Voter %s casts a vote for: ", voters[i].name);
        scanf("%s", candidates[voters[i].vote].name);
        votes[voters[i].vote]++;
    }

    printf("\nElection Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, votes[i]);
    }

    return 0;
}