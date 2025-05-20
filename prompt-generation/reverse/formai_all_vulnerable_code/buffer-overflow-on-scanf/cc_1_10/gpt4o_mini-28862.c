//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 5

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char username[50];
    int hasVoted;
} Voter;

Voter voters[MAX_VOTERS];
Candidate candidates[MAX_CANDIDATES];
int voterCount = 0;
int candidateCount = 0;

void initializeCandidates() {
    strcpy(candidates[0].name, "Alpha");
    strcpy(candidates[1].name, "Beta");
    strcpy(candidates[2].name, "Gamma");
    strcpy(candidates[3].name, "Delta");
    strcpy(candidates[4].name, "Epsilon");

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
    }

    candidateCount = MAX_CANDIDATES;
}

void printCandidates() {
    printf("Available Candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

int authenticateVoter(char *username) {
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].username, username) == 0) {
            return i; // returning the index of the voter
        }
    }
    // New voter, register them
    strcpy(voters[voterCount].username, username);
    voters[voterCount].hasVoted = 0;
    return voterCount++; // returning the index of the new voter
}

void castVote(int voterIndex) {
    if (voters[voterIndex].hasVoted) {
        printf("You have already voted!\n");
        return;
    }

    int choice;
    printf("Enter candidate number to vote (1-%d): ", candidateCount);
    scanf("%d", &choice);

    if (choice < 1 || choice > candidateCount) {
        printf("Invalid choice. Vote not counted.\n");
    } else {
        candidates[choice - 1].votes++;
        voters[voterIndex].hasVoted = 1;
        printf("Vote successfully cast for %s!\n", candidates[choice - 1].name);
    }
}

void displayResults() {
    printf("Election Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void votingSession() {
    char username[50];
    
    printf("Welcome to the Futuristic Voting System!\n");
    printf("Please enter your username to proceed: ");
    scanf("%s", username);
    
    int voterIndex = authenticateVoter(username);
    printf("Hello, %s! Let's cast your vote.\n", username);
    
    printCandidates();
    
    castVote(voterIndex);
}

int main() {
    srand(time(NULL));
    initializeCandidates();
    votingSession();
    displayResults();
    
    return 0;
}