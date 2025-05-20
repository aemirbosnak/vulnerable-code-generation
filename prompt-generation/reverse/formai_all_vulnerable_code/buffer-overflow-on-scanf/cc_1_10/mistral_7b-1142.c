//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#define MAX_VOTERS 100
#define NUM_CANDIDATES 5
#define TRUE 1
#define FALSE 0

typedef struct {
    int voter_id;
    int candidate;
} Voter;

int main() {
    int total_voters = 0, total_votes = 0;
    int candidates[NUM_CANDIDATES] = {0};
    Voter voters[MAX_VOTERS];

    for (int i = 0; i < MAX_VOTERS && total_voters < MAX_VOTERS; i++) {
        printf("Voter %d, please enter your ID: ", i + 1);
        scanf("%d", &voters[i].voter_id);

        if (total_voters >= MAX_VOTERS) {
            printf("\nMaximum number of voters reached.\n");
            break;
        }

        int valid_vote = FALSE;
        while (!valid_vote) {
            printf("Voter %d, please enter the ID of your preferred candidate (1-5): ", i + 1);
            scanf("%d", &voters[i].candidate);

            if (voters[i].candidate >= 1 && voters[i].candidate <= NUM_CANDIDATES) {
                valid_vote = TRUE;
                total_voters++;
                candidates[voters[i].candidate - 1]++;
                total_votes++;
            } else {
                printf("Invalid candidate ID. Please try again.\n");
            }
        }
    }

    printf("\nTotal number of voters: %d\n", total_voters);
    printf("Total number of votes: %d\n", total_votes);
    printf("\nNumber of votes received by each candidate:\n");

    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("Candidate %d: %d votes\n", i + 1, candidates[i]);
    }

    return 0;
}