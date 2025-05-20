//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define NUM_CANDIDATES 5
#define NUM_VOTERS 100

// Structure for a candidate
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Function to compare two candidates based on their votes
int compare_candidates(const void *a, const void *b) {
    Candidate *candidate_a = (Candidate *)a;
    Candidate *candidate_b = (Candidate *)b;

    if (candidate_a->votes > candidate_b->votes) {
        return -1;
    } else if (candidate_a->votes < candidate_b->votes) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print the election results
void print_results(Candidate candidates[NUM_CANDIDATES]) {
    qsort(candidates, NUM_CANDIDATES, sizeof(Candidate), compare_candidates);

    printf("Election Results:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    // Initialize the candidates
    Candidate candidates[NUM_CANDIDATES] = {{"Alice", 0}, {"Bob", 0}, {"Charlie", 0}, {"David", 0}, {"Eve", 0}};

    // Simulate votes from NUM_VOTERS voters
    for (int i = 0; i < NUM_VOTERS; i++) {
        int choice;
        printf("Voter %d, please enter your choice (0-4): ", i + 1);
        scanf("%d", &choice);

        if (choice >= 0 && choice < NUM_CANDIDATES) {
            candidates[choice].votes++;
        } else {
            printf("Invalid choice.\n");
        }
    }

    // Print the election results
    print_results(candidates);

    return 0;
}