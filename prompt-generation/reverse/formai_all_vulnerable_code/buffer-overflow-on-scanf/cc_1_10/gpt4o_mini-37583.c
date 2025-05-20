//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

// Structure to store candidate details
typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

// Structure to store voter details
typedef struct {
    int id;
    int hasVoted;
} Voter;

// Function declarations
void initializeCandidates(Candidate candidates[], int candidateCount);
void displayCandidates(Candidate candidates[], int candidateCount);
void castVote(Candidate candidates[], int candidateCount, Voter voters[], int voterCount);
void displayResults(Candidate candidates[], int candidateCount);

int main() {
    int candidateCount, voterCount;
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    // Seed random number generator
    srand(time(0));

    // Initialize candidates
    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &candidateCount);
    getchar(); // Consume newline character
    initializeCandidates(candidates, candidateCount);

    // Initialize voters
    printf("Enter the number of voters (max %d): ", MAX_VOTERS);
    scanf("%d", &voterCount);
    for (int i = 0; i < voterCount; i++) {
        voters[i].id = i + 1;
        voters[i].hasVoted = 0; // No voter has voted yet
    }

    // Voting process
    char continueVoting = 'y';
    while (continueVoting == 'y' && voterCount > 0) {
        displayCandidates(candidates, candidateCount);
        castVote(candidates, candidateCount, voters, voterCount);
        
        printf("Do you want to continue voting? (y/n): ");
        scanf(" %c", &continueVoting);
    }

    // Display results
    displayResults(candidates, candidateCount);

    return 0;
}

void initializeCandidates(Candidate candidates[], int candidateCount) {
    for (int i = 0; i < candidateCount; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        fgets(candidates[i].name, MAX_NAME_LENGTH, stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = '\0'; // Remove newline
        candidates[i].votes = 0; // Initialize votes to 0
    }
}

void displayCandidates(Candidate candidates[], int candidateCount) {
    printf("\nAvailable Candidates for Voting:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void castVote(Candidate candidates[], int candidateCount, Voter voters[], int voterCount) {
    int voterId;
    int candidateId;

    // Prompt for voter ID
    printf("Enter your voter ID (1-%d): ", voterCount);
    scanf("%d", &voterId);

    if (voterId < 1 || voterId > voterCount || voters[voterId - 1].hasVoted == 1) {
        printf("Invalid voter ID or voter has already voted!\n");
        return;
    }

    // Prompt for candidate choice
    printf("Select a candidate ID to vote for (1-%d): ", candidateCount);
    scanf("%d", &candidateId);

    if (candidateId < 1 || candidateId > candidateCount) {
        printf("Invalid candidate ID!\n");
        return;
    }

    // Cast the vote
    candidates[candidateId - 1].votes++;
    voters[voterId - 1].hasVoted = 1; // Mark voter as having voted
    printf("Vote casted successfully for %s!\n", candidates[candidateId - 1].name);
}

void displayResults(Candidate candidates[], int candidateCount) {
    printf("\nVoting Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Determine the winner
    int maxVotes = -1;
    char winner[MAX_NAME_LENGTH];
    for (int i = 0; i < candidateCount; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            strcpy(winner, candidates[i].name);
        }
    }
    printf("The winner is: %s with %d votes!\n", winner, maxVotes);
}