//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int voteCount;
} Candidate;

typedef struct {
    char voterID[10];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int numCandidates = 0;
int numVoters = 0;

void initializeCandidates() {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("Enter name for candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].voteCount = 0;
        numCandidates++;
    }
}

void initializeVoters() {
    for (int i = 0; i < MAX_VOTERS; i++) {
        printf("Enter voter ID for voter %d: ", i + 1);
        scanf("%s", voters[i].voterID);
        voters[i].hasVoted = 0;
        numVoters++;
    }
}

int findVoterIndex(char voterID[]) {
    for (int i = 0; i < numVoters; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            return i;
        }
    }
    return -1;
}

int findCandidateIndex(char candidateName[]) {
    for (int i = 0; i < numCandidates; i++) {
        if (strcmp(candidates[i].name, candidateName) == 0) {
            return i;
        }
    }
    return -1;
}

void castVote() {
    char voterID[10], candidateName[50];
    
    printf("Enter your voter ID: ");
    scanf("%s", voterID);
    
    int voterIndex = findVoterIndex(voterID);
    if (voterIndex == -1) {
        printf("Voter ID not found!\n");
        return;
    }
    
    if (voters[voterIndex].hasVoted) {
        printf("You have already voted!\n");
        return;
    }

    printf("Enter the name of the candidate you want to vote for: ");
    scanf("%s", candidateName);
    
    int candidateIndex = findCandidateIndex(candidateName);
    if (candidateIndex == -1) {
        printf("Candidate not found!\n");
        return;
    }

    candidates[candidateIndex].voteCount++;
    voters[voterIndex].hasVoted = 1;

    printf("Vote cast successfully for %s!\n", candidates[candidateIndex].name);
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].voteCount);
    }
}

int main() {
    int choice;
    
    printf("Welcome to the Electronic Voting System\n");
    do {
        printf("\nMenu:\n");
        printf("1. Initialize Candidates\n");
        printf("2. Initialize Voters\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                initializeCandidates();
                break;
            case 2:
                initializeVoters();
                break;
            case 3:
                castVote();
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting the voting system.\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 5);
    
    return 0;
}