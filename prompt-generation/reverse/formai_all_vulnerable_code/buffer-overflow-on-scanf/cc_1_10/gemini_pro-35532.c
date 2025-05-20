//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the structure of a candidate
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// Define the structure of a voter
typedef struct voter {
    char name[50];
    int candidate_id;
} voter;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Array of voters
voter voters[MAX_VOTERS];

// Main function
int main() {
    // Get the number of candidates
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Get the details of each candidate
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Get the number of voters
    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Get the vote of each voter
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);

        // Get the candidate ID of the voter's choice
        int candidate_id;
        printf("Enter the candidate ID of your choice: ");
        scanf("%d", &candidate_id);

        // Increment the vote count of the chosen candidate
        candidates[candidate_id - 1].votes++;
    }

    // Find the winning candidate
    int max_votes = 0;
    int winning_candidate_id = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winning_candidate_id = i;
        }
    }

    // Print the result
    printf("The winning candidate is: %s\n", candidates[winning_candidate_id].name);
    printf("Total votes: %d\n", max_votes);

    return 0;
}