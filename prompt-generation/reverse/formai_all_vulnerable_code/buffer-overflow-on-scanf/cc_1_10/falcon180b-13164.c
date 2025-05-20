//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES_PER_VOTER 3

typedef struct {
    char name[50];
    int votes[MAX_CANDIDATES];
} Candidate;

typedef struct {
    char name[50];
    int vote_index;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];

void read_candidates() {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[i].name);
    }
}

void read_voters() {
    int i;
    for (i = 0; i < MAX_VOTERS; i++) {
        printf("Enter voter name: ");
        scanf("%s", voters[i].name);
    }
}

void cast_vote(int voter_index) {
    int i, j, vote_count = 0;
    printf("Voter %s is casting their vote:\n", voters[voter_index].name);
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: ", candidates[i].name);
        for (j = 0; j < MAX_VOTES_PER_VOTER; j++) {
            if (vote_count >= MAX_VOTES_PER_VOTER) {
                printf("(Max votes reached)\n");
                break;
            }
            if (candidates[i].votes[j] == 0) {
                candidates[i].votes[j] = 1;
                voters[voter_index].vote_index = i;
                vote_count++;
                break;
            } else {
                printf("%d ", candidates[i].votes[j]);
            }
        }
        printf("\n");
    }
}

void count_votes() {
    int i, j;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("Candidate %s received %d votes:\n", candidates[i].name, candidates[i].votes[0]);
        for (j = 1; j < MAX_VOTES_PER_VOTER; j++) {
            if (candidates[i].votes[j]!= 0) {
                printf("%d ", candidates[i].votes[j]);
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    read_candidates();
    read_voters();
    int i;
    for (i = 0; i < MAX_VOTERS; i++) {
        cast_vote(i);
    }
    count_votes();
    return 0;
}