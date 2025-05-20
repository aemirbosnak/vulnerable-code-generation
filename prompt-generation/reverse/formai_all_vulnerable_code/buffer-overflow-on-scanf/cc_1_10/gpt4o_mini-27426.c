//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: real-life
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
    int voted; // 1 if voted, 0 if not
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int voterCount = 0;
int candidateCount = 0;

void registerCandidate(char *name) {
    if (candidateCount < MAX_CANDIDATES) {
        strcpy(candidates[candidateCount].name, name);
        candidates[candidateCount].votes = 0;
        candidateCount++;
        printf("Candidate '%s' has been registered.\n", name);
    } else {
        printf("Candidate limit reached!\n");
    }
}

void registerVoter(char *voterID) {
    if (voterCount < MAX_VOTERS) {
        strcpy(voters[voterCount].voterID, voterID);
        voters[voterCount].voted = 0;
        voterCount++;
        printf("Voter '%s' has been registered.\n", voterID);
    } else {
        printf("Voter limit reached!\n");
    }
}

void castVote() {
    char voterID[20];
    printf("Enter your voter ID: ");
    scanf("%s", voterID);

    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            if (voters[i].voted == 1) {
                printf("You have already voted!\n");
                return;
            }

            printf("Available candidates:\n");
            for (int j = 0; j < candidateCount; j++) {
                printf("%d. %s\n", j + 1, candidates[j].name);
            }

            int choice;
            printf("Choose candidate number to vote: ");
            scanf("%d", &choice);

            if (choice > 0 && choice <= candidateCount) {
                candidates[choice - 1].votes++;
                voters[i].voted = 1;
                printf("Vote has been cast for '%s'.\n", candidates[choice - 1].name);
            } else {
                printf("Invalid choice!\n");
            }
            return;
        }
    }
    printf("Voter ID not found!\n");
}

void displayResults() {
    printf("\nVoting Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int option;
    char name[50];
    char voterID[20];

    do {
        printf("\nElectronic Voting System\n");
        printf("1. Register Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", name);
                registerCandidate(name);
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
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 5);

    return 0;
}