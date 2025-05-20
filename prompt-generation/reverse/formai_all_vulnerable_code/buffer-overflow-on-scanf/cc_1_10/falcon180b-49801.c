//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_VOTES 10

typedef struct {
    char name[50];
    int votes[MAX_CANDIDATES];
} voter;

typedef struct {
    char name[50];
    int votes;
} candidate;

void generate_random_votes(int num_votes, int num_candidates, voter* voters) {
    srand(time(NULL));
    for (int i = 0; i < num_votes; i++) {
        for (int j = 0; j < num_candidates; j++) {
            voters[i].votes[j] = rand() % 10;
        }
    }
}

void print_candidates(candidate* candidates, int num_candidates) {
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void print_results(candidate* candidates, int num_candidates, voter* voters, int num_votes) {
    int total_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        candidates[i].votes = 0;
    }
    for (int i = 0; i < num_votes; i++) {
        for (int j = 0; j < num_candidates; j++) {
            candidates[j].votes += voters[i].votes[j];
            total_votes += voters[i].votes[j];
        }
    }
    printf("\nResults:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s - %d votes (%d%%)\n", i + 1, candidates[i].name, candidates[i].votes, (int)(((float)candidates[i].votes / total_votes) * 100.0));
    }
}

int main() {
    candidate candidates[MAX_CANDIDATES];
    voter voters[MAX_VOTERS];
    int num_candidates, num_votes;

    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);

    printf("Enter candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        scanf("%s", candidates[i].name);
    }

    printf("Enter number of voters: ");
    scanf("%d", &num_votes);

    for (int i = 0; i < num_votes; i++) {
        printf("Enter voter %d name: ", i + 1);
        scanf("%s", voters[i].name);
        generate_random_votes(MAX_VOTES, num_candidates, &voters[i]);
    }

    print_candidates(candidates, num_candidates);
    print_results(candidates, num_candidates, voters, num_votes);

    return 0;
}