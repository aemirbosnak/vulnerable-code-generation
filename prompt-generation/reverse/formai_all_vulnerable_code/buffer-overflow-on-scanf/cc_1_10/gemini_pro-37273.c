//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store candidate details
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// Function to compare candidates by votes
int compare_candidates(const void *a, const void *b) {
    const candidate *c1 = a;
    const candidate *c2 = b;
    return c2->votes - c1->votes;
}

// Function to get candidate by name
candidate *get_candidate_by_name(char *name, candidate *candidates, int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(name, candidates[i].name) == 0) {
            return &candidates[i];
        }
    }
    return NULL;
}

// Function to print election results
void print_results(candidate *candidates, int num_candidates) {
    printf("Election Results:\n");
    qsort(candidates, num_candidates, sizeof(candidate), compare_candidates);
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    // Initialize candidates
    candidate candidates[] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Charlie", 0},
        {"Dave", 0},
        {"Eve", 0}
    };
    int num_candidates = sizeof(candidates) / sizeof(candidate);

    // Get number of votes
    int num_votes;
    printf("Enter number of votes: ");
    scanf("%d", &num_votes);

    // Get votes
    for (int i = 0; i < num_votes; i++) {
        char name[50];
        printf("Enter candidate name: ");
        scanf("%s", name);

        candidate *candidate = get_candidate_by_name(name, candidates, num_candidates);
        if (candidate != NULL) {
            candidate->votes++;
        } else {
            printf("Invalid candidate name\n");
        }
    }

    // Print results
    print_results(candidates, num_candidates);

    return 0;
}