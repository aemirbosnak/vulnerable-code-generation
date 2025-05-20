//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of candidates
#define NUM_CANDIDATES 10

// Define the maximum number of votes
#define MAX_VOTES 1000000

// Define the structure of a candidate
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Function to initialize the candidates
void initCandidates(Candidate candidates[]) {
    int i;
    for (i = 0; i < NUM_CANDIDATES; i++) {
        candidates[i].votes = 0;
        sprintf(candidates[i].name, "Candidate %d", i + 1);
    }
}

// Function to print the candidates
void printCandidates(Candidate candidates[]) {
    int i;
    for (i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Function to get the user's vote
int getVote() {
    int vote;
    printf("Enter your vote (1-%d): ", NUM_CANDIDATES);
    scanf("%d", &vote);
    return vote - 1;
}

// Function to cast a vote
void castVote(Candidate candidates[], int vote) {
    candidates[vote].votes++;
}

// Function to display the results
void displayResults(Candidate candidates[]) {
    int i;
    printf("The results are:\n");
    for (i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    srand(time(NULL));

    // Initialize the candidates
    Candidate candidates[NUM_CANDIDATES];
    initCandidates(candidates);

    // Print the candidates
    printf("The candidates are:\n");
    printCandidates(candidates);

    // Get the user's vote
    int vote = getVote();

    // Cast the vote
    castVote(candidates, vote);

    // Display the results
    printf("\nThe results are:\n");
    displayResults(candidates);

    return 0;
}