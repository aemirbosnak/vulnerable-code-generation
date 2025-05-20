//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

struct Candidate {
    char name[50];
    int votes;
};

struct Voter {
    char id[10];
    int hasVoted;
};

struct Candidate candidates[MAX_CANDIDATES];
struct Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void initialize() {
    printf("Initializing Electronic Voting System...\n");
}

void addCandidate(char *name) {
    if (candidateCount < MAX_CANDIDATES) {
        strncpy(candidates[candidateCount].name, name, sizeof(candidates[candidateCount].name));
        candidates[candidateCount].votes = 0;
        candidateCount++;
        printf("Candidate '%s' added successfully!\n", name);
    } else {
        printf("Cannot add more candidates. Maximum limit reached.\n");
    }
}

void addVoter(char *id) {
    if (voterCount < MAX_VOTERS) {
        strncpy(voters[voterCount].id, id, sizeof(voters[voterCount].id));
        voters[voterCount].hasVoted = 0;
        voterCount++;
        printf("Voter with ID '%s' added successfully!\n", id);
    } else {
        printf("Cannot add more voters. Maximum limit reached.\n");
    }
}

int findVoter(char *id) {
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

int findCandidate(char *name) {
    for (int i = 0; i < candidateCount; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void castVote(char *voterId, char *candidateName) {
    int voterIndex = findVoter(voterId);
    int candidateIndex = findCandidate(candidateName);

    if (voterIndex == -1) {
        printf("Voter ID '%s' not found!\n", voterId);
        return;
    }
    if (candidateIndex == -1) {
        printf("Candidate '%s' not found!\n", candidateName);
        return;
    }
    if (voters[voterIndex].hasVoted) {
        printf("Voter ID '%s' has already voted!\n", voterId);
        return;
    }

    candidates[candidateIndex].votes++;
    voters[voterIndex].hasVoted = 1;

    printf("Vote cast successfully for '%s' by Voter ID '%s'.\n", candidateName, voterId);
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("Candidate: %s, Votes: %d\n", candidates[i].name, candidates[i].votes);
    }
}

void displayMenu() {
    printf("\n=== Electronic Voting System ===\n");
    printf("1. Add Candidate\n");
    printf("2. Add Voter\n");
    printf("3. Cast Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    initialize();
    
    int choice;
    char name[50];
    char id[10];
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", name);
                addCandidate(name);
                break;
            case 2:
                printf("Enter voter ID: ");
                scanf("%s", id);
                addVoter(id);
                break;
            case 3:
                printf("Enter voter ID: ");
                scanf("%s", id);
                printf("Enter candidate name: ");
                scanf("%s", name);
                castVote(id, name);
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting system...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    
    return 0;
}