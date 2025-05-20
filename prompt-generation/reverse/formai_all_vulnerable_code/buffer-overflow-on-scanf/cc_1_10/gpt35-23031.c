//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a candidate
typedef struct {
    char name[50];
    int vote_count;
} Candidate;

// Function prototypes
void create_candidate_list(int n, Candidate* candidate_list);
void display_candidate_list(int n, Candidate* candidate_list);
int cast_vote(int n, Candidate* candidate_list, int selected_candidate);
void display_winner(int n, Candidate* candidate_list);

int main() {
    int n, selected_candidate, vote_cast;

    // Get the number of candidates from the user
    printf("Enter the number of candidates: ");
    scanf("%d", &n);

    // Allocate memory for the candidate list
    Candidate* candidate_list = (Candidate*) malloc(n * sizeof(Candidate));

    // Create the candidate list
    create_candidate_list(n, candidate_list);

    // Display the candidate list
    display_candidate_list(n, candidate_list);

    // Allow the user to cast a vote
    printf("Enter the number of the candidate you want to vote for: ");
    scanf("%d", &selected_candidate);

    vote_cast = cast_vote(n, candidate_list, selected_candidate);

    if (vote_cast) {
        printf("Thanks for casting your vote.\n");
    } else {
        printf("Sorry, there was an error casting your vote.\n");
    }

    // Display the winner
    display_winner(n, candidate_list);

    free(candidate_list);

    return 0;
}

// Function to create the candidate list
void create_candidate_list(int n, Candidate* candidate_list) {
    for (int i = 0; i < n; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidate_list[i].name);
        candidate_list[i].vote_count = 0;
    }
}

// Function to display the candidate list
void display_candidate_list(int n, Candidate* candidate_list) {
    printf("\nList of Candidates:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i+1, candidate_list[i].name);
    }
    printf("\n");
}

// Function to cast a vote
int cast_vote(int n, Candidate* candidate_list, int selected_candidate) {
    if (selected_candidate < 1 || selected_candidate > n) {
        return 0;
    } else {
        candidate_list[selected_candidate-1].vote_count++;
        return 1;
    }
}

// Function to display the winner
void display_winner(int n, Candidate* candidate_list) {
    Candidate winner = candidate_list[0];

    for (int i = 1; i < n; i++) {
        if (candidate_list[i].vote_count > winner.vote_count) {
            winner = candidate_list[i];
        }
    }

    printf("The winner is: %s with %d votes.\n", winner.name, winner.vote_count);
}