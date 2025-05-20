//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5  // maximum number of candidates
#define MAX_VOTERS 100    // maximum number of voters

// define struct for candidate
typedef struct {
    char name[50];
    int votes;
} Candidate;

// function prototypes
void showMenu();
void addCandidate(Candidate [], int *);
void printCandidates(Candidate [], int);
void castVote(Candidate [], int);
void printSummary(Candidate [], int);

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int numCandidates = 0;
    int selection;

    do {
        showMenu();
        printf("\nEnter selection: ");
        scanf("%d", &selection);
        printf("\n");

        switch (selection) {
            case 1:
                addCandidate(candidates, &numCandidates);
                break;
            case 2:
                printCandidates(candidates, numCandidates);
                break;
            case 3:
                castVote(candidates, numCandidates);
                break;
            case 4:
                printSummary(candidates, numCandidates);
                break;
            case 5:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid selection. Please try again.\n");
                break;
        }
    } while (selection != 5);

    return 0;
}

void showMenu() {
    printf("========== Electronic Voting System ==========\n");
    printf("1. Add Candidate\n");
    printf("2. Print Candidates\n");
    printf("3. Cast Vote\n");
    printf("4. Print Vote Summary\n");
    printf("5. Exit\n");
}

void addCandidate(Candidate candidates[], int *numCandidates) {
    if (*numCandidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }

    Candidate newCandidate;
    printf("Enter candidate name: ");
    scanf("%s", newCandidate.name);
    newCandidate.votes = 0;

    candidates[*numCandidates] = newCandidate;
    (*numCandidates)++;
    printf("Candidate added successfully.\n");
}

void printCandidates(Candidate candidates[], int numCandidates) {
    if (numCandidates == 0) {
        printf("No candidates added.\n");
        return;
    }

    printf("================== Candidates ==================\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
    printf("=================================================\n");
}

void castVote(Candidate candidates[], int numCandidates) {
    if (numCandidates == 0) {
        printf("No candidates added.\n");
        return;
    }

    char candidateName[50];
    printf("Enter candidate name: ");
    scanf("%s", candidateName);

    for (int i = 0; i < numCandidates; i++) {
        if (strcmp(candidates[i].name, candidateName) == 0) {
            candidates[i].votes++;
            printf("Vote added successfully.\n");
            return;
        }
    }

    printf("Candidate not found.\n");
}

void printSummary(Candidate candidates[], int numCandidates) {
    if (numCandidates == 0) {
        printf("No candidates added.\n");
        return;
    }

    int totalVotes = 0;
    printf("================== Vote Summary ==================\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].votes);
        totalVotes += candidates[i].votes;
    }
    printf("Total Votes: %d\n", totalVotes);
    printf("===================================================\n");
}