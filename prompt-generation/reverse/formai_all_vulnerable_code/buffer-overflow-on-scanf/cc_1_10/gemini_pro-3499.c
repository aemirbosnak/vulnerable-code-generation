//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the data structures for the candidates and voters
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

typedef struct voter {
    char name[50];
    int voted;
} voter;

// Define the functions for the electronic voting system
void registerCandidate(candidate *candidates, int *numCandidates, char *name);
void registerVoter(voter *voters, int *numVoters, char *name);
void castVote(candidate *candidates, int numCandidates, voter *voters, int numVoters, char *name);
void countVotes(candidate *candidates, int numCandidates);
void printResults(candidate *candidates, int numCandidates);

// Main function
int main() {
    // Initialize the variables
    int numCandidates = 0;
    candidate candidates[MAX_CANDIDATES];
    int numVoters = 0;
    voter voters[MAX_VOTERS];
    char name[50];

    // Register the candidates
    printf("Enter the names of the candidates (press Enter to finish):\n");
    while (1) {
        scanf("%s", name);
        if (strlen(name) == 0) {
            break;
        }
        registerCandidate(candidates, &numCandidates, name);
    }

    // Register the voters
    printf("Enter the names of the voters (press Enter to finish):\n");
    while (1) {
        scanf("%s", name);
        if (strlen(name) == 0) {
            break;
        }
        registerVoter(voters, &numVoters, name);
    }

    // Cast the votes
    printf("Enter the names of the voters and their choices (press Enter to finish):\n");
    while (1) {
        scanf("%s %s", name, name);
        if (strlen(name) == 0) {
            break;
        }
        castVote(candidates, numCandidates, voters, numVoters, name);
    }

    // Count the votes
    countVotes(candidates, numCandidates);

    // Print the results
    printResults(candidates, numCandidates);

    return 0;
}

// Function to register a candidate
void registerCandidate(candidate *candidates, int *numCandidates, char *name) {
    strcpy(candidates[*numCandidates].name, name);
    candidates[*numCandidates].votes = 0;
    (*numCandidates)++;
}

// Function to register a voter
void registerVoter(voter *voters, int *numVoters, char *name) {
    strcpy(voters[*numVoters].name, name);
    voters[*numVoters].voted = 0;
    (*numVoters)++;
}

// Function to cast a vote
void castVote(candidate *candidates, int numCandidates, voter *voters, int numVoters, char *name) {
    int i;
    // Find the voter
    for (i = 0; i < numVoters; i++) {
        if (strcmp(voters[i].name, name) == 0) {
            // Check if the voter has already voted
            if (voters[i].voted == 1) {
                printf("Error: Voter %s has already voted.\n", name);
                return;
            }

            // Find the candidate
            for (int j = 0; j < numCandidates; j++) {
                if (strcmp(candidates[j].name, name) == 0) {
                    // Increment the candidate's vote count
                    candidates[j].votes++;

                    // Mark the voter as having voted
                    voters[i].voted = 1;

                    return;
                }
            }

            // If the candidate is not found, print an error message
            printf("Error: Candidate %s not found.\n", name);
            return;
        }
    }

    // If the voter is not found, print an error message
    printf("Error: Voter %s not found.\n", name);
}

// Function to count the votes
void countVotes(candidate *candidates, int numCandidates) {
    int i;
    for (i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Function to print the results
void printResults(candidate *candidates, int numCandidates) {
    int i, maxVotes = 0;
    int winnerIndex = -1;
    for (i = 0; i < numCandidates; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }

    printf("The winner is %s with %d votes.\n", candidates[winnerIndex].name, candidates[winnerIndex].votes);
}