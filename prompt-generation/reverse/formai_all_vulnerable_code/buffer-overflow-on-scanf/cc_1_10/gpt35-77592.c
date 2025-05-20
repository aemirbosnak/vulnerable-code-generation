//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for a voter
struct Voter {
    char name[50];
    unsigned int age;
    char id[10];
    int hasVoted;
};

// function to register a voter
void registerVoter(struct Voter *v) {
    printf("Enter your name: ");
    scanf("%s", v->name);
    printf("Enter your age: ");
    scanf("%u", &v->age);
    printf("Enter your ID: ");
    scanf("%s", v->id);
    v->hasVoted = 0;
    printf("\nRegistration successful!\n\n");
}

// function to validate a voter
int validateVoter(struct Voter *v, char *id) {
    if(strcmp(v->id, id) == 0) {
        return 1;
    }
    return 0;
}

// function to cast vote
void castVote(struct Voter *v, int *votes, int numCandidates) {
    if(v->hasVoted == 1) {
        printf("Sorry, you have already cast your vote.\n\n");
        return;
    }
    printf("Choose a candidate:\n");
    for(int i = 0; i < numCandidates; i++) {
        printf("%d. Candidate %d\n", i+1, i+1);
    }
    int choice;
    scanf("%d", &choice);
    if(choice > 0 && choice <= numCandidates) {
        v->hasVoted = 1;
        votes[choice-1]++;
        printf("\nThank you for voting!\n\n");
    } else {
        printf("\nInvalid choice.\n\n");
    }
}

// function to display results
void displayResults(int *votes, int numCandidates) {
    printf("Results:\n");
    for(int i = 0; i < numCandidates; i++) {
        printf("Candidate %d: %d votes\n", i+1, votes[i]);
    }
}

// main function
int main() {
    int numVoters;
    int numCandidates;

    printf("Welcome to the Electronic Voting System!\n");
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    struct Voter voters[numVoters];
    int votes[numCandidates];

    for(int i = 0; i < numVoters; i++) {
        printf("Registering voter %d:\n", i+1);
        registerVoter(&voters[i]);
    }

    while(1) {
        printf("Enter your ID to validate or enter 0 to exit: ");
        char id[10];
        scanf("%s", id);
        if(strcmp(id, "0") == 0) {
            break;
        }
        int voterIndex = -1;
        for(int i = 0; i < numVoters; i++) {
            if(validateVoter(&voters[i], id) == 1) {
                voterIndex = i;
                break;
            }
        }
        if(voterIndex == -1) {
            printf("Invalid ID.\n\n");
        } else {
            castVote(&voters[voterIndex], votes, numCandidates);
        }
    }

    displayResults(votes, numCandidates);

    return 0;
}