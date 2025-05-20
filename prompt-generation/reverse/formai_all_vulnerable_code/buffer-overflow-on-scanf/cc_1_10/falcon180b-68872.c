//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTER_NAME_LENGTH 50

typedef struct {
    char name[MAX_VOTER_NAME_LENGTH];
    int age;
} voter_t;

typedef struct {
    char name[MAX_VOTER_NAME_LENGTH];
} candidate_t;

void read_candidates(candidate_t candidates[MAX_CANDIDATES]) {
    int i = 0;
    printf("Enter the number of candidates: ");
    scanf("%d", &i);
    if (i > MAX_CANDIDATES) {
        printf("Error: too many candidates.\n");
        exit(1);
    }
    for (int j = 0; j < i; j++) {
        printf("Enter the name of candidate %d: ", j + 1);
        scanf("%s", candidates[j].name);
    }
}

void read_voters(voter_t voters[MAX_VOTERS]) {
    int i = 0;
    printf("Enter the number of voters: ");
    scanf("%d", &i);
    if (i > MAX_VOTERS) {
        printf("Error: too many voters.\n");
        exit(1);
    }
    for (int j = 0; j < i; j++) {
        printf("Enter the name and age of voter %d: ", j + 1);
        scanf("%s %d", voters[j].name, &voters[j].age);
    }
}

int count_votes(voter_t voters[MAX_VOTERS], candidate_t candidates[MAX_CANDIDATES]) {
    int votes[MAX_CANDIDATES] = {0};
    for (int i = 0; i < MAX_VOTERS; i++) {
        printf("Voter %d's vote: ", i + 1);
        for (int j = 0; j < MAX_CANDIDATES; j++) {
            printf("%s ", candidates[j].name);
        }
        int choice;
        scanf("%d", &choice);
        votes[choice - 1]++;
    }
    return votes[0];
}

int main() {
    candidate_t candidates[MAX_CANDIDATES];
    voter_t voters[MAX_VOTERS];

    read_candidates(candidates);
    read_voters(voters);

    int winner_index = count_votes(voters, candidates);
    printf("The winner is: %s\n", candidates[winner_index].name);

    return 0;
}