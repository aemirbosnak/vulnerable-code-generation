//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: sophisticated
#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

void initCandidates(Candidate candidates[MAX_CANDIDATES]);
void printMenu();
void getUserInput(int votes[MAX_VOTERS][MAX_CANDIDATES]);
void countVotes(Candidate candidates[MAX_CANDIDATES], int votes[MAX_VOTERS][MAX_CANDIDATES]);

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int voters[MAX_VOTERS][MAX_CANDIDATES];

    initCandidates(candidates);
    printMenu();

    for (int i = 0; i < MAX_VOTERS; i++) {
        getUserInput(voters[i]);
    }

    countVotes(candidates, voters);

    printf("\n--- Final Results ---\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("\n%s: %d votes", candidates[i].name, candidates[i].votes);
    }

    return 0;
}

void initCandidates(Candidate candidates[MAX_CANDIDATES]) {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
        strcpy(candidates[i].name, "");
    }
}

void printMenu() {
    printf("\n--- Welcome to the Electronic Voting System ---\n");
    printf("1. Register as a candidate\n");
    printf("2. Cast your vote\n");
    printf("3. Exit\n");
}

void getUserInput(int votes[MAX_VOTERS][MAX_CANDIDATES]) {
    int candidateIndex, voterIndex;

    printf("\nEnter your candidate index (0-%d): ", MAX_CANDIDATES - 1);
    scanf("%d", &candidateIndex);

    printf("Enter your voter index (0-%d): ", MAX_VOTERS - 1);
    scanf("%d", &voterIndex);

    votes[voterIndex][candidateIndex]++;
}

void countVotes(Candidate candidates[MAX_CANDIDATES], int votes[MAX_VOTERS][MAX_CANDIDATES]) {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        for (int j = 0; j < MAX_VOTERS; j++) {
            candidates[i].votes += votes[j][i];
        }
    }
}