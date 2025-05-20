#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void vote(char candidates[10][256], int *votes, int num_candidates) {
    char choice[256];
    int i;

    printf("Enter candidate name to vote: ");
    scanf("%255s", choice);

    for (i = 0; i < num_candidates; ++i) {
        if (strcmp(choice, candidates[i]) == 0) {
            votes[i]++;
            return;
        }
    }

    printf("Invalid candidate.\n");
}

int main() {
    char candidates[10][256] = {"Candidate1", "Candidate2", "Candidate3", "Candidate4", "Candidate5", "Candidate6", "Candidate7", "Candidate8", "Candidate9", "Candidate10"};
    int votes[10] = {0};
    int num_candidates = 10;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Cast Vote\n");
        printf("2. View Results\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                vote(candidates, votes, num_candidates);
                break;
            case 2:
                printf("Results:\n");
                for (int i = 0; i < num_candidates; ++i) {
                    printf("%s: %d votes\n", candidates[i], votes[i]);
                }
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
