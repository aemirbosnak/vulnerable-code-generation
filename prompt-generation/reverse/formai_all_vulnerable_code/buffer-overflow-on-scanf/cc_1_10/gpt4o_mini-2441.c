//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char username[50];
    int voted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void addCandidate(char* name) {
    if (candidateCount < MAX_CANDIDATES) {
        strcpy(candidates[candidateCount].name, name);
        candidates[candidateCount].votes = 0;
        candidateCount++;
        printf("Candidate %s added successfully.\n", name);
    } else {
        printf("Maximum number of candidates reached.\n");
    }
}

void registerVoter(char* username) {
    if (voterCount < MAX_VOTERS) {
        strcpy(voters[voterCount].username, username);
        voters[voterCount].voted = 0;
        voterCount++;
        printf("Voter %s registered successfully.\n", username);
    } else {
        printf("Maximum number of voters reached.\n");
    }
}

void castVote(char* username, int candidateIndex) {
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].username, username) == 0) {
            if (voters[i].voted == 0) {
                candidates[candidateIndex].votes++;
                voters[i].voted = 1;
                printf("Vote cast successfully for %s by %s.\n", 
                       candidates[candidateIndex].name, username);
            } else {
                printf("Error: %s has already voted.\n", username);
            }
            return;
        }
    }
    printf("Error: Voter %s not registered.\n", username);
}

void displayResults() {
    printf("\nVoting Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("Candidate %s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void clearScreen() {
    printf("\033[H\033[J");
}

void displayMenu() {
    printf("======== Electronic Voting System ========\n");
    printf("1. Add Candidate\n");
    printf("2. Register Voter\n");
    printf("3. Cast Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
    printf("==========================================\n");
}

int main() {
    int choice;
    char username[50];
    char candidateName[50];
    int candidateIndex;

    do {
        clearScreen();
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume trailing newline

        switch (choice) {
            case 1:
                printf("Enter candidate name: ");
                fgets(candidateName, sizeof(candidateName), stdin);
                candidateName[strcspn(candidateName, "\n")] = 0; // remove newline
                addCandidate(candidateName);
                break;

            case 2:
                printf("Enter voter username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // remove newline
                registerVoter(username);
                break;

            case 3:
                printf("Enter voter username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // remove newline
                printf("Enter candidate index (0-%d): ", candidateCount - 1);
                scanf("%d", &candidateIndex);
                castVote(username, candidateIndex);
                break;

            case 4:
                displayResults();
                printf("Press Enter to continue...\n");
                getchar();
                break;

            case 5:
                printf("Exiting the voting system.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}