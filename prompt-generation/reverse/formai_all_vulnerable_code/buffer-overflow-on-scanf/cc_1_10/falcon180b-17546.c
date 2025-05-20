//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char name[50];
    int votes;
} candidate;

void add_candidate(candidate *candidates, int *num_candidates, char *name) {
    strcpy(candidates[*num_candidates].name, name);
    candidates[*num_candidates].votes = 0;
    (*num_candidates)++;
}

void print_candidates(candidate *candidates, int num_candidates) {
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

void cast_vote(candidate *candidates, int num_candidates, int choice) {
    printf("Enter the name of the candidate you want to vote for:\n");
    char name[50];
    scanf("%s", name);

    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            candidates[i].votes++;
            printf("Your vote has been cast for %s.\n", name);
            return;
        }
    }

    printf("Invalid candidate name.\n");
}

void display_results(candidate *candidates, int num_candidates) {
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    candidate candidates[10];
    int num_candidates = 0;

    add_candidate(candidates, &num_candidates, "John Doe");
    add_candidate(candidates, &num_candidates, "Jane Smith");
    add_candidate(candidates, &num_candidates, "Bob Johnson");

    print_candidates(candidates, num_candidates);

    int choice;
    printf("Enter the number of the candidate you want to vote for:\n");
    scanf("%d", &choice);

    cast_vote(candidates, num_candidates, choice);

    display_results(candidates, num_candidates);

    return 0;
}