//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_NAME_LENGTH 50

struct candidate {
    char name[MAX_NAME_LENGTH];
    int votes;
};

struct voter {
    char name[MAX_NAME_LENGTH];
    int age;
    int voter_id;
};

void print_candidates(struct candidate candidates[], int num_candidates) {
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

int main() {
    struct candidate candidates[MAX_CANDIDATES];
    int num_candidates = 0;

    printf("Enter the number of candidates (up to %d): ", MAX_CANDIDATES);
    scanf("%d", &num_candidates);

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    int num_voters = 0;

    printf("Enter the number of voters (up to %d): ", MAX_VOTERS);
    scanf("%d", &num_voters);

    struct voter voters[MAX_VOTERS];

    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);
        printf("Enter the age of voter %d: ", i + 1);
        scanf("%d", &voters[i].age);
        voters[i].voter_id = i + 1;
    }

    int choice;
    printf("Enter your choice:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    scanf("%d", &choice);

    candidates[choice - 1].votes++;

    printf("Thank you for voting!\n");

    return 0;
}