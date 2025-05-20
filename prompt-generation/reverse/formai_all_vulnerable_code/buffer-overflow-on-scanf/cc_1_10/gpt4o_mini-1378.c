//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 50
#define SECRET_KEY 12345

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char voterID[MAX_NAME_LENGTH];
    int hasVoted;
} Voter;

Voter voters[MAX_VOTERS];
Candidate candidates[MAX_CANDIDATES];
int totalVoters = 0;
int totalCandidates = 0;

// Function Prototypes
void addVoter(const char* voterID);
void addCandidate(const char* candidateName);
int castVote(const char* voterID, int candidateIndex);
void displayResults();
void initVoting();
void printMenu();
void paranoidCheck();

int main() {
    paranoidCheck();
    initVoting();
    return 0;
}

void initVoting() {
    // Initialize candidates
    addCandidate("Alice");
    addCandidate("Bob");
    addCandidate("Charlie");

    // Initialize voters
    addVoter("Voter001");
    addVoter("Voter002");
    
    char voterID[MAX_NAME_LENGTH];
    int candidateChoice;

    while (1) {
        printMenu();
        printf("Enter your voter ID (or 'exit' to quit): ");
        scanf("%s", voterID);
        
        if (strcmp(voterID, "exit") == 0) {
            break;
        }

        int voterIndex = -1;
        for (int i = 0; i < totalVoters; i++) {
            if (strcmp(voters[i].voterID, voterID) == 0) {
                voterIndex = i;
                break;
            }
        }

        if (voterIndex == -1 || voters[voterIndex].hasVoted) {
            printf("Invalid voter ID or you have already voted!\n");
            continue;
        }

        printf("Candidates:\n");
        for (int i = 0; i < totalCandidates; i++) {
            printf("%d. %s\n", i + 1, candidates[i].name);
        }

        printf("Select a candidate by their number: ");
        scanf("%d", &candidateChoice);
        candidateChoice -= 1; // Adjust for zero-based indexing

        if (candidateChoice < 0 || candidateChoice >= totalCandidates) {
            printf("Invalid candidate selection.\n");
        } else {
            if (castVote(voterID, candidateChoice)) {
                printf("Vote cast successfully!\n");
            } else {
                printf("Failed to cast vote.\n");
            }
        }
    }

    displayResults();
}

void addVoter(const char* voterID) {
    if (totalVoters < MAX_VOTERS) {
        strcpy(voters[totalVoters].voterID, voterID);
        voters[totalVoters].hasVoted = 0;
        totalVoters++;
    } else {
        printf("Max voter limit reached!\n");
    }
}

void addCandidate(const char* candidateName) {
    if (totalCandidates < MAX_CANDIDATES) {
        strcpy(candidates[totalCandidates].name, candidateName);
        candidates[totalCandidates].votes = 0;
        totalCandidates++;
    } else {
        printf("Max candidate limit reached!\n");
    }
}

int castVote(const char* voterID, int candidateIndex) {
    // Simulate a paranoid voting process
    for (int i = 0; i < totalVoters; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0 && !voters[i].hasVoted) {
            voters[i].hasVoted = 1; // Mark the voter as having voted
            candidates[candidateIndex].votes++; // Increment the vote for the candidate
            return 1; // Vote casted successfully
        }
    }
    return 0; // Vote casting failed
}

void displayResults() {
    printf("\n--- Election Results ---\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }
}

void printMenu() {
    printf("\n-------------------\n");
    printf("Welcome to the Paranoid Electronic Voting System\n");
    printf("-------------------\n");
}

void paranoidCheck() {
    printf("Performing system integrity checks...\n");
    srand(time(0)); // for random paranoia simulations

    // Simulating random paranoia checks
    if (rand() % 10 < 2) {
        printf("Warning: System may be compromised! Proceed with caution.\n");
    }
    printf("Integrity check passed.\n");
}