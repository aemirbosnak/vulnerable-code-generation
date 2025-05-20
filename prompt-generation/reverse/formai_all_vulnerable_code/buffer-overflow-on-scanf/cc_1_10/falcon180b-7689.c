//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Candidate structure
struct Candidate {
    char name[50];
    int votes;
};

// Function to compare candidate names (for sorting)
int compare_candidates(const void *a, const void *b) {
    struct Candidate *candidateA = (struct Candidate *)a;
    struct Candidate *candidateB = (struct Candidate *)b;

    return strcmp(candidateA->name, candidateB->name);
}

// Function to print candidate list
void print_candidates(struct Candidate candidates[], int num_candidates) {
    qsort(candidates, num_candidates, sizeof(struct Candidate), compare_candidates);

    printf("Candidate List:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

// Function to get user input for candidate choice
int get_candidate_choice(struct Candidate candidates[], int num_candidates) {
    int choice;

    printf("Enter the number of your chosen candidate:\n");
    scanf("%d", &choice);

    if (choice < 1 || choice > num_candidates) {
        printf("Invalid choice. Please try again.\n");
        return -1;
    }

    return choice - 1;
}

// Function to cast a vote
void cast_vote(struct Candidate candidates[], int num_candidates, int choice) {
    candidates[choice].votes++;
}

// Function to display voting results
void display_results(struct Candidate candidates[], int num_candidates) {
    qsort(candidates, num_candidates, sizeof(struct Candidate), compare_candidates);

    printf("\nVoting Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s - %d votes\n", i + 1, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    // Candidate list
    struct Candidate candidates[] = {{"John Doe", 0}, {"Jane Smith", 0}, {"Bob Johnson", 0}};
    int num_candidates = sizeof(candidates) / sizeof(struct Candidate);

    // Main voting loop
    while (1) {
        print_candidates(candidates, num_candidates);

        int choice = get_candidate_choice(candidates, num_candidates);
        if (choice == -1) {
            continue;
        }

        cast_vote(candidates, num_candidates, choice);
    }

    return 0;
}