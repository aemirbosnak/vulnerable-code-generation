//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUM_CANDIDATES 5

typedef struct {
    char name[20];
    int votes;
} candidate;

candidate candidates[NUM_CANDIDATES];

bool is_valid_candidate(int index) {
    return index >= 0 && index < NUM_CANDIDATES;
}

void print_candidate_votes(int index) {
    if (is_valid_candidate(index)) {
        printf("%s: %d votes\n", candidates[index].name, candidates[index].votes);
    } else {
        printf("Invalid candidate index.\n");
    }
}

void cast_vote(int index) {
    if (is_valid_candidate(index)) {
        candidates[index].votes++;
        printf("Vote cast for %s.\n", candidates[index].name);
    } else {
        printf("Invalid candidate index.\n");
    }
}

int main() {
    int choice;

    for (int i = 0; i < NUM_CANDIDATES; i++) {
        strcpy(candidates[i].name, "Candidate");
        candidates[i].votes = 0;
    }

    do {
        printf("\nPlease enter the number of the candidate you would like to vote for, or enter 0 to quit:\n");
        scanf("%d", &choice);

        if (choice >= 0 && choice < NUM_CANDIDATES) {
            cast_vote(choice);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    printf("\nVote count:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        print_candidate_votes(i);
    }

    return 0;
}