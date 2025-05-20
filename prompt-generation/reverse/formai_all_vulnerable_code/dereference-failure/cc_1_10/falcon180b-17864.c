//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    int votes;
} candidate;

void print_candidates(candidate* candidates, int num_candidates) {
    printf("Candidate Name\tVotes\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s\t%d\n", candidates[i].name, candidates[i].votes);
    }
}

void sort_candidates(candidate* candidates, int num_candidates) {
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
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    candidate* candidates = (candidate*) malloc(num_candidates * sizeof(candidate));

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    int num_votes;
    printf("Enter the number of votes: ");
    scanf("%d", &num_votes);

    for (int i = 0; i < num_votes; i++) {
        int vote_index;
        printf("Enter vote for candidate: ");
        scanf("%d", &vote_index);
        candidates[vote_index - 1].votes++;
    }

    print_candidates(candidates, num_candidates);

    sort_candidates(candidates, num_candidates);

    printf("\nCandidate Name\tVotes\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s\t%d\n", candidates[i].name, candidates[i].votes);
    }

    free(candidates);
    return 0;
}