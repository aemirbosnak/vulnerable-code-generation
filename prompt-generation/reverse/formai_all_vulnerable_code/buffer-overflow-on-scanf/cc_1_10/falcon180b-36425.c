//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} candidate_t;

candidate_t candidates[MAX_CANDIDATES];

void add_candidate(candidate_t* new_candidate) {
    int i = 0;
    while (i < MAX_CANDIDATES && candidates[i].name[0]!= '\0') {
        i++;
    }
    if (i == MAX_CANDIDATES) {
        printf("Error: Maximum number of candidates reached.\n");
        exit(1);
    }
    strncpy(candidates[i].name, new_candidate->name, MAX_NAME_LENGTH - 1);
    candidates[i].name[MAX_NAME_LENGTH - 1] = '\0';
    candidates[i].votes = 0;
}

void vote(candidate_t* voter_choice) {
    int i = 0;
    while (i < MAX_CANDIDATES && strcmp(voter_choice->name, candidates[i].name)!= 0) {
        i++;
    }
    if (i == MAX_CANDIDATES) {
        printf("Error: Candidate not found.\n");
        exit(1);
    }
    candidates[i].votes++;
}

void print_results() {
    printf("Election Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].name[0]!= '\0') {
            printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        }
    }
}

int main() {
    candidate_t new_candidate;
    printf("Enter the name of the new candidate: ");
    scanf("%s", new_candidate.name);
    add_candidate(&new_candidate);

    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    for (int i = 0; i < num_voters; i++) {
        candidate_t voter_choice;
        printf("Enter the name of the voter's choice: ");
        scanf("%s", voter_choice.name);
        vote(&voter_choice);
    }

    print_results();

    return 0;
}