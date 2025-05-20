//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the structure of a candidate
typedef struct {
    char name[50];
    int votes;
} candidate;

// Define the structure of a voter
typedef struct {
    char name[50];
    int voted;
} voter;

// Define the array of candidates
candidate candidates[MAX_CANDIDATES];

// Define the array of voters
voter voters[MAX_VOTERS];

// Define the number of candidates and voters
int num_candidates;
int num_voters;

// Get the number of candidates and voters
void get_num_candidates_and_voters() {
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
}

// Get the names of the candidates
void get_candidate_names() {
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
    }
}

// Get the votes for the candidates
void get_votes() {
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of the candidate you want to vote for, %s: ", voters[i].name);
        char candidate_name[50];
        scanf("%s", candidate_name);

        // Find the index of the candidate
        int candidate_index = -1;
        for (int j = 0; j < num_candidates; j++) {
            if (strcmp(candidate_name, candidates[j].name) == 0) {
                candidate_index = j;
                break;
            }
        }

        // If the candidate was not found, print an error message
        if (candidate_index == -1) {
            printf("Invalid candidate name. Please try again.\n");
            i--;
        }
        // Otherwise, increment the candidate's vote count
        else {
            candidates[candidate_index].votes++;
            voters[i].voted = 1;
        }
    }
}

// Print the results of the election
void print_results() {
    printf("\nThe results of the election are as follows:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Find the winner of the election
    int winner_index = -1;
    int max_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    // Print the name of the winner
    printf("\nThe winner of the election is: %s\n", candidates[winner_index].name);
}

// Main function
int main() {
    // Get the number of candidates and voters
    get_num_candidates_and_voters();

    // Get the names of the candidates
    get_candidate_names();

    // Get the votes for the candidates
    get_votes();

    // Print the results of the election
    print_results();

    return 0;
}