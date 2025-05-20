//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 5

struct Candidate {
    char name[50];
    int votes;
};

struct Voter {
    char name[50];
    int voted;
};

struct Candidate candidates[MAX_CANDIDATES];
struct Voter voters[MAX_VOTERS];
int totalVoters = 0, totalCandidates = 0;

void addCandidate() {
    if (totalCandidates >= MAX_CANDIDATES) {
        printf("Maximum candidates reached!\n");
        return;
    }
    printf("Enter candidate name: ");
    scanf("%s", candidates[totalCandidates].name);
    candidates[totalCandidates].votes = 0;
    totalCandidates++;
    printf("Candidate %s added successfully!\n", candidates[totalCandidates - 1].name);
}

void registerVoter() {
    if (totalVoters >= MAX_VOTERS) {
        printf("Maximum voters reached!\n");
        return;
    }
    printf("Enter voter name: ");
    scanf("%s", voters[totalVoters].name);
    voters[totalVoters].voted = 0;
    totalVoters++;
    printf("Voter %s registered successfully!\n", voters[totalVoters - 1].name);
}

void castVote() {
    char voterName[50];
    printf("Enter your name to cast a vote: ");
    scanf("%s", voterName);

    for (int i = 0; i < totalVoters; i++) {
        if (strcmp(voterName, voters[i].name) == 0) {
            if (voters[i].voted) {
                printf("You have already voted!\n");
                return;
            }
            printf("Available candidates:\n");
            for (int j = 0; j < totalCandidates; j++) {
                printf("%d. %s\n", j + 1, candidates[j].name);
            }
            int choice;
            printf("Select a candidate number: ");
            scanf("%d", &choice);
            if (choice < 1 || choice > totalCandidates) {
                printf("Invalid choice!\n");
                return;
            }
            candidates[choice - 1].votes++;
            voters[i].voted = 1;
            printf("Thank you for voting, %s!\n", voterName);
            return;
        }
    }
    printf("Voter %s not found!\n", voterName);
}

void displayResults() {
    printf("\n--- Election Results ---\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("------------------------\n");
}

void showMenu() {
    printf("\n--- Electronic Voting System ---\n");
    printf("1. Register Voter\n");
    printf("2. Add Candidate\n");
    printf("3. Cast Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
    printf("-------------------------------\n");
}

int main() {
    int choice;
    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                registerVoter();
                break;
            case 2:
                addCandidate();
                break;
            case 3:
                castVote();
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}