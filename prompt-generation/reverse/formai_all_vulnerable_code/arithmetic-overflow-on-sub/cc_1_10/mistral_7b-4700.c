//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 1000
#define MAX_OPTIONS 5

struct Candidate {
    char name[50];
    int votes;
};

struct Candidate candidates[MAX_OPTIONS];
int num_candidates = 0;

void register_candidate() {
    if (num_candidates >= MAX_OPTIONS) {
        printf("Maximum number of candidates reached.\n");
        return;
    }

    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void vote(int candidate_index) {
    if (candidate_index < 0 || candidate_index >= num_candidates) {
        printf("Invalid candidate index.\n");
        return;
    }

    candidates[candidate_index].votes++;
}

void print_results() {
    int i;

    printf("\nResults:\n");

    for (i = 0; i < num_candidates; i++) {
        printf("%d. %s - %d votes\n", i + 1, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    int voter_id = 1;

    while (1) {
        printf("\n--- Electronic Voting System ---\n");
        printf("1. Register candidate\n");
        printf("2. Cast vote\n");
        printf("3. Display results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_candidate();
                break;
            case 2:
                printf("Enter candidate index to vote for: ");
                scanf("%d", &choice);
                vote(choice - 1);
                break;
            case 3:
                print_results();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}