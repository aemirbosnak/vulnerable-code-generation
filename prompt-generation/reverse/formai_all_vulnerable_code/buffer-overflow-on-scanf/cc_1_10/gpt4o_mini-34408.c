//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
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

// Function prototypes
void addCandidate();
void displayCandidates();
void castVote();
void displayResults();
void initializeVoting();

int main() {
    int choice;

    initializeVoting();

    while(1) {
        printf("\n--- Electronic Voting System ---\n");
        printf("1. Add Candidate\n");
        printf("2. Display Candidates\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                displayCandidates();
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
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void addCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Maximum limit of candidates reached.\n");
        return;
    }

    Candidate newCandidate;
    newCandidate.id = candidateCount + 1;
    printf("Enter candidate name: ");
    scanf("%s", newCandidate.name);
    newCandidate.votes = 0;

    candidates[candidateCount] = newCandidate;
    candidateCount++;
    printf("Candidate added successfully!\n");
}

void displayCandidates() {
    if (candidateCount == 0) {
        printf("No candidates available.\n");
        return;
    }

    printf("\nCandidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("ID: %d, Name: %s, Votes: %d\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
}

void castVote() {
    if (voterCount >= MAX_VOTERS) {
        printf("Maximum limit of voters reached.\n");
        return;
    }

    int voterId;
    printf("Enter voter ID (1 to %d): ", voterCount + 1);
    scanf("%d", &voterId);

    if (voterId < 1 || voterId > voterCount) {
        printf("Invalid voter ID.\n");
        return;
    }

    if (voters[voterId - 1].hasVoted) {
        printf("Voter has already voted.\n");
        return;
    }

    displayCandidates();
    int candidateId;
    printf("Enter candidate ID to vote: ");
    scanf("%d", &candidateId);

    if (candidateId < 1 || candidateId > candidateCount) {
        printf("Invalid candidate ID.\n");
        return;
    }

    candidates[candidateId - 1].votes++;
    voters[voterId - 1].hasVoted = 1; // Mark voter as having voted
    printf("Vote cast successfully!\n");

    if (voterId == voterCount) {
        Voter newVoter;
        newVoter.id = voterCount + 1;
        printf("Enter voter name: ");
        scanf("%s", newVoter.name);
        newVoter.hasVoted = 0; // New voter has not voted yet
        voters[voterCount] = newVoter;
        voterCount++;
    }
}

void displayResults() {
    if (candidateCount == 0) {
        printf("No candidates available. No results to display.\n");
        return;
    }

    printf("\n--- Voting Results ---\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("Candidate: %s, Votes: %d\n", candidates[i].name, candidates[i].votes);
    }
}

void initializeVoting() {
    printf("Welcome to the Electronic Voting System!\n");
}