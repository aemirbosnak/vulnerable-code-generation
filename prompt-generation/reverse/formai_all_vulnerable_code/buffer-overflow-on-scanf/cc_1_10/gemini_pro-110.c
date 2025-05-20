//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} candidate_t;

typedef struct {
    int id;
    int voted;
} voter_t;

candidate_t candidates[MAX_CANDIDATES];
voter_t voters[MAX_VOTERS];

int num_candidates = 0;
int num_voters = 0;

void add_candidate(char *name) {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Error: Too many candidates!\n");
        return;
    }

    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void add_voter(int id) {
    if (num_voters >= MAX_VOTERS) {
        printf("Error: Too many voters!\n");
        return;
    }

    voters[num_voters].id = id;
    voters[num_voters].voted = 0;
    num_voters++;
}

void vote(int voter_id, char *candidate_name) {
    int i;

    for (i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i].name, candidate_name) == 0) {
            candidates[i].votes++;
            voters[voter_id].voted = 1;
            return;
        }
    }

    printf("Error: Invalid candidate name!\n");
}

void print_results() {
    int i;

    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int i, j;
    char input[100];

    add_candidate("John Doe");
    add_candidate("Jane Doe");
    add_candidate("Bob Smith");

    add_voter(1);
    add_voter(2);
    add_voter(3);

    while (1) {
        printf("Enter voter ID (-1 to exit): ");
        scanf("%d", &i);

        if (i == -1) {
            break;
        }

        printf("Enter candidate name: ");
        scanf("%s", input);

        vote(i, input);
    }

    print_results();

    return 0;
}