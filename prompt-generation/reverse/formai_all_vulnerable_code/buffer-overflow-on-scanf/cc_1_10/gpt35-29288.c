//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a simple structure to represent each candidate
struct candidate {
    char name[50];
    int votes;
};

// Define a function that will display the candidates
void display_candidates(struct candidate candidates[], int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

// Define a function that will allow the user to vote
void vote(struct candidate candidates[], int num_candidates) {
    int choice;

    // Display the candidates
    display_candidates(candidates, num_candidates);

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Increment the selected candidate's vote count
    candidates[choice-1].votes++;

    printf("Thank you for voting!\n");
}

// Define a function to display the results
void display_results(struct candidate candidates[], int num_candidates) {
    printf("Results\n");

    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int num_candidates;
    struct candidate *candidates;

    // Get the number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Allocate memory for the candidates
    candidates = malloc(num_candidates * sizeof(struct candidate));

    // Get the candidates' names
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Allow the user to vote
    vote(candidates, num_candidates);

    // Display the results
    display_results(candidates, num_candidates);

    free(candidates); // Free the allocated memory

    return 0;
}