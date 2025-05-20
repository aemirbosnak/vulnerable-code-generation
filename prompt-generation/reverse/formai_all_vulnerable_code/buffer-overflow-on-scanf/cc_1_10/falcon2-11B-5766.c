//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numCandidates = 3;  // Number of candidates
    int numUsers = 5;       // Number of users

    char *candidateNames[numCandidates];
    char *userNames[numUsers];

    // Initialize candidate names
    candidateNames[0] = "Candidate 1";
    candidateNames[1] = "Candidate 2";
    candidateNames[2] = "Candidate 3";

    // Initialize user names
    userNames[0] = "User 1";
    userNames[1] = "User 2";
    userNames[2] = "User 3";
    userNames[3] = "User 4";
    userNames[4] = "User 5";

    // Initialize votes
    int votes[numCandidates][numUsers];

    for (int i = 0; i < numCandidates; i++) {
        votes[i][0] = 0;
        votes[i][1] = 0;
        votes[i][2] = 0;
        votes[i][3] = 0;
        votes[i][4] = 0;
    }

    // Vote logic
    for (int user = 0; user < numUsers; user++) {
        printf("%s's vote: ", userNames[user]);
        int choice;
        printf("Enter the ID of the candidate you want to vote for: ");
        scanf("%d", &choice);
        while (choice < 1 || choice > numCandidates) {
            printf("Invalid choice. Please try again: ");
            scanf("%d", &choice);
        }
        votes[choice-1][user]++;
        printf("Vote for %s recorded.\n", candidateNames[choice-1]);
    }

    // Print results
    printf("Results:\n");
    for (int candidate = 0; candidate < numCandidates; candidate++) {
        int totalVotes = 0;
        for (int user = 0; user < numUsers; user++) {
            totalVotes += votes[candidate][user];
        }
        printf("Candidate %d: %d votes\n", candidate+1, totalVotes);
    }

    // Find winner
    int maxVotes = 0;
    int winnerIndex = 0;
    for (int candidate = 0; candidate < numCandidates; candidate++) {
        if (votes[candidate][0] > maxVotes) {
            maxVotes = votes[candidate][0];
            winnerIndex = candidate;
        }
    }

    printf("Winner: %s\n", candidateNames[winnerIndex]);

    return 0;
}