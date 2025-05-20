//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: interoperable
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
} Voter;

int main() {
    int numCandidates, numVoters;
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);

    // Initialize candidates
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter candidate %d's name: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Initialize voters
    for (int i = 0; i < numVoters; i++) {
        printf("Enter voter %d's name: ", i + 1);
        scanf("%s", voters[i].name);
        voters[i].voterID = i + 1;
    }

    // Voting process
    int choice;
    printf("\nVoting has started.\n");
    for (int i = 0; i < numVoters; i++) {
        printf("Voter %d is voting.\n", voters[i].voterID);
        for (int j = 0; j < numCandidates; j++) {
            printf("Candidate %d: %s\n", j + 1, candidates[j].name);
        }
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= numCandidates) {
            candidates[choice - 1].votes++;
        } else {
            printf("Invalid choice.\n");
        }
    }

    // Display results
    printf("\nVoting has ended.\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("Candidate %d: %s (%d votes)\n", i + 1, candidates[i].name, candidates[i].votes);
    }

    return 0;
}