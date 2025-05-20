//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a voter
typedef struct {
    char name[100];
    int age;
} Voter;

// Define a structure to represent a candidate
typedef struct {
    char name[100];
    int votes;
} Candidate;

// Function to initialize the voter structure
void initializeVoter(Voter *voter) {
    voter->name[0] = '\0';
    voter->age = 0;
}

// Function to initialize the candidate structure
void initializeCandidate(Candidate *candidate) {
    candidate->name[0] = '\0';
    candidate->votes = 0;
}

// Function to add a voter to the system
void addVoter(Voter *voters, int numVoters, char *name, int age) {
    voters[numVoters].name[0] = '\0';
    voters[numVoters].age = age;
}

// Function to add a candidate to the system
void addCandidate(Candidate *candidates, int numCandidates, char *name, int votes) {
    candidates[numCandidates].name[0] = '\0';
    candidates[numCandidates].votes = votes;
}

// Function to cast a vote for a candidate
void castVote(Voter *voters, Candidate *candidates, int numVoters, int numCandidates, char *name, int index) {
    int i;
    for (i = 0; i < numVoters; i++) {
        if (strcmp(voters[i].name, name) == 0) {
            voters[i].age++;
            candidates[index].votes++;
            break;
        }
    }
}

// Function to count the votes for each candidate
void countVotes(Candidate *candidates, int numCandidates) {
    int i;
    for (i = 0; i < numCandidates; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    // Initialize the voter structure
    Voter voters[100];
    initializeVoter(voters);

    // Initialize the candidate structure
    Candidate candidates[100];
    initializeCandidate(candidates);

    // Add a voter to the system
    char name[100];
    int age;
    printf("Enter voter's name: ");
    scanf("%s", name);
    printf("Enter voter's age: ");
    scanf("%d", &age);
    addVoter(voters, 100, name, age);

    // Add a candidate to the system
    char candidateName[100];
    int candidateVotes;
    printf("Enter candidate's name: ");
    scanf("%s", candidateName);
    printf("Enter candidate's votes: ");
    scanf("%d", &candidateVotes);
    addCandidate(candidates, 100, candidateName, candidateVotes);

    // Cast a vote for a candidate
    char voterName[100];
    int voterIndex;
    printf("Enter voter's name: ");
    scanf("%s", voterName);
    printf("Enter voter's index (1-100): ");
    scanf("%d", &voterIndex);
    castVote(voters, candidates, 100, 100, voterName, voterIndex);

    // Count the votes for each candidate
    countVotes(candidates, 100);

    return 0;
}