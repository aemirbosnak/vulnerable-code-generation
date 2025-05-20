//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int voter_id;
    int candidate_id;
    char voted;
} Vote;

void cast_vote(Vote *vote, int num_candidates) {
    printf("Enter Voter ID: ");
    scanf("%d", &vote->voter_id);
    printf("Enter Candidate ID: ");
    scanf("%d", &vote->candidate_id);
    if(vote->candidate_id < 1 || vote->candidate_id > num_candidates) {
        printf("Invalid Candidate ID\n");
    } else {
        vote->voted = 1;
        printf("Vote Cast Successfully\n");
    }
}

void print_results(Vote *votes, int num_votes, int num_candidates) {
    int *results = (int*) calloc(num_candidates+1, sizeof(int));
    for(int i = 0; i < num_votes; i++) {
        if(votes[i].voted) {
            results[votes[i].candidate_id]++;
        }
    }
    printf("\nVote Results:\n");
    for(int i = 1; i <= num_candidates; i++) {
        printf("Candidate %d: %d votes\n", i, results[i]);
    }
    free(results);
}

int main() {
    int num_voters, num_candidates;
    printf("Enter Number of Voters: ");
    scanf("%d", &num_voters);
    printf("Enter Number of Candidates: ");
    scanf("%d", &num_candidates);

    Vote *votes = (Vote*) calloc(num_voters, sizeof(Vote));

    for(int i = 0; i < num_voters; i++) {
        printf("\nVote %d:\n", i+1);
        cast_vote(&votes[i], num_candidates);
    }

    print_results(votes, num_voters, num_candidates);

    free(votes);
    return 0;
}