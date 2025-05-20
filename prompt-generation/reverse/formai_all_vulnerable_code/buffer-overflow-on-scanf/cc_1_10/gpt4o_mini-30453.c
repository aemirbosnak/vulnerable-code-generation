//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 5

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char voterID[20];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalVoters = 0;
int totalCandidates = 0;

void addCandidate(const char *name) {
    if (totalCandidates < MAX_CANDIDATES) {
        strcpy(candidates[totalCandidates].name, name);
        candidates[totalCandidates].votes = 0;
        totalCandidates++;
    } else {
        printf("Candidate limit reached.\n");
    }
}

int findVoter(const char *voterID) {
    for (int i = 0; i < totalVoters; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            return i;
        }
    }
    return -1;
}

int findCandidate(const char *name) {
    for (int i = 0; i < totalCandidates; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void registerVoter() {
    if (totalVoters < MAX_VOTERS) {
        printf("Enter voter ID: ");
        scanf("%s", voters[totalVoters].voterID);
        voters[totalVoters].hasVoted = 0;
        totalVoters++;
    } else {
        printf("Voter limit reached.\n");
    }
}

void castVote() {
    char voterID[20], candidateName[50];
    printf("Enter voter ID: ");
    scanf("%s", voterID);
    
    int voterIndex = findVoter(voterID);
    if (voterIndex == -1) {
        printf("Voter not registered!\n");
        return;
    }
    
    if (voters[voterIndex].hasVoted) {
        printf("Voter has already voted!\n");
        return;
    }
    
    printf("Available candidates:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    
    printf("Enter candidate name to vote for: ");
    scanf("%s", candidateName);
    
    int candidateIndex = findCandidate(candidateName);
    if (candidateIndex == -1) {
        printf("Candidate not found!\n");
        return;
    }
    
    candidates[candidateIndex].votes++;
    voters[voterIndex].hasVoted = 1;
    printf("Vote casted for %s successfully!\n", candidates[candidateIndex].name);
}

void displayResults() {
    printf("Election Results:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int option;
    char candidateName[50];
    
    while (1) {
        printf("\n--- Electronic Voting System ---\n");
        printf("1. Add Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", candidateName);
                addCandidate(candidateName);
                printf("Candidate %s added.\n", candidateName);
                break;
            case 2:
                registerVoter();
                printf("Voter registered successfully!\n");
                break;
            case 3:
                castVote();
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting the voting system.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}