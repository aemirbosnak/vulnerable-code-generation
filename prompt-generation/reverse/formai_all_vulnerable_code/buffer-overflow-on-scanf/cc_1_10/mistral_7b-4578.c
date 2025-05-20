//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 50

typedef struct {
    char name[50];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int voter_id = 0;
int num_candidates = 0;
int num_voters = 0;

void register_candidate(char *name) {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void vote(int candidate_id) {
    if (candidate_id < 0 || candidate_id >= num_candidates) {
        printf("Invalid candidate id.\n");
        return;
    }
    candidates[candidate_id].votes++;
}

void display_results() {
    printf("\nResults:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    char name[50];

    printf("Welcome to the Electronic Voting System.\n");

    while (1) {
        printf("\n1. Register candidate\n2. Cast vote\n3. Display results\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", name);
                register_candidate(name);
                break;
            case 2:
                if (num_voters >= MAX_VOTERS) {
                    printf("Maximum number of voters reached.\n");
                    break;
                }
                printf("Enter voter id: ");
                scanf("%d", &voter_id);
                printf("Enter candidate id: ");
                int candidate_id;
                scanf("%d", &candidate_id);
                vote(candidate_id);
                num_voters++;
                break;
            case 3:
                display_results();
                break;
            case 4:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}