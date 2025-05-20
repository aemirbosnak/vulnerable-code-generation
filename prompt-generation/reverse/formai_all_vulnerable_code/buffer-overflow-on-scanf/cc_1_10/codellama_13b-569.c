//Code Llama-13B DATASET v1.0 Category: Electronic Voting System ; Style: detailed
// Electronic Voting System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structures for candidate and voter data
typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char name[50];
    int age;
    char gender;
    char party[50];
    char address[50];
} Voter;

// Function to print candidate information
void printCandidate(Candidate candidate) {
    printf("Name: %s\n", candidate.name);
    printf("Votes: %d\n", candidate.votes);
}

// Function to print voter information
void printVoter(Voter voter) {
    printf("Name: %s\n", voter.name);
    printf("Age: %d\n", voter.age);
    printf("Gender: %c\n", voter.gender);
    printf("Party: %s\n", voter.party);
    printf("Address: %s\n", voter.address);
}

// Function to calculate the total votes for all candidates
int calculateTotalVotes(Candidate *candidates, int numCandidates) {
    int totalVotes = 0;
    for (int i = 0; i < numCandidates; i++) {
        totalVotes += candidates[i].votes;
    }
    return totalVotes;
}

// Function to calculate the percentage of votes for a particular candidate
int calculatePercentage(Candidate candidate, int totalVotes) {
    return (candidate.votes * 100) / totalVotes;
}

// Function to print the results of the election
void printResults(Candidate *candidates, int numCandidates) {
    int totalVotes = calculateTotalVotes(candidates, numCandidates);
    printf("Total votes: %d\n", totalVotes);
    for (int i = 0; i < numCandidates; i++) {
        printf("Candidate %d: %s\n", i + 1, candidates[i].name);
        printf("Votes: %d (%d%%)\n", candidates[i].votes, calculatePercentage(candidates[i], totalVotes));
        printf("\n");
    }
}

// Function to run the election
void runElection(Voter *voters, int numVoters, Candidate *candidates, int numCandidates) {
    // Initialize the vote counts for each candidate
    for (int i = 0; i < numCandidates; i++) {
        candidates[i].votes = 0;
    }

    // Have each voter cast their ballot
    for (int i = 0; i < numVoters; i++) {
        int candidateIndex = 0;
        printf("Voter %d: ", i + 1);
        scanf("%d", &candidateIndex);
        if (candidateIndex < 1 || candidateIndex > numCandidates) {
            printf("Invalid candidate index. Try again.\n");
            i--;
            continue;
        }
        candidates[candidateIndex - 1].votes++;
    }

    // Print the results of the election
    printResults(candidates, numCandidates);
}

int main() {
    // Initialize the voter data
    Voter voters[] = {
        {"John", 25, 'M', "Democrat", "123 Main St"},
        {"Jane", 30, 'F', "Republican", "456 Elm St"},
        {"Bob", 35, 'M', "Independent", "789 Oak St"}
    };
    int numVoters = sizeof(voters) / sizeof(voters[0]);

    // Initialize the candidate data
    Candidate candidates[] = {
        {"Candidate 1", 0},
        {"Candidate 2", 0},
        {"Candidate 3", 0}
    };
    int numCandidates = sizeof(candidates) / sizeof(candidates[0]);

    // Run the election
    runElection(voters, numVoters, candidates, numCandidates);

    return 0;
}