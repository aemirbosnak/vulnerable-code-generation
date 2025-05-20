//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidate {
    char* name;
    int votes;
} Candidate;

void print_candidates(Candidate candidates[], int num_candidates) {
    int i;
    printf("Candidate Names: ");
    for (i = 0; i < num_candidates; i++) {
        printf("%s ", candidates[i].name);
    }
    printf("\n");
}

void print_results(Candidate candidates[], int num_candidates) {
    int i;
    printf("Results:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    Candidate candidates[10];
    int num_candidates = 0;

    while (1) {
        char candidate_name[20];
        printf("Enter candidate name: ");
        scanf("%s", candidate_name);

        if (strcmp(candidate_name, "quit") == 0) {
            break;
        }

        candidates[num_candidates].name = strdup(candidate_name);
        candidates[num_candidates].votes = 0;
        num_candidates++;
    }

    printf("Enter votes for each candidate (separated by spaces): ");
    scanf("%s", candidates[0].name);

    for (int i = 1; i < num_candidates; i++) {
        scanf("%s", candidates[i].name);
    }

    printf("Results:\n");
    print_candidates(candidates, num_candidates);
    print_results(candidates, num_candidates);

    return 0;
}