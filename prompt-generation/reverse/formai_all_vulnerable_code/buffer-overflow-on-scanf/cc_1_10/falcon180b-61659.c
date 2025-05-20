//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char name[50];
    int voterID;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];

void addCandidate(Candidate* c) {
    int i = 0;
    while (i < MAX_CANDIDATES && candidates[i].name[0]!= '\0') {
        i++;
    }
    strcpy(candidates[i].name, c->name);
    candidates[i].votes = 0;
}

void addVoter(Voter* v) {
    int i = 0;
    while (i < MAX_VOTERS && voters[i].name[0]!= '\0') {
        i++;
    }
    strcpy(voters[i].name, v->name);
    voters[i].voterID = i + 1;
}

void vote(int voterID, int candidateID) {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].name[0]!= '\0' && candidates[i].votes == candidateID) {
            candidates[i].votes++;
            break;
        }
    }
}

void displayResults() {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].name[0]!= '\0') {
            printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        }
    }
}

int main() {
    srand(time(NULL));

    int numCandidates, numVoters;
    printf("Enter number of candidates: ");
    scanf("%d", &numCandidates);

    for (int i = 0; i < numCandidates; i++) {
        Candidate c;
        printf("Enter candidate name: ");
        scanf("%s", c.name);
        addCandidate(&c);
    }

    printf("Enter number of voters: ");
    scanf("%d", &numVoters);

    for (int i = 0; i < numVoters; i++) {
        Voter v;
        printf("Enter voter name: ");
        scanf("%s", v.name);
        addVoter(&v);
    }

    int choice;
    while (1) {
        printf("\nChoose an option:\n1. Vote\n2. Display results\n3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter voter ID: ");
            scanf("%d", &choice);
            printf("Enter candidate ID: ");
            scanf("%d", &choice);
            vote(choice, choice);
        } else if (choice == 2) {
            displayResults();
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}