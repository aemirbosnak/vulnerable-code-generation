//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Candidate structure
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// Function to compare two candidates based on their votes
int compare_candidates(const void *a, const void *b) {
    const candidate *c1 = (const candidate *)a;
    const candidate *c2 = (const candidate *)b;
    return c2->votes - c1->votes;
}

// Function to print the results of the election
void print_results(candidate *candidates, int num_candidates) {
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
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

    // Get the number of candidates
    int num_candidates = sizeof(candidates) / sizeof(candidates[0]);

    // Get the number of voters
    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Get the votes for each candidate
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of the candidate you want to vote for: ");
        char name[50];
        scanf("%s", name);
        for (int j = 0; j < num_candidates; j++) {
            if (strcmp(candidates[j].name, name) == 0) {
                candidates[j].votes++;
            }
        }
    }

    // Sort the candidates by their votes
    qsort(candidates, num_candidates, sizeof(candidate), compare_candidates);

    // Print the results of the election
    print_results(candidates, num_candidates);

    return 0;
}