//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define struct for each candidate
typedef struct {
    char name[20];
    int votes;
} Candidate;

int getTotalVotes(Candidate candidates[], int numCandidates);
void printResults(Candidate candidates[], int numCandidates);

int main() {
    int numCandidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    // Dynamic allocation for candidates array
    Candidate *candidates = (Candidate*) malloc(sizeof(Candidate) * numCandidates);

    // Prompt user to enter candidate names
    for(int i = 0; i < numCandidates; i++) {
        printf("Enter candidate %d's name: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    int voterID;
    int vote;
    int numVoters = 0;

    while(1) {
        printf("\nVoter %d, enter your voter ID: ", numVoters + 1);
        scanf("%d", &voterID);

        // Check if voter has already voted
        for(int i = 0; i < numCandidates; i++) {
            if(candidates[i].votes == voterID) {
                printf("You have already voted!\n");
                break;
            }
        }

        printf("Enter your vote (1-%d): ", numCandidates);
        scanf("%d", &vote);

        // Validate vote
        if (vote < 1 || vote > numCandidates) {
            printf("Invalid vote!\n");
            continue;
        }

        // Add vote to candidate
        candidates[vote - 1].votes = voterID;
        numVoters++;

        // Ask if user wants to stop voting
        char choice;
        printf("\nContinue voting? (Y/N): ");
        getchar(); // Flush input buffer
        choice = getchar();
        if(choice == 'N' || choice == 'n') {
            break;
        }
    }

    // Print election results
    printResults(candidates, numCandidates);

    // Free memory
    free(candidates);

    return 0;
}

// Function to calculate total number of votes
int getTotalVotes(Candidate candidates[], int numCandidates) {
    int totalVotes = 0;
    for(int i = 0; i < numCandidates; i++) {
        totalVotes += candidates[i].votes != 0 ? 1 : 0;
    }
    return totalVotes;
}

// Function to print election results
void printResults(Candidate candidates[], int numCandidates) {
    int totalVotes = getTotalVotes(candidates, numCandidates);
    printf("\nElection Results\n");
    printf("-----------------\n");
    printf("Total Votes: %d\n", totalVotes);
    printf("-----------------\n");
    for(int i = 0; i < numCandidates; i++) {
        int votes = candidates[i].votes != 0 ? 1 : 0;
        float percentage = totalVotes > 0 ? (float) votes / totalVotes * 100 : 0;
        printf("%d. %s: %d votes (%.2f%%)\n", i + 1, candidates[i].name, votes, percentage);
    }
}