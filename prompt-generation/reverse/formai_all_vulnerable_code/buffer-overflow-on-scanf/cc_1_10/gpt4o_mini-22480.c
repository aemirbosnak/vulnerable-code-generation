//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char name[50];
    int id;
    int hasVoted;
} Voter;

int candidateCount = 0;
Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int voterCount = 0;

void addCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Maximum candidate limit reached.\n");
        return;
    }
    printf("Enter candidate name: ");
    scanf("%s", candidates[candidateCount].name);
    candidates[candidateCount].votes = 0;
    candidateCount++;
    printf("Candidate added successfully!\n");
}

void registerVoter() {
    if (voterCount >= MAX_VOTERS) {
        printf("Maximum voter limit reached.\n");
        return;
    }
    printf("Enter voter ID: ");
    scanf("%d", &voters[voterCount].id);
    printf("Enter voter name: ");
    scanf("%s", voters[voterCount].name);
    voters[voterCount].hasVoted = 0;
    voterCount++;
    printf("Voter registered successfully!\n");
}

void castVote() {
    int voterId, i;
    printf("Enter your voter ID: ");
    scanf("%d", &voterId);
    
    for (i = 0; i < voterCount; i++) {
        if (voters[i].id == voterId) {
            if (voters[i].hasVoted) {
                printf("You have already voted.\n");
                return;
            }
            char candidateName[50];
            printf("Enter candidate name to vote for: ");
            scanf("%s", candidateName);
            for (int j = 0; j < candidateCount; j++) {
                if (strcmp(candidates[j].name, candidateName) == 0) {
                    candidates[j].votes++;
                    voters[i].hasVoted = 1;
                    printf("Vote cast successfully for %s!\n", candidates[j].name);
                    return;
                }
            }
            printf("Candidate not found.\n");
            return;
        }
    }
    printf("Voter ID not found.\n");
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void displayMenu() {
    printf("\nElectronic Voting System\n");
    printf("1. Add Candidate\n");
    printf("2. Register Voter\n");
    printf("3. Cast Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addCandidate();
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
                printf("Thank you for using the Electronic Voting System!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}