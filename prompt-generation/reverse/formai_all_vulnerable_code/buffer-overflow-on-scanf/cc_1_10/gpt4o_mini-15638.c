//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 5
#define VOTING_PERIOD 3 // 3 refers to how many rounds of voting we have (or time slots for votes)

typedef struct {
    char name[50];
    int voteCount;
} Candidate;

typedef struct {
    char voterID[20];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalVoters = 0;
int totalCandidates = 0;

// Function declarations
void registerCandidate();
void registerVoter();
void castVote();
void displayResults();
void displayMenu();

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: registerCandidate(); break;
            case 2: registerVoter(); break;
            case 3: castVote(); break;
            case 4: displayResults(); break;
            case 5: printf("Exiting the Voting System. Goodbye!\n"); exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Electronic Voting System ---\n");
    printf("1. Register Candidate\n");
    printf("2. Register Voter\n");
    printf("3. Cast Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
}

void registerCandidate() {
    if (totalCandidates >= MAX_CANDIDATES) {
        printf("Candidate registration is full!\n");
        return;
    }
    printf("Enter the name of the candidate: ");
    scanf("%s", candidates[totalCandidates].name);
    candidates[totalCandidates].voteCount = 0;
    totalCandidates++;
    printf("Candidate '%s' registered successfully!\n", candidates[totalCandidates - 1].name);
}

void registerVoter() {
    if (totalVoters >= MAX_VOTERS) {
        printf("Voter registration is full!\n");
        return;
    }
    printf("Enter your Voter ID: ");
    scanf("%s", voters[totalVoters].voterID);
    voters[totalVoters].hasVoted = 0; 
    totalVoters++;
    printf("Voter '%s' registered successfully!\n", voters[totalVoters - 1].voterID);
}

void castVote() {
    char voterID[20];
    printf("Enter your Voter ID: ");
    scanf("%s", voterID);
    
    // Check if voter is registered
    int voterIndex = -1; 
    for (int i = 0; i < totalVoters; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            voterIndex = i;
            break;
        }
    }

    if (voterIndex == -1) {
        printf("Voter ID not found! Please register first.\n");
        return;
    }
    
    if (voters[voterIndex].hasVoted) {
        printf("Voter ID '%s' has already voted. You can't vote again.\n", voterID);
        return;
    }

    printf("Voting for candidates:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    
    int vote;
    printf("Enter candidate number to vote: ");
    scanf("%d", &vote);
    
    if (vote < 1 || vote > totalCandidates) {
        printf("Invalid candidate number!\n");
        return;
    }

    candidates[vote - 1].voteCount++;
    voters[voterIndex].hasVoted = 1;
    printf("Vote casted successfully for '%s'!\n", candidates[vote - 1].name);
}

void displayResults() {
    printf("\n--- Voting Results ---\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].voteCount);
    }

    // Determine the winner
    int maxVotes = -1;
    char winner[50]; 
    for (int i = 0; i < totalCandidates; i++) {
        if (candidates[i].voteCount > maxVotes) {
            maxVotes = candidates[i].voteCount;
            strcpy(winner, candidates[i].name);
        }
    }
    printf("Winner: %s with %d votes!\n", winner, maxVotes);
}