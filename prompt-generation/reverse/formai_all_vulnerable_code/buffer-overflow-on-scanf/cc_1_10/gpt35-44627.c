//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 5
#define MAX_VOTERS 50

// Define the structure of a candidate
struct candidate {
    char name[20];
    unsigned int vote_count;
};

// Declare the array of candidates
struct candidate candidates[MAX_CANDIDATES];

// Declare the array of voters
int voters[MAX_VOTERS];

// Declare the number of candidates and voters
int num_candidates = 0;
int num_voters = 0;

// Function to add a candidate to the array of candidates
void add_candidate(char name[]) {
    if (num_candidates < MAX_CANDIDATES) {
        strncpy(candidates[num_candidates].name, name, 20);
        candidates[num_candidates].vote_count = 0;
        num_candidates++;
    } else {
        printf("Error: Maximum number of candidates reached.\n");
    }
}

// Function to cast a vote for a candidate
void cast_vote(int candidate_index) {
    if (candidate_index >= 0 && candidate_index < num_candidates) {
        candidates[candidate_index].vote_count++;
    } else {
        printf("Error: Invalid candidate index.\n");
    }
}

// Function to check if a voter has already voted
int has_voted(int voter_id) {
    int i;
    for (i = 0; i < num_voters; i++) {
        if (voters[i] == voter_id) {
            return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    int i, j;
    char choice = ' ';
    
    // Get the number of candidates from the user
    while (num_candidates < 1 || num_candidates > MAX_CANDIDATES) {
        printf("Enter the number of candidates (1 to %d): ", MAX_CANDIDATES);
        scanf("%d", &num_candidates);
    }
    
    // Get the names of the candidates from the user
    printf("Enter the names of the candidates:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("Candidate #%d: ", i+1);
        scanf("%s", candidates[i].name);
    }
    
    // Get the number of voters from the user
    while (num_voters < 1 || num_voters > MAX_VOTERS) {
        printf("Enter the number of voters (1 to %d): ", MAX_VOTERS);
        scanf("%d", &num_voters);
    }
    
    // Get the votes from the voters
    for (i = 0; i < num_voters; i++) {
        int voter_id;
        char vote[20];
        
        // Get the voter ID from the user
        printf("Voter #%d, enter your ID: ", i+1);
        scanf("%d", &voter_id);
        
        // Check if the voter has already voted
        if (has_voted(voter_id)) {
            printf("Error: You have already voted.\n");
            i--; // Decrement i so that this voter can vote again
            continue; // Skip to the next iteration of the loop
        }
        voters[i] = voter_id; // Store the voter ID in the array
        
        // Get the vote from the user
        printf("Who do you want to vote for? ");
        scanf("%s", vote);
        
        // Find the candidate with the given name
        for (j = 0; j < num_candidates; j++) {
            if (strcmp(candidates[j].name, vote) == 0) { // If the names match
                cast_vote(j); // Cast the vote for this candidate
                printf("Thank you for voting.\n");
                break; // Stop searching for the candidate
            }
        }
        if (j == num_candidates) { // If no candidate was found
            printf("Error: Invalid vote.\n");
            i--; // Decrement i so that this voter can vote again
            continue; // Skip to the next iteration of the loop
        }
    }
    
    // Print the results
    printf("\nElection Results\n");
    printf("====================\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }
    
    return 0;
}