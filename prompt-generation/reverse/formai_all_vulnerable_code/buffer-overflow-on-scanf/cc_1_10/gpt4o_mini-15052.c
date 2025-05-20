//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: surprised
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
int candidateCount = 0;
int voterCount = 0;

void initializeCandidates() {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
        candidateCount++;
    }
}

void registerVoter() {
    if (voterCount >= MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
        return;
    }
    printf("Enter Voter ID: ");
    scanf("%s", voters[voterCount].voterID);
    voters[voterCount].hasVoted = 0;
    voterCount++;
    printf("Voter registered successfully!\n");
}

int isVoterRegistered(char *voterID) {
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            return i;
        }
    }
    return -1;
}

void castVote() {
    char voterID[20];
    printf("Enter your Voter ID: ");
    scanf("%s", voterID);

    int voterIndex = isVoterRegistered(voterID);
    
    if (voterIndex == -1) {
        printf("Voter ID not found. Please register first.\n");
        return;
    }

    if (voters[voterIndex].hasVoted) {
        printf("This voter has already voted!\n");
        return;
    }

    printf("Choose a candidate to vote for:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    int choice;
    printf("Enter the candidate number: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > candidateCount) {
        printf("Invalid candidate choice.\n");
        return;
    }

    candidates[choice - 1].votes++;
    voters[voterIndex].hasVoted = 1;
    printf("Vote casted for %s successfully!\n", candidates[choice - 1].name);
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    int maxVotes = -1;
    int winnerIndex = -1;
    for (int i = 0; i < candidateCount; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }

    if (winnerIndex != -1) {
        printf("The winner is: %s with %d votes!\n", candidates[winnerIndex].name, maxVotes);
    } else {
        printf("No votes were cast.\n");
    }
}

void displayMenu() {
    printf("\n--- Electronic Voting System ---\n");
    printf("1. Register Voter\n");
    printf("2. Cast Vote\n");
    printf("3. Display Results\n");
    printf("4. Exit\n");
    printf("-------------------------------\n");
}

int main() {
    int choice;
    initializeCandidates();

    do {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerVoter();
                break;
            case 2:
                castVote();
                break;
            case 3:
                displayResults();
                break;
            case 4:
                printf("Thank you for using the Electronic Voting System!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}