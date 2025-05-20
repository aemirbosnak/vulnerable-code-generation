//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTE_LENGTH 20

struct candidate {
    char name[MAX_VOTE_LENGTH];
    int votes;
};

struct voter {
    char name[MAX_VOTE_LENGTH];
    int vote;
};

void generate_candidates(struct candidate candidates[MAX_CANDIDATES], int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }
}

void generate_voters(struct voter voters[MAX_VOTERS], int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        voters[i].name[0] = '\0';
        voters[i].vote = -1;
    }
}

int main() {
    int num_candidates, num_voters;

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    struct candidate candidates[MAX_CANDIDATES];
    generate_candidates(candidates, num_candidates);

    struct voter voters[MAX_VOTERS];
    generate_voters(voters, num_voters);

    int i, j;
    for (i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);
        printf("Enter the vote of voter %d: ", i + 1);
        scanf("%d", &voters[i].vote);
    }

    for (i = 0; i < num_voters; i++) {
        for (j = 0; j < num_candidates; j++) {
            if (voters[i].vote == j) {
                candidates[j].votes++;
            }
        }
    }

    printf("\nElection Results:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}