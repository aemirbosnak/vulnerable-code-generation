//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Structure for a candidate
typedef struct candidate {
    int candidate_id;
    char name[50];
    int votes;
} Candidate;

// Structure for a voter
typedef struct voter {
    int voter_id;
    int candidate_id;
    int has_voted;
} Voter;

int main() {

    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    
    // Set up candidates
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].candidate_id = i + 1;
        printf("Enter candidate %d's name: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    
    // Set up voters
    int num_voters;
    printf("Enter number of voters: ");
    scanf("%d", &num_voters);
    
    for (int i = 0; i < num_voters; i++) {
        voters[i].voter_id = i + 1;
        voters[i].has_voted = 0;
    }
    
    // Start voting process
    int vote_count = 0;
    while (vote_count < num_voters) {
        printf("\n\n");
        printf("Welcome to the Electronic Voting System\n");
        printf("======================================\n");

        // Show candidates
        printf("Candidates:\n");
        for (int i = 0; i < MAX_CANDIDATES; i++) {
            printf("%d. %s\n", candidates[i].candidate_id, candidates[i].name);
        }

        // Get voter id
        int voter_id;
        printf("Enter your voter id: ");
        scanf("%d", &voter_id);

        // Check if voter has already voted
        if (voters[voter_id-1].has_voted) {
            printf("Sorry, you have already voted.\n");
            continue;
        }

        // Get candidate id
        int candidate_id;
        printf("Enter the candidate id you want to vote for: ");
        scanf("%d", &candidate_id);
        
        // Check if candidate id is valid
        int valid_candidate = 0;
        for (int i = 0; i < MAX_CANDIDATES; i++) {
            if (candidates[i].candidate_id == candidate_id) {
                valid_candidate = 1;
                break;
            }
        }
        
        // Add vote to candidate
        if (valid_candidate) {
            for (int i = 0; i < MAX_CANDIDATES; i++) {
                if (candidates[i].candidate_id == candidate_id) {
                    candidates[i].votes++;
                    break;
                }
            }
            
            // Mark voter as voted
            voters[voter_id-1].has_voted = 1;
            
            printf("Thank you for voting!\n");
            vote_count++;
        } else {
            printf("Sorry, you entered an invalid candidate id.\n");
        }
    }
    
    // Display Results
    printf("\n\n");
    printf("Election Results\n");
    printf("================\n");
    
    int max_votes = 0;
    int winner_index = -1;
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }
    
    printf("\nWinner: %s\n", candidates[winner_index].name);
    
    return 0;
}