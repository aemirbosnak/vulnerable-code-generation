#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int num_candidates = 0;
int votes_count = 0;

void add_candidate(char *name) {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }

    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void vote(int index) {
    if (index < 0 || index >= num_candidates) {
        printf("Invalid candidate index.\n");
        return;
    }

    candidates[index].votes++;
    votes_count++;
}

void print_results() {
    printf("\nResults:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    char input[100];
    int vote_index;

    add_candidate("Alice");
    add_candidate("Bob");
    add_candidate("Charlie");

    while (1) {
        printf("\nEnter candidate index to vote (0 to exit): ");
        scanf("%s", input);

        if (strcmp(input, "0") == 0) {
            break;
        }

        vote_index = atoi(input);
        vote(vote_index - 1);
    }

    print_results();

    return 0;
}
