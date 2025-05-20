//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

Candidate *candidates;
int num_candidates = 0;
int num_votes = 0;

void register_candidate() {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }

    candidates = realloc(candidates, (num_candidates + 1) * sizeof(Candidate));

    printf("Enter candidate name: ");
    fgets(candidates[num_candidates].name, sizeof(candidates[num_candidates].name), stdin);
    strtok(candidates[num_candidates].name, "\n");

    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void cast_vote(int index) {
    if (index < 0 || index >= num_candidates) {
        printf("Invalid candidate index.\n");
        return;
    }

    candidates[index].votes++;
    num_votes++;
}

void display_results() {
    printf("\nResults:\n");

    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    candidates = malloc(sizeof(Candidate));

    int choice;

    while (1) {
        printf("\n1. Register Candidate\n2. Cast Vote\n3. Display Results\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_candidate();
                break;
            case 2:
                if (num_candidates == 0) {
                    printf("No candidates to vote for.\n");
                    break;
                }

                int candidate_index;
                printf("Enter candidate index: ");
                scanf("%d", &candidate_index);
                cast_vote(candidate_index);
                break;
            case 3:
                display_results();
                break;
            case 4:
                free(candidates);
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}