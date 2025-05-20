//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure for a candidate
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Function to print the menu
void printMenu(Candidate candidates[], int numCandidates) {
    printf("Please select a candidate:\n");
    for(int i=0; i<numCandidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

// Function to get the user's choice
int getChoice(Candidate candidates[], int numCandidates) {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice-1; // Convert 1-based index to 0-based index
}

// Function to add a vote for a candidate
void addVote(Candidate candidates[], int numCandidates, int choice) {
    candidates[choice].votes++;
}

// Function to display the results
void displayResults(Candidate candidates[], int numCandidates) {
    printf("Election results:\n");
    for(int i=0; i<numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Recursive function to conduct the election
void conductElection(Candidate candidates[], int numCandidates) {
    // Print the menu
    printMenu(candidates, numCandidates);

    // Get the user's choice
    int choice = getChoice(candidates, numCandidates);

    // Add a vote for the chosen candidate
    addVote(candidates, numCandidates, choice);

    // Display the results
    displayResults(candidates, numCandidates);

    // Check if there is a clear winner
    if(candidates[0].votes >= numCandidates/2) {
        printf("We have a winner: %s\n", candidates[0].name);
    } else {
        // Conduct another round of voting
        conductElection(candidates, numCandidates);
    }
}

// Main function
int main() {
    // Initialize the candidates
    Candidate candidates[] = {{"Alice", 0}, {"Bob", 0}, {"Charlie", 0}};
    int numCandidates = sizeof(candidates)/sizeof(candidates[0]);

    // Conduct the election
    conductElection(candidates, numCandidates);

    return 0;
}