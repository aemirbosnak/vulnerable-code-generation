//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} candidate;

typedef struct {
    char name[50];
    int vote;
} voter;

candidate candidates[MAX_CANDIDATES];
voter voters[MAX_VOTERS];
int num_candidates = 0;
int num_voters = 0;

void add_candidate(char* name) {
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void add_voter(char* name) {
    strcpy(voters[num_voters].name, name);
    num_voters++;
}

void vote(int candidate_index, int voter_index) {
    candidates[candidate_index].votes++;
    voters[voter_index].vote = candidate_index;
}

void print_results() {
    int i;
    printf("Election Results:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int i, j;
    char name[50];
    printf("Electronic Voting System\n");
    printf("---------------------------------\n");
    printf("Enter the names of the candidates:\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        scanf("%s", name);
        add_candidate(name);
    }
    printf("\nEnter the names of the voters:\n");
    for (i = 0; i < MAX_VOTERS; i++) {
        scanf("%s", name);
        add_voter(name);
    }
    printf("\nEnter the votes:\n");
    for (i = 0; i < num_voters; i++) {
        printf("%s voted for:", voters[i].name);
        scanf("%d", &j);
        vote(j, i);
    }
    print_results();
    return 0;
}