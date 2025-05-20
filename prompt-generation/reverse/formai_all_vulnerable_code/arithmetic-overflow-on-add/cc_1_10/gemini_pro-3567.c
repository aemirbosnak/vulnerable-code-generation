//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Let's make our program jolly!
#define VOTE_PROMPT "Cast your precious vote, my dear friend!"
#define THANK_YOU_MESSAGE "Thank you for participating, your voice matters!"

// Let's define our candidates and their vote counts
typedef struct {
    char name[50];
    int voteCount;
} Candidate;

// Our cheerful candidate list
Candidate candidates[] = {
    { "Alice the Amazing", 0 },
    { "Bob the Brave", 0 },
    { "Carol the Clever", 0 }
};

// Function to display candidates and collect votes
void castVote() {
    printf("%s\n", VOTE_PROMPT);
    printf("Meet our incredible candidates:\n\n");

    // Loop over candidates and display their names
    for (int i = 0; i < sizeof(candidates) / sizeof(Candidate); i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    // Get the voter's choice
    int choice;
    printf("Enter the number of your chosen candidate: ");
    scanf("%d", &choice);

    // Cast the vote for the chosen candidate
    candidates[choice - 1].voteCount++;
    printf("%s\n", THANK_YOU_MESSAGE);
}

// Function to display the election results
void announceResults() {
    printf("\n\nDrumroll please! Here are the thrilling results:\n\n");

    // Find the winner by iterating over candidates and finding the highest vote count
    int maxVotes = 0;
    int winnerIndex;
    for (int i = 0; i < sizeof(candidates) / sizeof(Candidate); i++) {
        if (candidates[i].voteCount > maxVotes) {
            maxVotes = candidates[i].voteCount;
            winnerIndex = i;
        }
    }

    // Declare the winner!
    printf("Congratulations to %s, our shining victor!\n", candidates[winnerIndex].name);
}

int main() {
    // Welcome the voters
    printf("Welcome to our electronic voting system, where your voice counts!\n\n");

    // Collect votes
    castVote();

    // Announce the results
    announceResults();

    return 0;
}