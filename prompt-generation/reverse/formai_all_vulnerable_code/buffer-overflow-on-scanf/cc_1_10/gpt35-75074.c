//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: safe
#include <stdio.h>
#include <string.h>

struct candidate {
    char name[30];
    int votes;
};
typedef struct candidate Candidate;

int main() {
    int num_of_candidates, num_of_voters, i, j, voter_choice;
    char voter_id[50];
    Candidate candidates[10];

    printf("Welcome to the Electronic Voting System\n\n");

    // Get the number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &num_of_candidates);

    // Get candidate names
    printf("Enter the names of the candidates: \n");
    for(i = 0; i < num_of_candidates; i++) {
        printf("Candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Get the number of voters
    printf("\nEnter the number of voters: ");
    scanf("%d", &num_of_voters);

    // Start the voting process
    for(i = 0; i < num_of_voters; i++) {
        printf("\nVoter %d, enter your voter ID: ", i+1);
        scanf("%s", voter_id);

        // Check if voter has already voted
        for(j = 0; j < i; j++) {
            if(strcmp(voter_id, candidates[j].name) == 0) {
                printf("Sorry, you have already voted.\n");
                break;
            }
        }

        // Allow voter to vote
        if(j == i) {
            printf("\nCandidates:\n");
            for(j = 0; j < num_of_candidates; j++) {
                printf("%d. %s\n", j+1, candidates[j].name);
            }

            printf("\nEnter your choice (1-%d): ", num_of_candidates);
            scanf("%d", &voter_choice);

            if(voter_choice > 0 && voter_choice <= num_of_candidates) {
                candidates[voter_choice-1].votes++;
                printf("Thank you for voting.\n");
            } else {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }

    // Display results
    printf("\nResults:\n");
    for(i = 0; i < num_of_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}