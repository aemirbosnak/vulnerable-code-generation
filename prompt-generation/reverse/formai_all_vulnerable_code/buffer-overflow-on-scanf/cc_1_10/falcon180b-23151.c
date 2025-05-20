//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct candidate {
    char name[30];
    int votes;
};

int main() {
    struct candidate candidates[10];
    int num_candidates = 0;
    int i, j, choice, max_votes = 0;
    char input[100];

    // Read in candidate names
    printf("Enter candidate names (up to 10):\n");
    while (num_candidates < 10 && scanf(" %s", input) == 1) {
        strcpy(candidates[num_candidates].name, input);
        num_candidates++;
    }

    // Initialize votes to zero
    for (i = 0; i < num_candidates; i++) {
        candidates[i].votes = 0;
    }

    // Main voting loop
    while (1) {
        system("clear");
        printf("Electronic Voting System\n");
        for (i = 0; i < num_candidates; i++) {
            printf("%d. %s\n", i+1, candidates[i].name);
        }
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > num_candidates) {
            printf("Invalid choice.\n");
            continue;
        }
        candidates[choice-1].votes++;
        if (candidates[choice-1].votes > max_votes) {
            max_votes = candidates[choice-1].votes;
        }
    }

    // Print results
    printf("\nResults:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("\nWinner: %s with %d votes\n", candidates[0].name, max_votes);

    return 0;
}