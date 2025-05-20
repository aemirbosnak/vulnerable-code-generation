//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold each candidate's information
typedef struct Candidate {
    int id;
    char name[50];
    int votes;
} candidate_t;

// Structure to hold the voting information
typedef struct Vote {
    int voterID;
    int candidateID;
} vote_t;

// Global variables to hold the number of voters and candidates
int numVoters = 0;
int numCandidates = 0;

// Array to hold the candidates
candidate_t candidates[10];

// Array to hold the votes
vote_t votes[100];

// Function to display the menu
void displayMenu() {
    printf("1. Register Candidate\n");
    printf("2. Display Candidates\n");
    printf("3. Register Voter\n");
    printf("4. Display Voters\n");
    printf("5. Vote\n");
    printf("6. Display Results\n");
    printf("7. Exit\n");
}

// Function to register a candidate
void registerCandidate() {
    printf("Enter Candidate Name: ");
    scanf("%s", candidates[numCandidates].name);
    candidates[numCandidates].id = numCandidates + 1;
    candidates[numCandidates].votes = 0;
    numCandidates++;
}

// Function to display all registered candidates
void displayCandidates() {
    printf("ID\tName\tVotes\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d\t%s\t%d\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
}

// Function to register a voter
void registerVoter() {
    printf("Enter Voter ID: ");
    scanf("%d", &votes[numVoters].voterID);
    numVoters++;
}

// Function to display all registered voters
void displayVoters() {
    printf("Voter ID\n");
    for (int i = 0; i < numVoters; i++) {
        printf("%d\n", votes[i].voterID);
    }
}

// Function to cast a vote
void castVote() {
    int voterID, candidateID, flag = 0;
    printf("Enter Voter ID: ");
    scanf("%d", &voterID);
    for (int i = 0; i < numVoters; i++) {
        if (votes[i].voterID == voterID) {
            flag = 1;
            printf("Enter Candidate ID: ");
            scanf("%d", &candidateID);
            votes[i].candidateID = candidateID;
            candidates[candidateID - 1].votes++;
            printf("Vote Successfully Casted!\n");
            break;
        }
    }
    if (flag == 0) {
        printf("Invalid Voter ID!\n");
    }
}

// Function to display the election results
void displayResults() {
    printf("Election Results:\n");
    printf("Candidate\tVotes\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s\t%d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                registerCandidate();
                break;
            case 2:
                displayCandidates();
                break;
            case 3:
                registerVoter();
                break;
            case 4:
                displayVoters();
                break;
            case 5:
                castVote();
                break;
            case 6:
                displayResults();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 7);
    return 0;
}