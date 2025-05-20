//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
} Candidate;

typedef struct {
    int id;
    char name[50];
    int votes;
} Result;

Candidate candidates[] = {
    {1, "Alice"},
    {2, "Bob"},
    {3, "Carol"},
};

int num_candidates = sizeof(candidates) / sizeof(Candidate);

Result results[] = {};

int num_results = 0;

void print_candidates() {
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d: %s\n", candidates[i].id, candidates[i].name);
    }
}

void vote(int candidate_id) {
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].id == candidate_id) {
            results[i].votes++;
        }
    }
}

void print_results() {
    printf("Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d: %s (%d votes)\n", candidates[i].id, candidates[i].name, results[i].votes);
    }
}

int main() {
    print_candidates();

    while (1) {
        int candidate_id;
        printf("Enter candidate ID to vote for (0 to exit): ");
        scanf("%d", &candidate_id);

        if (candidate_id == 0) {
            break;
        }

        vote(candidate_id);
    }

    print_results();

    return 0;
}