//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define CANDIDATE_NAME_LENGTH 50

typedef struct {
    char name[CANDIDATE_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char voterId[10];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void addCandidate(char *name) {
    if (candidateCount < MAX_CANDIDATES) {
        strncpy(candidates[candidateCount].name, name, CANDIDATE_NAME_LENGTH);
        candidates[candidateCount].votes = 0;
        candidateCount++;
    } else {
        printf("Maximum number of candidates reached.\n");
    }
}

void registerVoter(char *id) {
    if (voterCount < MAX_VOTERS) {
        strncpy(voters[voterCount].voterId, id, sizeof(voters[voterCount].voterId));
        voters[voterCount].hasVoted = 0;
        voterCount++;
    } else {
        printf("Maximum number of voters reached.\n");
    }
}

int findVoter(char *id) {
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].voterId, id) == 0) {
            return i;
        }
    }
    return -1; // Voter not found
}

int findCandidate(char *name) {
    for (int i = 0; i < candidateCount; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Candidate not found
}

void castVote() {
    char voterId[10];
    char candidateName[CANDIDATE_NAME_LENGTH];

    printf("Enter your voter ID: ");
    scanf("%s", voterId);

    int voterIndex = findVoter(voterId);
    if (voterIndex == -1) {
        printf("You are not registered to vote. Please register before voting.\n");
        return;
    }
    if (voters[voterIndex].hasVoted) {
        printf("You have already voted. Thank you!\n");
        return;
    }

    printf("Enter the candidate's name you wish to vote for: ");
    scanf("%s", candidateName);
    
    int candidateIndex = findCandidate(candidateName);
    if (candidateIndex == -1) {
        printf("Candidate not found. Please check the name and try again.\n");
        return;
    }

    candidates[candidateIndex].votes++;
    voters[voterIndex].hasVoted = 1;

    printf("Thank you for voting, %s!\n", voterId);
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void displayMenu() {
    printf("\nElectronic Voting System\n");
    printf("1. Register Voter\n");
    printf("2. Add Candidate\n");
    printf("3. Cast Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char voterId[10];
                printf("Enter voter ID: ");
                scanf("%s", voterId);
                registerVoter(voterId);
                break;
            }
            case 2: {
                char candidateName[CANDIDATE_NAME_LENGTH];
                printf("Enter the candidate's name: ");
                scanf("%s", candidateName);
                addCandidate(candidateName);
                break;
            }
            case 3:
                castVote();
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}