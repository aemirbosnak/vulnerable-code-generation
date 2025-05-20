//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: creative
/*
* Electronic Voting System Program
* Written by: [Your Name]
* Date: [Today's Date]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 20
#define PASSWORD "Password123"

// Define Candidate struct
typedef struct {
    int candidateID;
    char name[MAX_NAME_LENGTH];
    int numVotes;
} Candidate;

// Define Voter struct
typedef struct {
    int voterID;
    char name[MAX_NAME_LENGTH];
    int votedFor;
} Voter;

// Function Prototypes
int verifyPassword();
void displayCandidateMenu(Candidate[]);
void displayVoterMenu(Candidate[], Voter[], int*);
void voteForCandidate(Candidate[], Voter[], int*);
void displayResults(Candidate[]);
void displayExitMessage();

int main() {
    // Declare variables
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int numCandidates = 0;
    int numVoters = 0;
    int loggedIn = 0;
    int i, j;

    // Verify password
    loggedIn = verifyPassword();

    // Get number of candidates and their details
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    for (i = 0; i < numCandidates; i++) {
        printf("\nCandidate %d Details: \n", i+1);
        candidates[i].candidateID = i+1;
        printf("Enter candidate name: ");
        scanf("%s", candidates[i].name);
        candidates[i].numVotes = 0;
    }

    // Get number of voters and their details
    printf("\n\nEnter the number of voters: ");
    scanf("%d", &numVoters);

    for (i = 0; i < numVoters; i++) {
        printf("\nVoter %d Details: \n", i+1);
        voters[i].voterID = i+1;
        printf("Enter voter name: ");
        scanf("%s", voters[i].name);
        voters[i].votedFor = 0;
    }

    // Display main menu based on whether user is logged in as admin or voter
    if (loggedIn == 1) {
        displayCandidateMenu(candidates);
    }
    else {
        displayVoterMenu(candidates, voters, &numVoters);
    }

    return 0;
}

/* Function to verify password */
int verifyPassword() {
    char password[MAX_NAME_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(password, PASSWORD) == 0) {
        printf("\n\nLogin Successful!\n");
        return 1;
    }
    else {
        printf("\n\nIncorrect Password!\n");
        exit(0);
    }
}

/* Function to display candidate menu */
void displayCandidateMenu(Candidate candidates[]) {
    int choice = 0;

    while (choice != 3) {
        printf("\n\nCANDIDATE MENU\n\n");
        printf("1. Vote Count\n");
        printf("2. Display Results\n");
        printf("3. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n\nVOTE COUNT\n\n");
                for (int i = 0; i < MAX_CANDIDATES; i++) {
                    printf("%d. %s - %d\n", candidates[i].candidateID, candidates[i].name, candidates[i].numVotes);
                }
                break;
            case 2:
                displayResults(candidates);
                break;
            case 3:
                displayExitMessage();
                break;
            default:
                printf("\n\nInvalid choice!\n");
        }
    }
}

/* Function to display voter menu */
void displayVoterMenu(Candidate candidates[], Voter voters[], int *numVoters) {
    int voterID, i;

    // check if the voter has already voted
    printf("Enter your Voter ID: ");
    scanf("%d", &voterID);

    for (i = 0; i < *numVoters; i++) {
        if (voters[i].voterID == voterID) {
            if (voters[i].votedFor != 0) {
                printf("\n\nYou have already voted!\n");
                exit(0);
            }
            else {
                voteForCandidate(candidates, voters, &voterID);
                *numVoters -= 1;
                break;
            }
        }
    }

    // If voterID not found in the voters list, exit
    if (i == *numVoters) {
        printf("\n\nInvalid Voter ID!\n");
        exit(0);
    }
}

/* Function to allow voter to vote for candidate */
void voteForCandidate(Candidate candidates[], Voter voters[], int *voterID) {
    int candidateID, i;

    printf("\n\nCANDIDATE LIST\n\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d. %s\n", candidates[i].candidateID, candidates[i].name);
    }

    printf("\nEnter candidate ID you want to vote for: ");
    scanf("%d", &candidateID);

    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].candidateID == candidateID) {
            candidates[i].numVotes += 1;
            printf("\n\nThank you for voting!\n");
            break;
        }
    }

    // If candidateID not found in the candidates list, exit
    if (i == MAX_CANDIDATES) {
        printf("\n\nInvalid candidate ID!\n");
        exit(0);
    }

    // Update voter's votedFor field
    for (i = 0; i < MAX_VOTERS; i++) {
        if (voters[i].voterID == *voterID) {
            voters[i].votedFor = candidateID;
            break;
        }
    }
}

/* Function to display the election results */
void displayResults(Candidate candidates[]) {
    int maxVotes = 0, winnerIndex = -1, i;

    // Find the candidate with the most votes
    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].numVotes > maxVotes) {
            maxVotes = candidates[i].numVotes;
            winnerIndex = i;
        }
    }

    printf("\n\nELECTION RESULTS\n\n");
    printf("Winner: %s\n", candidates[winnerIndex].name);
    printf("Total Votes: %d\n", MAX_VOTERS);
    printf("Total Invalid Votes: 0\n"); // For simplicity, we assume all votes are valid
    printf("Total Votes Cast: %d\n", MAX_VOTERS);

    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].numVotes);
    }
}

/* Function to display exit message */
void displayExitMessage() {
    printf("\n\nThank you for using our Electronic Voting System!\n\n");
}