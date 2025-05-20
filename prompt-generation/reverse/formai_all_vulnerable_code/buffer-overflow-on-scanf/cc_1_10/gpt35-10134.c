//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure representing a candidate
typedef struct Candidate {
    char name[50]; // Candidate name
    int votes; // Number of votes the candidate has received
} Candidate;

// Main function
int main() {
    int numCandidates; // Number of candidates
    Candidate *candidates; // Array of candidates

    // Prompt the user to enter the number of candidates
    printf("Welcome to our electronic voting system!\n");
    printf("Please enter the number of candidates: ");
    scanf("%d", &numCandidates);

    // Allocate memory for the array of candidates
    candidates = (Candidate*) malloc(numCandidates * sizeof(Candidate));

    // Prompt the user to enter the names of the candidates
    for(int i = 0; i < numCandidates; i++) {
        printf("Please enter the name of candidate #%d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0; // Initialize votes to 0
    }

    // Voting process
    int numVotes; // Number of total votes
    while(1) {
        printf("\n\n");
        printf("Please enter the number of total votes: ");
        scanf("%d", &numVotes);

        // Exit if the user enters 0
        if(numVotes == 0) {
            printf("Thank you for using our electronic voting system!\n");
            break;
        }

        // Prompt the user to enter their vote
        int vote;
        printf("\nPlease enter the number of the candidate you would like to vote for:\n");
        for(int i = 0; i < numCandidates; i++) {
            printf("%d. %s\n", i+1, candidates[i].name);
        }
        printf("\nEnter your vote: ");
        scanf("%d", &vote);

        // Validate the user's vote
        if(vote < 1 || vote > numCandidates) {
            printf("\nInvalid vote! Please try again.\n");
            continue;
        }

        // Increment the vote count for the selected candidate
        candidates[vote-1].votes++;
        printf("\nThank you for voting!\n");
    }

    // Display the results
    printf("\n\nResults:\n");
    for(int i = 0; i < numCandidates; i++) {
        printf("%d. %s: %d votes\n", i+1, candidates[i].name, candidates[i].votes);
    }

    free(candidates); // Free memory for the array of candidates

    return 0;
}