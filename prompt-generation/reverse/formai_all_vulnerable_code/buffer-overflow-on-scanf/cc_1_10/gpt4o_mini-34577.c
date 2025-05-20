//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    bool hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalCandidates = 0;
int totalVoters = 0;

void initializeCandidates() {
    strcpy(candidates[0].name, "Alice");
    candidates[0].id = 1;
    candidates[0].votes = 0;

    strcpy(candidates[1].name, "Bob");
    candidates[1].id = 2;
    candidates[1].votes = 0;

    strcpy(candidates[2].name, "Charlie");
    candidates[2].id = 3;
    candidates[2].votes = 0;

    strcpy(candidates[3].name, "Diana");
    candidates[3].id = 4;
    candidates[3].votes = 0;

    strcpy(candidates[4].name, "Edward");
    candidates[4].id = 5;
    candidates[4].votes = 0;

    totalCandidates = MAX_CANDIDATES;
}

void registerVoter() {
    if (totalVoters >= MAX_VOTERS) {
        printf("Maximum number of voters reached. Cannot register more voters.\n");
        return;
    }
    Voter newVoter;
    newVoter.id = totalVoters + 1;

    printf("Enter voter's name: ");
    scanf("%s", newVoter.name);
    
    newVoter.hasVoted = false;

    voters[totalVoters] = newVoter;
    totalVoters++;
    printf("Voter registered: %s (ID: %d)\n", newVoter.name, newVoter.id);
}

void castVote() {
    int voterId;
    printf("Enter your voter ID: ");
    scanf("%d", &voterId);

    if (voterId < 1 || voterId > totalVoters) {
        printf("Invalid voter ID.\n");
        return;
    }

    if (voters[voterId - 1].hasVoted) {
        printf("You have already voted!\n");
        return;
    }

    printf("Available candidates:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("ID: %d, Name: %s\n", candidates[i].id, candidates[i].name);
    }

    int candidateId;
    printf("Enter candidate ID to vote for: ");
    scanf("%d", &candidateId);

    if (candidateId < 1 || candidateId > totalCandidates) {
        printf("Invalid candidate ID.\n");
        return;
    }

    candidates[candidateId - 1].votes++;
    voters[voterId - 1].hasVoted = true;
    printf("Vote casted for: %s\n", candidates[candidateId - 1].name);
}

void displayResults() {
    printf("\nVoting Results:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("Candidate: %s, Votes: %d\n", candidates[i].name, candidates[i].votes);
    }
}

void resetVoting() {
    for (int i = 0; i < totalCandidates; i++) {
        candidates[i].votes = 0;
    }
    for (int i = 0; i < totalVoters; i++) {
        voters[i].hasVoted = false;
    }
    totalVoters = 0;
    printf("Voting has been reset.\n");
}

int main() {
    int choice;
    initializeCandidates();

    do {
        printf("\nElectronic Voting System\n");
        printf("1. Register Voter\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Reset Voting\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
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
                resetVoting();
                break;
            case 5:
                printf("Exiting the Voting System. Thank you!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}