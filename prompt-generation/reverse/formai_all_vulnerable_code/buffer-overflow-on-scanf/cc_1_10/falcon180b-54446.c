//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define the number of candidates
#define NUM_CANDIDATES 5

// Define the maximum number of votes
#define MAX_VOTES 1000

// Define the structure for a candidate
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Define the structure for a vote
typedef struct {
    int candidateID;
} Vote;

// Function to print the candidates
void printCandidates(Candidate candidates[]) {
    printf("Candidate ID\tCandidate Name\tNumber of Votes\n");
    for(int i=0; i<NUM_CANDIDATES; i++) {
        printf("%d\t%s\t%d\n", i+1, candidates[i].name, candidates[i].votes);
    }
}

// Function to cast a vote
void castVote(Vote vote[], int voterID) {
    printf("Enter the candidate ID you want to vote for:\n");
    scanf("%d", &vote[voterID].candidateID);
}

// Function to count the votes
void countVotes(Vote vote[], Candidate candidates[]) {
    for(int i=0; i<MAX_VOTES; i++) {
        if(vote[i].candidateID >= 1 && vote[i].candidateID <= NUM_CANDIDATES) {
            candidates[vote[i].candidateID-1].votes++;
        }
    }
}

// Function to display the results
void displayResults(Candidate candidates[]) {
    printf("Election Results:\n");
    printf("-----------------\n");
    for(int i=0; i<NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    // Initialize the candidates
    Candidate candidates[NUM_CANDIDATES] = {{"John Doe", 0}, {"Jane Doe", 0}, {"Bob Smith", 0}, {"Alice Johnson", 0}, {"Charlie Brown", 0}};

    // Initialize the votes
    Vote vote[MAX_VOTES];

    // Cast votes
    int numVoters = 0;
    while(numVoters < MAX_VOTES) {
        castVote(vote, numVoters);
        numVoters++;
    }

    // Count votes
    countVotes(vote, candidates);

    // Display results
    displayResults(candidates);

    return 0;
}