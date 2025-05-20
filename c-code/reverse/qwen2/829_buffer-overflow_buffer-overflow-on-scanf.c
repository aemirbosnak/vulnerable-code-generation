#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAX_CANDIDATES 10

int main() {
    char candidates[MAX_CANDIDATES][50];
    int voteCount[MAX_CANDIDATES] = {0};
    int numCandidates = 0;
    int choice;

    printf("Welcome to the Electronic Voting System\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Candidate\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numCandidates >= MAX_CANDIDATES) {
                    printf("Cannot add more candidates.\n");
                    break;
                }
                printf("Enter candidate name: ");
                scanf("%s", candidates[numCandidates]);
                numCandidates++;
                break;
            case 2:
                if (numCandidates == 0) {
                    printf("No candidates available.\n");
                    break;
                }
                printf("Available candidates:\n");
                for (int i = 0; i < numCandidates; i++) {
                    printf("%d. %s\n", i + 1, candidates[i]);
                }
                printf("Enter your choice: ");
                int voteChoice;
                scanf("%d", &voteChoice);
                if (voteChoice > 0 && voteChoice <= numCandidates) {
                    voteCount[voteChoice - 1]++;
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            case 3:
                if (numCandidates == 0) {
                    printf("No candidates available.\n");
                    break;
                }
                printf("\nVote Results:\n");
                for (int i = 0; i < numCandidates; i++) {
                    printf("%s: %d votes\n", candidates[i], voteCount[i]);
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
