//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

// Candidate Structure
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Voter Structure
typedef struct {
    char name[50];
    int voted; // 0 = no, 1 = yes
} Voter;

// Function Declarations
void initializeCandidates(Candidate candidates[]);
void initializeVoters(Voter voters[]);
void displayCandidates(Candidate candidates[], int numCandidates);
void castVote(Candidate candidates[], int numCandidates, Voter voters[], int numVoters);
void displayResults(Candidate candidates[], int numCandidates);

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int numCandidates = 0;
    int numVoters = 0;
    char choice;

    // Initialize candidates and voters
    printf("Welcome to the Electronic Voting System!\n\n");
    printf("Enter number of candidates (1 to %d): ", MAX_CANDIDATES);
    scanf("%d", &numCandidates);
    while(numCandidates < 1 || numCandidates > MAX_CANDIDATES) {
        printf("Please enter a valid number of candidates (1 to %d): ", MAX_CANDIDATES);
        scanf("%d", &numCandidates);
    }
    
    initializeCandidates(candidates);
    initializeVoters(voters);

    while(1) {
        printf("\nMenu:\n");
        printf("1. Display Candidates\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        getchar(); // Consume newline
        choice = getchar();

        switch(choice) {
            case '1':
                displayCandidates(candidates, numCandidates);
                break;
            case '2':
                castVote(candidates, numCandidates, voters, numVoters);
                numVoters++;
                break;
            case '3':
                displayResults(candidates, numCandidates);
                break;
            case '4':
                printf("Thank you for participating in the voting process!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void initializeCandidates(Candidate candidates[]) {
    for(int i = 0; i < MAX_CANDIDATES; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        getchar(); // Consume newline
        fgets(candidates[i].name, 50, stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = '\0'; // Remove newline
        candidates[i].votes = 0; // Initialize votes
    }
}

void initializeVoters(Voter voters[]) {
    for(int i = 0; i < MAX_VOTERS; i++) {
        strcpy(voters[i].name, "Anonymous");
        voters[i].voted = 0; // Initialize to no votes
    }
}

void displayCandidates(Candidate candidates[], int numCandidates) {
    printf("\nList of Candidates:\n");
    for(int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void castVote(Candidate candidates[], int numCandidates, Voter voters[], int numVoters) {
    int candidateIndex;
    
    printf("Please enter your name: ");
    getchar(); // Consume newline
    fgets(voters[numVoters].name, 50, stdin);
    voters[numVoters].name[strcspn(voters[numVoters].name, "\n")] = '\0'; // Remove newline
    
    if (voters[numVoters].voted) {
        printf("Sorry, you have already voted.\n");
        return;
    }
    
    displayCandidates(candidates, numCandidates);
    printf("Select your candidate by entering the candidate number (1 to %d): ", numCandidates);
    scanf("%d", &candidateIndex);
    
    while(candidateIndex < 1 || candidateIndex > numCandidates) {
        printf("Invalid selection. Please enter a valid candidate number: ");
        scanf("%d", &candidateIndex);
    }
    
    candidates[candidateIndex - 1].votes++;
    voters[numVoters].voted = 1; // Mark as voted
    printf("Thank you for your vote, %s!\n", voters[numVoters].name);
}

void displayResults(Candidate candidates[], int numCandidates) {
    printf("\nVoting Results:\n");
    for(int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}