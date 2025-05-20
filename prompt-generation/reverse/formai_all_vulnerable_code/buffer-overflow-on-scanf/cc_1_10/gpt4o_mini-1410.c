//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char voterId[20];
    int vote; // -1 indicates no vote.
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int num_candidates = 0;
int num_voters = 0;

// Function to add a candidate
void addCandidate(char* name) {
    if (num_candidates < MAX_CANDIDATES) {
        strcpy(candidates[num_candidates].name, name);
        candidates[num_candidates].votes = 0;
        num_candidates++;
    } else {
        printf("Maximum number of candidates reached!\n");
    }
}

// Function to register a voter
void registerVoter(char* voterId) {
    if (num_voters < MAX_VOTERS) {
        strcpy(voters[num_voters].voterId, voterId);
        voters[num_voters].vote = -1; // No vote initially
        num_voters++;
    } else {
        printf("Maximum number of voters reached!\n");
    }
}

// Function to cast a vote
void castVote(char* voterId, int candidateIndex) {
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(voters[i].voterId, voterId) == 0) {
            if (voters[i].vote == -1) {
                voters[i].vote = candidateIndex;
                candidates[candidateIndex].votes++;
                printf("Vote casted for %s\n", candidates[candidateIndex].name);
            } else {
                printf("You have already voted!\n");
            }
            return;
        }
    }
    printf("Voter ID not found!\n");
}

// Function to display the results
void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    char command[50];

    // Adding candidates
    addCandidate("Alice");
    addCandidate("Bob");
    addCandidate("Charlie");

    // Registering voters
    registerVoter("Voter1");
    registerVoter("Voter2");
    registerVoter("Voter3");

    // Voting process
    while (1) {
        printf("\nEnter command (vote, results, exit): ");
        scanf("%s", command);

        if (strcmp(command, "vote") == 0) {
            char voterId[20];
            int candidateIndex;

            printf("Enter your Voter ID: ");
            scanf("%s", voterId);
            printf("Enter candidate index (0 - %d): ", num_candidates - 1);
            scanf("%d", &candidateIndex);

            if (candidateIndex >= 0 && candidateIndex < num_candidates) {
                castVote(voterId, candidateIndex);
            } else {
                printf("Invalid candidate index!\n");
            }

        } else if (strcmp(command, "results") == 0) {
            displayResults();
            
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the voting system.\n");
            break;

        } else {
            printf("Invalid command! Please try again.\n");
        }
    }

    return 0;
}