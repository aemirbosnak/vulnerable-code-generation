//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CANDIDATES 4

// Structure to hold candidate information
typedef struct {
    char name[50];
    int votes;
} candidate_t;

// Function to print menu
void print_menu(candidate_t candidates[]) {
    printf("Electronic Voting System\n");
    printf("=========================\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
    printf("%d. Exit\n", NUM_CANDIDATES);
}

// Function to get user input
int get_input(void) {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to cast vote
void cast_vote(candidate_t candidates[]) {
    int choice;
    printf("Cast your vote:\n");
    print_menu(candidates);
    choice = get_input();

    if (choice >= 1 && choice <= NUM_CANDIDATES) {
        candidates[choice-1].votes++;
    } else {
        printf("Invalid choice.\n");
    }
}

// Function to display results
void display_results(candidate_t candidates[]) {
    printf("\nResults:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    srand(time(NULL));

    // Initialize candidate information
    candidate_t candidates[NUM_CANDIDATES] = {{"Alice", 0}, {"Bob", 0}, {"Charlie", 0}, {"Dave", 0}};

    // Simulate multiple voters
    for (int i = 0; i < 100; i++) {
        cast_vote(candidates);
    }

    // Display results
    display_results(candidates);

    return 0;
}