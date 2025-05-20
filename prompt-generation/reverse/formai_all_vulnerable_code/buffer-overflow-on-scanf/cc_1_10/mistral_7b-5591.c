//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    int id;
    int candidate_choice;
    char name[50];
} Voter;

void register_voter(Voter voters[], int *num_voters) {
    if (*num_voters >= MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
        return;
    }

    printf("Enter voter ID: ");
    scanf("%d", &voters[*num_voters].id);

    printf("Enter voter name: ");
    scanf("%s", voters[*num_voters].name);

    printf("Enter candidate choice (1-%d): ", MAX_CANDIDATES);
    scanf("%d", &voters[*num_voters].candidate_choice);

    (*num_voters)++;
}

void count_votes(Voter voters[], int num_voters, int candidates[]) {
    int i, vote;

    for (i = 0; i < num_voters; i++) {
        vote = voters[i].candidate_choice - 1;
        candidates[vote]++;
    }
}

void find_winner(int candidates[], int num_candidates) {
    int max_votes = 0, winning_candidate = 0;

    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i] > max_votes) {
            max_votes = candidates[i];
            winning_candidate = i + 1;
        }
    }

    printf("Candidate %d wins!\n", winning_candidate);
}

int main() {
    Voter voters[MAX_VOTERS];
    int num_voters = 0, candidates[MAX_CANDIDATES] = {0};

    printf("Welcome to the Electronic Voting System!\n");

    while (num_voters < MAX_VOTERS) {
        register_voter(voters, &num_voters);
    }

    printf("Voting closed. Counting votes...\n");

    count_votes(voters, num_voters, candidates);

    printf("Total number of votes: %d\n", (num_voters));

    find_winner(candidates, MAX_CANDIDATES);

    return 0;
}