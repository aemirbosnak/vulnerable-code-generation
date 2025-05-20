#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define MAX_CANDIDATES 10

int main() {
    int numCandidates;
    printf("Enter number of candidates: ");
    scanf("%d", &numCandidates);

    if (numCandidates > MAX_CANDIDATES) {
        printf("Number of candidates exceeds maximum limit.\n");
        return 1;
    }

    int votes[MAX_CANDIDATES] = {0};
    char candidateNames[MAX_CANDIDATES][50];

    printf("Enter names of candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        scanf("%s", candidateNames[i]);
    }

    int choice;
    while (1) {
        printf("\nVote for a candidate (1-%d), or enter 0 to stop voting: ", numCandidates);
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else if (choice < 1 || choice > numCandidates) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        votes[choice - 1]++;
    }

    printf("\nVoting Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidateNames[i], votes[i]);
    }

    return 0;
}
