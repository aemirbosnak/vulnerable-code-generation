//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10

typedef struct Candidate {
    char name[50];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(Candidate *candidate) {
    candidate->votes++;
}

int main() {
    int i, j, vote_count, candidate_count = 0;
    char vote_choice[50];

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
    }

    // Get candidate count from user
    printf("Enter the number of candidates: ");
    scanf("%d", &candidate_count);

    // Create candidates
    for (i = 0; i < candidate_count; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
    }

    // Voting loop
    printf("Enter your vote choice: ");
    scanf("%s", vote_choice);

    // Validate vote choice
    for (i = 0; i < candidate_count; i++) {
        if (strcmp(vote_choice, candidates[i].name) == 0) {
            vote(&candidates[i]);
            break;
        }
    }

    // Print results
    printf("The results are:");
    for (i = 0; i < candidate_count; i++) {
        printf("Candidate: %s, Votes: %d\n", candidates[i].name, candidates[i].votes);
    }

    // Calculate winner
    vote_count = candidates[0].votes;
    for (i = 1; i < candidate_count; i++) {
        if (candidates[i].votes > vote_count) {
            vote_count = candidates[i].votes;
        }
    }

    printf("The winner is: %s\n", candidates[0].name);

    return 0;
}