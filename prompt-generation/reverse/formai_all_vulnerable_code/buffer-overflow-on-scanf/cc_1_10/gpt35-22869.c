//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_CANDIDATES 10

typedef struct candidate {
    int id;
    char name[MAX_NAME_LENGTH];
    int votes;
} candidate_t;

void add_candidate(candidate_t *candidates, int *num_candidates) {
    printf("Enter candidate name: ");
    scanf(" %[^\n]", candidates[*num_candidates].name);
    candidates[*num_candidates].id = (*num_candidates) + 1;
    candidates[*num_candidates].votes = 0;
    (*num_candidates)++;
}

void list_candidates(candidate_t *candidates, int num_candidates) {
    printf("List of candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }
}

int vote(candidate_t *candidates, int num_candidates) {
    int candidate_id;
    printf("Enter candidate ID to vote for: ");
    scanf("%d", &candidate_id);
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].id == candidate_id) {
            candidates[i].votes++;
            printf("Voted for %s!\n", candidates[i].name);
            return 1;
        }
    }
    printf("Invalid candidate ID.\n");
    return 0;
}

void show_results(candidate_t *candidates, int num_candidates) {
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s - %d votes\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    candidate_t candidates[MAX_CANDIDATES];
    int num_candidates = 0;
    int choice;

    printf("Welcome to the Electronic Voting System!\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add a candidate\n");
        printf("2. List candidates\n");
        printf("3. Vote\n");
        printf("4. Show results\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_candidates >= MAX_CANDIDATES) {
                    printf("Maximum number of candidates reached.\n");
                } else {
                    add_candidate(candidates, &num_candidates);
                }
                break;
            case 2:
                list_candidates(candidates, num_candidates);
                break;
            case 3:
                vote(candidates, num_candidates);
                break;
            case 4:
                show_results(candidates, num_candidates);
                break;
            case 5:
                printf("Thank you for using the Electronic Voting System!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}