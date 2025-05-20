//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

void initializeCandidates(Candidate candidates[], int count);
void castVote(Candidate candidates[], int count);
void displayResults(Candidate candidates[], int count);

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int choice, numberOfCandidates;

    printf("Welcome to the Electronic Voting System\n");
    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &numberOfCandidates);

    while (numberOfCandidates > MAX_CANDIDATES || numberOfCandidates <= 0) {
        printf("Please enter a valid number of candidates (1 - %d): ", MAX_CANDIDATES);
        scanf("%d", &numberOfCandidates);
    }

    initializeCandidates(candidates, numberOfCandidates);

    do {
        printf("\nMenu:\n");
        printf("1. Cast Vote\n");
        printf("2. Display Results\n");
        printf("3. Exit\n");
        printf("Select an option (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                castVote(candidates, numberOfCandidates);
                break;
            case 2:
                displayResults(candidates, numberOfCandidates);
                break;
            case 3:
                printf("Exiting the voting system. Thank you!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void initializeCandidates(Candidate candidates[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0; // Initialize votes to 0
    }
}

void castVote(Candidate candidates[], int count) {
    int vote;
    printf("Vote for your candidate (1-%d): ", count);
    scanf("%d", &vote);

    while (vote < 1 || vote > count) {
        printf("Invalid candidate number. Please vote for a candidate (1-%d): ", count);
        scanf("%d", &vote);
    }

    candidates[vote - 1].votes++; // Increment the votes for the selected candidate
    printf("Thank you for your vote for %s!\n", candidates[vote - 1].name);
}

void displayResults(Candidate candidates[], int count) {
    printf("\nElection Results:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}