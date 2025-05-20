//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10

struct candidate {
    char name[50];
    int votes;
};

int main() {
    int num_candidates;
    struct candidate candidates[MAX_CANDIDATES];

    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);

    while (num_candidates > MAX_CANDIDATES) {
        printf("Maximum number of candidates is %d.\n", MAX_CANDIDATES);
        printf("Please enter a smaller number: ");
        scanf("%d", &num_candidates);
    }

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    int num_voters;
    printf("Enter number of voters: ");
    scanf("%d", &num_voters);

    for (int i = 0; i < num_voters; i++) {
        printf("Voter %d, please enter your vote.\n", i + 1);

        for (int j = 0; j < num_candidates; j++) {
            printf("%d. %s\n", j + 1, candidates[j].name);
        }

        int vote;
        printf("Enter your vote: ");
        scanf("%d", &vote);

        while (vote < 1 || vote > num_candidates) {
            printf("Invalid vote. Please enter a valid vote: ");
            scanf("%d", &vote);
        }

        candidates[vote - 1].votes++;
    }

    printf("Voting complete. Results:\n");

    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}