//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int id;
} Voter;

typedef struct {
    char name[50];
    int votes;
} Candidate;

Voter voters[MAX_VOTERS];
Candidate candidates[10];

int num_voters = 0;
int num_candidates = 0;

void add_voter(char* name, int id) {
    strcpy(voters[num_voters].name, name);
    voters[num_voters].id = id;
    num_voters++;
}

void add_candidate(char* name) {
    strcpy(candidates[num_candidates].name, name);
    num_candidates++;
}

int authenticate_voter(int id) {
    for (int i = 0; i < num_voters; i++) {
        if (voters[i].id == id) {
            return 1;
        }
    }
    return 0;
}

void vote(int voter_id, int candidate_id) {
    if (authenticate_voter(voter_id)) {
        candidates[candidate_id].votes++;
    }
}

void display_results() {
    printf("Votes:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    add_voter("Alice", 1);
    add_voter("Bob", 2);
    add_voter("Charlie", 3);

    add_candidate("Candidate A");
    add_candidate("Candidate B");

    int choice;
    while (1) {
        system("clear");
        printf("Please enter your voter ID:\n");
        scanf("%d", &choice);
        if (authenticate_voter(choice)) {
            printf("Welcome, %s!\n", voters[choice - 1].name);
            printf("Please choose a candidate to vote for:\n");
            for (int i = 0; i < num_candidates; i++) {
                printf("%d. %s\n", i + 1, candidates[i].name);
            }
            scanf("%d", &choice);
            vote(choice, choice - 1);
            printf("Thank you for voting!\n");
        } else {
            printf("Invalid voter ID.\n");
        }
    }

    display_results();

    return 0;
}