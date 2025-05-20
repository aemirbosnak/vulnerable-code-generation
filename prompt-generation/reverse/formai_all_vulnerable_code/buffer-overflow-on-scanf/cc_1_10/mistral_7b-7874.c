//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 1000
#define MAX_OPTIONS 5

typedef struct {
    char name[50];
    int votes[MAX_OPTIONS];
} Candidate;

void register_voter(Candidate candidates[], int *num_candidates);
void cast_vote(Candidate candidates[], int num_candidates, int voter_id);
void print_results(Candidate candidates[], int num_candidates);

int main() {
    Candidate candidates[MAX_VOTERS];
    int num_candidates = 0;

    register_voter(candidates, &num_candidates);
    cast_vote(candidates, num_candidates, 1);
    cast_vote(candidates, num_candidates, 2);
    cast_vote(candidates, num_candidates, 3);
    cast_vote(candidates, num_candidates, 4);

    print_results(candidates, num_candidates);

    return 0;
}

void register_voter(Candidate candidates[], int *num_candidates) {
    Candidate new_candidate;
    printf("Enter candidate name: ");
    scanf("%s", new_candidate.name);
    for (int i = 0; i < *num_candidates; i++) {
        if (strcmp(candidates[i].name, new_candidate.name) == 0) {
            printf("Candidate already exists.\n");
            return;
        }
    }

    candidates[*num_candidates] = new_candidate;
    (*num_candidates)++;
}

void cast_vote(Candidate candidates[], int num_candidates, int voter_id) {
    int option;
    printf("Enter option number for voter %d: ", voter_id);
    scanf("%d", &option);

    if (option < 1 || option > MAX_OPTIONS) {
        printf("Invalid option number.\n");
        return;
    }

    candidates[voter_id - 1].votes[option - 1]++;
}

void print_results(Candidate candidates[], int num_candidates) {
    int total_votes = 0;
    printf("\nResults:\n");
    for (int i = 0; i < num_candidates; i++) {
        total_votes += candidates[i].votes[0] + candidates[i].votes[1] + candidates[i].votes[2] + candidates[i].votes[3] + candidates[i].votes[4];
        printf("%s: %d votes (%d%, %d%%)\n", candidates[i].name, candidates[i].votes[0] + candidates[i].votes[1] + candidates[i].votes[2] + candidates[i].votes[3] + candidates[i].votes[4], (candidates[i].votes[0] + candidates[i].votes[1] + candidates[i].votes[2] + candidates[i].votes[3] + candidates[i].votes[4]) * 100 / total_votes, 100.0);
    }
}