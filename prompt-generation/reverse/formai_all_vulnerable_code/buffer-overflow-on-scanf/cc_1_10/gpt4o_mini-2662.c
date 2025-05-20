//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: intelligent
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
    int voted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void registerCandidate();
void castVote();
void displayResults();
int findVoter(char *voterID);
int findCandidate(char *candidateName);

int main() {
    int option;

    while (1) {
        printf("\n*** Electronic Voting System ***\n");
        printf("1. Register Candidate\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                registerCandidate();
                break;
            case 2:
                castVote();
                break;
            case 3:
                displayResults();
                break;
            case 4:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}

void registerCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached!\n");
        return;
    }

    printf("Enter candidate name: ");
    scanf("%s", candidates[candidateCount].name);
    candidates[candidateCount].votes = 0;
    candidateCount++;
    printf("Candidate '%s' registered successfully!\n", candidates[candidateCount - 1].name);
}

void castVote() {
    char voterID[20];
    char candidateName[50];

    printf("Enter your voter ID: ");
    scanf("%s", voterID);
    
    int voterIndex = findVoter(voterID);
    if (voterIndex != -1) {
        printf("You have already voted!\n");
        return;
    }

    printf("Candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    printf("Enter the name of the candidate you want to vote for: ");
    scanf("%s", candidateName);

    int candidateIndex = findCandidate(candidateName);
    if (candidateIndex != -1) {
        voters[voterCount].voted = 1;
        strcpy(voters[voterCount].voterID, voterID);
        voters[voterCount].voted = 1;
        candidates[candidateIndex].votes++;
        voterCount++;
        printf("Vote casted successfully for '%s'.\n", candidateName);
    } else {
        printf("Candidate '%s' not found!\n", candidateName);
    }
}

void displayResults() {
    printf("\n*** Voting Results ***\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int findVoter(char *voterID) {
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            return i; // Voter found
        }
    }
    return -1; // Voter not found
}

int findCandidate(char *candidateName) {
    for (int i = 0; i < candidateCount; i++) {
        if (strcmp(candidates[i].name, candidateName) == 0) {
            return i; // Candidate found
        }
    }
    return -1; // Candidate not found
}