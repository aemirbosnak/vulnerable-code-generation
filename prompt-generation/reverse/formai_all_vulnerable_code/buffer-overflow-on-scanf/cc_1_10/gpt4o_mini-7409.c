//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void addCandidate(const char* name) {
    if(candidateCount < MAX_CANDIDATES) {
        strncpy(candidates[candidateCount].name, name, MAX_NAME_LENGTH);
        candidates[candidateCount].votes = 0;
        candidateCount++;
    } else {
        printf("Candidate limit reached! Cannot add more candidates.\n");
    }
}

void registerVoter(const char* name) {
    if(voterCount < MAX_VOTERS) {
        strncpy(voters[voterCount].name, name, MAX_NAME_LENGTH);
        voters[voterCount].hasVoted = 0;
        voterCount++;
    } else {
        printf("Voter limit reached! Cannot register more voters.\n");
    }
}

int findVoter(const char* name) {
    for(int i = 0; i < voterCount; i++) {
        if(strcmp(voters[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int findCandidate(const char* name) {
    for(int i = 0; i < candidateCount; i++) {
        if(strcmp(candidates[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void castVote(const char* voterName, const char* candidateName) {
    int voterIndex = findVoter(voterName);
    int candidateIndex = findCandidate(candidateName);

    if(voterIndex == -1) {
        printf("Voter not registered!\n");
        return;
    }
    if(candidates[candidateIndex].name[0] == '\0') {
        printf("Candidate not found!\n");
        return;
    }
    if(voters[voterIndex].hasVoted) {
        printf("You have already voted!\n");
        return;
    }

    voters[voterIndex].hasVoted = 1;
    candidates[candidateIndex].votes++;
    printf("%s has voted for %s.\n", voterName, candidateName);
}

void displayResults() {
    printf("\nElection Results:\n");
    for(int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    
    while (1) {
        printf("\nElectronic Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter candidate name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                addCandidate(name);
                break;
            case 2:
                printf("Enter voter name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                registerVoter(name);
                break;
            case 3:
                printf("Enter your name: ");
                char voterName[MAX_NAME_LENGTH];
                fgets(voterName, MAX_NAME_LENGTH, stdin);
                voterName[strcspn(voterName, "\n")] = 0; // Remove newline character
                printf("Enter candidate name to vote: ");
                char candidateName[MAX_NAME_LENGTH];
                fgets(candidateName, MAX_NAME_LENGTH, stdin);
                candidateName[strcspn(candidateName, "\n")] = 0; // Remove newline character
                castVote(voterName, candidateName);
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}