//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(char candidate) {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].name[0] == candidate) {
            candidates[i].votes++;
            break;
        }
    }
}

int main() {
    int i, j, votes, candidate;
    char vote_char;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    // Get the number of votes
    printf("Enter the number of votes: ");
    scanf("%d", &votes);

    // Vote
    for (i = 0; i < votes; i++) {
        printf("Enter the candidate's name: ");
        scanf(" %c", &vote_char);

        vote(vote_char);
    }

    // Print the results
    printf("\nResults:");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("Candidate: %s, Votes: %d\n", candidates[i].name, candidates[i].votes);
    }

    // Find the winner
    j = 0;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].votes > candidates[j].votes) {
            j = i;
        }
    }

    // Print the winner
    printf("\nWinner: %s\n", candidates[j].name);

    return 0;
}