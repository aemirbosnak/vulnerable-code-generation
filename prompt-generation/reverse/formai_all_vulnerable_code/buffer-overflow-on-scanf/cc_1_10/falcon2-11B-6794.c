//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

struct candidate {
    char name[20];
    int votes;
};

struct voter {
    char name[20];
    int candidate_id;
};

struct voter voters[MAX_VOTERS];
struct candidate candidates[MAX_CANDIDATES];

int main() {
    int num_voters = 0, num_candidates = 0, i, j, k;
    int max_votes = 0;
    char buffer[100];

    // Read voter and candidate information
    printf("Enter number of voters: ");
    scanf("%d", &num_voters);

    for (i = 0; i < num_voters; i++) {
        printf("Enter voter name: ");
        fgets(voters[i].name, sizeof(voters[i].name), stdin);

        printf("Enter candidate ID: ");
        scanf("%d", &voters[i].candidate_id);
    }

    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);

    for (i = 0; i < num_candidates; i++) {
        printf("Enter candidate name: ");
        fgets(candidates[i].name, sizeof(candidates[i].name), stdin);
        candidates[i].votes = 0;
    }

    // Vote for candidates
    printf("Enter voter name: ");
    fgets(buffer, sizeof(buffer), stdin);
    while (strlen(buffer)!= 0) {
        for (i = 0; i < num_voters; i++) {
            if (strcmp(voters[i].name, buffer) == 0) {
                printf("Enter candidate ID: ");
                scanf("%d", &voters[i].candidate_id);
            }
        }

        for (j = 0; j < num_candidates; j++) {
            if (voters[i].candidate_id == j) {
                candidates[j].votes++;
            }
        }

        printf("Enter voter name: ");
        fgets(buffer, sizeof(buffer), stdin);
    }

    // Calculate winner and print result
    for (i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            k = i;
        }
    }

    printf("Winner: %s - %d votes\n", candidates[k].name, max_votes);

    return 0;
}