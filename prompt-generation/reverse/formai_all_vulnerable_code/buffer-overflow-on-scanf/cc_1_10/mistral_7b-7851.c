//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: peaceful
#include <stdio.h>
#include <stdbool.h>

#define MAX_CANDIDATES 3
#define VOTES_CAST 0
#define VOTES_RECEIVED 1

typedef struct {
    int number;
    int votes;
} candidate_t;

candidate_t candidates[MAX_CANDIDATES];

void initialize_candidates() {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].number = i + 1;
        candidates[i].votes = 0;
    }
}

void print_candidates() {
    printf("\nList of Presidential Candidates:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("\n%d. Candidate %d", i + 1, candidates[i].number);
    }
}

bool is_valid_candidate(int candidate_number) {
    if (candidate_number >= 1 && candidate_number <= MAX_CANDIDATES) {
        return true;
    }
    return false;
}

void cast_vote(int candidate_number) {
    if (is_valid_candidate(candidate_number)) {
        candidates[candidate_number - 1].votes++;
        printf("\nYour vote has been cast for Candidate %d.\n", candidates[candidate_number - 1].number);
    } else {
        printf("\nInvalid candidate number. Please try again.\n");
    }
}

void print_results() {
    printf("\nPresidential Candidate Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("\nCandidate %d received %d votes", candidates[i].number, candidates[i].votes);
    }
}

int main() {
    initialize_candidates();

    int choice;

    while (true) {
        print_candidates();
        printf("\nPlease enter the number of the candidate you would like to vote for (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        cast_vote(choice);
    }

    print_results();

    return 0;
}