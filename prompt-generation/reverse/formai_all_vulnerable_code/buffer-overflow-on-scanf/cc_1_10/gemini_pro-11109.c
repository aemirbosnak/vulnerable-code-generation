//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the candidate names and their vote counts
char *candidates[] = {"Alice", "Bob", "Carol", "Dave", "Eve"};
int votes[] = {0, 0, 0, 0, 0};

// Declare the number of candidates and voters
int num_candidates = sizeof(candidates) / sizeof(char *);
int num_voters = 0;

// Function to get the index of a candidate by their name
int get_candidate_index(char *name) {
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i], name) == 0) {
            return i;
        }
    }

    return -1;
}

// Function to cast a vote for a candidate
void cast_vote(char *name) {
    int index = get_candidate_index(name);

    if (index == -1) {
        printf("Invalid candidate name: %s\n", name);
        return;
    }

    votes[index]++;
    num_voters++;
}

// Function to print the election results
void print_results() {
    printf("Election results:\n");

    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i], votes[i]);
    }

    printf("Total number of voters: %d\n", num_voters);
}

// Main function
int main() {
    // Get the number of voters
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Get the votes from the voters
    for (int i = 0; i < num_voters; i++) {
        char name[20];

        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", name);

        cast_vote(name);
    }

    // Print the election results
    print_results();

    return 0;
}