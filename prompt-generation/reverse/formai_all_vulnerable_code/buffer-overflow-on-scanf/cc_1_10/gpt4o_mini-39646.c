//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int voteCount;
} Candidate;

typedef struct {
    char voterID[50];
    int hasVoted; // 0 for no, 1 for yes
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS]; 
int candidateCount = 0;
int voterCount = 0;

void addCandidate(const char *name) {
    if (candidateCount < MAX_CANDIDATES) {
        strcpy(candidates[candidateCount].name, name);
        candidates[candidateCount].voteCount = 0;
        candidateCount++;
    } else {
        printf("Maximum candidates reached!\n");
    }
}

void registerVoter(const char *voterID) {
    if (voterCount < MAX_VOTERS) {
        strcpy(voters[voterCount].voterID, voterID);
        voters[voterCount].hasVoted = 0;
        voterCount++;
    } else {
        printf("Maximum voters reached!\n");
    }
}

void castVote() {
    char voterID[50];
    int i;

    printf("Enter your voter ID: ");
    scanf("%s", voterID);

    // Check if the voter is registered and hasn't voted
    for (i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            if (voters[i].hasVoted == 1) {
                printf("You have already voted!\n");
                return;
            } else {
                break;
            }
        }
    }

    if (i == voterCount) {
        printf("Voter not registered!\n");
        return;
    }

    printf("Select a candidate to vote for:\n");
    for (int j = 0; j < candidateCount; j++) {
        printf("%d: %s\n", j + 1, candidates[j].name);
    }

    int choice;
    printf("Enter candidate number: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > candidateCount) {
        printf("Invalid choice!\n");
        return;
    }

    candidates[choice - 1].voteCount++;
    voters[i].hasVoted = 1; // Mark voter as having voted
    printf("Vote casted successfully!\n");
}

void displayResults() {
    printf("Election Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].voteCount);
    }
}

int main() {
    int choice, configChoice;
    char name[50];
    char voterID[50];

    printf("Welcome to the Electronic Voting System\n");

    do {
        printf("1. Add Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. View Results\n");
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
                castVote();
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}