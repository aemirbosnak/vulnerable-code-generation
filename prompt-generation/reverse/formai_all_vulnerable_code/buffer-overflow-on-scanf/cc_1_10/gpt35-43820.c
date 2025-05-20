//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10

typedef struct candidate {
    char name[50];
    int votes;
} candidate_t;

int get_num_candidates();
void get_candidates(candidate_t [], int);
void print_candidates(candidate_t [], int);
int vote(candidate_t [], int);
void declare_winner(candidate_t [], int);

int main() {
    // Get number of candidates
    int num_candidates = get_num_candidates();

    // Create array of candidates
    candidate_t candidates[MAX_CANDIDATES];

    // Get candidate names
    get_candidates(candidates, num_candidates);

    // Print out candidate list
    print_candidates(candidates, num_candidates);

    // Conduct voting
    int winner = vote(candidates, num_candidates);

    // Declare winner
    printf("\n\nThe winner is: %s with %d votes!\n", candidates[winner].name, candidates[winner].votes);

    return 0;
}

int get_num_candidates() {
    int num;
    printf("How many candidates are in the election? (1-%d)\n", MAX_CANDIDATES);
    scanf("%d", &num);

    while (num < 1 || num > MAX_CANDIDATES) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_CANDIDATES);
        scanf("%d", &num);
    }

    return num;
}

void get_candidates(candidate_t candidates[], int num_candidates) {
    printf("Enter candidate names:\n");

    for (int i = 0; i < num_candidates; i++) {
        printf("Candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
    }
}

void print_candidates(candidate_t candidates[], int num_candidates) {
    printf("\n\nCandidate List:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

int vote(candidate_t candidates[], int num_candidates) {
    int vote_for, winner;

    printf("\n\nVoting begins!\n");

    while (1) {
        printf("\nEnter the number of the candidate you want to vote for (1-%d). Enter 0 to end voting.\n", num_candidates);
        scanf("%d", &vote_for);

        if (vote_for == 0) {
            break;
        } else if (vote_for < 1 || vote_for > num_candidates) {
            printf("Invalid input!\n");
            continue;
        }

        candidates[vote_for-1].votes++;
        printf("You have voted for %s.\n", candidates[vote_for-1].name);
    }

    // Determine winner
    winner = 0;
    for (int i = 1; i < num_candidates; i++) {
        if (candidates[i].votes > candidates[winner].votes) {
            winner = i;
        }
    }

    return winner;
}

void declare_winner(candidate_t candidates[], int num_candidates) {
    printf("\n\nThe winner is: %s with %d votes!\n", candidates[0].name, candidates[0].votes);
}