//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

typedef struct {
    char name[50];
    int age;
    char gender[10];
} Voter;

typedef struct {
    char name[50];
    int votes;
} Candidate;

void addCandidate(Candidate candidates[], int *numCandidates, char name[]) {
    if (*numCandidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }

    strcpy(candidates[*numCandidates].name, name);
    candidates[*numCandidates].votes = 0;
    (*numCandidates)++;
}

void addVoter(Voter voters[], int *numVoters, char name[], int age, char gender[]) {
    if (*numVoters >= MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
        return;
    }

    strcpy(voters[*numVoters].name, name);
    voters[*numVoters].age = age;
    strcpy(voters[*numVoters].gender, gender);
    (*numVoters)++;
}

int main() {
    int numCandidates, numVoters;
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    numCandidates = 0;
    numVoters = 0;

    addCandidate(candidates, &numCandidates, "John Doe");
    addCandidate(candidates, &numCandidates, "Jane Doe");

    addVoter(voters, &numVoters, "Alice", 25, "Female");
    addVoter(voters, &numVoters, "Bob", 30, "Male");

    int i, j, choice;

    printf("Welcome to the electronic voting system!\n");
    printf("Please select a candidate to vote for:\n");

    for (i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    scanf("%d", &choice);

    if (choice < 1 || choice > numCandidates) {
        printf("Invalid choice.\n");
        return 1;
    }

    candidates[choice - 1].votes++;

    printf("Thank you for voting!\n");

    return 0;
}