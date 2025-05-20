//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 20
#define MAX_NAME_LENGTH 50

typedef struct candidate {
    char name[MAX_NAME_LENGTH];
    int votes;
} candidate;

int get_num_candidates();
void get_candidate_info(candidate candidates[], int num_candidates);
void print_candidates(candidate candidates[], int num_candidates);
int cast_vote(candidate candidates[], int num_candidates, char* voter_name);

int main() {
    candidate candidates[MAX_CANDIDATES];
    int num_candidates;

    printf("Welcome to the Ken Thompson Electronic Voting System!\n\n");

    num_candidates = get_num_candidates();

    get_candidate_info(candidates, num_candidates);

    print_candidates(candidates, num_candidates);

    char voter_name[MAX_NAME_LENGTH];
    printf("\nEnter your name to cast your vote: ");
    fgets(voter_name, MAX_NAME_LENGTH, stdin);

    if (cast_vote(candidates, num_candidates, voter_name) == 0) {
        printf("Sorry, your vote could not be cast.\n");
        return 1;
    }

    printf("Thank you for voting!\n");

    return 0;
}

/*
 * Returns the number of candidates entered by the user.
 */
int get_num_candidates() {
    int num_candidates = 0;

    do {
        printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
        scanf("%d", &num_candidates);
    } while (num_candidates < 1 || num_candidates > MAX_CANDIDATES);

    return num_candidates;
}

/*
 * Gets the name and other information of each candidate from the user.
 */
void get_candidate_info(candidate candidates[], int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("\nEnter the name of candidate %d: ", i+1);
        while (getchar() != '\n');  // flush input buffer
        fgets(candidates[i].name, MAX_NAME_LENGTH, stdin);

        // remove trailing newline character
        candidates[i].name[strcspn(candidates[i].name, "\n")] = '\0';

        candidates[i].votes = 0;
    }
}

/*
 * Prints the list of candidates and their information.
 */
void print_candidates(candidate candidates[], int num_candidates) {
    printf("\nList of candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

/*
 * Casts a vote for the candidate selected by the user.
 */
int cast_vote(candidate candidates[], int num_candidates, char* voter_name) {
    int choice;

    printf("\nEnter the number of the candidate you want to vote for: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > num_candidates) {
        return 0;
    }

    candidates[choice-1].votes++;
    printf("Vote for %s cast by %s\n", candidates[choice-1].name, voter_name);

    return 1;
}