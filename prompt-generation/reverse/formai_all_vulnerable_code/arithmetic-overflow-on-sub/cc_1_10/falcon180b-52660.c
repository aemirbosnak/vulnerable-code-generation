//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 50

typedef struct {
    char name[50];
    int votes;
} candidate_t;

candidate_t candidates[MAX_CANDIDATES];

int main() {
    int i, j, choice, num_candidates, num_voters;
    char name[50];

    // Initialize random seed
    srand(time(NULL));

    // Get number of candidates
    printf("Enter the number of candidates (1-5): ");
    scanf("%d", &num_candidates);

    // Generate random candidate names
    for (i = 0; i < num_candidates; i++) {
        candidates[i].votes = 0;
        sprintf(candidates[i].name, "Candidate %d", i + 1);
    }

    // Get number of voters
    printf("Enter the number of voters (1-50): ");
    scanf("%d", &num_voters);

    // Simulate voting
    for (i = 0; i < num_voters; i++) {
        printf("\nVoter %d:\n", i + 1);

        // Display candidate list
        printf("Candidates:\n");
        for (j = 0; j < num_candidates; j++) {
            printf("%d. %s\n", j + 1, candidates[j].name);
        }

        // Get voter choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Increment candidate vote count
        candidates[choice - 1].votes++;
    }

    // Display election results
    printf("\nElection Results:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%d. %s - %d votes\n", i + 1, candidates[i].name, candidates[i].votes);
    }

    return 0;
}