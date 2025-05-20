//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a candidate
typedef struct candidate {
    char name[50];
    int votes;
} candidate_t;

// Array of candidates
candidate_t candidates[] = {
    {"John Smith", 0},
    {"Jane Doe", 0},
    {"Bob Johnson", 0},
    {"Alice Walker", 0}
};

// Number of candidates
int num_candidates = sizeof(candidates) / sizeof(candidate_t);

// Function to get the index of a candidate by name
int get_candidate_index(char *name) {
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

// Function to cast a vote for a candidate
void cast_vote(char *name) {
    int index = get_candidate_index(name);
    if (index != -1) {
        candidates[index].votes++;
    }
}

// Function to print the results of the election
void print_results() {
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    // Get the number of votes
    int num_votes;
    printf("Enter the number of votes to be cast: ");
    scanf("%d", &num_votes);

    // Cast the votes
    for (int i = 0; i < num_votes; i++) {
        char name[50];
        printf("Enter the name of the candidate you want to vote for: ");
        scanf("%s", name);
        cast_vote(name);
    }

    // Print the results of the election
    print_results();

    return 0;
}