//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Structure to hold candidate details
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Structure to hold voter details
typedef struct {
    int voterId;
    int hasVoted;
} Voter;

// Function prototypes
void displayCandidates(Candidate candidates[], int numCandidates);
void castVote(Candidate candidates[], int numCandidates, Voter voters[], int numVoters);
void displayResults(Candidate candidates[], int numCandidates);
void resetVoting(Candidate candidates[], int numCandidates, Voter voters[], int numVoters);

int main() {
    int numCandidates, numVoters;
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    
    // Configure number of candidates
    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &numCandidates);
    
    // Input candidate names
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter candidate %d name: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0; // Initialize votes to 0
    }
    
    // Configure number of voters
    printf("Enter the number of voters (max %d): ", MAX_VOTERS);
    scanf("%d", &numVoters);
    
    // Initialize voters
    for (int i = 0; i < numVoters; i++) {
        voters[i].voterId = i + 1;
        voters[i].hasVoted = 0; // Initialize voting status
    }
    
    int choice;
    do {
        printf("\nElectronic Voting System Menu:\n");
        printf("1. Display Candidates\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Reset Voting\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayCandidates(candidates, numCandidates);
                break;
            case 2:
                castVote(candidates, numCandidates, voters, numVoters);
                break;
            case 3:
                displayResults(candidates, numCandidates);
                break;
            case 4:
                resetVoting(candidates, numCandidates, voters, numVoters);
                printf("Voting has been reset.\n");
                break;
            case 5:
                printf("Exiting the voting system.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}

void displayCandidates(Candidate candidates[], int numCandidates) {
    printf("\nList of Candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void castVote(Candidate candidates[], int numCandidates, Voter voters[], int numVoters) {
    int voterId, candidateId;
    
    printf("Enter your voter ID (1 to %d): ", numVoters);
    scanf("%d", &voterId);
    
    if (voterId < 1 || voterId > numVoters) {
        printf("Invalid voter ID! Please try again.\n");
        return;
    }
    
    if (voters[voterId - 1].hasVoted) {
        printf("You have already voted! Cannot vote again.\n");
        return;
    }
    
    displayCandidates(candidates, numCandidates);
    printf("Select candidate ID to vote for (1 to %d): ", numCandidates);
    scanf("%d", &candidateId);
    
    if (candidateId < 1 || candidateId > numCandidates) {
        printf("Invalid candidate ID! Please try again.\n");
        return;
    }
    
    candidates[candidateId - 1].votes++;
    voters[voterId - 1].hasVoted = 1; // Mark as voted
    printf("Vote cast successfully for %s by voter ID %d.\n", candidates[candidateId - 1].name, voterId);
}

void displayResults(Candidate candidates[], int numCandidates) {
    printf("\nElection Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void resetVoting(Candidate candidates[], int numCandidates, Voter voters[], int numVoters) {
    for (int i = 0; i < numCandidates; i++) {
        candidates[i].votes = 0; // Reset votes
    }
    
    for (int i = 0; i < numVoters; i++) {
        voters[i].hasVoted = 0; // Reset voting status
    }
}