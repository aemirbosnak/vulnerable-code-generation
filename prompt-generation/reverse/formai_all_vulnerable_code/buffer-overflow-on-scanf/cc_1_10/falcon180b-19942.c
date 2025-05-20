//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} candidate_t;

candidate_t candidates[MAX_CANDIDATES];

void add_candidate(char* name) {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].votes == 0) {
            strcpy(candidates[i].name, name);
            break;
        }
    }
}

void vote(char* voter_name, int candidate_index) {
    candidates[candidate_index].votes++;
}

void print_results() {
    int i;
    printf("Election Results:\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].votes > 0) {
            printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        }
    }
}

int main() {
    int i;
    char name[MAX_NAME_LENGTH];
    printf("Enter the names of the candidates (up to %d):\n", MAX_CANDIDATES);
    for (i = 0; i < MAX_CANDIDATES; i++) {
        scanf("%s", candidates[i].name);
    }
    printf("Enter the names of the voters (up to %d):\n", MAX_VOTERS);
    while (scanf("%s", name)!= EOF) {
        vote(name, 0);
    }
    print_results();
    return 0;
}