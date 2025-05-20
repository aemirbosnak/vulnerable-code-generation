//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

struct Candidate {
    int id;
    char name[50];
    int votes;
};

struct Voter {
    int id;
    int hasVoted;
};

struct Candidate candidates[MAX_CANDIDATES];
struct Voter voters[MAX_VOTERS];

int totalCandidates = 0;
int totalVoters = 0;

// Function prototypes
void initializeCandidates();
void initializeVoters();
void castVote(int voterId);
void displayResults();
void printCandidates();
int checkVoter(int voterId);

int main() {
    int choice;
    initializeCandidates();
    initializeVoters();

    while (1) {
        printf("\n=== Electronic Voting System ===\n");
        printf("1. Cast Vote\n");
        printf("2. Display Results\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int voterId;
                printf("Enter your voter ID (1-%d): ", MAX_VOTERS);
                scanf("%d", &voterId);

                if (checkVoter(voterId)) {
                    castVote(voterId);
                } else {
                    printf("Invalid voter ID or you have already voted!\n");
                }
                break;
            }
            case 2:
                displayResults();
                break;
            case 3:
                printf("Exiting the voting system.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void initializeCandidates() {
    printf("Enter the number of candidates (maximum %d): ", MAX_CANDIDATES);
    scanf("%d", &totalCandidates);
    if (totalCandidates > MAX_CANDIDATES) {
        totalCandidates = MAX_CANDIDATES;
    }
    for (int i = 0; i < totalCandidates; i++) {
        candidates[i].id = i + 1;
        printf("Enter name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void initializeVoters() {
    printf("Enter the total number of voters (maximum %d): ", MAX_VOTERS);
    scanf("%d", &totalVoters);
    if (totalVoters > MAX_VOTERS) {
        totalVoters = MAX_VOTERS;
    }
    for (int i = 0; i < totalVoters; i++) {
        voters[i].id = i + 1;
        voters[i].hasVoted = 0; // Mark as not voted
    }
}

int checkVoter(int voterId) {
    if (voterId < 1 || voterId > totalVoters) {
        return 0; // Invalid voter ID
    }
    return voters[voterId - 1].hasVoted == 0; // Check if the voter has voted
}

void castVote(int voterId) {
    int candidateId;
    printf("Choose a candidate to vote for (1-%d): ", totalCandidates);
    scanf("%d", &candidateId);

    if (candidateId < 1 || candidateId > totalCandidates) {
        printf("Invalid candidate ID!\n");
        return;
    }
    
    candidates[candidateId - 1].votes++; // Increment vote count
    voters[voterId - 1].hasVoted = 1; // Mark voter as voted
    printf("Vote cast successfully for %s!\n", candidates[candidateId - 1].name);
}

void displayResults() {
    printf("\n=== Voting Results ===\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("Candidate %s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}