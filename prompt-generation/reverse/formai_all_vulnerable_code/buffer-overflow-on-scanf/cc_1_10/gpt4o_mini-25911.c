//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    int id;
    char name[100];
    int votes;
} Candidate;

typedef struct {
    int id;
    char name[100];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

// Function Prototypes
void registerCandidate();
void registerVoter();
void castVote();
void displayResults();
void showMenu();

int main() {
    int choice;
    do {
        showMenu();
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
                printf("Exiting the Electronic Voting System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
    return 0;
}

void showMenu() {
    printf("\n--- Electronic Voting System ---\n");
    printf("1. Register Candidate\n");
    printf("2. Register Voter\n");
    printf("3. Cast Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void registerCandidate() {
    if (candidateCount < MAX_CANDIDATES) {
        candidates[candidateCount].id = candidateCount + 1;
        printf("Enter candidate name: ");
        scanf("%s", candidates[candidateCount].name);
        candidates[candidateCount].votes = 0;
        candidateCount++;
        printf("Candidate registered successfully!\n");
    } else {
        printf("Maximum candidates registered. Cannot register more.\n");
    }
}

void registerVoter() {
    if (voterCount < MAX_VOTERS) {
        voters[voterCount].id = voterCount + 1;
        printf("Enter voter name: ");
        scanf("%s", voters[voterCount].name);
        voters[voterCount].hasVoted = 0;
        voterCount++;
        printf("Voter registered successfully!\n");
    } else {
        printf("Maximum voters registered. Cannot register more.\n");
    }
}

void castVote() {
    int voterId, candidateId;

    printf("Enter your voter ID (1-%d): ", voterCount);
    scanf("%d", &voterId);
    
    if (voterId < 1 || voterId > voterCount || voters[voterId - 1].hasVoted) {
        printf("Invalid voter ID or you have already voted.\n");
        return;
    }

    printf("List of Candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d: %s\n", candidates[i].id, candidates[i].name);
    }
    
    printf("Enter candidate ID to vote for (1-%d): ", candidateCount);
    scanf("%d", &candidateId);

    if (candidateId < 1 || candidateId > candidateCount) {
        printf("Invalid candidate ID.\n");
        return;
    }

    candidates[candidateId - 1].votes++;
    voters[voterId - 1].hasVoted = 1;
    printf("Vote casted successfully!\n");
}

void displayResults() {
    printf("\n--- Voting Results ---\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}