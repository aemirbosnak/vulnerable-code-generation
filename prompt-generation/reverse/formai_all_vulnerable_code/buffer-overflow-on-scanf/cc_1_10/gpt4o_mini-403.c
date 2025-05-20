//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: brave
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
int numberOfCandidates = 0;
int numberOfVoters = 0;

void displayCandidates() {
    printf("\nCandidates:\n");
    for (int i = 0; i < numberOfCandidates; i++) {
        printf("%d. %s - Votes: %d\n", i + 1, candidates[i].name, candidates[i].votes);
    }
}

void registerCandidate() {
    if (numberOfCandidates >= MAX_CANDIDATES) {
        printf("Cannot register more candidates.\n");
        return;
    }
    printf("Enter candidate name: ");
    scanf("%s", candidates[numberOfCandidates].name);
    candidates[numberOfCandidates].votes = 0;
    numberOfCandidates++;
    printf("Candidate %s registered successfully!\n", candidates[numberOfCandidates - 1].name);
}

void registerVoter() {
    if (numberOfVoters >= MAX_VOTERS) {
        printf("Voting capacity reached, cannot register more voters.\n");
        return;
    }
    printf("Enter voter name: ");
    scanf("%s", voters[numberOfVoters].name);
    voters[numberOfVoters].hasVoted = 0;
    numberOfVoters++;
    printf("Voter %s registered successfully!\n", voters[numberOfVoters - 1].name);
}

void castVote() {
    char voterName[50];
    printf("Enter your name: ");
    scanf("%s", voterName);

    for (int i = 0; i < numberOfVoters; i++) {
        if (strcmp(voterName, voters[i].name) == 0) {
            if (voters[i].hasVoted) {
                printf("You have already voted!\n");
                return;
            }
            int candidateNumber;
            displayCandidates();
            printf("Select candidate by number: ");
            scanf("%d", &candidateNumber);
            if (candidateNumber < 1 || candidateNumber > numberOfCandidates) {
                printf("Invalid candidate number!\n");
                return;
            }
            candidates[candidateNumber - 1].votes++;
            voters[i].hasVoted = 1;
            printf("Vote casted for %s!\n", candidates[candidateNumber - 1].name);
            return;
        }
    }
    printf("Voter not found! Please register first.\n");
}

void showResult() {
    printf("\nElection Results:\n");
    displayCandidates();
}

int main() {
    int choice;

    do {
        printf("\nElectronic Voting System\n");
        printf("1. Register Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Show Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
                showResult();
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice, please select again.\n");
        }
    } while (choice != 5);

    return 0;
}