//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CANDIDATES 5

typedef struct {
    char name[50];
    int votes;
} candidate;

candidate candidates[MAX_CANDIDATES];

int num_candidates = 0;

void register_candidate(char *name) {
    if (num_candidates < MAX_CANDIDATES) {
        strcpy(candidates[num_candidates].name, name);
        candidates[num_candidates].votes = 0;
        num_candidates++;
        printf("Candidate %s registered successfully.\n", name);
    } else {
        printf("Maximum number of candidates reached.\n");
    }
}

void cast_vote(int index) {
    if (index >= 0 && index < num_candidates) {
        candidates[index].votes++;
        printf("Vote cast for %s.\n", candidates[index].name);
    } else {
        printf("Invalid candidate index.\n");
    }
}

void display_results() {
    printf("\n--------------- Result ----------------\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s : %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    char name[50];
    int choice, index;

    while (1) {
        printf("\n------------------ Menu ------------------\n");
        printf("1. Register Candidate\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", name);
                register_candidate(name);
                break;
            case 2:
                printf("Enter candidate index: ");
                scanf("%d", &index);
                cast_vote(index);
                break;
            case 3:
                display_results();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}