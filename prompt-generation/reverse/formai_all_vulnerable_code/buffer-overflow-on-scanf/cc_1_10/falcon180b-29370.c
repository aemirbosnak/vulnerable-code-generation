//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
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
            printf("Candidate already exists.\n");
            return;
        }
    }
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void display_candidates(struct candidate *candidates, int num_candidates) {
    int i;
    for (i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

int main() {
    int num_candidates = 0;
    struct candidate candidates[100];
    char choice;
    while (1) {
        printf("1. Add candidate\n2. Display candidates\n3. Vote\n4. View results\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", candidates[num_candidates].name);
                num_candidates++;
                break;
            case 2:
                display_candidates(candidates, num_candidates);
                break;
            case 3:
                printf("Enter candidate number: ");
                scanf("%d", &choice);
                candidates[choice-1].votes++;
                break;
            case 4:
                display_candidates(candidates, num_candidates);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}