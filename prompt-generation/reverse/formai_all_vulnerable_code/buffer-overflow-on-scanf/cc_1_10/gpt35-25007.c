//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10

// Voter structure
typedef struct voter {
    int id;
    int vote;
    int has_voted;
} Voter;

// Candidate structure
typedef struct candidate {
    int id;
    char name[50];
    int votes;
} Candidate;

// Initialize voters
void init_voters(Voter* voters, int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        voters[i].id = i + 1;
        voters[i].vote = -1;
        voters[i].has_voted = 0;
    }
}

// Initialize candidates
void init_candidates(Candidate* candidates, int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        candidates[i].id = i + 1;
        printf("Enter candidate %d name: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

// Display candidates
void display_candidates(Candidate* candidates, int num_candidates) {
    printf("List of candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }
}

// Vote for candidate
void cast_vote(Voter* voter, Candidate* candidate) {
    voter->has_voted = 1;
    voter->vote = candidate->id;
    candidate->votes += 1;
    printf("Thank you for voting!\n");
}

// Display election results
void display_results(Candidate* candidates, int num_candidates) {
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int num_voters, num_candidates;
    Voter voters[MAX_VOTERS];
    Candidate candidates[MAX_CANDIDATES];

    printf("Enter number of voters: ");
    scanf("%d", &num_voters);
    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);

    if (num_voters > MAX_VOTERS || num_candidates > MAX_CANDIDATES) {
        printf("Error: too many voters or candidates.\n");
        return 1;
    }

    init_voters(voters, num_voters);
    init_candidates(candidates, num_candidates);

    while (1) {
        int voter_id, candidate_id;
        printf("Enter voter id (0 to quit): ");
        scanf("%d", &voter_id);

        if (voter_id == 0) break;

        if (voters[voter_id-1].has_voted) {
            printf("Error: voter has already voted.\n");
            continue;
        }

        display_candidates(candidates, num_candidates);
        printf("Enter candidate id to vote for: ");
        scanf("%d", &candidate_id);

        for (int i = 0; i < num_candidates; i++) {
            if (candidates[i].id == candidate_id) {
                cast_vote(&voters[voter_id-1], &candidates[i]);
                break;
            }
            if (i == num_candidates - 1) {
                printf("Error: invalid candidate id.\n");
            }
        }
    }

    display_results(candidates, num_candidates);

    return 0;
}