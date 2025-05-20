//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: multivariable
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
    char name[50];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalVoters = 0, totalCandidates = 0;

void initializeCandidates() {
    printf("Enter number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &totalCandidates);
    for (int i = 0; i < totalCandidates; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void registerVoter() {
    if (totalVoters >= MAX_VOTERS) {
        printf("Maximum voters reached. Cannot register more voters.\n");
        return;
    }
    printf("Enter your name: ");
    scanf("%s", voters[totalVoters].name);
    voters[totalVoters].hasVoted = 0;
    totalVoters++;
}

void castVote() {
    char voterName[50];
    printf("Enter your name to cast vote: ");
    scanf("%s", voterName);

    for (int i = 0; i < totalVoters; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            if (voters[i].hasVoted) {
                printf("You have already voted!\n");
                return;
            }
            printf("Available candidates:\n");
            for (int j = 0; j < totalCandidates; j++) {
                printf("%d. %s\n", j + 1, candidates[j].name);
            }
            int choice;
            printf("Select candidate number to vote: ");
            scanf("%d", &choice);
            if (choice < 1 || choice > totalCandidates) {
                printf("Invalid candidate choice!\n");
            } else {
                candidates[choice - 1].votes++;
                voters[i].hasVoted = 1;
                printf("Vote casted successfully for %s.\n", candidates[choice - 1].name);
            }
            return;
        }
    }
    printf("Voter not registered. Please register first.\n");
}

void displayResults() {
    printf("\nVoting Results:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void resetVoting() {
    for (int i = 0; i < totalCandidates; i++) {
        candidates[i].votes = 0;
    }
    for (int i = 0; i < totalVoters; i++) {
        voters[i].hasVoted = 0;
    }
    totalVoters = 0;
    printf("Voting has been reset.\n");
}

int main() {
    int option;

    while (1) {
        printf("\nElectronic Voting System\n");
        printf("1. Initialize Candidates\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Reset Voting\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                initializeCandidates();
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
                resetVoting();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}