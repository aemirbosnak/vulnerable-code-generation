//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: Donald Knuth
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
    int voted;  // 1 if voted, 0 if not
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void registerCandidate();
void registerVoter();
void castVote();
void displayResults();
int findVoterIndex(const char *name);
int findCandidateIndex(const char *name);

int main() {
    int choice;

    do {
        printf("\n=== Electronic Voting System ===\n");
        printf("1. Register Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                registerCandidate();
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
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void registerCandidate() {
    if(candidateCount < MAX_CANDIDATES) {
        printf("Enter candidate name: ");
        fgets(candidates[candidateCount].name, sizeof(candidates[candidateCount].name), stdin);
        candidates[candidateCount].name[strcspn(candidates[candidateCount].name, "\n")] = 0; // Remove newline
        candidates[candidateCount].votes = 0;
        candidateCount++;
        printf("Candidate %s registered successfully!\n", candidates[candidateCount - 1].name);
    } else {
        printf("Maximum candidates registered. Cannot register more.\n");
    }
}

void registerVoter() {
    if(voterCount < MAX_VOTERS) {
        printf("Enter voter name: ");
        fgets(voters[voterCount].name, sizeof(voters[voterCount].name), stdin);
        voters[voterCount].name[strcspn(voters[voterCount].name, "\n")] = 0; // Remove newline
        voters[voterCount].voted = 0;
        voterCount++;
        printf("Voter %s registered successfully!\n", voters[voterCount - 1].name);
    } else {
        printf("Maximum voters registered. Cannot register more.\n");
    }
}

void castVote() {
    char voterName[50], candidateName[50];
    printf("Enter your name: ");
    fgets(voterName, sizeof(voterName), stdin);
    voterName[strcspn(voterName, "\n")] = 0; // Remove newline

    int voterIndex = findVoterIndex(voterName);
    if(voterIndex == -1) {
        printf("Voter not registered.\n");
        return;
    } else if(voters[voterIndex].voted) {
        printf("You have already voted!\n");
        return;
    }

    printf("Available candidates:\n");
    for(int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    printf("Enter the name of the candidate you wish to vote for: ");
    fgets(candidateName, sizeof(candidateName), stdin);
    candidateName[strcspn(candidateName, "\n")] = 0; // Remove newline

    int candidateIndex = findCandidateIndex(candidateName);
    if(candidateIndex == -1) {
        printf("Candidate not found.\n");
        return;
    }

    candidates[candidateIndex].votes++;
    voters[voterIndex].voted = 1;
    printf("Vote cast successfully for %s!\n", candidates[candidateIndex].name);
}

void displayResults() {
    printf("\n=== Voting Results ===\n");
    for(int i = 0; i < candidateCount; i++) {
        printf("Candidate: %s, Votes: %d\n", candidates[i].name, candidates[i].votes);
    }
}

int findVoterIndex(const char *name) {
    for(int i = 0; i < voterCount; i++) {
        if(strcmp(voters[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Voter not found
}

int findCandidateIndex(const char *name) {
    for(int i = 0; i < candidateCount; i++) {
        if(strcmp(candidates[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Candidate not found
}