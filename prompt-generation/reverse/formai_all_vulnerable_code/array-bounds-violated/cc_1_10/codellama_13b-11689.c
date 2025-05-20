//Code Llama-13B DATASET v1.0 Category: Electronic Voting System ; Style: thoughtful
/*
 * C Electronic Voting System Example Program
 *
 * This program demonstrates a simple electronic voting system.
 * It takes a list of candidates and allows users to vote for their preferred candidates.
 * The program also keeps track of the total number of votes cast and the number of votes for each candidate.
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 100
#define MAX_VOTERS 1000

typedef struct {
    char name[50];
    int votes;
} Candidate;

int main() {
    // Declare variables
    Candidate candidates[MAX_CANDIDATES];
    int num_candidates;
    int num_voters;
    int vote;
    int total_votes = 0;

    // Get number of candidates and voters
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Initialize candidates
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Voting loop
    for (int i = 0; i < num_voters; i++) {
        // Display candidates
        printf("Candidates:\n");
        for (int j = 0; j < num_candidates; j++) {
            printf("%d. %s\n", j + 1, candidates[j].name);
        }

        // Get vote
        printf("Enter your vote (1-%d): ", num_candidates);
        scanf("%d", &vote);
        vote--;

        // Increment vote count
        candidates[vote].votes++;
        total_votes++;
    }

    // Display results
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes (%.2f%%)\n", candidates[i].name, candidates[i].votes, (float)candidates[i].votes / total_votes * 100);
    }

    return 0;
}