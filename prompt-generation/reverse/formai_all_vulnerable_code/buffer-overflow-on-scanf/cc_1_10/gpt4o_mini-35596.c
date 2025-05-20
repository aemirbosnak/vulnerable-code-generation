//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char voterID[20];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalCandidates = 0;
int totalVoters = 0;

// Function to initialize candidates
void initializeCandidates() {
    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &totalCandidates);
    if (totalCandidates > MAX_CANDIDATES) {
        totalCandidates = MAX_CANDIDATES;
        printf("Maximum number of candidates set to %d.\n", MAX_CANDIDATES);
    }
    for (int i = 0; i < totalCandidates; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

// Function to register voters
void registerVoters() {
    printf("Enter the number of voters (max %d): ", MAX_VOTERS);
    scanf("%d", &totalVoters);
    if (totalVoters > MAX_VOTERS) {
        totalVoters = MAX_VOTERS;
        printf("Maximum number of voters set to %d.\n", MAX_VOTERS);
    }
    for (int i = 0; i < totalVoters; i++) {
        printf("Enter voter ID for voter %d: ", i + 1);
        scanf("%s", voters[i].voterID);
        voters[i].hasVoted = 0;
    }
}

// Function to display candidates
void displayCandidates() {
    printf("\nCandidates:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

// Function to cast a vote
void castVote() {
    char voterID[20];
    printf("Enter your voter ID: ");
    scanf("%s", voterID);

    for (int i = 0; i < totalVoters; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            if (voters[i].hasVoted) {
                printf("You have already voted!\n");
                return;
            } else {
                displayCandidates();
                int choice;
                printf("Vote for candidate (1 to %d): ", totalCandidates);
                scanf("%d", &choice);
                if (choice < 1 || choice > totalCandidates) {
                    printf("Invalid choice!\n");
                    return;
                }
                candidates[choice - 1].votes++;
                voters[i].hasVoted = 1;
                printf("Thank you for voting!\n");
                return;
            }
        }
    }
    printf("Voter ID not found!\n");
}

// Function to display results
void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int option;
    do {
        printf("\nElectronic Voting System\n");
        printf("1. Initialize Candidates\n");
        printf("2. Register Voters\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                initializeCandidates();
                break;
            case 2:
                registerVoters();
                break;
            case 3:
                if (totalCandidates == 0 || totalVoters == 0) {
                    printf("Please initialize candidates and register voters first!\n");
                } else {
                    castVote();
                }
                break;
            case 4:
                if (totalCandidates == 0) {
                    printf("No candidates available to display results!\n");
                } else {
                    displayResults();
                }
                break;
            case 5:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    } while (option != 5);

    return 0;
}