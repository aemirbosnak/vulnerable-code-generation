//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Defining the maximum number of voters and candidates
#define MAX_VOTERS 1000
#define MAX_CANDIDATES 5

// Struct for candidate information
typedef struct {
    char name[20];
    int num_votes;
} Candidate;

// Struct for voter information
typedef struct {
    char name[20];
    int voted_for; // Candidate number they voted for
} Voter;

int main() {
    // Initializing candidates and voters arrays
    Candidate candidates[MAX_CANDIDATES] = {{"Candidate 1", 0}, {"Candidate 2", 0}, {"Candidate 3", 0}, {"Candidate 4", 0}, {"Candidate 5", 0}};
    Voter voters[MAX_VOTERS];
    
    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    
    // Recording voter information
    for (int i = 0; i < num_voters; i++) {
        printf("\nEnter voter name: ");
        scanf("%s", voters[i].name);
        
        // Displaying candidate options for voter to select
        printf("\nCandidate options:\n");
        for (int j = 0; j < MAX_CANDIDATES; j++) {
            printf("%d. %s\n", (j+1), candidates[j].name);
        }
        
        int vote;
        printf("\n%s, enter the number of your candidate: ", voters[i].name);
        scanf("%d", &vote);
        
        // Checking if candidate number entered is valid
        if (vote < 1 || vote > MAX_CANDIDATES) {
            printf("Invalid candidate number entered. Please try again.\n");
            i--; // Taking one step back so that the same voter can vote again
        } else {
            candidates[vote-1].num_votes++; // Adding one to the candidate's vote count
            voters[i].voted_for = vote; // Storing the candidate number the voter voted for
        }
    }
    
    // Displaying election results
    printf("\nElection Results\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].num_votes);
    }
    printf("--------------------------------------------------\n");
    
    // Displaying voters and their chosen candidate
    printf("\nVoter Information\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < num_voters; i++) {
        printf("%s voted for %s.\n", voters[i].name, candidates[voters[i].voted_for-1].name);
    }
    printf("--------------------------------------------------\n");
    
    return 0;
}