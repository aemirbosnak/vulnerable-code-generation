//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VOTERS 10000
#define MAX_OPTIONS 5

typedef struct {
    char name[50];
    int votes[MAX_OPTIONS];
} Candidate;

void register_voter(Candidate candidates[], int *num_candidates);
void cast_vote(Candidate candidates[], int num_candidates, int voter_id);
void display_results(Candidate candidates[], int num_candidates);

int main() {
    srand(time(NULL));
    Candidate my_candidates[MAX_VOTERS];
    int num_candidates = 0;

    // Register voters
    for (int i = 0; i < MAX_VOTERS && num_candidates < MAX_VOTERS / 2; i++) {
        register_voter(my_candidates, &num_candidates);
    }

    // Cast votes
    for (int i = 0; i < num_candidates; i++) {
        cast_vote(my_candidates, num_candidates, rand() % (MAX_VOTERS / 2) + 1);
    }

    // Display results
    display_results(my_candidates, num_candidates);

    return 0;
}

void register_voter(Candidate candidates[], int *num_candidates) {
    char name[50];
    printf("Enter voter name: ");
    scanf("%s", name);

    Candidate new_candidate = {name, {0}};
    candidates[*num_candidates] = new_candidate;
    (*num_candidates)++;
}

void cast_vote(Candidate candidates[], int num_candidates, int voter_id) {
    printf("Voter %d casting vote...\n", voter_id);

    int option;
    printf("Enter option number (1-%d): ", MAX_OPTIONS);
    scanf("%d", &option);

    if (option < 1 || option > MAX_OPTIONS) {
        printf("Invalid option number.\n");
        return;
    }

    candidates[voter_id - 1].votes[option - 1]++;
}

void display_results(Candidate candidates[], int num_candidates) {
    printf("\nResults:\n");

    for (int i = 0; i < num_candidates; i++) {
        printf("%s: ", candidates[i].name);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d ", candidates[i].votes[j]);
        }
        printf("\n");
    }
}