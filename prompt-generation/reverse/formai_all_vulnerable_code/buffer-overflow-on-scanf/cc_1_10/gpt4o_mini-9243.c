//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 5
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[NAME_LENGTH];
    int voted; // 0: Not Voted, 1: Voted
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalVoters = 0, totalCandidates = 0;

// Function to initialize candidates
void initCandidates() {
    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &totalCandidates);
    getchar(); // Consume newline character

    for (int i = 0; i < totalCandidates; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        fgets(candidates[i].name, NAME_LENGTH, stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = '\0'; // Remove newline
        candidates[i].votes = 0;
    }
}

// Function to register voters
void registerVoter() {
    if (totalVoters >= MAX_VOTERS) {
        printf("Maximum voter limit reached!\n");
        return;
    }

    printf("Enter voter name: ");
    fgets(voters[totalVoters].name, NAME_LENGTH, stdin);
    voters[totalVoters].name[strcspn(voters[totalVoters].name, "\n")] = '\0'; // Remove newline
    voters[totalVoters].voted = 0;
    totalVoters++;
    printf("Voter registered successfully!\n");
}

// Function to cast a vote
void castVote() {
    char voterName[NAME_LENGTH];

    printf("Enter your name: ");
    fgets(voterName, NAME_LENGTH, stdin);
    voterName[strcspn(voterName, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < totalVoters; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            if (voters[i].voted == 1) {
                printf("You have already voted!\n");
                return;
            }

            printf("Candidates:\n");
            for (int j = 0; j < totalCandidates; j++) {
                printf("%d. %s\n", j + 1, candidates[j].name);
            }

            int candidateChoice;
            printf("Enter candidate number to vote: ");
            scanf("%d", &candidateChoice);
            getchar(); // Consume newline character

            if (candidateChoice < 1 || candidateChoice > totalCandidates) {
                printf("Invalid choice!\n");
            } else {
                candidates[candidateChoice - 1].votes++;
                voters[i].voted = 1;
                printf("Vote cast successfully!\n");
            }
            return;
        }
    }

    printf("Voter not found!\n");
}

// Function to display results
void displayResults() {
    printf("\nVoting Results:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;

    do {
        printf("\nElectronic Voting System\n");
        printf("1. Initialize Candidates\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                initCandidates();
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
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}