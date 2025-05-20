//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold candidate details
struct Candidate {
    char name[50];
    int votes;
};

int main() {
    int numCandidates, numVoters;
    printf("Welcome to the Electronic Voting System!\n");
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);
    
    // Dynamically allocate memory for candidates
    struct Candidate* candidates = malloc(numCandidates * sizeof(struct Candidate));
    
    // Get candidate details
    for(int i=0; i<numCandidates; i++) {
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);
    printf("\n");

    // Electronic Voting Begins!
    for(int i=0; i<numVoters; i++) {
        printf("Voter %d, please cast your vote (Enter the number of candidate you choose): \n", i+1);
        
        // Print the candidate list
        for(int j=0; j<numCandidates; j++) {
            printf("%d - %s\n", j+1, candidates[j].name);
        }
        
        int vote;
        scanf("%d", &vote);
        
        // Validate vote
        if(vote < 1 || vote > numCandidates) {
            printf("Invalid vote! Please try again.\n");
            i--;
            continue;
        }
        
        candidates[vote-1].votes++;  // Add vote to candidate
        printf("Thank you, your vote has been recorded.\n\n");
    }
    
    // Display the election results
    printf("The votes are in!\n");
    for(int i=0; i<numCandidates; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
    }
    
    // Find the winner (person with highest votes)
    int max_index = 0;
    for(int i=1; i<numCandidates; i++) {
        if(candidates[i].votes > candidates[max_index].votes) {
            max_index = i;
        }
    }
    
    printf("\nThe winner of the election is %s! With %d votes\n\n", candidates[max_index].name, candidates[max_index].votes);
    
    // Deallocate memory to avoid memory leak
    free(candidates);
    
    return 0;
}