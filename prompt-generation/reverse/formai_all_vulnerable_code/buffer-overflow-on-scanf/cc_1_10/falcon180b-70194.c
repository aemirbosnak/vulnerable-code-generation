//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate {
    char name[50];
    int votes;
};

void add_candidate(struct candidate *candidates, int num_candidates, char *name) {
    int i;
    for (i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            printf("Candidate %s already exists.\n", name);
            return;
        }
    }
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void vote(struct candidate *candidates, int num_candidates, char *name) {
    int i;
    for (i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            candidates[i].votes++;
            printf("Vote cast for %s.\n", candidates[i].name);
            return;
        }
    }
    printf("Candidate %s does not exist.\n", name);
}

void display_results(struct candidate *candidates, int num_candidates) {
    int i;
    printf("Election Results:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int num_candidates = 0;
    struct candidate candidates[100];
    char name[50];
    int choice;

    do {
        printf("1. Add candidate\n");
        printf("2. Cast vote\n");
        printf("3. Display results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter candidate name: ");
            scanf("%s", name);
            add_candidate(candidates, num_candidates, name);
            break;
        case 2:
            printf("Enter candidate name: ");
            scanf("%s", name);
            vote(candidates, num_candidates, name);
            break;
        case 3:
            display_results(candidates, num_candidates);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}