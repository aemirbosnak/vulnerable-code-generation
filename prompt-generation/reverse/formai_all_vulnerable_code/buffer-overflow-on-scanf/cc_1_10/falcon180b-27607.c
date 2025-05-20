//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_VOTES 10

typedef struct {
    char name[50];
    int votes[MAX_CANDIDATES];
} voter;

typedef struct {
    char name[50];
    int votes;
} candidate;

voter voters[MAX_VOTERS];
candidate candidates[MAX_CANDIDATES];

int num_candidates, num_voters;

void initialize_election() {
    int i, j;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    printf("Enter the names of the candidates:\n");
    for (i = 0; i < num_candidates; i++) {
        scanf("%s", candidates[i].name);
    }
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    printf("Enter the names of the voters:\n");
    for (i = 0; i < num_voters; i++) {
        scanf("%s", voters[i].name);
    }
}

void vote() {
    int i, j, k;
    printf("Enter your votes (0-9): ");
    for (i = 0; i < num_candidates; i++) {
        scanf("%d", &voters[0].votes[i]);
    }
}

void count_votes() {
    int i, j;
    for (i = 0; i < num_candidates; i++) {
        candidates[i].votes = 0;
    }
    for (i = 0; i < num_voters; i++) {
        for (j = 0; j < num_candidates; j++) {
            candidates[j].votes += voters[i].votes[j];
        }
    }
}

void print_results() {
    int i;
    printf("\nElection Results:\n");
    printf("--------------------\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    srand(time(NULL));
    initialize_election();
    vote();
    count_votes();
    print_results();
    return 0;
}