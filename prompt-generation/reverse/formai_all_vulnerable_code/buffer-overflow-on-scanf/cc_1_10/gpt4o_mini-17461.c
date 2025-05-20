//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char voterID[10];
    bool hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int numCandidates = 0;
int numVoters = 0;

void initializeCandidates() {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        snprintf(candidates[i].name, sizeof(candidates[i].name), "Candidate_%d", i + 1);
        candidates[i].votes = 0;
    }
    numCandidates = MAX_CANDIDATES;
}

void registerVoter() {
    if (numVoters >= MAX_VOTERS) {
        printf("Voter registration limit reached!\n");
        return;
    }
    
    printf("Enter Voter ID: ");
    scanf("%s", voters[numVoters].voterID);
    voters[numVoters].hasVoted = false;
    numVoters++;
    printf("Voter registered successfully!\n");
}

bool hasVoterVoted(char *voterID) {
    for (int i = 0; i < numVoters; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            return voters[i].hasVoted;
        }
    }
    return false;
}

void castVote() {
    char voterID[10];
    printf("Enter Voter ID: ");
    scanf("%s", voterID);
    
    if (hasVoterVoted(voterID)) {
        printf("You have already voted!\n");
        return;
    }
    
    printf("Available candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    
    int choice;
    printf("Choose a candidate by number: ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > numCandidates) {
        printf("Invalid choice. Vote not counted.\n");
        return;
    }
    
    candidates[choice - 1].votes++;
    
    for (int i = 0; i < numVoters; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            voters[i].hasVoted = true;
            break;
        }
    }

    printf("Vote casted successfully for %s!\n", candidates[choice - 1].name);
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void clearScreen() {
    printf("\033[H\033[J"); 
}

int main() {
    int option;

    initializeCandidates();

    while (true) {
        clearScreen();
        printf("Welcome to the Electronic Voting System\n");
        printf("1. Register Voter\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                registerVoter();
                break;
            case 2:
                castVote();
                break;
            case 3:
                displayResults();
                break;
            case 4:
                printf("Exiting the voting system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again!\n");
                break;
        }
        sleep(2);
    }
    return 0;
}