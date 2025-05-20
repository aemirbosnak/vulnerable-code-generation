//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char voterID[NAME_LENGTH];
    int hasVoted;
} Voter;

// Function prototypes
void displayCandidates(Candidate candidates[], int candidateCount);
void castVote(Voter voters[], Candidate candidates[], int voterCount, int candidateCount);

int main() {
    int candidateCount, voterCount;
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    // Initialize candidates
    printf("Enter the number of candidates (Max: %d): ", MAX_CANDIDATES);
    scanf("%d", &candidateCount);
    if (candidateCount > MAX_CANDIDATES || candidateCount <= 0) {
        printf("Invalid number of candidates, exiting!\n");
        return 1;
    }

    for (int i = 0; i < candidateCount; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0; // initialize votes to zero
    }

    // Initialize voters
    printf("Enter the number of voters (Max: %d): ", MAX_VOTERS);
    scanf("%d", &voterCount);
    if (voterCount > MAX_VOTERS || voterCount <= 0) {
        printf("Invalid number of voters, exiting!\n");
        return 1;
    }

    for (int i = 0; i < voterCount; i++) {
        printf("Enter voter ID for voter %d: ", i + 1);
        scanf("%s", voters[i].voterID);
        voters[i].hasVoted = 0; // Voter has not voted yet
    }

    // Cast votes
    castVote(voters, candidates, voterCount, candidateCount);

    // Display results
    printf("\nElection Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("Candidate %s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}

void displayCandidates(Candidate candidates[], int candidateCount) {
    printf("Available Candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void castVote(Voter voters[], Candidate candidates[], int voterCount, int candidateCount) {
    for (int i = 0; i < voterCount; i++) {
        if (voters[i].hasVoted == 0) {
            int choice;

            displayCandidates(candidates, candidateCount);
            printf("Voter %s, please cast your vote (enter candidate number): ", voters[i].voterID);
            scanf("%d", &choice);

            if (choice > 0 && choice <= candidateCount) {
                candidates[choice - 1].votes++;
                voters[i].hasVoted = 1; // Mark as voted
                printf("Thank you, %s! Your vote for %s has been cast.\n", voters[i].voterID, candidates[choice - 1].name);
            } else {
                printf("Invalid choice, please try again.\n");
            }
        } else {
            printf("Voter %s has already voted.\n", voters[i].voterID);
        }
    }
}