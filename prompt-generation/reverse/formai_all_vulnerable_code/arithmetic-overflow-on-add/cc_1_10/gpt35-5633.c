//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: ultraprecise
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_CANDIDATES 20 // Maximum number of candidates that can participate in the election
#define MAX_VOTERS 10000 // Maximum number of voters that can participate in the election
 
typedef struct candidate {
    char name[20];
    int vote_count;
} Candidate;
 
int main(void) {
    Candidate candidates[MAX_CANDIDATES]; // An array to store all the candidates
    int candidate_count; // The actual number of candidates
    int voter_count; // The number of voters that have voted
    int i, j; // Loops counters
    bool is_voted[MAX_VOTERS] = {false}; // An array to keep track of which voters have voted
    
    printf("Welcome to the Electronic Voting System!\n");
    
    // Ask for the number of candidates
    printf("Please enter the number of candidates: ");
    scanf("%d", &candidate_count);
    
    // Ask for the candidates' names
    printf("Please enter the candidates' names:\n");
    for (i = 0; i < candidate_count; i++) {
        scanf("%s", candidates[i].name);
        candidates[i].vote_count = 0;
    }
    
    // Ask for the number of voters
    printf("Please enter the number of voters: ");
    scanf("%d", &voter_count);
    
    // Ask each voter to cast their vote
    for (i = 0; i < voter_count; i++) {
        int choice;
        printf("Dear voter #%d, please enter your vote:\n", i+1);
        
        for (j = 0; j < candidate_count; j++) {
            printf("%d. %s\n", j+1, candidates[j].name);
        }
        
        scanf("%d", &choice);
        
        // Check if the voter has already voted
        if (!is_voted[i]) {
            candidates[choice-1].vote_count++; // Add the vote to the candidate's tally
            is_voted[i] = true; // Mark the voter as having voted
            printf("Thank you for casting your vote!\n");
        }
        else {
            printf("ERROR: You have already cast your vote! Please try again.\n");
        }
    }
    
    // Print the election results
    printf("\nElection results:\n");
    for (i = 0; i < candidate_count; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }
    
    // Determine the winner(s)
    int max_votes = 0;
    int winners[MAX_CANDIDATES] = {0};
    for (i = 0; i < candidate_count; i++) {
        if (candidates[i].vote_count > max_votes) {
            max_votes = candidates[i].vote_count;
            winners[0] = i;
        }
        else if (candidates[i].vote_count == max_votes) {
            winners[max_votes] = i;
        }
    }
    
    // Print the winner(s)
    printf("\nWinner(s):\n");
    for (i = 0; i <= max_votes; i++) {
        printf("%s\n", candidates[winners[i]].name);
    }
    
    return 0;
}