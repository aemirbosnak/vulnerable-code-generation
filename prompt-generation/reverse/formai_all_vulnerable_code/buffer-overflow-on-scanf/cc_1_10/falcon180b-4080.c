//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

struct candidate {
    char name[MAX_NAME_LENGTH];
    int votes;
};

struct voter {
    char name[MAX_NAME_LENGTH];
    int vote;
};

void read_candidates(struct candidate candidates[MAX_CANDIDATES]) {
    int i = 0;
    printf("Enter the names of the candidates (up to %d):\n", MAX_CANDIDATES - 1);
    while (i < MAX_CANDIDATES && scanf("%s", candidates[i].name)!= EOF) {
        i++;
    }
}

void read_voters(struct voter voters[MAX_VOTERS], int* num_voters) {
    int i = 0;
    printf("Enter the names of the voters (up to %d):\n", MAX_VOTERS - 1);
    while (i < MAX_VOTERS && scanf("%s", voters[i].name)!= EOF) {
        i++;
    }
    *num_voters = i;
}

void vote(struct candidate candidates[MAX_CANDIDATES], struct voter voters[MAX_VOTERS], int num_voters) {
    int i;
    for (i = 0; i < num_voters; i++) {
        printf("Voter %s, please enter your vote:\n", voters[i].name);
        int vote = 0;
        while (vote < MAX_CANDIDATES && scanf("%d", &vote)!= EOF) {
            if (vote >= 0 && vote < MAX_CANDIDATES) {
                candidates[vote].votes++;
                break;
            } else {
                printf("Invalid vote, please try again.\n");
            }
        }
    }
}

void print_results(struct candidate candidates[MAX_CANDIDATES]) {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    struct candidate candidates[MAX_CANDIDATES];
    struct voter voters[MAX_VOTERS];
    int num_voters;

    read_candidates(candidates);
    read_voters(voters, &num_voters);
    vote(candidates, voters, num_voters);
    print_results(candidates);

    return 0;
}