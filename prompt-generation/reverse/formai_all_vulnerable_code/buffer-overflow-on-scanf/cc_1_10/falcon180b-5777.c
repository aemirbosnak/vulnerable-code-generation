//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int votes;
} candidate;

candidate candidates[MAX_CANDIDATES];
int num_candidates = 0;

void add_candidate(char *name) {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Error: Maximum number of candidates reached.\n");
        return;
    }
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void vote(int voter_id, int candidate_id) {
    if (voter_id < 0 || voter_id >= MAX_VOTERS) {
        printf("Error: Invalid voter ID.\n");
        return;
    }
    if (candidate_id < 0 || candidate_id >= num_candidates) {
        printf("Error: Invalid candidate ID.\n");
        return;
    }
    candidates[candidate_id].votes++;
}

void display_results() {
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    char name[MAX_NAME_LEN];
    int choice, candidate_id;

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    add_candidate(name);

    while (1) {
        printf("\n%s, please select an option:\n", name);
        printf("1. Vote\n2. Display Results\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter candidate ID to vote for: ");
            scanf("%d", &candidate_id);
            vote(0, candidate_id);
            break;
        case 2:
            display_results();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}