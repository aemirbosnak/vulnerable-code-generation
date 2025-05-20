//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CANDIDATES 5
#define NUM_VOTERS 100

struct candidate {
    char name[50];
    int votes;
};

void generate_candidates() {
    struct candidate candidates[NUM_CANDIDATES];
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }
    printf("Enter the names of %d candidates:\n", NUM_CANDIDATES);
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        scanf("%s", candidates[i].name);
    }
    printf("Candidates:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s ", candidates[i].name);
    }
    printf("\n");
}

void generate_voters() {
    int voters[NUM_VOTERS];
    for (int i = 0; i < NUM_VOTERS; i++) {
        voters[i] = rand() % NUM_CANDIDATES;
    }
    printf("Generated %d voters:\n", NUM_VOTERS);
    for (int i = 0; i < NUM_VOTERS; i++) {
        printf("%d ", voters[i]);
    }
    printf("\n");
}

void cast_vote(int voter_id, struct candidate candidates[]) {
    printf("Voter %d casting vote:\n", voter_id);
    printf("Candidates:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    int choice;
    scanf("%d", &choice);
    candidates[choice - 1].votes++;
}

void print_results(struct candidate candidates[]) {
    printf("Election results:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    srand(time(NULL));
    struct candidate candidates[NUM_CANDIDATES];
    generate_candidates();
    generate_voters();
    for (int i = 0; i < NUM_VOTERS; i++) {
        cast_vote(i + 1, candidates);
    }
    print_results(candidates);
    return 0;
}