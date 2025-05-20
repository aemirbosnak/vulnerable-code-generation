//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The following constants could be customized based on specific requirements
#define MAX_CANDIDATES 10 // Maximum number of candidates allowed in the election
#define MAX_VOTERS 100 // Maximum number of voters allowed for the election
#define MAX_VOTE 4 // Maximum number of votes allowed per voter
#define PASSWORD "Election2021" // Password for accessing admin functions

// Struct that holds the candidate's data
typedef struct {
    int id;
    char name[20];
    int vote;
} Candidate;

// Struct that represents a single voter
typedef struct {
    int id;
    char name[20];
    int voted[MAX_VOTE];
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int numCandidates = 0, numVoters = 0;

// Function prototypes
void addCandidate();
void printCandidates();
void castVote();
void printResults();
int isAdmin();

int main() {
    int option;

    while (1) {
        printf("\n\t\tElectronic Voting System\n\n");
        printf("1. Add Candidate\n2. Print Candidates\n3. Cast Vote\n4. Print Results\n5. Exit\n\n");

        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addCandidate();
                break;

            case 2:
                printCandidates();
                break;

            case 3:
                castVote();
                break;

            case 4:
                printResults();
                break;

            case 5:
                printf("\nGoodbye!\n\n");
                exit(0);

            default:
                printf("\nInvalid option. Please try again.\n\n");
                break;
        }
    }

    return 0;
}

// Adds a new candidate to the list
void addCandidate() {
    if (numCandidates == MAX_CANDIDATES) {
        printf("\nMaximum number of candidates reached. Can't add any more.\n\n");
        return;
    }

    Candidate newCandidate;

    printf("\nEnter candidate name: ");
    scanf("%s", newCandidate.name);

    newCandidate.id = ++numCandidates;
    newCandidate.vote = 0;

    candidates[numCandidates - 1] = newCandidate;

    printf("\nCandidate has been added successfully!\n\n");
}

// Prints the list of candidates
void printCandidates() {
    printf("\nList of Candidates\n\n");

    if (numCandidates == 0) {
        printf("No candidates found.\n\n");
        return;
    }

    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s - Votes: %d\n", candidates[i].id, candidates[i].name, candidates[i].vote);
    }
}

// Casts vote for a voter
void castVote() {
    if (numVoters == MAX_VOTERS) {
        printf("\nMaximum number of voters reached. Can't cast any more votes.\n\n");
        return;
    }

    Voter newVoter;

    printf("\nEnter voter name: ");
    scanf("%s", newVoter.name);

    newVoter.id = ++numVoters;

    for (int i = 0; i < MAX_VOTE; i++) {
        int candidateId;

        printf("\nEnter the candidate ID for vote %d (enter -1 to exit): ", i + 1);
        scanf("%d", &candidateId);

        if (candidateId == -1) {
            break;
        }

        if (candidateId <= 0 || candidateId > numCandidates) {
            printf("\nInvalid candidate ID. Please try again.\n");
            i--;
            continue;
        }

        newVoter.voted[i] = candidateId;
        candidates[candidateId - 1].vote++;
    }

    printf("\nThanks for voting!\n\n");

    voters[numVoters - 1] = newVoter;
}

// Prints the results of the election
void printResults() {
    printf("\nResults of the Election\n\n");

    if (numCandidates == 0) {
        printf("No candidates found.\n\n");
        return;
    }

    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s - Votes: %d\n", candidates[i].id, candidates[i].name, candidates[i].vote);
    }
}

// Checks if the user is admin by asking for password
int isAdmin() {
    char passwordInput[20];

    printf("\nEnter admin password: ");
    scanf("%s", passwordInput);

    if (strcmp(passwordInput, PASSWORD) == 0) {
        return 1;
    } else {
        return 0;
    }
}