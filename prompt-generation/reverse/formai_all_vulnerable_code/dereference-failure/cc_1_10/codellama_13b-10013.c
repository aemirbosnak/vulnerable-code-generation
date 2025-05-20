//Code Llama-13B DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CANDIDATES 5
#define NUM_VOTERS 10
#define VOTE_LIMIT 3

// Structure to store vote information
typedef struct {
    int vote_count;
    char candidate_name[20];
} vote_t;

// Function to generate random number between 1 and NUM_CANDIDATES
int generate_random_number(void) {
    return rand() % NUM_CANDIDATES + 1;
}

// Function to simulate a vote
void simulate_vote(vote_t *votes, int num_votes) {
    int i;
    for (i = 0; i < num_votes; i++) {
        int random_number = generate_random_number();
        strcpy(votes[i].candidate_name, "Candidate ");
        votes[i].candidate_name[strlen(votes[i].candidate_name)] = random_number + '0';
        votes[i].vote_count++;
    }
}

// Function to display vote results
void display_results(vote_t *votes, int num_votes) {
    int i;
    for (i = 0; i < num_votes; i++) {
        printf("%s: %d\n", votes[i].candidate_name, votes[i].vote_count);
    }
}

int main(void) {
    srand(time(NULL));

    // Initialize vote information
    vote_t votes[NUM_CANDIDATES];
    memset(votes, 0, sizeof(votes));

    // Simulate votes
    simulate_vote(votes, NUM_VOTERS);

    // Display results
    display_results(votes, NUM_CANDIDATES);

    return 0;
}