//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store candidate details
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// Function to compare candidates by name
int compare_candidates(const void *a, const void *b) {
    return strcmp(((struct candidate *)a)->name, ((struct candidate *)b)->name);
}

// Function to print candidate results
void print_results(candidate *candidates, int num_candidates) {
    // Sort candidates by name
    qsort(candidates, num_candidates, sizeof(candidate), compare_candidates);

    // Print candidate names and votes
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    // Initialize candidates
    candidate candidates[] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Carol", 0},
        {"Dave", 0},
        {"Eve", 0},
    };

    int num_candidates = sizeof(candidates) / sizeof(candidates[0]);

    // Prompt user to vote
    printf("Brave Electronic Voting System\n");
    printf("-----------------------------\n");
    printf("Please enter the name of the candidate you wish to vote for:\n");

    // Get user input
    char name[50];
    scanf("%s", name);

    // Find candidate by name
    int candidate_index = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            candidate_index = i;
            break;
        }
    }

    // If candidate not found, print error message
    if (candidate_index == -1) {
        printf("Invalid candidate name.\n");
        return 1;
    }

    // Increment candidate's vote count
    candidates[candidate_index].votes++;

    // Print results
    printf("Your vote has been counted.\n");
    printf("\n");
    print_results(candidates, num_candidates);

    return 0;
}