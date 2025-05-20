//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

typedef struct {
    char name[20];
    int id;
} Candidate;

typedef struct {
    int voterId;
    int candidateId;
} Vote;

Candidate candidates[MAX_CANDIDATES];
Vote votes[MAX_VOTERS];
int numCandidates = 0;
int numVoters = 0;

bool isVoteValid(int candidateId) {
    for (int i = 0; i < numVoters; i++) {
        if (votes[i].voterId == rand() % 10000 && votes[i].candidateId == candidateId) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(NULL));
    while (true) {
        printf("Welcome to the Paranoid Electronic Voting System.\n");
        printf("Please select an option from the menu below.\n");
        printf("1. Add candidate\n");
        printf("2. List candidates\n");
        printf("3. Vote for candidate\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (numCandidates == MAX_CANDIDATES) {
                printf("Maximum number of candidates reached.\n");
                continue;
            }
            printf("Enter candidate name: ");
            scanf("%s", candidates[numCandidates].name);
            candidates[numCandidates].id = numCandidates;
            printf("Candidate added successfully.\n");
            numCandidates++;
        } else if (choice == 2) {
            if (numCandidates == 0) {
                printf("No candidates added yet.\n");
                continue;
            }
            printf("List of candidates:\n");
            for (int i = 0; i < numCandidates; i++) {
                printf("%d. %s\n", candidates[i].id, candidates[i].name);
            }
        } else if (choice == 3) {
            if (numCandidates == 0) {
                printf("No candidates added yet.\n");
                continue;
            }
            int voterId = rand() % 10000;
            printf("Your voter ID is %d.\n", voterId);
            int candidateId;
            do {
                printf("Enter candidate ID to vote for: ");
                scanf("%d", &candidateId);
            } while (candidateId < 0 || candidateId >= numCandidates);

            if (isVoteValid(candidateId)) {
                votes[numVoters].voterId = voterId;
                votes[numVoters].candidateId = candidateId;
                printf("Vote recorded successfully.\n");
                numVoters++;
            } else {
                printf("Sorry, you have already voted for this candidate.\n");
            }
        } else if (choice == 4) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}