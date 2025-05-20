//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of candidates and their names
#define NUM_CANDIDATES 3
char candidate_names[NUM_CANDIDATES][30] = {"Candidate A", "Candidate B", "Candidate C"};

// Function to print all candidate names
void print_candidate_names() {
    printf("\nCandidate Names: \n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s\n", candidate_names[i]);
    }
}

// Function to get the index of the selected candidate
int get_selected_candidate_index() {
    printf("\nSelect a candidate: \n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%d. %s\n", i+1, candidate_names[i]);
    }
    int selected_index;
    scanf("%d", &selected_index);
    return selected_index;
}

// Function to get the total number of votes
int get_total_votes() {
    printf("\nEnter the total number of votes: ");
    int total_votes;
    scanf("%d", &total_votes);
    return total_votes;
}

// Function to calculate the winner
char* calculate_winner(int total_votes) {
    int max_votes = 0;
    int winner_index = 0;
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        int votes = 0;
        for (int j = 0; j < total_votes; j++) {
            if (i == get_selected_candidate_index()) {
                votes++;
            }
        }
        if (votes > max_votes) {
            max_votes = votes;
            winner_index = i;
        }
    }
    return candidate_names[winner_index];
}

// Main function
int main() {
    int total_votes;
    total_votes = get_total_votes();
    print_candidate_names();
    int selected_index = get_selected_candidate_index();
    printf("\nWinner: %s\n", calculate_winner(total_votes));
    return 0;
}