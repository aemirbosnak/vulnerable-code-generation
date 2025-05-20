//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

// Structure to hold a candidate's data
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Structure to hold a voter's data
typedef struct {
    char voterID[20];
    int hasVoted; // 0 for no, 1 for yes
} Voter;

// Function prototypes
void initializeCandidates(Candidate candidates[], int numCandidates);
void displayCandidates(Candidate candidates[], int numCandidates);
int castVote(Candidate candidates[], Voter voters[], int numCandidates, int numVoters, char *voterID);
void displayResults(Candidate candidates[], int numCandidates);
void generateVoterID(char *ID, int length);

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    char voterID[20];
    int numCandidates = 0, numVoters = 0, choice;

    printf("Welcome to the Electronic Voting System\n");
    
    // Initialize candidates
    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &numCandidates);
    if (numCandidates > MAX_CANDIDATES || numCandidates < 1) {
        printf("Invalid number of candidates. Exiting.\n");
        return 1;
    }

    initializeCandidates(candidates, numCandidates);

    // Initialize voters' status
    for (int i = 0; i < MAX_VOTERS; i++) {
        voters[i].hasVoted = 0;
        generateVoterID(voters[i].voterID, 8); // Generate random voter ID
    }
    numVoters = MAX_VOTERS;

    // Voting loop
    do {
        printf("\n1. Cast a vote\n2. Display results\n3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your voter ID: ");
                scanf("%s", voterID);
                int result = castVote(candidates, voters, numCandidates, numVoters, voterID);
                if (result == 0) {
                    printf("Vote cast successfully!\n");
                } else if (result == -1) {
                    printf("Invalid voter ID!\n");
                } else if (result == -2) {
                    printf("You have already voted!\n");
                }
                break;
            case 2:
                displayResults(candidates, numCandidates);
                break;
            case 3:
                printf("Exiting the voting system. Thank you!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to initialize candidates
void initializeCandidates(Candidate candidates[], int numCandidates) {
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

// Function to display candidates
void displayCandidates(Candidate candidates[], int numCandidates) {
    printf("\nCandidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

// Function to cast a vote
int castVote(Candidate candidates[], Voter voters[], int numCandidates, int numVoters, char *voterID) {
    // Check if voter ID is valid and has not voted
    for (int i = 0; i < numVoters; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) { // Valid voter ID found
            if (voters[i].hasVoted == 1) { // Already voted
                return -2; // Error: Voter has already voted
            }
            voters[i].hasVoted = 1; // Mark as voted

            displayCandidates(candidates, numCandidates);
            int vote;
            printf("Choose a candidate (1-%d): ", numCandidates);
            scanf("%d", &vote);
            if (vote < 1 || vote > numCandidates) {
                printf("Invalid candidate choice!\n");
                return 1;
            }
            candidates[vote - 1].votes++; // Increment votes
            return 0; // Successful vote
        }
    }
    return -1; // Invalid voter ID
}

// Function to display the results
void displayResults(Candidate candidates[], int numCandidates) {
    printf("\nVoting Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Function to generate a random voter ID
void generateVoterID(char *ID, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    srand(time(NULL)); // Seed for random number generator
    for (int i = 0; i < length; i++) {
        ID[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    ID[length] = '\0'; // Null terminate
}