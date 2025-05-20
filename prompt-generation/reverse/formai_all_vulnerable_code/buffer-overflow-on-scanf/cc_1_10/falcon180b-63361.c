//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES_PER_VOTER 5

typedef struct {
    char name[50];
    int votes[MAX_VOTES_PER_VOTER];
} Voter;

typedef struct {
    char name[50];
    int vote_count;
} Candidate;

void read_candidates(Candidate* candidates, int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].vote_count = 0;
    }
}

void read_voters(Voter* voters, int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        printf("Enter name of voter %d: ", i+1);
        scanf("%s", voters[i].name);
        for (int j = 0; j < MAX_VOTES_PER_VOTER; j++) {
            voters[i].votes[j] = 0;
        }
    }
}

void print_candidates(Candidate* candidates, int num_candidates) {
    printf("List of candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s\n", candidates[i].name);
    }
}

void print_voters(Voter* voters, int num_voters) {
    printf("List of voters:\n");
    for (int i = 0; i < num_voters; i++) {
        printf("%s\n", voters[i].name);
    }
}

void sort_candidates(Candidate* candidates, int num_candidates) {
    for (int i = 0; i < num_candidates-1; i++) {
        for (int j = i+1; j < num_candidates; j++) {
            if (candidates[j].vote_count > candidates[i].vote_count) {
                Candidate temp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp;
            }
        }
    }
}

int main() {
    int num_candidates, num_voters;
    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);
    printf("Enter number of voters: ");
    scanf("%d", &num_voters);

    Candidate candidates[num_candidates];
    Voter voters[num_voters];

    read_candidates(candidates, num_candidates);
    read_voters(voters, num_voters);

    int num_rounds = 0;
    while (num_rounds < num_candidates) {
        printf("Round %d:\n", num_rounds+1);
        print_candidates(candidates, num_candidates);
        for (int i = 0; i < num_voters; i++) {
            printf("Voter %d, please enter the number of the candidate you want to vote for: ", i+1);
            scanf("%d", &voters[i].votes[num_rounds]);
            candidates[voters[i].votes[num_rounds]-1].vote_count++;
        }
        num_rounds++;
    }

    sort_candidates(candidates, num_candidates);
    printf("Final results:\n");
    print_candidates(candidates, num_candidates);

    return 0;
}