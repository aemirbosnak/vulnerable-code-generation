//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int votes;
} candidate;

void sort_candidates(candidate *candidates, int num_candidates) {
    for (int i = 0; i < num_candidates - 1; i++) {
        for (int j = i + 1; j < num_candidates; j++) {
            if (candidates[j].votes > candidates[i].votes) {
                candidate temp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp;
            }
        }
    }
}

int main() {
    candidate candidates[5];
    int num_candidates = 0;

    // Read candidate data from file
    FILE *fp = fopen("candidates.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    while (fscanf(fp, "%s %d", candidates[num_candidates].name, &candidates[num_candidates].votes)!= EOF) {
        num_candidates++;
    }

    fclose(fp);

    // Sort candidates by number of votes
    sort_candidates(candidates, num_candidates);

    // Print results
    printf("Election Results:\n");
    printf("-------------------\n");

    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s: %d votes\n", i + 1, candidates[i].name, candidates[i].votes);
    }

    return 0;
}