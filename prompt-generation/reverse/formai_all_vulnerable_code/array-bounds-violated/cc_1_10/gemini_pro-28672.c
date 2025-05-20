//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: lively
#include <stdio.h>

// Data Structures
struct Candidate {
    char name[50];
    int votes;
};

struct Voter {
    int id;
    int hasVoted;
};

// Global Variables
struct Candidate candidates[] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Carol", 0},
};
struct Voter voters[] = {
    {1, 0},
    {2, 0},
    {3, 0},
};
int numCandidates = sizeof(candidates) / sizeof(candidates[0]);
int numVoters = sizeof(voters) / sizeof(voters[0]);

// Functions
void printWelcomeMessage() {
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter your voter ID to cast your vote.\n");
}

int getVoterIndex(int id) {
    for (int i = 0; i < numVoters; i++) {
        if (voters[i].id == id) {
            return i;
        }
    }
    return -1; // Not found
}

void castVote(int voterIndex, int candidateIndex) {
    if (candidates[candidateIndex].votes >= 0) {
        candidates[candidateIndex].votes++;
        voters[voterIndex].hasVoted = 1;
        printf("Vote successfully cast!\n");
    } else {
        printf("Invalid candidate.\n");
    }
}

void printResults() {
    printf("Election Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("Voter Turnout: %d/%d (%.2f%%)\n",
        numVoters - 1, numVoters - 1,
        (double)(numVoters - 1) / numVoters * 100);
}

int main() {
    int voterId, candidateIndex;
    printWelcomeMessage();
    scanf("%d", &voterId);
    int voterIndex = getVoterIndex(voterId);
    if (voterIndex == -1) {
        printf("Invalid voter ID.\n");
        return 1;
    }
    if (voters[voterIndex].hasVoted) {
        printf("You have already voted.\n");
        return 1;
    }
    printf("Please enter the candidate you wish to vote for (1-%d): ", numCandidates);
    scanf("%d", &candidateIndex);
    candidateIndex--; // Adjust for 0-based indexing
    castVote(voterIndex, candidateIndex);
    printResults();
    return 0;
}