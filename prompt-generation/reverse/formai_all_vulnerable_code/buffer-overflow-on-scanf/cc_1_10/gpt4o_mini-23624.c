//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_LEN 50

typedef struct {
    char name[MAX_LEN];
    int votes;
} Candidate;

void displayCandidates(Candidate candidates[], int count) {
    printf("\nList of Candidates:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - Votes: %d\n", i + 1, candidates[i].name, candidates[i].votes);
    }
}

void registerCandidates(Candidate candidates[], int *count) {
    printf("\nEnter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", count);
    if (*count > MAX_CANDIDATES) {
        printf("Exceeded maximum candidates. Setting count to %d.\n", MAX_CANDIDATES);
        *count = MAX_CANDIDATES;
    }
    for (int i = 0; i < *count; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0; // Initialize votes to 0
    }
}

void castVote(Candidate candidates[], int count) {
    int choice;
    printf("\nCast your vote! Choose a candidate by number (1 to %d): ", count);
    scanf("%d", &choice);
    if (choice < 1 || choice > count) {
        printf("Invalid choice. Vote not counted.\n");
    } else {
        candidates[choice - 1].votes++;
        printf("Thank you for voting for %s!\n", candidates[choice - 1].name);
    }
}

void displayResults(Candidate candidates[], int count) {
    printf("\nElection Results:\n");
    for (int i = 0; i < count; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int candidateCount = 0;
    int choice;

    while (1) {
        printf("\n==== Electronic Voting System ====\n");
        printf("1. Register Candidates\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Please choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerCandidates(candidates, &candidateCount);
                break;
            case 2:
                if (candidateCount == 0) {
                    printf("No candidates registered yet!\n");
                } else {
                    castVote(candidates, candidateCount);
                }
                break;
            case 3:
                if (candidateCount == 0) {
                    printf("No results available. Please register candidates first.\n");
                } else {
                    displayResults(candidates, candidateCount);
                }
                break;
            case 4:
                printf("Exiting the voting system. Thank you for participating!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }

    return 0;
}