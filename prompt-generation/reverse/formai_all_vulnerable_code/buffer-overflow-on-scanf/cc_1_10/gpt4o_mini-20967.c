//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 100
#define MAX_VOTERS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalCandidates = 0;
int totalVoters = 0;

void registerCandidate() {
    if (totalCandidates >= MAX_CANDIDATES) {
        printf("Max candidates reached. Cannot register more candidates.\n");
        return;
    }

    Candidate newCandidate;
    newCandidate.id = totalCandidates + 1;

    printf("Enter candidate name: ");
    scanf("%s", newCandidate.name);
    newCandidate.votes = 0;

    candidates[totalCandidates] = newCandidate;
    totalCandidates++;

    printf("Candidate %s registered successfully.\n", newCandidate.name);
}

void registerVoter() {
    if (totalVoters >= MAX_VOTERS) {
        printf("Max voters reached. Cannot register more voters.\n");
        return;
    }

    Voter newVoter;
    newVoter.id = totalVoters + 1;
    newVoter.hasVoted = 0;

    printf("Enter voter name: ");
    scanf("%s", newVoter.name);

    voters[totalVoters] = newVoter;
    totalVoters++;

    printf("Voter %s registered successfully.\n", newVoter.name);
}

void castVote() {
    int voterId, candidateId;

    printf("Enter your voter ID: ");
    scanf("%d", &voterId);

    if (voterId < 1 || voterId > totalVoters || voters[voterId - 1].hasVoted) {
        printf("Invalid voter ID or you have already voted.\n");
        return;
    }

    printf("Candidates List:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }

    printf("Enter candidate ID to vote for: ");
    scanf("%d", &candidateId);

    if (candidateId < 1 || candidateId > totalCandidates) {
        printf("Invalid candidate ID.\n");
        return;
    }

    candidates[candidateId - 1].votes++;
    voters[voterId - 1].hasVoted = 1;

    printf("Vote cast successfully for %s.\n", candidates[candidateId - 1].name);
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nDecentralized Voting System\n");
        printf("1. Register Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
                printf("Exiting the voting system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}