//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

// Voter struct to store voter's information
typedef struct Voter {
    char name[50];
    int voted;
    int candidateID;
} Voter;

// Candidate struct to store candidate's information
typedef struct Candidate {
    char name[50];
    int candidateID;
    int votes;
} Candidate;

// Function to print the candidate list
void printCandidateList(Candidate candidates[], int numCandidates) {
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", candidates[i].candidateID, candidates[i].name);
    }
}

// Function to add a new voter to the voter list
void addVoter(Voter voters[], int *numVoters) {
    printf("Enter Voter Name: ");
    scanf("%s", voters[*numVoters].name);
    voters[*numVoters].voted = 0;
    (*numVoters)++;
}

// Function to mark the voter as voted
void markAsVoted(Voter voters[], int numVoters, int voterID) {
    voters[voterID].voted = 1;
}

// Function to add a new candidate to the candidate list
void addCandidate(Candidate candidates[], int *numCandidates) {
    printf("Enter Candidate Name: ");
    scanf("%s", candidates[*numCandidates].name);
    candidates[*numCandidates].candidateID = (*numCandidates) + 1;
    candidates[*numCandidates].votes = 0;
    (*numCandidates)++;
}

// Function to cast a vote
void castVote(Candidate candidates[], int numCandidates, Voter voters[], int numVoters, int voterID, int candidateID) {
    voters[voterID].voted = 1;
    voters[voterID].candidateID = candidateID;
    candidates[candidateID - 1].votes++;
}

// Function to print the voting report
void printVotingReport(Candidate candidates[], int numCandidates) {
    printf("Voting Report:\n");
    printf("Candidate Name \t\t Votes\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s \t\t\t %d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int numVoters = 0, numCandidates = 0;
    Voter voters[MAX_VOTERS];
    Candidate candidates[MAX_CANDIDATES];

    // Add initial candidates
    addCandidate(candidates, &numCandidates);
    addCandidate(candidates, &numCandidates);

    // Add initial voters
    addVoter(voters, &numVoters);
    addVoter(voters, &numVoters);

    while (1) {
        printf("\n\n");
        printf("1. Add Voter\n");
        printf("2. Add Candidate\n");
        printf("3. Cast Vote\n");
        printf("4. Print Candidate List\n");
        printf("5. Print Voting Report\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (numVoters == MAX_VOTERS) {
                    printf("Voter List Full.\n");
                } else {
                    addVoter(voters, &numVoters);
                    printf("Voter Added Successfully.\n");
                }
                break;

            case 2:
                if (numCandidates == MAX_CANDIDATES) {
                    printf("Candidate List Full.\n");
                } else {
                    addCandidate(candidates, &numCandidates);
                    printf("Candidate Added Successfully.\n");
                }
                break;

            case 3:
                printf("Enter Voter ID: ");
                int voterID;
                scanf("%d", &voterID);

                if (voterID >= numVoters) {
                    printf("Invalid Voter ID.\n");
                    break;
                }

                if (voters[voterID].voted) {
                    printf("Sorry, You have already voted.\n");
                    break;
                }

                printf("Select a candidate from the below list:\n");
                printCandidateList(candidates, numCandidates);

                int candidateID;
                scanf("%d", &candidateID);

                if (candidateID < 1 || candidateID > numCandidates) {
                    printf("Invalid Candidate ID.\n");
                    break;
                }

                castVote(candidates, numCandidates, voters, numVoters, voterID, candidateID);
                printf("Voted Successfully.\n");
                break;

            case 4:
                printf("Candidate List:\n");
                printCandidateList(candidates, numCandidates);
                break;

            case 5:
                printVotingReport(candidates, numCandidates);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice.\n");
                break;
        }
    }

    return 0;
}