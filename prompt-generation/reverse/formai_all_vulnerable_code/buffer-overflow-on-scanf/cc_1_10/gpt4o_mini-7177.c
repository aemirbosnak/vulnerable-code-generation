//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 5
#define NAME_LENGTH 50
#define VOTER_ID_LENGTH 10

typedef struct {
    char name[NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char voterID[VOTER_ID_LENGTH];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void addCandidate(char name[]) {
    if (candidateCount < MAX_CANDIDATES) {
        strcpy(candidates[candidateCount].name, name);
        candidates[candidateCount].votes = 0;
        candidateCount++;
        printf("Candidate '%s' added successfully!\n\n", name);
    } else {
        printf("Maximum number of candidates reached. Cannot add more.\n\n");
    }
}

void registerVoter(char voterID[]) {
    if (voterCount < MAX_VOTERS) {
        strcpy(voters[voterCount].voterID, voterID);
        voters[voterCount].hasVoted = 0;
        voterCount++;
        printf("Voter '%s' registered successfully!\n\n", voterID);
    } else {
        printf("Maximum number of voters reached. Cannot register more.\n\n");
    }
}

int findVoter(char voterID[]) {
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            return i;
        }
    }
    return -1;
}

void castVote(char voterID[]) {
    int voterIndex = findVoter(voterID);
    if (voterIndex == -1) {
        printf("Voter ID not found. Please register first.\n\n");
        return;
    }
    if (voters[voterIndex].hasVoted) {
        printf("Voter '%s' has already voted!\n\n", voterID);
        return;
    }

    printf("Candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    printf("Select a candidate by number: ");
    int choice;
    scanf("%d", &choice);

    if (choice > 0 && choice <= candidateCount) {
        candidates[choice - 1].votes++;
        voters[voterIndex].hasVoted = 1;
        printf("Vote cast successfully for '%s'!\n\n", candidates[choice - 1].name);
    } else {
        printf("Invalid choice. Vote not counted.\n\n");
    }
}

void displayResults() {
    printf("Current voting results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("\n");
}

int main() {
    int choice;
    char name[NAME_LENGTH];
    char voterID[VOTER_ID_LENGTH];

    while (1) {
        printf("=== Electronic Voting System ===\n");
        printf("1. Add Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", name);
                addCandidate(name);
                break;
            case 2:
                printf("Enter voter ID: ");
                scanf("%s", voterID);
                registerVoter(voterID);
                break;
            case 3:
                printf("Enter voter ID: ");
                scanf("%s", voterID);
                castVote(voterID);
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting the voting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}