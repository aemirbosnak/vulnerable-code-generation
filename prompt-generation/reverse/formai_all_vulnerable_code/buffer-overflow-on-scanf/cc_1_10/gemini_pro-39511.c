//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int votes;
} Candidate;

Candidate candidates[100];
int num_candidates;

void vote(char *name) {
    int i;
    for (i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            candidates[i].votes++;
            return;
        }
    }
    printf("Candidate %s not found.\n", name);
}

void print_results() {
    int i;
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int i;
    char name[50];

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    while (1) {
        printf("Enter the name of the candidate you want to vote for (or 'q' to quit): ");
        scanf("%s", name);
        if (strcmp(name, "q") == 0) {
            break;
        }
        vote(name);
    }

    print_results();

    return 0;
}