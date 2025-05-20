//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(char candidate) {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (strcmp(candidates[i].name, candidate) == 0) {
            candidates[i].votes++;
            break;
        }
    }
}

int main() {
    int i;
    char vote_choice;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
    }

    // Get candidate's name
    printf("Enter the candidate's name: ");
    scanf("%s", candidates[0].name);

    // Get the number of votes
    printf("Enter the number of votes: ");
    scanf("%d", &candidates[0].votes);

    // Vote
    printf("Enter your vote choice: ");
    scanf(" %c", &vote_choice);

    vote(vote_choice);

    // Print the results
    printf("The results are:");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("\n%s: %d votes", candidates[i].name, candidates[i].votes);
    }

    return 0;
}