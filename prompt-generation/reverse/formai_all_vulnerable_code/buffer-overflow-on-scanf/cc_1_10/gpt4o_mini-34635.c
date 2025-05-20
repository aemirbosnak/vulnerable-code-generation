//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[100];
    int votes;
} Candidate;

typedef struct {
    char id[10];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalCandidates = 0;
int totalVoters = 0;

void initializeVotingSystem() {
    totalCandidates = 0;
    totalVoters = 0;
}

void addCandidate(const char *name) {
    if (totalCandidates < MAX_CANDIDATES) {
        strcpy(candidates[totalCandidates].name, name);
        candidates[totalCandidates].votes = 0;
        totalCandidates++;
    }
}

void registerVoter(const char *id) {
    if (totalVoters < MAX_VOTERS) {
        strcpy(voters[totalVoters].id, id);
        voters[totalVoters].hasVoted = 0;
        totalVoters++;
    }
}

void castVote(const char *voterId, int candidateIndex) {
    for (int i = 0; i < totalVoters; i++) {
        if (strcmp(voters[i].id, voterId) == 0) {
            if (voters[i].hasVoted == 0 && candidateIndex >= 0 && candidateIndex < totalCandidates) {
                candidates[candidateIndex].votes++;
                voters[i].hasVoted = 1;
                printf("Vote casted successfully for %s!\n", candidates[candidateIndex].name);
                return;
            } else if (voters[i].hasVoted == 1) {
                printf("Error: Voter %s has already voted!\n", voterId);
                return;
            } else {
                printf("Error: Invalid candidate selection!\n");
                return;
            }
        }
    }
    printf("Error: Voter ID %s not found!\n", voterId);
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void menu() {
    int choice;
    while (1) {
        printf("\n--- Electronic Voting System ---\n");
        printf("1. Add Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                char name[100];
                printf("Enter candidate name: ");
                scanf("%s", name);
                addCandidate(name);
                break;
            }
            case 2: {
                char id[10];
                printf("Enter voter ID: ");
                scanf("%s", id);
                registerVoter(id);
                break;
            }
            case 3: {
                char voterId[10];
                int candidateIndex;
                printf("Enter voter ID: ");
                scanf("%s", voterId);
                printf("Enter candidate index (0 to %d): ", totalCandidates - 1);
                scanf("%d", &candidateIndex);
                castVote(voterId, candidateIndex);
                break;
            }
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting the voting system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

int main() {
    initializeVotingSystem();
    menu();
    return 0;
}