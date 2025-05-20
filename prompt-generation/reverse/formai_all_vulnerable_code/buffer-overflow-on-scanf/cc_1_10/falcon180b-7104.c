//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_VOTER_NAME_LENGTH 50
#define MAX_CANDIDATE_NAME_LENGTH 50

typedef struct {
    char name[MAX_CANDIDATE_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_VOTER_NAME_LENGTH];
    int voterID;
} Voter;

int main() {
    char choice;
    int numCandidates, numVoters;

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the number of candidates: ");
    scanf("%d", &numCandidates);
    printf("Please enter the number of voters: ");
    scanf("%d", &numVoters);

    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    int i;
    for (i = 0; i < numCandidates; i++) {
        printf("Please enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    for (i = 0; i < numVoters; i++) {
        printf("Please enter the name of voter %d: ", i+1);
        scanf("%s", voters[i].name);
        voters[i].voterID = i+1;
    }

    printf("Please enter your voter ID: ");
    scanf("%d", &choice);

    int voterID = -1;
    for (i = 0; i < numVoters; i++) {
        if (voters[i].voterID == choice) {
            voterID = i;
            break;
        }
    }

    if (voterID == -1) {
        printf("Invalid voter ID!\n");
        return 0;
    }

    printf("Please enter the ID of the candidate you want to vote for: ");
    scanf("%d", &choice);

    int candidateID = -1;
    for (i = 0; i < numCandidates; i++) {
        if (candidates[i].name[0] == choice) {
            candidateID = i;
            break;
        }
    }

    if (candidateID == -1) {
        printf("Invalid candidate ID!\n");
        return 0;
    }

    candidates[candidateID].votes++;

    printf("Thank you for voting!\n");
    return 0;
}