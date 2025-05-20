//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LEN 50
#define MAX_VOTES 5

typedef struct {
    char name[MAX_NAME_LEN];
    int votes;
} candidate_t;

typedef struct {
    char name[MAX_NAME_LEN];
    int vote[MAX_CANDIDATES];
} voter_t;

int main() {
    int num_candidates, num_voters;
    char input[100];
    candidate_t candidates[MAX_CANDIDATES];
    voter_t voters[MAX_VOTERS];

    // Read number of candidates
    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);

    // Read candidate names and store in array
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d name: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Read number of voters
    printf("Enter number of voters: ");
    scanf("%d", &num_voters);

    // Read voter names and store in array
    for (int i = 0; i < num_voters; i++) {
        printf("Enter voter %d name: ", i + 1);
        scanf("%s", voters[i].name);
    }

    // Read votes for each candidate
    for (int i = 0; i < num_voters; i++) {
        printf("Enter votes for voter %s (1-5): ", voters[i].name);
        scanf("%d", &voters[i].vote[0]);
        for (int j = 1; j < MAX_VOTES; j++) {
            scanf("%d", &voters[i].vote[j]);
        }
    }

    // Count votes for each candidate
    for (int i = 0; i < num_candidates; i++) {
        for (int j = 0; j < num_voters; j++) {
            if (voters[j].vote[0] == i + 1) {
                candidates[i].votes++;
            }
        }
    }

    // Print winners
    printf("Election results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}