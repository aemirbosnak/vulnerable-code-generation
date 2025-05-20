//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int numCandidates = 0, numVoters = 0;

void registerCandidate() {
    if (numCandidates >= MAX_CANDIDATES) {
        printf("Candidate limit reached.\n");
        return;
    }
    
    printf("Enter the name of the candidate: ");
    scanf("%s", candidates[numCandidates].name);
    candidates[numCandidates].votes = 0;
    numCandidates++;
    printf("Candidate %s has been registered successfully!\n", candidates[numCandidates - 1].name);
}

void registerVoter() {
    if (numVoters >= MAX_VOTERS) {
        printf("Voter limit reached.\n");
        return;
    }
    
    printf("Enter your name: ");
    scanf("%s", voters[numVoters].name);
    voters[numVoters].hasVoted = 0;
    numVoters++;
    printf("Voter %s has been registered successfully!\n", voters[numVoters - 1].name);
}

void castVote() {
    char voterName[MAX_NAME_LENGTH];
    printf("Enter your name to vote: ");
    scanf("%s", voterName);

    for (int i = 0; i < numVoters; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            if (voters[i].hasVoted) {
                printf("You have already voted!\n");
                return;
            }
            printf("Available candidates:\n");
            for (int j = 0; j < numCandidates; j++) {
                printf("%d. %s\n", j + 1, candidates[j].name);
            }
            int candidateIndex;
            printf("Select a candidate by number: ");
            scanf("%d", &candidateIndex);
            if (candidateIndex < 1 || candidateIndex > numCandidates) {
                printf("Invalid candidate selection.\n");
                return;
            }
            candidates[candidateIndex - 1].votes++;
            voters[i].hasVoted = 1;
            printf("Thank you %s, your vote has been cast for %s!\n", voters[i].name, candidates[candidateIndex - 1].name);
            return;
        }
    }
    printf("Voter not registered.\n");
}

void displayResults() {
    printf("\n--- Election Results ---\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("Candidate: %s | Votes: %d\n", candidates[i].name, candidates[i].votes);
    }
}

void menu() {
    while (1) {
        printf("\n----- Electronic Voting System -----\n");
        printf("1. Register Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerCandidate();
                break;
            case 2:
                registerVoter();
                break;
            case 3:
                castVote();
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}