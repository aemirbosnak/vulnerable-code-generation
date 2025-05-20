//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VOTER_COUNT 5
#define CANDIDATE_COUNT 3

typedef struct {
    char name[50];
    int votes[CANDIDATE_COUNT];
} Voter;

typedef struct {
    char name[50];
    int votes;
} Candidate;

Voter voters[VOTER_COUNT] = {
    {"Alice", {1, 0, 0}},
    {"Bob", {0, 1, 0}},
    {"Charlie", {0, 0, 1}},
    {"David", {1, 1, 0}},
    {"Eve", {0, 0, 1}}
};

Candidate candidates[CANDIDATE_COUNT] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Charlie", 0}
};

void print_candidates() {
    int i;
    for (i = 0; i < CANDIDATE_COUNT; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int i, j, k;
    char vote[50];
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter your name: ");
    scanf("%s", vote);
    for (i = 0; i < VOTER_COUNT; i++) {
        if (strcmp(vote, voters[i].name) == 0) {
            printf("Welcome back, %s! Please cast your vote:\n", vote);
            for (j = 0; j < CANDIDATE_COUNT; j++) {
                printf("%d. %s\n", j + 1, candidates[j].name);
            }
            printf("Enter your choice (1-%d): ", CANDIDATE_COUNT);
            scanf("%d", &k);
            if (k >= 1 && k <= CANDIDATE_COUNT) {
                candidates[k - 1].votes++;
                voters[i].votes[k - 1] = 1;
            } else {
                printf("Invalid choice.\n");
            }
            break;
        }
    }
    if (i == VOTER_COUNT) {
        printf("Sorry, %s is not a registered voter.\n", vote);
        return 1;
    }
    print_candidates();
    return 0;
}