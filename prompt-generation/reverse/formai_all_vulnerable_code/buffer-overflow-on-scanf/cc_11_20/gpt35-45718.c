//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of candidates in the election.
#define MAX_CANDIDATES 10

// Define the structure for a candidate, which includes their name and the number of votes they received.
typedef struct candidate {
    char name[20];
    int votes;
} Candidate;

int main() {
    int num_candidates;
    Candidate candidates[MAX_CANDIDATES];

    printf("Welcome to the electronic voting system!\n\n");

    // Get the number of candidates from the user.
    while (1) {
        printf("How many candidates are in the election? (Maximum of %d) ", MAX_CANDIDATES);
        scanf("%d", &num_candidates);

        if (num_candidates > 0 && num_candidates <= MAX_CANDIDATES) {
            break;
        } else {
            printf("Invalid number of candidates. Please try again.\n");
        }
    }

    // Get the name of each candidate from the user.
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Allow users to cast their votes.
    while (1) {
        printf("\n");
        printf("Here are the candidates in the election:\n\n");

        for (int i = 0; i < num_candidates; i++) {
            printf("%d. %s\n", i + 1, candidates[i].name);
        }

        printf("\n");
        printf("Enter the number of the candidate you wish to vote for, or 0 to exit: ");

        int vote;
        scanf("%d", &vote);

        if (vote == 0) {
            break;
        } else if (vote > 0 && vote <= num_candidates) {
            candidates[vote - 1].votes++;
            printf("You have voted for %s.\n", candidates[vote - 1].name);
        } else {
            printf("Invalid candidate number. Please try again.\n");
        }
    }
    
    // Print the results of the election.
    printf("\n");
    printf("Here are the results of the election:\n\n");

    int total_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        total_votes += candidates[i].votes;
    }

    if (total_votes == 0) {
        printf("No votes were cast in the election.\n");
    } else {
        for (int i = 0; i < num_candidates; i++) {
            printf("%s received %d votes (%.1f%% of the total).\n",
                   candidates[i].name,
                   candidates[i].votes,
                   100.0 * candidates[i].votes / total_votes);
        }
    }
    
    return 0;
}