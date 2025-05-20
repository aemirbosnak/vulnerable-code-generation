//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CANDIDATES 5
#define NUM_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} candidate_t;

candidate_t candidates[NUM_CANDIDATES] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Charlie", 0},
    {"David", 0},
    {"Eve", 0}
};

void print_candidates(void) {
    int i;

    for (i = 0; i < NUM_CANDIDATES; i++) {
        printf("%d. %s: %d votes\n", i+1, candidates[i].name, candidates[i].votes);
    }
}

void vote(int candidate_index) {
    candidates[candidate_index - 1].votes++;
}

int main(void) {
    int i, j;
    int choice;

    srand(time(NULL));

    // Initialize random votes for each candidate
    for (i = 0; i < NUM_CANDIDATES; i++) {
        candidates[i].votes = rand() % 1000;
    }

    // Print initial vote counts
    printf("Initial Vote Counts:\n");
    print_candidates();

    // Simulate voting by random voters
    for (i = 0; i < NUM_VOTERS; i++) {
        printf("\nVoter %d:\n", i+1);

        // Display list of candidates
        print_candidates();

        // Ask for voter's choice
        printf("Enter your choice (1-%d): ", NUM_CANDIDATES);
        scanf("%d", &choice);

        // Cast vote
        vote(choice);
    }

    // Print final vote counts
    printf("\nFinal Vote Counts:\n");
    print_candidates();

    return 0;
}