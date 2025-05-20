//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Voting System Program
// Implemented using dynamic memory allocation in C

struct candidate {
    char name[50];
    int count;
};

int main() {
    int i, num_candidates, num_voters, user_choice;
    struct candidate *candidates;
    char voter_name[50];

    printf("***Welcome to the Electronic Voting System*** \n\n");

    // Prompt user for number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Allocate dynamic memory for candidates array
    candidates = (struct candidate*) malloc(num_candidates * sizeof(struct candidate));

    // Prompt user to input candidate names
    printf("\nEnter the names of the candidates: \n");
    for(i = 0; i < num_candidates; i++){
        printf("Candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].count = 0;
    }

    // Prompt user for number of voters
    printf("\nEnter the number of voters: ");
    scanf("%d", &num_voters);

    // Loop through each voter
    for(i = 0; i < num_voters; i++) {
        printf("\nEnter the name of the voter: ");
        scanf("%s", voter_name);

        // Prompt voter to select candidate
        printf("\nPlease select your choice of candidate:\n");
        for(int j = 0; j < num_candidates; j++){
            printf("%d. %s\n", j+1, candidates[j].name);
        }
        scanf("%d", &user_choice);

        // Increment vote count for selected candidate
        candidates[user_choice-1].count++;
        printf("%s has casted their vote for %s.\n", voter_name, candidates[user_choice-1].name);
    }

    // Print overall result
    printf("\n\n*****FINAL RESULT*****\n");
    for(i = 0; i<num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].count);
    }

    // Free dynamic memory allocated for candidates array
    free(candidates);

    return 0;
}