#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int num_candidates = 0;
    int choice, vote_index;

    while (1) {
        printf("\nElectronic Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. Record Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (num_candidates >= MAX_CANDIDATES) {
                printf("Cannot add more candidates.\n");
                continue;
            }
            printf("Enter candidate name: ");
            scanf("%s", candidates[num_candidates].name);
            candidates[num_candidates].votes = 0;
            num_candidates++;
        } else if (choice == 2) {
            if (num_candidates == 0) {
                printf("No candidates available.\n");
                continue;
            }
            printf("Available candidates:\n");
            for (int i = 0; i < num_candidates; i++) {
                printf("%d. %s\n", i + 1, candidates[i].name);
            }
            printf("Enter the number of the candidate you want to vote for: ");
            scanf("%d", &vote_index);
            if (vote_index > 0 && vote_index <= num_candidates) {
                candidates[vote_index - 1].votes++;
            } else {
                printf("Invalid candidate number.\n");
            }
        } else if (choice == 3) {
            if (num_candidates == 0) {
                printf("No candidates available.\n");
                continue;
            }
            printf("\nVote Results:\n");
            for (int i = 0; i < num_candidates; i++) {
                printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
            }
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
