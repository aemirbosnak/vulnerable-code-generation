//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define VOTE_LIMIT 100

typedef struct {
    int candidate_number;
    char name[50];
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int votes[MAX_CANDIDATES];

void initialize_candidates() {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].candidate_number = i + 1;
        sprintf(candidates[i].name, "Candidate %d", i + 1);
        votes[i] = 0;
    }
}

void print_candidates() {
    printf("\nList of Candidates:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d. %s\n", candidates[i].candidate_number, candidates[i].name);
    }
}

int validate_vote(int candidate_number) {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].candidate_number == candidate_number) {
            return i;
        }
    }
    printf("\nInvalid candidate number. Please try again.\n");
    return -1;
}

int main() {
    int user_input, validated_candidate;

    initialize_candidates();
    print_candidates();

    printf("\nEnter your candidate number: ");
    scanf("%d", &user_input);

    validated_candidate = validate_vote(user_input);

    if (validated_candidate != -1) {
        votes[validated_candidate]++;
        printf("\nYour vote has been cast for %s.\n", candidates[validated_candidate].name);
    }

    return 0;
}