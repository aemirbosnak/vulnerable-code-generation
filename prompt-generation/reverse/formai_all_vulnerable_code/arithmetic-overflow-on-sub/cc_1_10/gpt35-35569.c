//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 20

typedef struct {
    char name[30];
    int votes;
} candidate_t;

typedef struct {
    char name[30];
    int voted;
    int voteIndex;
} voter_t;

int numCandidates;
candidate_t candidates[MAX_CANDIDATES];
int numVoters;
voter_t voters[MAX_VOTERS];

void getCandidates() {
    printf("Enter number of candidates: ");
    scanf("%d", &numCandidates);
    getchar(); // get rid of newline character
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter candidate %d name: ", i+1);
        fgets(candidates[i].name, 30, stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = 0; // get rid of newline character
        candidates[i].votes = 0;
    }
}

void getVoters() {
    printf("Enter number of voters: ");
    scanf("%d", &numVoters);
    getchar(); // get rid of newline character
    for (int i = 0; i < numVoters; i++) {
        printf("Enter voter %d name: ", i+1);
        fgets(voters[i].name, 30, stdin);
        voters[i].name[strcspn(voters[i].name, "\n")] = 0; // get rid of newline character
        voters[i].voted = 0;
        voters[i].voteIndex = -1;
    }
}

void castVote(int voterIndex) {
    int candidateIndex;
    printf("Enter candidate number to vote for: ");
    scanf("%d", &candidateIndex);
    candidateIndex--; // adjust for 0-based indexing
    if (candidateIndex < numCandidates) {
        if (voters[voterIndex].voted == 0) {
            candidates[candidateIndex].votes++;
            voters[voterIndex].voted = 1;
            voters[voterIndex].voteIndex = candidateIndex;
            printf("%s voted for %s.\n", voters[voterIndex].name, candidates[candidateIndex].name);
        } else {
            printf("%s has already voted.\n", voters[voterIndex].name);
        }
    } else {
        printf("Invalid candidate number.\n");
    }
}

void printResults() {
    printf("Candidate Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s - %d votes\n", i+1, candidates[i].name, candidates[i].votes);
    }
    printf("Voter Results:\n");
    for (int i = 0; i < numVoters; i++) {
        if (voters[i].voted) {
            printf("%s voted for %s.\n", voters[i].name, candidates[voters[i].voteIndex].name);
        } else {
            printf("%s has not voted.\n", voters[i].name);
        }
    }
}

int main() {
    getCandidates();
    getVoters();
    printf("Electronic Voting System initialized.\n");
    while (1) {
        printf("Options:\n1. Cast Vote\n2. Print Results\n3. Quit\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter voter number to cast vote: ");
            int voterIndex;
            scanf("%d", &voterIndex);
            voterIndex--; // adjust for 0-based indexing
            if (voterIndex < numVoters) {
                castVote(voterIndex);
            } else {
                printf("Invalid voter number.\n");
            }
        } else if (choice == 2) {
            printResults();
        } else if (choice == 3) {
            printf("Exiting Electronic Voting System.\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}