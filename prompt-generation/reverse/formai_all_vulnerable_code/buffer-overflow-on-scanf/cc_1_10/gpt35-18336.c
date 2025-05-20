//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_CANDIDATES 10
#define MAX_VOTES_PER_CANDIDATE 100

struct candidate {
    int id;
    char name[50];
    int vote_count;
};

int main(void) {
    struct candidate candidates[MAX_NUM_CANDIDATES];
    int num_candidates, num_votes;
    int i, j, k;
    
    // Get number of candidates
    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);

    // Get candidate information
    for (i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d ID: ", i+1);
        scanf("%d", &candidates[i].id);

        printf("Enter candidate %d name: ", i+1);
        scanf("%s", candidates[i].name);

        candidates[i].vote_count = 0;
    }

    // Get number of votes
    printf("Enter number of votes: ");
    scanf("%d", &num_votes);

    // Get vote information
    for (i = 0; i < num_votes; i++) {
        int vote;
        printf("Vote number %d:\n", i+1);

        // Get candidate ID and validate it
        printf("Enter candidate ID: ");
        scanf("%d", &vote);
        for (j = 0; j < num_candidates; j++) {
            if (candidates[j].id == vote) {
                candidates[j].vote_count++;
                printf("Vote recorded for candidate %s\n", candidates[j].name);
                break;
            }
        }
        if (j == num_candidates) {
            printf("Invalid candidate ID\n");
        }   
    }

    // Print results
    printf("\nResults:\n");
    printf("Candidate Name\t| Votes Received\n");
    printf("----------------------------------\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%-15s\t| %d\n", candidates[i].name, candidates[i].vote_count);
    }

    // Determine winner
    int max_votes = candidates[0].vote_count;
    int winner = 0;
    for (i = 1; i < num_candidates; i++) {
        if (candidates[i].vote_count > max_votes) {
            max_votes = candidates[i].vote_count;
            winner = i;
        }
    }
    printf("\nThe winner is %s with %d votes!\n", candidates[winner].name, max_votes);

    return 0;
}