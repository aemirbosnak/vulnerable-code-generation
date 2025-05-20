//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: interoperable
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
int candidateCount = 0;
int voterCount = 0;

void initializeCandidates() {
    for (int i = 0; i < candidateCount; i++) {
        candidates[i].votes = 0;
    }
}

void addCandidate(const char* name) {
    if (candidateCount < MAX_CANDIDATES) {
        strcpy(candidates[candidateCount].name, name);
        candidates[candidateCount].votes = 0;
        candidateCount++;
    } else {
        printf("Maximum candidates reached.\n");
    }
}

int findVoter(const char* voterName) {
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            return i; // Voter found
        }
    }
    return -1; // Voter not found
}

int findCandidate(const char* candidateName) {
    for (int i = 0; i < candidateCount; i++) {
        if (strcmp(candidates[i].name, candidateName) == 0) {
            return i; // Candidate found
        }
    }
    return -1; // Candidate not found
}

void vote(const char* voterName, const char* candidateName) {
    int voterIndex = findVoter(voterName);
    if (voterIndex == -1) {
        strcpy(voters[voterCount].name, voterName);
        voters[voterCount].hasVoted = 1;
        voterCount++;
        voterIndex = voterCount - 1;
    } 
    else if (voters[voterIndex].hasVoted) {
        printf("You have already voted!\n");
        return;
    }

    int candidateIndex = findCandidate(candidateName);
    if (candidateIndex != -1) {
        candidates[candidateIndex].votes++;
        voters[voterIndex].hasVoted = 1;
        printf("Vote recorded for %s.\n", candidateName);
    } else {
        printf("Candidate not found!\n");
    }
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void menu() {
    int choice;
    char name[50];
    do {
        printf("\n--- Electronic Voting System ---\n");
        printf("1. Add Candidate\n");
        printf("2. Vote\n");
        printf("3. Show Results\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline
        
        switch (choice) {
            case 1:
                printf("Enter candidate name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                addCandidate(name);
                break;
            case 2:
                printf("Enter your name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                char candidate[50];
                printf("Enter candidate's name to vote: ");
                fgets(candidate, sizeof(candidate), stdin);
                candidate[strcspn(candidate, "\n")] = 0; // Remove newline
                vote(name, candidate);
                break;
            case 3:
                displayResults();
                break;
            case 4:
                printf("Exiting... Thank you for participating!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (choice != 4);
}

int main() {
    initializeCandidates();
    menu();
    return 0;
}