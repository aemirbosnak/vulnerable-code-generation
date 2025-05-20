//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a candidate
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// Function to compare two candidates by their votes
int compare(const void *a, const void *b) {
    candidate *c1 = (candidate *)a;
    candidate *c2 = (candidate *)b;
    return c2->votes - c1->votes;
}

// Function to print the results of the election
void print_results(candidate *candidates, int num_candidates) {
    printf("Election results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Function to run the election
void run_election(candidate *candidates, int num_candidates, int num_voters) {
    // Allocate memory for the votes
    int *votes = malloc(sizeof(int) * num_voters);

    // Get the votes from the voters
    for (int i = 0; i < num_voters; i++) {
        printf("Voter %d, enter your vote (1-%d): ", i + 1, num_candidates);
        scanf("%d", &votes[i]);
    }

    // Count the votes
    for (int i = 0; i < num_voters; i++) {
        candidates[votes[i] - 1].votes++;
    }

    // Sort the candidates by their votes
    qsort(candidates, num_candidates, sizeof(candidate), compare);

    // Print the results of the election
    print_results(candidates, num_candidates);

    // Free the memory allocated for the votes
    free(votes);
}

// Main function
int main() {
    // Initialize the candidates
    candidate candidates[] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Carol", 0},
        {"Dave", 0},
        {"Eve", 0}
    };

    // Get the number of candidates and voters
    int num_candidates = sizeof(candidates) / sizeof(candidate);
    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Run the election
    run_election(candidates, num_candidates, num_voters);

    return 0;
}