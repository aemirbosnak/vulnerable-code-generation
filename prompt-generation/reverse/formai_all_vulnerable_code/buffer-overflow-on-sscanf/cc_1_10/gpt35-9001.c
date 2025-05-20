//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of candidates and voters
#define MAX_CANDIDATES 50
#define MAX_VOTERS 100

// Define candidate struct
typedef struct Candidate {
    char name[50];
    int votes;
} Candidate;

// Define voter struct
typedef struct Voter {
    char name[50];
    int votedCandidateIndex;
} Voter;

// Declare global variables
Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int numCandidates = 0;
int numVoters = 0;

// Function to add a candidate
void addCandidate(char name[]) {
    // Check if max number of candidates has been reached
    if (numCandidates >= MAX_CANDIDATES) {
        printf("Error: max number of candidates reached\n");
        return;
    }
    
    // Add candidate to candidates array
    strcpy(candidates[numCandidates].name, name);
    candidates[numCandidates].votes = 0;
    numCandidates++;
}

// Function to print all candidates
void printCandidates() {
    printf("Candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

// Function to add a voter
void addVoter(char name[]) {
    // Check if max number of voters has been reached
    if (numVoters >= MAX_VOTERS) {
        printf("Error: max number of voters reached\n");
        return;
    }
    
    // Add voter to voters array
    strcpy(voters[numVoters].name, name);
    voters[numVoters].votedCandidateIndex = -1;
    numVoters++;
}

// Function to print all voters
void printVoters() {
    printf("Voters:\n");
    for (int i = 0; i < numVoters; i++) {
        printf("%d. %s\n", i+1, voters[i].name);
    }
}

// Function to vote for a candidate
void vote(char voterName[], char candidateName[]) {
    // Check if voter has already voted
    for (int i = 0; i < numVoters; i++) {
        if (strcmp(voters[i].name, voterName) == 0 && voters[i].votedCandidateIndex != -1) {
            printf("Error: you have already voted\n");
            return;
        }
    }
    
    // Find candidate with given name
    int candidateIndex = -1;
    for (int i = 0; i < numCandidates; i++) {
        if (strcmp(candidates[i].name, candidateName) == 0) {
            candidateIndex = i;
            break;
        }
    }
    if (candidateIndex == -1) {
        printf("Error: candidate not found\n");
        return;
    }
    
    // Add vote to candidate and to voter
    candidates[candidateIndex].votes++;
    for (int i = 0; i < numVoters; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            voters[i].votedCandidateIndex = candidateIndex;
            break;
        }
    }
}

// Function to print election results
void printResults() {
    printf("Election results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Main function
int main() {
    // Print welcome message
    printf("Welcome to the mind-bending electronic voting system!\n");
    
    // Initialize variables
    char input[100];
    char action[10];
    char name[50];
    char candidateName[50];
    
    // Loop to handle user input
    while (1) {
        // Print options to user
        printf("Please select an action:\n");
        printf("- Add candidate (add)\n");
        printf("- Add voter (voter)\n");
        printf("- Print candidates (printc)\n");
        printf("- Print voters (printv)\n");
        printf("- Vote (vote)\n");
        printf("- Print results (results)\n");
        printf("- Exit (exit)\n");
        
        // Get user input
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%s", action);
        
        // Handle user input
        if (strcmp(action, "add") == 0) {
            // Add candidate
            printf("Please enter candidate name: ");
            fgets(input, sizeof(input), stdin);
            sscanf(input, "%s", name);
            addCandidate(name);
        } else if (strcmp(action, "voter") == 0) {
            // Add voter
            printf("Please enter voter name: ");
            fgets(input, sizeof(input), stdin);
            sscanf(input, "%s", name);
            addVoter(name);
        } else if (strcmp(action, "printc") == 0) {
            // Print candidates
            printCandidates();
        } else if (strcmp(action, "printv") == 0) {
            // Print voters
            printVoters();
        } else if (strcmp(action, "vote") == 0) {
            // Vote for candidate
            printf("Please enter voter name: ");
            fgets(input, sizeof(input), stdin);
            sscanf(input, "%s", name);
            printf("Please enter candidate name: ");
            fgets(input, sizeof(input), stdin);
            sscanf(input, "%s", candidateName);
            vote(name, candidateName);
        } else if (strcmp(action, "results") == 0) {
            // Print election results
            printResults();
        } else if (strcmp(action, "exit") == 0) {
            // Exit program
            printf("Thank you for using the mind-bending electronic voting system!\n");
            return 0;
        } else {
            // Invalid action
            printf("Error: invalid action\n");
        }
    }
    
    return 0;
}