//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 3
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Charlie", 0}
};

Voter voters[MAX_VOTERS];
int voterCount = 0;

void registerVoter() {
    if (voterCount >= MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter voter name: ");
    scanf("%s", name);

    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].name, name) == 0) {
            printf("Voter already registered.\n");
            return;
        }
    }

    strcpy(voters[voterCount].name, name);
    voters[voterCount].hasVoted = 0;
    voterCount++;
    printf("Voter %s registered successfully!\n", name);
}

void vote() {
    char voterName[MAX_NAME_LENGTH];
    printf("Enter your name to vote: ");
    scanf("%s", voterName);

    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            if (voters[i].hasVoted) {
                printf("You have already voted!\n");
                return;
            }

            printf("Candidates:\n");
            for (int j = 0; j < MAX_CANDIDATES; j++) {
                printf("%d. %s\n", j + 1, candidates[j].name);
            }

            int choice;
            printf("Enter candidate number to vote: ");
            scanf("%d", &choice);

            if (choice < 1 || choice > MAX_CANDIDATES) {
                printf("Invalid choice.\n");
                return;
            }

            candidates[choice - 1].votes++;
            voters[i].hasVoted = 1;
            printf("Thank you for voting!\n");
            return;
        }
    }

    printf("Voter not registered.\n");
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nElectronic Voting System\n");
        printf("1. Register Voter\n");
        printf("2. Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerVoter();
                break;
            case 2:
                vote();
                break;
            case 3:
                displayResults();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}