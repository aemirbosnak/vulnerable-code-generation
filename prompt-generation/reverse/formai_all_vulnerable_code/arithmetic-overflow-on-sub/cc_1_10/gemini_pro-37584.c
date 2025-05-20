//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Create a structure to represent a candidate
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// Create an array of candidates
candidate candidates[] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Carol", 0},
    {"Dave", 0},
    {"Eve", 0}
};

// Get the number of candidates
int num_candidates = sizeof(candidates) / sizeof(candidate);

// Get the number of votes
int get_num_votes() {
    int num_votes;
    printf("Enter the number of votes: ");
    scanf("%d", &num_votes);
    return num_votes;
}

// Get the votes for each candidate
void get_votes(int num_votes) {
    int i;
    for (i = 0; i < num_votes; i++) {
        int candidate_index;
        printf("Enter the candidate index (1-%d): ", num_candidates);
        scanf("%d", &candidate_index);
        candidates[candidate_index - 1].votes++;
    }
}

// Print the results
void print_results() {
    int i;
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Get the winner
candidate get_winner() {
    int i;
    int max_votes = 0;
    candidate winner;
    for (i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner = candidates[i];
        }
    }
    return winner;
}

// Main function
int main() {
    int num_votes;
    
    // Get the number of votes
    num_votes = get_num_votes();
    
    // Get the votes for each candidate
    get_votes(num_votes);
    
    // Print the results
    print_results();
    
    // Get the winner
    candidate winner = get_winner();
    
    // Print the winner
    printf("The winner is %s with %d votes\n", winner.name, winner.votes);
    
    return 0;
}