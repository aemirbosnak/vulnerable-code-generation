//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multivariable
#include <stdio.h> 
#define VOTER_ALLOWED 200  // Maximum number of allowed voters
#define CANDIDATE_ALLOWED 3 // Maximum number of allowed candidates

float candidate_votes[CANDIDATE_ALLOWED]; // Declare an array of candidate votes
int registered_voters[VOTER_ALLOWED]; // Declare an array of registered voters
int voter_count = 0; // Track the total number of registered voters
int voting_closed = 0; // A flag to indicate whether the voting process has ended or not

void register_voters() {
    int i, voter_id;
    
    printf("Enter the voter IDs (0 to stop):\n");
    
    // Get voter IDs from the user
    for(i = 0; i < VOTER_ALLOWED; i++) {
        scanf("%d", &voter_id);
        // Stop getting IDs if zero is entered
        if(voter_id == 0) {
            break;
        }
        registered_voters[i] = voter_id;
        voter_count++; // Increment the count of registered voters
    }
    
    printf("\nTotal number of registered voters: %d\n", voter_count);
}

void vote() {
    int i, candidate_id;
    
    printf("Enter your candidate ID:\n");
    scanf("%d", &candidate_id);
    
    // Increment the vote count for the selected candidate
    candidate_votes[candidate_id-1]++;
    
    printf("Thank you for voting!\n");
}

void close_voting() {
    char confirmation;
    
    printf("Are you sure you want to close the voting process? (Y/N)\n");
    scanf(" %c", &confirmation);
    
    if(confirmation == 'Y' || confirmation == 'y') {
        voting_closed = 1;
        printf("Voting process is closed.\n");
    } else {
        printf("Voting process is not closed.\n");
    }
}

void display_results() {
    int i;
    
    printf("Candidate Votes\n");
    for(i = 0; i < CANDIDATE_ALLOWED; i++) {
        printf("Candidate %d: %.0f\n", i+1, candidate_votes[i]);
    }
}

int main() {
    int i;
    
    register_voters(); // Call the register_voters function
    
    while(voting_closed == 0) { // Loop until the voting process is closed
        for(i = 0; i < voter_count; i++) {
            int current_voter_id = registered_voters[i];
            
            printf("Voter ID: %d\n", current_voter_id);
            
            // Only allow the voter to vote once
            if(candidate_votes[0] + candidate_votes[1] + candidate_votes[2] < 1) {
                vote();
            } else {
                printf("You have already voted.\n");
            }
        }
        close_voting();
    }
    
    display_results(); // Call the display_results function
    
    return 0;
}