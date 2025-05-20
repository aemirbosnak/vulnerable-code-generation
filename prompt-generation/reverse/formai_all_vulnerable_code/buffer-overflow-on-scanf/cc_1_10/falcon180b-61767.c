//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTER_NAME 50

struct candidate {
    char name[MAX_VOTER_NAME];
    int votes;
};

struct voter {
    char name[MAX_VOTER_NAME];
    int vote;
};

void display_candidates(struct candidate candidates[], int num_candidates) {
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

int main() {
    struct candidate candidates[MAX_CANDIDATES];
    int num_candidates = 0;

    printf("Enter number of candidates (maximum %d): ", MAX_CANDIDATES);
    scanf("%d", &num_candidates);

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    struct voter voters[MAX_VOTERS];
    int num_voters = 0;

    printf("Enter number of voters (maximum %d): ", MAX_VOTERS);
    scanf("%d", &num_voters);

    for (int i = 0; i < num_voters; i++) {
        printf("Enter name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);
    }

    printf("Voting begins...\n");

    for (int i = 0; i < num_voters; i++) {
        printf("Voter %s is voting...\n", voters[i].name);
        printf("Enter vote for candidate: ");
        scanf("%d", &voters[i].vote);
    }

    printf("Voting ends.\n");

    for (int i = 0; i < num_candidates; i++) {
        for (int j = 0; j < num_voters; j++) {
            if (voters[j].vote == i + 1) {
                candidates[i].votes++;
            }
        }
    }

    printf("Election results:\n");
    display_candidates(candidates, num_candidates);

    return 0;
}