//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

/* Define maximum number of candidates and voters */
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

/* Define Candidate struct */
typedef struct {
    char name[50];
    int votes;
} Candidate;

/* Define global variables */
int num_candidates = 0;
Candidate candidates[MAX_CANDIDATES];

/* Declare functions */
void add_candidate();
void cast_vote();

int main() {

    int choice;
    int done = 0;
    
    printf("Welcome to the Electronic Voting System!\n");

    /* Loop until user is done */
    while (!done) {
        printf("\nSelect an option:\n");
        printf("1. Add Candidate\n");
        printf("2. Cast Vote\n");
        printf("3. View Results\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        /* Execute user's choice */
        switch(choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                cast_vote();
                break;
            case 3:
                printf("\nResults:\n");
                for (int i = 0; i < num_candidates; i++) {
                    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
                }
                break;
            case 4:
                printf("\nThank you for using the Electronic Voting System!\n");
                done = 1;
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }

    return 0;
}

/* Function to add a new candidate */
void add_candidate() {
    /* Check if maximum number of candidates has been reached */
    if (num_candidates >= MAX_CANDIDATES) {
        printf("\nMaximum number of candidates reached.\n");
        return;
    }

    /* Prompt user for candidate name */
    printf("\nEnter candidate name: ");
    scanf("%s", candidates[num_candidates].name);

    /* Set initial number of votes to 0 */
    candidates[num_candidates].votes = 0;

    /* Increment number of candidates */
    num_candidates++;

    printf("\nCandidate added successfully.\n");
}

/* Function to cast a vote */
void cast_vote() {
    /* Check if there are any candidates */
    if (num_candidates == 0) {
        printf("\nNo candidates available.\n");
        return;
    }

    /* Prompt user for candidate choice */
    printf("\nSelect a candidate:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
    int choice;
    scanf("%d", &choice);

    /* Increment chosen candidate's vote count */
    if (choice >= 1 && choice <= num_candidates) {
        candidates[choice-1].votes++;
        printf("\nVote cast successfully.\n");
    } else {
        printf("\nInvalid choice, please try again.\n");
    }
}