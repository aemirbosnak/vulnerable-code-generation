//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[100];
    int vote;
} Voter;

typedef struct {
    char name[100];
    int votes;
} Candidate;

void addCandidate(Candidate *candidates, int numCandidates, char *name) {
    int i;
    for(i = 0; i < numCandidates; i++) {
        if(strcmp(candidates[i].name, name) == 0) {
            candidates[i].votes++;
            return;
        }
    }
    strcpy(candidates[numCandidates].name, name);
    candidates[numCandidates].votes = 1;
    numCandidates++;
}

void addVoter(Voter *voters, int numVoters, char *name, int vote) {
    int i;
    for(i = 0; i < numVoters; i++) {
        if(strcmp(voters[i].name, name) == 0) {
            voters[i].vote = vote;
            return;
        }
    }
    strcpy(voters[numVoters].name, name);
    voters[numVoters].vote = vote;
    numVoters++;
}

void printCandidates(Candidate *candidates, int numCandidates) {
    int i;
    for(i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void printVoters(Voter *voters, int numVoters) {
    int i;
    for(i = 0; i < numVoters; i++) {
        printf("%s voted for %d\n", voters[i].name, voters[i].vote);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int numCandidates = 0, numVoters = 0;
    char name[100];
    int vote, i;

    printf("Enter the name of a candidate: ");
    scanf("%s", name);
    addCandidate(candidates, numCandidates, name);

    while(1) {
        printf("Enter the name of a voter: ");
        scanf("%s", name);

        printf("Did %s vote for candidate 1? (y/n): ", name);
        scanf(" %c", &vote);
        if(vote == 'y' || vote == 'Y') {
            addVoter(voters, numVoters, name, 1);
        }

        printf("Did %s vote for candidate 2? (y/n): ", name);
        scanf(" %c", &vote);
        if(vote == 'y' || vote == 'Y') {
            addVoter(voters, numVoters, name, 2);
        }

        printf("Did %s vote for candidate 3? (y/n): ", name);
        scanf(" %c", &vote);
        if(vote == 'y' || vote == 'Y') {
            addVoter(voters, numVoters, name, 3);
        }

        printf("Enter 'done' to finish adding voters: ");
        scanf("%s", name);
        if(strcmp(name, "done") == 0) {
            break;
        }
    }

    printf("Candidate results:\n");
    printCandidates(candidates, numCandidates);

    printf("\nVoter results:\n");
    printVoters(voters, numVoters);

    return 0;
}