//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

/* Define a struct to store candidate information */
typedef struct {
    char name[20];
    int votes;
} Candidate;

int main() {
    int num_candidates, num_voters, i, j, candidate_choice, voter_choice;
    Candidate *candidates;

    /* Prompt the user to enter the number of candidates */
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    /* Allocate memory for the candidates array */
    candidates = (Candidate*) malloc(sizeof(Candidate) * num_candidates);

    /* Prompt the user to enter candidate information */
    for (i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    /* Prompt the user to enter the number of voters */
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    /* Loop through each voter */
    for (i = 0; i < num_voters; i++) {
        printf("\nVoter %d, please select a candidate:\n", i+1);

        /* Display the list of candidates */
        for (j = 0; j < num_candidates; j++) {
            printf("%d. %s\n", j+1, candidates[j].name);
        }

        /* Get the voter's choice */
        do {
            printf("Your choice: ");
            scanf("%d", &candidate_choice);
        } while (candidate_choice < 1 || candidate_choice > num_candidates);

        /* Increase the candidate's vote count */
        candidates[candidate_choice-1].votes++;
    }

    /* Display the results */
    printf("\nResults:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    /* Free the memory allocated for the candidates array */
    free(candidates);

    return 0;
}