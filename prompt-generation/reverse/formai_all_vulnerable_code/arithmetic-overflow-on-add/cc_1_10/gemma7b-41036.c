//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 10
#define MAX_CANDIDATES 5

typedef struct Voter {
    char name[20];
    int vote;
} Voter;

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

void vote(Voter *v, Candidate *c) {
    v->vote = c->votes++;
}

int main() {
    Voter voters[MAX_VOTERS];
    Candidate candidates[MAX_CANDIDATES];

    // Initialize voters and candidates
    for (int i = 0; i < MAX_VOTERS; i++) {
        voters[i].name[0] = '\0';
        voters[i].vote = 0;
    }

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    // Register voters and cast votes
    for (int i = 0; i < MAX_VOTERS; i++) {
        printf("Enter voter name: ");
        scanf("%s", voters[i].name);

        printf("Enter candidate number: ");
        int candidate_num;
        scanf("%d", &candidate_num);

        vote(&voters[i], &candidates[candidate_num - 1]);
    }

    // Print results
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("Candidate: %s, Votes: %d\n", candidates[i].name, candidates[i].votes);
    }

    // Find winner
    int winner = -1;
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].votes > winner) {
            winner = i;
        }
    }

    // Announce winner
    if (winner != -1) {
        printf("Winner: %s\n", candidates[winner].name);
    } else {
        printf("No winner\n");
    }

    return 0;
}