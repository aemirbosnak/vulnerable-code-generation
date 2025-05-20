//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_VOTER_NAME_LENGTH 50

struct candidate {
    char name[MAX_VOTER_NAME_LENGTH];
    int votes;
};

struct voter {
    char name[MAX_VOTER_NAME_LENGTH];
    int voter_id;
};

void print_candidates(struct candidate candidates[], int num_candidates) {
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

int main() {
    struct candidate candidates[MAX_CANDIDATES];
    int num_candidates = 0;

    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    int num_voters;
    printf("Enter number of voters: ");
    scanf("%d", &num_voters);

    struct voter voters[MAX_VOTERS];

    for (int i = 0; i < num_voters; i++) {
        printf("Enter voter name: ");
        scanf("%s", voters[i].name);
        voters[i].voter_id = i + 1;
    }

    int valid_votes = 0;

    for (int i = 0; i < num_voters; i++) {
        printf("Voter %d, enter your vote:\n", voters[i].voter_id);
        int vote;
        scanf("%d", &vote);

        if (vote >= 1 && vote <= num_candidates) {
            candidates[vote - 1].votes++;
            valid_votes++;
        } else {
            printf("Invalid vote.\n");
        }
    }

    printf("Election results:\n");
    print_candidates(candidates, num_candidates);

    return 0;
}