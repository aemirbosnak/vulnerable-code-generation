//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 5

typedef struct {
    int vote_count;
    char name[50];
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void register_candidate(int candidate_number, char *name) {
    strcpy(candidates[candidate_number].name, name);
    candidates[candidate_number].vote_count = 0;
}

void vote(int candidate_number) {
    if (candidate_number >= 0 && candidate_number < MAX_CANDIDATES) {
        candidates[candidate_number].vote_count++;
    } else {
        printf("Invalid candidate number.\n");
    }
}

void print_results() {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }
}

int main() {
    int i, num_candidates;

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    if (num_candidates > MAX_CANDIDATES) {
        printf("Maximum number of candidates allowed is %d.\n", MAX_CANDIDATES);
        return 1;
    }

    printf("Registering candidates:\n");
    for (i = 0; i < num_candidates; i++) {
        char name[50];
        printf("Candidate %d: ", i + 1);
        scanf("%s", name);
        register_candidate(i, name);
    }

    printf("\nCasting votes:\n");
    int candidate_number;
    for (i = 0; i < 10; i++) {
        printf("Enter candidate number to vote for (0 to stop): ");
        scanf("%d", &candidate_number);
        if (candidate_number == 0) {
            break;
        }
        vote(candidate_number - 1);
    }

    printf("\nResults:\n");
    print_results();

    return 0;
}