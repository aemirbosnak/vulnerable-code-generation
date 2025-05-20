//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

struct candidate {
    char name[50];
    int votes;
};

struct voter {
    char name[50];
    int age;
};

void print_candidates(struct candidate candidates[], int num_candidates) {
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void print_voters(struct voter voters[], int num_voters) {
    printf("Voters:\n");
    for (int i = 0; i < num_voters; i++) {
        printf("%s: %d years old\n", voters[i].name, voters[i].age);
    }
}

int main() {
    struct candidate candidates[MAX_CANDIDATES];
    int num_candidates = 0;
    struct voter voters[MAX_VOTERS];
    int num_voters = 0;

    srand(time(NULL));

    while (num_candidates < MAX_CANDIDATES) {
        printf("Enter name of candidate (%d/%d): ", num_candidates + 1, MAX_CANDIDATES);
        scanf("%s", candidates[num_candidates].name);
        candidates[num_candidates].votes = 0;
        num_candidates++;
    }

    while (num_voters < MAX_VOTERS) {
        printf("Enter name of voter (%d/%d): ", num_voters + 1, MAX_VOTERS);
        scanf("%s", voters[num_voters].name);
        printf("Enter age of voter: ");
        scanf("%d", &voters[num_voters].age);
        num_voters++;
    }

    printf("Voting has started!\n");

    for (int i = 0; i < num_voters; i++) {
        int candidate_index = rand() % num_candidates;
        candidates[candidate_index].votes++;
    }

    print_candidates(candidates, num_candidates);
    print_voters(voters, num_voters);

    return 0;
}