//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_VOTES 1000

typedef struct {
    int voteId;
    char candidateName[50];
    int voteCount;
} Candidate;

int main() {
    Candidate candidates[MAX_VOTES];
    int numCandidates = 0;
    int totalVotes = 0;

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the number of candidates: ");
    scanf("%d", &numCandidates);

    // Input candidate names
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[i].candidateName);
        candidates[i].voteCount = 0;
    }

    // Start voting process
    int voter = 1;
    while (1) {
        printf("Enter 0 to exit, any other number to continue: ");
        int cont;
        scanf("%d", &cont);
        if (!cont) {
            break;
        }

        printf("Voter %d: Please enter your vote (candidate number): ", voter);
        int vote;
        scanf("%d", &vote);

        if (vote < 1 || vote > numCandidates) {
            printf("Invalid candidate selected. Please try again.\n");
            continue;
        }

        candidates[vote - 1].voteCount++;
        totalVotes++;
        printf("Your vote has been recorded. Thank you!\n");

        voter++;
    }

    // Display results
    printf("Results:\n");
    printf("Total Votes: %d\n", totalVotes);
    printf("Candidate\tVotes Received\tPercentage\n");
    for (int i = 0; i < numCandidates; i++) {
        float percentage = (candidates[i].voteCount / (float)totalVotes) * 100;
        printf("%s\t\t%d\t\t%.2f%%\n", candidates[i].candidateName, candidates[i].voteCount, percentage);
    }

    return 0;
}