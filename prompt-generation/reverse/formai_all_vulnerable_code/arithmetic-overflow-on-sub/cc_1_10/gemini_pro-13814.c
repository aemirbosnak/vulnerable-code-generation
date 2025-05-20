//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int votes;
} Candidate;

int main() {
    // Declare the candidates and their votes
    Candidate candidates[] = {
        {"Sir Reginald the Bold", 0},
        {"Lady Eleanor the Wise", 0},
        {"Lord Tristan the Just", 0},
        {"Dame Jane the Fair", 0},
        {"Master William the Scholar", 0},
    };

    // Get the number of voters
    int numVoters;
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);

    // Get the votes of the voters
    for (int i = 0; i < numVoters; i++) {
        // Get the voter's name
        char name[100];
        printf("Enter the name of voter %d: ", i + 1);
        scanf(" %[^\n]%*c", name);

        // Get the voter's vote
        int vote;
        printf("Enter the number of the candidate you wish to vote for (1-%d): ", sizeof(candidates) / sizeof(Candidate));
        scanf("%d", &vote);

        // Increment the vote count of the selected candidate
        candidates[vote - 1].votes++;
    }

    // Find the winner
    int maxVotes = 0;
    int winnerIndex = -1;
    for (int i = 0; i < sizeof(candidates) / sizeof(Candidate); i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }

    // Print the results
    printf("\nThe winner of the election is: %s\n", candidates[winnerIndex].name);
    printf("Total number of votes: %d\n", maxVotes);

    return 0;
}