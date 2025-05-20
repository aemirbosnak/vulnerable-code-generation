#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_VOTERS 100

struct Candidate {
    char name[MAX_NAME_LENGTH];
    int votes;
};

struct Candidate candidates[MAX_VOTERS];
int num_candidates;

void add_candidate(char *name) {
    if (num_candidates >= MAX_VOTERS) {
        printf("Maximum number of candidates reached.\n");
        return;
    }
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void vote(int index) {
    if (index >= num_candidates) {
        printf("Invalid candidate index.\n");
        return;
    }
    candidates[index].votes++;
}

int main() {
    char input[MAX_NAME_LENGTH];
    int i, votes;

    printf("Enter number of candidates:\n");
    scanf("%d", &num_candidates);

    for (i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d's name:\n", i + 1);
        scanf("%s", input);
        add_candidate(input);
    }

    printf("Enter voter's name:\n");
    scanf("%s", input);

    printf("Enter candidate index to vote for:\n");
    scanf("%d", &votes);
    vote(votes - 1);

    return 0;
}
