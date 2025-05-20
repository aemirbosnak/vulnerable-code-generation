//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CANDIDATES 10

typedef struct {
    char name[50];
    int votes;
} Candidate;

void register_candidate(Candidate candidates[], int *num_candidates);
void print_candidates(Candidate candidates[], int num_candidates);
void vote(Candidate candidates[], int *num_candidates, int *selected_candidate);

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int num_candidates = 0;
    int selected_candidate = -1;

    register_candidate(candidates, &num_candidates);

    if (num_candidates > 0) {
        print_candidates(candidates, num_candidates);

        do {
            vote(candidates, &num_candidates, &selected_candidate);
        } while (selected_candidate < 0 || selected_candidate >= num_candidates);

        printf("You have voted for %s.\n", candidates[selected_candidate].name);
    } else {
        printf("No candidates have registered.\n");
    }

    return 0;
}

void register_candidate(Candidate candidates[], int *num_candidates) {
    if (num_candidates < MAX_CANDIDATES) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[*num_candidates].name);

        (*num_candidates)++;
    } else {
        printf("Maximum number of candidates reached.\n");
    }
}

void print_candidates(Candidate candidates[], int num_candidates) {
    printf("\nList of Candidates:\n");

    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void vote(Candidate candidates[], int *num_candidates, int *selected_candidate) {
    int choice;

    printf("\nEnter candidate number to vote: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= *num_candidates) {
        (*selected_candidate) = choice - 1;
        candidates[*selected_candidate].votes++;
    } else {
        printf("Invalid candidate number.\n");
    }
}