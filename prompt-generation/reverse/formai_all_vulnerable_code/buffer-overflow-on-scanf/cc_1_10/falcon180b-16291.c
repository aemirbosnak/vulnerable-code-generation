//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Candidate structure
struct candidate {
    char name[100];
    int votes;
};

// Function to compare candidate names (for sorting)
int compare_candidates(const void *a, const void *b) {
    struct candidate *candidate_a = (struct candidate *)a;
    struct candidate *candidate_b = (struct candidate *)b;

    return strcmp(candidate_a->name, candidate_b->name);
}

// Function to print candidate list
void print_candidates(struct candidate candidates[], int num_candidates) {
    qsort(candidates, num_candidates, sizeof(struct candidate), compare_candidates);

    printf("Candidate List:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

// Function to get user input for candidate choice
int get_candidate_choice(struct candidate candidates[], int num_candidates) {
    int choice;

    printf("Enter the number of your chosen candidate: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > num_candidates) {
        printf("Invalid choice.\n");
        return -1;
    }

    return choice - 1;
}

// Function to cast a vote
void cast_vote(struct candidate candidates[], int num_candidates, int choice) {
    candidates[choice].votes++;
}

// Main function
int main() {
    struct candidate candidates[] = {{"Alice", 0}, {"Bob", 0}, {"Charlie", 0}};
    int num_candidates = sizeof(candidates) / sizeof(struct candidate);

    print_candidates(candidates, num_candidates);

    int choice = get_candidate_choice(candidates, num_candidates);

    if (choice >= 0) {
        cast_vote(candidates, num_candidates, choice);
        printf("Your vote has been cast for %s.\n", candidates[choice].name);
    }

    return 0;
}