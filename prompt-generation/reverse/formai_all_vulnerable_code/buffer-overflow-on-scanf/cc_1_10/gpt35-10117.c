//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10

struct candidate {
    char name[30];
    int votes;
};

struct candidate candidates[MAX_CANDIDATES];

int num_candidates;

void add_candidate() {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }

    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void vote() {
    char name[30];
    int valid_candidate = 0, i;

    printf("Enter candidate name to vote for: ");
    scanf("%s", name);

    for (i = 0; i < num_candidates; i++) {
        if (strcmp(name, candidates[i].name) == 0) {
            candidates[i].votes++;
            printf("Vote cast for %s.\n", candidates[i].name);
            valid_candidate = 1;
            break;
        }
    }

    if (!valid_candidate) {
        printf("Invalid candidate name.\n");
    }
}

void print_results() {
    int i;

    printf("\nCandidate\tVotes\n");

    for (i = 0; i < num_candidates; i++) {
        printf("%s\t\t%d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice = 0;

    while (choice != 4) {
        printf("\nElectronic Voting System\n");
        printf("1. Add candidate\n");
        printf("2. Cast vote\n");
        printf("3. View results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                vote();
                break;
            case 3:
                print_results();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}