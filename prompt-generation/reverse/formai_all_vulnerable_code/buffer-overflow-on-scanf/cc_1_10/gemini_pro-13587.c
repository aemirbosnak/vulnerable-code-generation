//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the candidates
#define CANDIDATES 5
const char *candidates[] = {
    "Sir Reginald of York",
    "Lady Eleanor of Gloucester",
    "Lord Edmund of Lancaster",
    "Sir Geoffrey de Mandeville",
    "Countess Margaret of Anjou"
};

// Define the number of voters
#define VOTERS 100

// Get the votes from the voters
int get_votes(int *votes) {
    int i;
    for (i = 0; i < VOTERS; i++) {
        printf("Voter %d, cast thy vote: ", i + 1);
        scanf("%d", &votes[i]);
    }
    return 0;
}

// Count the votes
int count_votes(int *votes, int *counts) {
    int i;
    for (i = 0; i < CANDIDATES; i++) {
        counts[i] = 0;
    }
    for (i = 0; i < VOTERS; i++) {
        counts[votes[i] - 1]++;
    }
    return 0;
}

// Find the winner
int find_winner(int *counts) {
    int i;
    int max_count = 0;
    int winner = -1;
    for (i = 0; i < CANDIDATES; i++) {
        if (counts[i] > max_count) {
            max_count = counts[i];
            winner = i;
        }
    }
    return winner;
}

// Announce the winner
void announce_winner(int winner) {
    printf("The winner is: %s\n", candidates[winner]);
}

int main() {
    int votes[VOTERS];
    int counts[CANDIDATES];
    int winner;

    get_votes(votes);
    count_votes(votes, counts);
    winner = find_winner(counts);
    announce_winner(winner);

    return 0;
}