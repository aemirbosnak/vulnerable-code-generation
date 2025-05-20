//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 50

struct candidate {
    char name[50];
    int votes;
};

struct voter {
    char name[50];
    int voter_id;
};

struct election {
    struct candidate candidates[MAX_CANDIDATES];
    struct voter voters[MAX_VOTERS];
    int num_candidates;
    int num_voters;
};

void print_candidates(struct election* e) {
    printf("Candidates:\n");
    for (int i = 0; i < e->num_candidates; i++) {
        printf("%d. %s\n", i+1, e->candidates[i].name);
    }
}

void print_voters(struct election* e) {
    printf("Voters:\n");
    for (int i = 0; i < e->num_voters; i++) {
        printf("%d. %s\n", i+1, e->voters[i].name);
    }
}

int main() {
    srand(time(NULL));
    struct election e;
    e.num_candidates = 0;
    e.num_voters = 0;

    printf("Enter number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &e.num_candidates);

    printf("Enter number of voters (max %d): ", MAX_VOTERS);
    scanf("%d", &e.num_voters);

    for (int i = 0; i < e.num_candidates; i++) {
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", e.candidates[i].name);
    }

    for (int i = 0; i < e.num_voters; i++) {
        printf("Enter name of voter %d: ", i+1);
        scanf("%s", e.voters[i].name);
        e.voters[i].voter_id = i+1;
    }

    printf("Voting has started.\n");
    for (int i = 0; i < e.num_voters; i++) {
        int choice;
        printf("Voter %d, please enter your choice (1-%d): ", e.voters[i].voter_id, e.num_candidates);
        scanf("%d", &choice);
        if (choice >= 1 && choice <= e.num_candidates) {
            e.candidates[choice-1].votes++;
        } else {
            printf("Invalid choice.\n");
        }
    }

    printf("Voting has ended.\n");
    print_candidates(&e);
    print_voters(&e);

    return 0;
}