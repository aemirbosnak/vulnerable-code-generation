//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

// Voter Struct
typedef struct Voter {
    char name[100];
    int age;
    int voted;
    int voteIndex;
} Voter;

// Candidate Struct
typedef struct Candidate {
    char name[100];
    char party[100];
    int votes;
} Candidate;

// Global Variables
Voter voters[MAX_VOTERS];
Candidate candidates[MAX_CANDIDATES];
int numVoters = 0, numCandidates = 0;

// Function to add a voter
void addVoter() {
    if (numVoters == MAX_VOTERS) {
        printf("\nMax voters reached!\n");
        return;
    }
    Voter voter;
    printf("\nEnter voter name: ");
    scanf("%s", voter.name);
    printf("Enter voter age: ");
    scanf("%d", &voter.age);
    voter.voted = 0;
    voters[numVoters++] = voter;
    printf("\nVoter %s added successfully.\n", voter.name);
}

// Function to add a candidate
void addCandidate() {
    if (numCandidates == MAX_CANDIDATES) {
        printf("\nMax candidates reached!\n");
        return;
    }
    Candidate candidate;
    printf("\nEnter candidate name: ");
    scanf("%s", candidate.name);
    printf("Enter candidate party: ");
    scanf("%s", candidate.party);
    candidate.votes = 0;
    candidates[numCandidates++] = candidate;
    printf("\nCandidate %s added successfully.\n", candidate.name);
}

// Function to display list of voters
void displayVoters() {
    if (numVoters == 0) {
        printf("\nNo voters added yet.\n");
        return;
    }
    printf("\nList of Voters:\n");
    printf("---------------\n");
    printf("Name\tAge\tVoted\tVoteIndex\n");
    printf("---------------\n");
    for (int i = 0; i < numVoters; i++) {
        printf("%s\t%d\t%d\t%d\n", voters[i].name, voters[i].age, voters[i].voted, voters[i].voteIndex);
    }
    printf("---------------\n");
}

// Function to display list of candidates
void displayCandidates() {
    if (numCandidates == 0) {
        printf("\nNo candidates added yet.\n");
        return;
    }
    printf("\nList of Candidates:\n");
    printf("-------------------\n");
    printf("Name\tParty\tVotes\n");
    printf("-------------------\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s\t%s\t%d\n", candidates[i].name, candidates[i].party, candidates[i].votes);
    }
    printf("-------------------\n");
}

// Function to vote
void vote() {
    if (numVoters == 0) {
        printf("\nNo voters added yet.\n");
        return;
    } else if (numCandidates == 0) {
        printf("\nNo candidates added yet.\n");
        return;
    }
    char voterName[100], candidateName[100];
    int index = 0, voteIndex = 0;
    printf("\nEnter voter name: ");
    scanf("%s", voterName);
    for (int i = 0; i < numVoters; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            if (voters[i].voted == 1) {
                printf("\nThis voter has already voted.\n");
                return;
            }
            index = i;
            break;
        }
    }
    printf("Enter candidate name: ");
    scanf("%s", candidateName);
    for (int i = 0; i < numCandidates; i++) {
        if (strcmp(candidates[i].name, candidateName) == 0) {
            voteIndex = i;
            break;
        }
    }
    voters[index].voted = 1;
    voters[index].voteIndex = voteIndex;
    candidates[voteIndex].votes++;
    printf("\nVote casted successfully.\n");
}

// Function to print election result
void printResult() {
    if (numVoters == 0) {
        printf("\nNo voters added yet.\n");
        return;
    } else if (numCandidates == 0) {
        printf("\nNo candidates added yet.\n");
        return;
    }
    printf("\nElection Result:\n");
    printf("-----------------\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].votes);
    }
    printf("-----------------\n");
}

int main() {
    int option = 0;
    while (1) {
        printf("\nElectronic Voting System:\n\n");
        printf("1. Add Voter\n");
        printf("2. Add Candidate\n");
        printf("3. Display List of Voters\n");
        printf("4. Display List of Candidates\n");
        printf("5. Cast Vote\n");
        printf("6. Print Election Result\n");
        printf("7. Exit\n\n");
        printf("Enter Option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                addVoter();
                break;
            case 2:
                addCandidate();
                break;
            case 3:
                displayVoters();
                break;
            case 4:
                displayCandidates();
                break;
            case 5:
                vote();
                break;
            case 6:
                printResult();
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid Option!\n");
        }
    }
    return 0;
}