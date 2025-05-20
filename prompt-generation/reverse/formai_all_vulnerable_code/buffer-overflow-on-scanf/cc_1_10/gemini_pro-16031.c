//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: interoperable
// Header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Candidate structure
typedef struct candidate {
    char name[100];
    int votes;
} candidate;

// Function to compare candidates
int compare_candidates(const void *a, const void *b) {
    const candidate *c1 = (const candidate *)a;
    const candidate *c2 = (const candidate *)b;
    return c2->votes - c1->votes;
}

// Main function
int main() {
    // Initialize candidates
    candidate candidates[] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Carol", 0},
        {"Dave", 0},
        {"Eve", 0}
    };

    // Get number of voters
    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Get votes
    for (int i = 0; i < num_voters; i++) {
        char vote[100];
        printf("Enter vote for voter %d (Alice, Bob, Carol, Dave, Eve): ", i + 1);
        scanf("%s", vote);

        // Find candidate with matching name
        for (int j = 0; j < sizeof(candidates) / sizeof(candidate); j++) {
            if (strcmp(vote, candidates[j].name) == 0) {
                candidates[j].votes++;
                break;
            }
        }
    }

    // Sort candidates by votes
    qsort(candidates, sizeof(candidates) / sizeof(candidate), sizeof(candidate), compare_candidates);

    // Print results
    for (int i = 0; i < sizeof(candidates) / sizeof(candidate); i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Return success
    return 0;
}