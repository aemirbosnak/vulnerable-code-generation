//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define VOTER_ID_LENGTH 10

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char voterID[VOTER_ID_LENGTH + 1];
    int hasVoted; // 0 - not voted, 1 - voted
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter *voters;
int numVoters;

void initializeCandidates() {
    strcpy(candidates[0].name, "Cyborg Chief");
    strcpy(candidates[1].name, "Techno Wizard");
    strcpy(candidates[2].name, "Green Guardian");
    strcpy(candidates[3].name, "Quantum Queen");
    strcpy(candidates[4].name, "Data Defender");

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
    }
}

void createVoters(int num) {
    voters = (Voter *) malloc(num * sizeof(Voter));
    numVoters = num;

    for (int i = 0; i < num; i++) {
        snprintf(voters[i].voterID, VOTER_ID_LENGTH + 1, "VOTER%03d", i+1);
        voters[i].hasVoted = 0;
    }
}

void displayCandidates() {
    printf("Available Candidates:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

int castVote(int voterIndex) {
    if (voters[voterIndex].hasVoted) {
        printf("You have already voted!\n");
        return 0;
    }
    
    int choice;
    printf("Select your candidate (1-%d): ", MAX_CANDIDATES);
    scanf("%d", &choice);

    if (choice < 1 || choice > MAX_CANDIDATES) {
        printf("Invalid choice! Please vote again.\n");
        return 0;
    }

    candidates[choice - 1].votes++;
    voters[voterIndex].hasVoted = 1;
    printf("Thank you for voting for %s!\n", candidates[choice - 1].name);
    return 1;
}

void displayResults() {
    printf("Voting Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void freeMemory() {
    free(voters);
}

int main() {
    srand(time(NULL)); // seed the random number generator
    int totalVoters;

    printf("Welcome to the Futuristic Electronic Voting System!\n");
    printf("Enter the total number of voters: ");
    scanf("%d", &totalVoters);

    if (totalVoters <= 0) {
        printf("Invalid number of voters. Exiting...\n");
        return 1;
    }

    initializeCandidates();
    createVoters(totalVoters);

    for (int i = 0; i < totalVoters; i++) {
        printf("Voter ID: %s\n", voters[i].voterID);
        int voteStatus = castVote(i);
        if (voteStatus) {
            printf("Vote cast successfully!\n");
        }
    }

    displayResults();
    freeMemory();
    printf("Thank you for participating in the election! Farewell.\n");
    return 0;
}