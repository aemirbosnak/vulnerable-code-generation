//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10
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
int candidateCount = 0;
int voterCount = 0;

void addCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Cannot add more candidates.\n");
        return;
    }
    printf("Enter candidate name: ");
    scanf("%s", candidates[candidateCount].name);
    candidates[candidateCount].votes = 0;
    candidateCount++;
    printf("Candidate %s added successfully.\n", candidates[candidateCount - 1].name);
}

void displayCandidates() {
    printf("\nAvailable Candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

int findVoter(char *name) {
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].name, name) == 0) {
            return i; // Voter found
        }
    }
    return -1; // Voter not found
}

void castVote() {
    char voterName[MAX_NAME_LENGTH];
    printf("Enter your name to vote: ");
    scanf("%s", voterName);

    int voterIndex = findVoter(voterName);
    if (voterIndex == -1) {
        // Voter is not registered
        strcpy(voters[voterCount].name, voterName);
        voters[voterCount].hasVoted = 0;
        voterIndex = voterCount; // Assign new voter index
        voterCount++;
    }

    if (voters[voterIndex].hasVoted) {
        printf("You have already voted!\n");
        return;
    }

    displayCandidates();
    int vote;
    printf("Select a candidate by entering the corresponding number: ");
    scanf("%d", &vote);

    if (vote < 1 || vote > candidateCount) {
        printf("Invalid selection.\n");
        return;
    }

    // Cast vote
    candidates[vote - 1].votes++;
    voters[voterIndex].hasVoted = 1; // Mark as voted
    printf("Thank you for voting, %s!\n", voters[voterIndex].name);
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }
}

void menu() {
    int choice;
    while (1) {
        printf("\nElectronic Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. Cast Your Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                castVote();
                break;
            case 3:
                displayResults();
                break;
            case 4:
                printf("Exiting program... Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Electronic Voting System!\n");
    menu();
    return 0;
}