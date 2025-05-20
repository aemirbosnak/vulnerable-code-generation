//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANDIDATE_COUNT 5
#define VOTE_COUNT 100

typedef struct {
    char name[50];
    int vote_count;
} candidate_t;

candidate_t candidates[CANDIDATE_COUNT];

void add_candidate(char* name) {
    int i;
    for (i = 0; i < CANDIDATE_COUNT; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            return;
        }
    }
    strcpy(candidates[CANDIDATE_COUNT - 1].name, name);
    candidates[CANDIDATE_COUNT - 1].vote_count = 0;
}

void cast_vote(int candidate_index) {
    candidates[candidate_index].vote_count++;
}

void print_results() {
    int i;
    for (i = 0; i < CANDIDATE_COUNT; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }
}

int main() {
    int i;

    // Add candidates
    add_candidate("Alice");
    add_candidate("Bob");
    add_candidate("Charlie");
    add_candidate("David");
    add_candidate("Eve");

    // Cast votes
    int vote;
    for (i = 0; i < VOTE_COUNT; i++) {
        printf("Vote %d:\n", i + 1);
        scanf("%d", &vote);
        cast_vote(vote - 1);
    }

    // Print results
    printf("\nResults:\n");
    print_results();

    return 0;
}