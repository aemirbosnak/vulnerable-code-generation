//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

typedef struct {
    char name[50];
    int voteCount;
} Candidate;

typedef struct {
    char name[50];
    int hasVoted;
} Voter;

Voter voters[MAX_VOTERS];
Candidate candidates[MAX_CANDIDATES];
int voterCount = 0;
int candidateCount = 0;

// Function declarations
void addCandidate();
void registerVoter();
void castVote();
void displayResults();
void displayMenu();
int findVoter(char *voterName);
int findCandidate(char *candidateName);

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character
        
        switch(choice) {
            case 1:
                addCandidate();
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
                printf("Exiting the voting system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n---- Electronic Voting System ----\n");
    printf("1. Add Candidate\n");
    printf("2. Register Voter\n");
    printf("3. Cast Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
}

void addCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Cannot add more candidates.\n");
        return;
    }
    printf("Enter candidate name: ");
    fgets(candidates[candidateCount].name, sizeof(candidates[candidateCount].name), stdin);
    candidates[candidateCount].name[strcspn(candidates[candidateCount].name, "\n")] = 0; // Trim newline
    candidates[candidateCount].voteCount = 0;
    candidateCount++;
    printf("Candidate %s added successfully.\n", candidates[candidateCount - 1].name);
}

void registerVoter() {
    if (voterCount >= MAX_VOTERS) {
        printf("Cannot register more voters.\n");
        return;
    }
    printf("Enter voter name: ");
    fgets(voters[voterCount].name, sizeof(voters[voterCount].name), stdin);
    voters[voterCount].name[strcspn(voters[voterCount].name, "\n")] = 0; // Trim newline
    voters[voterCount].hasVoted = 0;
    voterCount++;
    printf("Voter %s registered successfully.\n", voters[voterCount - 1].name);
}

void castVote() {
    char voterName[50];
    char candidateName[50];

    printf("Enter your name: ");
    fgets(voterName, sizeof(voterName), stdin);
    voterName[strcspn(voterName, "\n")] = 0; // Trim newline

    int voterIndex = findVoter(voterName);
    if (voterIndex == -1) {
        printf("Voter not registered.\n");
        return;
    }
    if (voters[voterIndex].hasVoted) {
        printf("You have already voted!\n");
        return;
    }

    printf("Available candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s\n", candidates[i].name);
    }

    printf("Enter candidate name to vote for: ");
    fgets(candidateName, sizeof(candidateName), stdin);
    candidateName[strcspn(candidateName, "\n")] = 0; // Trim newline

    int candidateIndex = findCandidate(candidateName);
    if (candidateIndex == -1) {
        printf("Candidate not found.\n");
        return;
    }

    candidates[candidateIndex].voteCount++;
    voters[voterIndex].hasVoted = 1;
    printf("Vote for %s recorded successfully!\n", candidates[candidateIndex].name);
}

void displayResults() {
    printf("\n---- Voting Results ----\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("Candidate: %s, Votes: %d\n", candidates[i].name, candidates[i].voteCount);
    }
}

int findVoter(char *voterName) {
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            return i;
        }
    }
    return -1; // Not found
}

int findCandidate(char *candidateName) {
    for (int i = 0; i < candidateCount; i++) {
        if (strcmp(candidates[i].name, candidateName) == 0) {
            return i;
        }
    }
    return -1; // Not found
}