//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the number of candidates
#define NUM_CANDIDATES 5

// Define the maximum number of votes per candidate
#define MAX_VOTES 100

// Define the data structure for a candidate
typedef struct {
    char name[50];
    int votes;
} candidate_t;

// Create an array of candidates
candidate_t candidates[NUM_CANDIDATES];

// Get the number of voters
int get_num_voters() {
    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    return num_voters;
}

// Get the votes for each candidate
void get_votes(int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of the candidate you want to vote for: ");
        scanf("%s", candidates[i].name);

        printf("Enter the number of votes for %s: ", candidates[i].name);
        scanf("%d", &candidates[i].votes);
    }
}

// Print the results of the election
void print_results() {
    // Find the winner
    int max_votes = 0;
    int winner_index = -1;
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    // Print the winner
    printf("The winner of the election is %s with %d votes.\n", candidates[winner_index].name, max_votes);
}

// Main function
int main() {
    // Get the number of voters
    int num_voters = get_num_voters();

    // Get the votes for each candidate
    get_votes(num_voters);

    // Print the results of the election
    print_results();

    return 0;
}