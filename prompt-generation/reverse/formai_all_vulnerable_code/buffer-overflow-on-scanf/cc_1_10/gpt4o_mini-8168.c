//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    int id;
    char name[50];
    int votes;
} Candidate;

typedef struct {
    int id;
    char name[50];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void initializeCandidates() {
    printf("Enter number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &candidateCount);
    getchar(); // consume newline character after number input
    for (int i = 0; i < candidateCount; i++) {
        candidates[i].id = i + 1;
        printf("Enter name for candidate %d: ", i + 1);
        fgets(candidates[i].name, sizeof(candidates[i].name), stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = 0; // remove newline
        candidates[i].votes = 0; // initialize votes to zero
    }
}

void registerVoters() {
    printf("Enter number of voters (max %d): ", MAX_VOTERS);
    scanf("%d", &voterCount);
    getchar(); // consume newline character after number input
    for (int i = 0; i < voterCount; i++) {
        voters[i].id = i + 1;
        printf("Enter name for voter %d: ", i + 1);
        fgets(voters[i].name, sizeof(voters[i].name), stdin);
        voters[i].name[strcspn(voters[i].name, "\n")] = 0; // remove newline
        voters[i].hasVoted = 0; // initialize hasVoted to false
    }
}

void castVote(int voterId) {
    int candidateId;
    printf("Voter %d: %s, please cast your vote (1-%d): ", voterId, voters[voterId - 1].name, candidateCount);
    scanf("%d", &candidateId);
    
    if (candidateId < 1 || candidateId > candidateCount) {
        printf("Invalid candidate selection. Vote not counted.\n");
        return;
    }

    if (voters[voterId - 1].hasVoted) {
        printf("You have already voted! Your vote cannot be counted again.\n");
        return;
    }

    candidates[candidateId - 1].votes++;
    voters[voterId - 1].hasVoted = 1; // Mark voter as having voted
    printf("Thank you! Your vote for %s has been counted.\n", candidates[candidateId - 1].name);
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("Candidate: %s, Votes: %d\n", candidates[i].name, candidates[i].votes);
    }
}

void menu() {
    int choice;
    
    do {
        printf("\nElectronic Voting System\n");
        printf("1. Cast Vote\n");
        printf("2. Display Results\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                for (int i = 0; i < voterCount; i++) {
                    castVote(voters[i].id);
                }
                break;
            case 2:
                displayResults();
                break;
            case 3:
                printf("Exiting the voting system. Thank you!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);
}

int main() {
    initializeCandidates();
    registerVoters();
    menu();

    return 0;
}