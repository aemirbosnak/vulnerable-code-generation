//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define data structures
typedef struct Candidate {
    char name[50];
    int votes;
} Candidate;

typedef struct Election {
    int num_candidates;
    Candidate* candidates;
} Election;

// Function prototypes
void register_candidates(Election* election);
void cast_vote(Election* election, int candidate_index);
void count_votes(Election* election);

int main() {
    // Initialize the election
    Election election;
    election.num_candidates = 0;

    // Register candidates
    register_candidates(&election);

    // Allow users to cast votes
    int num_votes = 0;
    while (num_votes < election.num_candidates) {
        int candidate_index;
        printf("Enter the index of the candidate you want to vote for: ");
        scanf("%d", &candidate_index);
        if (candidate_index >= 0 && candidate_index < election.num_candidates) {
            cast_vote(&election, candidate_index);
            num_votes++;
        } else {
            printf("Invalid candidate index. Please try again.\n");
        }
    }

    // Count votes
    count_votes(&election);

    // Display the results
    printf("\nResults:\n");
    for (int i = 0; i < election.num_candidates; i++) {
        printf("%s: %d votes\n", election.candidates[i].name, election.candidates[i].votes);
    }

    return 0;
}

void register_candidates(Election* election) {
    printf("Enter the number of candidates: ");
    scanf("%d", &election->num_candidates);

    election->candidates = malloc(election->num_candidates * sizeof(Candidate));

    for (int i = 0; i < election->num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", election->candidates[i].name);
        election->candidates[i].votes = 0;
    }
}

void cast_vote(Election* election, int candidate_index) {
    election->candidates[candidate_index].votes++;
}

void count_votes(Election* election) {
    for (int i = 0; i < election->num_candidates; i++) {
        election->candidates[i].votes = 0;
    }

    for (int i = 0; i < election->num_candidates; i++) {
        election->candidates[i].votes += election->candidates[i].votes;
    }
}