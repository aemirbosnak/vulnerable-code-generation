//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int num_candidates = 0;

void add_candidate() {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }

    printf("Enter candidate name: ");
    fgets(candidates[num_candidates].name, MAX_NAME_LENGTH, stdin);
    candidates[num_candidates].name[strcspn(candidates[num_candidates].name, "\n")] = '\0';
    candidates[num_candidates].votes = 0;

    num_candidates++;
}

void remove_candidate(int index) {
    if (index < 0 || index >= num_candidates) {
        printf("Invalid candidate index.\n");
        return;
    }

    memmove(&candidates[index], &candidates[index + 1], (num_candidates - index - 1) * sizeof(Candidate));
    num_candidates--;
}

void vote(int index) {
    if (index < 0 || index >= num_candidates) {
        printf("Invalid candidate index.\n");
        return;
    }

    candidates[index].votes++;
}

void display_votes() {
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    int candidate_index;

    while (1) {
        printf("\nElectronic Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. Remove Candidate\n");
        printf("3. Vote for Candidate\n");
        printf("4. Display Votes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                printf("Enter candidate index to remove: ");
                scanf("%d", &candidate_index);
                remove_candidate(candidate_index);
                break;
            case 3:
                printf("Enter candidate index to vote for: ");
                scanf("%d", &candidate_index);
                vote(candidate_index);
                break;
            case 4:
                display_votes();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}