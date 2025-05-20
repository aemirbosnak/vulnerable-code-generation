//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Claude Shannon
//Claude Shannon's Electronic Voting System
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// global variables
int candidateCount;

// define candidate structure
struct Candidate {
  char name[20];
  int votes;
};

// function to initialize candidates
void initializeCandidates(struct Candidate candidates[]) {
    for(int i = 0; i < candidateCount; i++) {
        printf("Enter name for candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

// function to print candidate details
void printCandidates(struct Candidate candidates[]) {
    printf("List of candidates:\n");
    for(int i = 0; i < candidateCount; i++) {
        printf("%d. %s - %d votes\n", i+1, candidates[i].name, candidates[i].votes);
    }
}

// function to cast vote
void castVote(struct Candidate candidates[], int choice) {
    candidates[choice-1].votes++;
    printf("\nYou have successfully cast your vote for %s!\n", candidates[choice-1].name);
}

// main function
int main() {
    printf("Welcome to Claude Shannon's Electronic Voting System!\n");

    printf("Enter number of candidates: ");
    scanf("%d", &candidateCount);

    struct Candidate candidates[candidateCount];

    // initialize candidates
    initializeCandidates(candidates);

    // print candidate details
    printCandidates(candidates);

    int choice;
    printf("Enter candidate number to cast your vote: ");
    scanf("%d", &choice);

    // cast vote
    castVote(candidates, choice);

    // print candidate details after vote is casted
    printf("\nUpdated candidate details:\n");
    printCandidates(candidates);

    return 0;
}