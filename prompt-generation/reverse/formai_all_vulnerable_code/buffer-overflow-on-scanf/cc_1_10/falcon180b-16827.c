//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: energetic
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
    int voterID;
    int voted;
} Voter;

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int numCandidates, numVoters;
    char choice;

    // Read in the number of candidates
    printf("Enter the number of candidates (1-10): ");
    scanf("%d", &numCandidates);

    // Read in the candidate names and store them in the candidates array
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter candidate name %d: ", i+1);
        scanf("%s", candidates[i].name);
    }

    // Read in the number of voters
    printf("Enter the number of voters (1-100): ");
    scanf("%d", &numVoters);

    // Read in the voter names and store them in the voters array
    for (int i = 0; i < numVoters; i++) {
        printf("Enter voter name %d: ", i+1);
        scanf("%s", voters[i].name);
        voters[i].voterID = i+1;
        voters[i].voted = 0;
    }

    // Start the voting process
    printf("\nVoting has started!\n");
    for (int i = 0; i < numVoters; i++) {
        printf("Voter %d, please enter your vote: ", i+1);
        scanf(" %c", &choice);

        // Find the candidate with the matching name and increment their vote count
        for (int j = 0; j < numCandidates; j++) {
            if (strcmp(candidates[j].name, choice) == 0) {
                candidates[j].votes++;
                voters[i].voted = 1;
                break;
            }
        }
    }

    // Print the voting results
    printf("\nVoting has ended!\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("Candidate %s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}