//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Structure to define candidate details
typedef struct Candidate {
    char candidateName[50];
    int votesReceived;
} Candidate;

// Structure to store voter details
typedef struct Voter {
    char voterName[50];
    int voterID;
    bool voted;
} Voter;

// Function to print out the list of candidates
void printCandidateList(Candidate candidateList[], int numCandidates) {
    printf("\nList of Candidates\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidateList[i].candidateName);
    }
}

// Function to print out the list of voters
void printVoterList(Voter voterList[], int numVoters) {
    printf("\nList of Voters\n");
    for (int i = 0; i < numVoters; i++) {
        printf("%d. %s\n", voterList[i].voterID, voterList[i].voterName);
    }
}

// Function to cast vote for a candidate
void castVote(Candidate candidateList[], int candidateID) {
    candidateList[candidateID - 1].votesReceived++;
}

int main() {

    // Variables to store the number of candidates and voters
    int numCandidates, numVoters;

    // Accept number of candidates from user
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    // Validate number of candidates
    while (numCandidates <= 0 || numCandidates > MAX_CANDIDATES) {
        printf("Invalid number of candidates. Please enter between 1 and %d: ", MAX_CANDIDATES);
        scanf("%d", &numCandidates);
    }

    // Accept candidate details from user
    Candidate candidateList[numCandidates];
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter candidate %d name: ", i + 1);
        scanf("%s", candidateList[i].candidateName);
        candidateList[i].votesReceived = 0;
    }

    // Accept number of voters from user
    printf("\nEnter the number of voters: ");
    scanf("%d", &numVoters);

    // Validate number of voters
    while (numVoters <= 0 || numVoters > MAX_VOTERS) {
        printf("Invalid number of voters. Please enter between 1 and %d: ", MAX_VOTERS);
        scanf("%d", &numVoters);
    }

    // Accept voter details from user
    Voter voterList[numVoters];
    for (int i = 0; i < numVoters; i++) {
        printf("Enter voter %d name: ", i + 1);
        scanf("%s", voterList[i].voterName);
        printf("Enter voter %d ID: ", i + 1);
        scanf("%d", &voterList[i].voterID);
        voterList[i].voted = false;
    }

    // Print out the list of candidates and voters
    printCandidateList(candidateList, numCandidates);
    printVoterList(voterList, numVoters);

    // Accept vote from user
    int voteCandidateID, voteVoterID;
    for (int i = 0; i < numVoters; i++) {
        printf("\nEnter your voter ID, %s: ", voterList[i].voterName);
        scanf("%d", &voteVoterID);

        // Validate voter ID
        while (voteVoterID != voterList[i].voterID) {
            printf("Invalid voter ID. Please enter again: ");
            scanf("%d", &voteVoterID);
        }

        // Check if voter has already voted
        if (voterList[i].voted) {
            printf("You have already voted!\n");
            continue;
        }

        printf("Enter your vote candidate ID for %s: ", voterList[i].voterName);
        scanf("%d", &voteCandidateID);

        // Validate candidate ID
        while (voteCandidateID <= 0 || voteCandidateID > numCandidates) {
            printf("Invalid candidate ID. Please enter again: ");
            scanf("%d", &voteCandidateID);
        }

        // Cast vote and mark voter as voted
        castVote(candidateList, voteCandidateID);
        voterList[i].voted = true;

        printf("Thank you for voting, %s!\n", voterList[i].voterName);
    }

    // Print out the results
    printf("\nElection Result\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s - %d votes\n", i + 1, candidateList[i].candidateName, candidateList[i].votesReceived);
    }

    return 0;
}