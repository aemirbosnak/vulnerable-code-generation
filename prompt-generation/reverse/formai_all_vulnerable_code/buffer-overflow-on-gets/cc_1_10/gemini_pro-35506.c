//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10

typedef struct {
    char name[50];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int num_candidates;

void add_candidate(char *name) {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Error: Too many candidates.\n");
        return;
    }

    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void vote(char *name) {
    int i;

    for (i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            candidates[i].votes++;
            return;
        }
    }

    printf("Error: Candidate not found.\n");
}

void print_results() {
    int i;

    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    char input[100];

    while (1) {
        printf("Enter a command (add, vote, results, quit): ");
        gets(input);

        if (strcmp(input, "add") == 0) {
            printf("Enter the candidate's name: ");
            gets(input);
            add_candidate(input);
        } else if (strcmp(input, "vote") == 0) {
            printf("Enter the candidate's name: ");
            gets(input);
            vote(input);
        } else if (strcmp(input, "results") == 0) {
            print_results();
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}