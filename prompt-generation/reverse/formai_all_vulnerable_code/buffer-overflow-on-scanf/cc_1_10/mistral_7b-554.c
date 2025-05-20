//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 2
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 20

// Structure to represent a candidate
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int num_candidates = 0;
int total_votes = 0;

void register_candidate() {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }

    printf("Enter candidate ID: ");
    scanf("%d", &candidates[num_candidates].id);

    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);

    num_candidates++;
}

void vote(int candidate_id) {
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].id == candidate_id) {
            candidates[i].votes++;
            total_votes++;
            return;
        }
    }

    printf("Invalid candidate ID.\n");
}

int main() {
    int choice;

    printf("Welcome to the Electronic Voting System!\n");

    // Register candidates
    while (1) {
        printf("1. Register candidate\n2. Cast vote\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            register_candidate();
        } else if (choice == 2) {
            int candidate_id;
            printf("Enter candidate ID to cast vote: ");
            scanf("%d", &candidate_id);
            vote(candidate_id);
            break;
        } else if (choice == 3) {
            printf("Exiting the system...\n");
            exit(0);
        } else {
            printf("Invalid choice.\n");
        }
    }

    printf("Total votes cast: %d\n", total_votes);

    for (int i = 0; i < num_candidates; i++) {
        printf("Candidate %d (%s) received %d votes.\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }

    return 0;
}