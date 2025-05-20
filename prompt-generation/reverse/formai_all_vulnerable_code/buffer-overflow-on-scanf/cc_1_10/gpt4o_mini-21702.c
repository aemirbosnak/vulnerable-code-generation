//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 5
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char voterId[MAX_NAME_LENGTH];
    int hasVoted; // 0 if hasn't voted, 1 if has voted
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalVoters = 0;
int totalCandidates = 0;

// Function Prototypes
void registerCandidate();
void registerVoter();
void castVote();
void displayResults();
int findVoter(char *voterId);
int findCandidate(char *candidateName);

int main() {
    int choice;

    while (1) {
        printf("\n--------------------------------------------------\n");
        printf("                     E-Voting System               \n");
        printf("--------------------------------------------------\n");
        printf("1. Register Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("--------------------------------------------------\n");
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
                printf("Thank you for using the E-Voting System!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void registerCandidate() {
    if (totalCandidates >= MAX_CANDIDATES) {
        printf("Candidate limit reached! Cannot register more candidates.\n");
        return;
    }
    
    printf("Enter candidate name: ");
    scanf("%s", candidates[totalCandidates].name);
    candidates[totalCandidates].votes = 0; // initialize votes to 0
    totalCandidates++;
    printf("Candidate %s registered successfully!\n", candidates[totalCandidates - 1].name);
}

void registerVoter() {
    if (totalVoters >= MAX_VOTERS) {
        printf("Voter limit reached! Cannot register more voters.\n");
        return;
    }
    
    printf("Enter voter ID: ");
    scanf("%s", voters[totalVoters].voterId);
    voters[totalVoters].hasVoted = 0; // initialize hasVoted to 0
    totalVoters++;
    printf("Voter %s registered successfully!\n", voters[totalVoters - 1].voterId);
}

void castVote() {
    char voterId[MAX_NAME_LENGTH];
    char candidateName[MAX_NAME_LENGTH];

    printf("Enter your voter ID: ");
    scanf("%s", voterId);

    int voterIndex = findVoter(voterId);
    if (voterIndex == -1) {
        printf("Voter ID not found! Please register first.\n");
        return;
    }

    if (voters[voterIndex].hasVoted) {
        printf("You have already voted! You can't vote again.\n");
        return;
    }

    printf("Candidates:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    printf("Enter the candidate name you want to vote for: ");
    scanf("%s", candidateName);

    int candidateIndex = findCandidate(candidateName);
    if (candidateIndex == -1) {
        printf("Candidate not found!\n");
        return;
    }

    candidates[candidateIndex].votes++;
    voters[voterIndex].hasVoted = 1; // mark as voted
    printf("Thank you for voting for %s!\n", candidates[candidateIndex].name);
}

void displayResults() {
    printf("\nVoting Results:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int findVoter(char *voterId) {
    for (int i = 0; i < totalVoters; i++) {
        if (strcmp(voters[i].voterId, voterId) == 0) {
            return i;
        }
    }
    return -1;
}

int findCandidate(char *candidateName) {
    for (int i = 0; i < totalCandidates; i++) {
        if (strcmp(candidates[i].name, candidateName) == 0) {
            return i;
        }
    }
    return -1;
}