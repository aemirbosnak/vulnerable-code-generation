//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

struct candidate {
    char name[MAX_NAME_LENGTH];
    int votes;
};

struct voter {
    char name[MAX_NAME_LENGTH];
    int voter_id;
};

void read_candidates(struct candidate candidates[]) {
    int i = 0;
    while (i < MAX_CANDIDATES && scanf("%s", candidates[i].name)!= EOF) {
        i++;
    }
}

void read_voters(struct voter voters[]) {
    int i = 0;
    while (i < MAX_VOTERS && scanf("%s%d", voters[i].name, &voters[i].voter_id)!= EOF) {
        i++;
    }
}

int main() {
    struct candidate candidates[MAX_CANDIDATES];
    struct voter voters[MAX_VOTERS];

    // Read candidates
    printf("Enter the names of the candidates (up to %d):\n", MAX_CANDIDATES);
    read_candidates(candidates);

    // Read voters
    printf("Enter the names and voter IDs of the voters (up to %d):\n", MAX_VOTERS);
    read_voters(voters);

    // Cast votes
    int i, j, k;
    for (i = 0; i < MAX_VOTERS; i++) {
        printf("Voter %d is casting their vote:\n", voters[i].voter_id);
        for (j = 0; j < MAX_CANDIDATES; j++) {
            printf("%s (%d)\n", candidates[j].name, j + 1);
        }
        printf("Enter the candidate number: ");
        scanf("%d", &k);
        if (k >= 1 && k <= MAX_CANDIDATES) {
            candidates[k - 1].votes++;
            printf("Vote cast for %s.\n", candidates[k - 1].name);
        } else {
            printf("Invalid candidate number.\n");
        }
    }

    // Display results
    printf("\nElection results:\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}