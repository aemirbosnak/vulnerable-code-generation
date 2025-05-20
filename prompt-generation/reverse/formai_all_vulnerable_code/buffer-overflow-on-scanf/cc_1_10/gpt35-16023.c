//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: calm
// This is a prototype for an electronic voting system program written in C. 
// The program can record votes, display results and allows the user to start a new election.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10   // Maximum number of candidates that can participate in an election
#define MAX_NAME_LENGTH 20  // Maximum name length of a candidate

// Each candidate has a name and a vote count
struct Candidate {
    char name[MAX_NAME_LENGTH];
    int votes;
};

// The election has a name, a list of candidates, and the number of candidates participating
struct Election {
    char name[MAX_NAME_LENGTH];
    struct Candidate candidates[MAX_CANDIDATES];
    int candidateCount;
};

// Prompts the user to enter the number of candidates, then generates the candidate list.
// Returns an election object containing the candidate list.
struct Election createElection() {
    struct Election election;
    printf("Enter the name of the election: ");
    scanf("%s", election.name);
    printf("Enter the number of candidates: ");
    scanf("%d", &election.candidateCount);
    printf("Enter the name of candidates:\n");

    for (int i = 0; i < election.candidateCount; i++) {
        printf("Candidate %d: ", i+1);
        scanf("%s", election.candidates[i].name);
        election.candidates[i].votes = 0;
    }
    return election;
}

// Displays the list of candidates and their vote counts
void displayResults(struct Election election) {
    printf("Results for %s election:\n", election.name);
    for (int i = 0; i < election.candidateCount; i++) {
        printf("%d. %s: %d votes\n", i+1, election.candidates[i].name, election.candidates[i].votes);
    }
}

// Prompts the user to vote for a candidate and increments the candidate's vote count
void castVote(struct Election *election) {
    printf("Enter your vote: ");
    int vote;
    scanf("%d", &vote);
    if ((vote > 0) && (vote <= election->candidateCount)) {
        election->candidates[vote-1].votes++;
        printf("You have successfully cast a vote for %s.\n", election->candidates[vote-1].name);
    }
    else {
        printf("Invalid vote.\n");
    }
}

// Main function that drives the program
int main() {
    struct Election currentElection;
    int choice;
    int endProgram = 0;

    while (!endProgram) {
        printf("----------------\n");
        printf("1. New Election\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Quit\n");
        printf("----------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                currentElection = createElection();
                printf("Election \"%s\" created successfully.\n", currentElection.name);
                break;
            case 2:
                if (currentElection.candidateCount > 0) {
                    castVote(&currentElection);
                }
                else {
                    printf("No election in progress. Please start a new election.\n");
                }
                break;
            case 3:
                if (currentElection.candidateCount > 0) {
                    displayResults(currentElection);
                }
                else {
                    printf("No election in progress. Please start a new election.\n");
                }
                break;
            case 4:
                endProgram = 1;
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}