#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 50

typedef struct Candidate {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int num_candidates = 0;
    char input[MAX_NAME_LENGTH];

    while (true) {
        printf("Enter candidate name (or 'q' to quit): ");
        scanf("%s", input);

        if (strcmp(input, "q") == 0)
            break;

        if (num_candidates >= MAX_CANDIDATES) {
            printf("Maximum number of candidates reached.\n");
            break;
        }

        strcpy(candidates[num_candidates].name, input);
        candidates[num_candidates].votes = 0;
        num_candidates++;
    }

    printf("\nCasting votes:\n");
    int voter;
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter voter %d: ", i + 1);
        scanf("%d", &voter);

        if (voter >= 0 && voter < num_candidates)
            candidates[voter].votes++;
        else
            printf("Invalid voter. Please try again.\n");
    }

    printf("\nResults:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}
