//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for candidate's information
struct candidate {
    char name[50];
    int votes;
};

int main() {
    int num_candidates, num_voters, i, j, choice;
    char voter_id[20];
    struct candidate candidates[50];

    // Ask for number of candidates
    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);

    // Ask for candidate names
    printf("Enter candidate names: \n");
    for (i = 0; i < num_candidates; i++) {
        printf("Candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Ask for number of voters
    printf("Enter number of voters: ");
    scanf("%d", &num_voters);

    // Loop through each voter
    for (i = 0; i < num_voters; i++) {
        printf("Enter your voter ID: ");
        scanf("%s", voter_id);

        // Check if voter ID already voted
        for (j = 0; j < i; j++) {
            if (strcmp(voter_id, candidates[j].name) == 0) {
                printf("You have already voted.\n");
                break;
            }
        }

        // If voter not yet voted, show candidates and ask for vote
        if (j == i) {
            printf("Candidates:\n");
            for (j = 0; j < num_candidates; j++) {
                printf("%d. %s\n", j+1, candidates[j].name);
            }
            printf("Choose the candidate you want to vote for: ");
            scanf("%d", &choice);
            candidates[choice-1].votes++;   // Increment candidate's vote count
        }
    }

    // Print results
    printf("Voting Finished.\n");

    printf("Results:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}