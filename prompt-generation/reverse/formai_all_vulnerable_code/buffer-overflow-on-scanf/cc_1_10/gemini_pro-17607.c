//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CANDIDATES 5
#define MAX_NAME_LEN 20
#define MAX_VOTES 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int votes;
} candidate_t;

candidate_t candidates[NUM_CANDIDATES];
int num_voters;
int total_votes;

void init_candidates() {
    strcpy(candidates[0].name, "Alice");
    candidates[0].votes = 0;
    strcpy(candidates[1].name, "Bob");
    candidates[1].votes = 0;
    strcpy(candidates[2].name, "Carol");
    candidates[2].votes = 0;
    strcpy(candidates[3].name, "Dave");
    candidates[3].votes = 0;
    strcpy(candidates[4].name, "Eve");
    candidates[4].votes = 0;
}

void cast_vote(char *name) {
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            candidates[i].votes++;
            total_votes++;
            return;
        }
    }
    printf("Invalid candidate name: %s\n", name);
}

void print_results() {
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d (%.2f%%)\n", candidates[i].name, candidates[i].votes, (float)candidates[i].votes / total_votes * 100);
    }
}

int main() {
    init_candidates();

    // Insert your creative voting logic here
    int num_inputs;
    scanf("%d", &num_inputs);
    char input[MAX_NAME_LEN];
    for (int i = 0; i < num_inputs; i++) {
        scanf("%s", input);
        cast_vote(input);
    }

    print_results();

    return 0;
}