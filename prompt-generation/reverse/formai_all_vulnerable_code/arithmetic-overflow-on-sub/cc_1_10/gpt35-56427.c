//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

struct candidate {
    int candidate_id;
    char candidate_name[30];
    int vote_count;
};

int main() {

    int total_voters;
    printf("Enter the total number of voters: ");
    scanf("%d", &total_voters);

    int total_candidates;
    printf("\nEnter the total number of candidates: ");
    scanf("%d", &total_candidates);

    struct candidate candidates[total_candidates];

    for (int i = 0; i < total_candidates; i++) {
        printf("\nEnter the details of candidate %d\n", i+1);
        printf("Candidate ID: ");
        scanf("%d", &candidates[i].candidate_id);
        printf("Candidate Name: ");
        scanf("%s", candidates[i].candidate_name);
        candidates[i].vote_count = 0;
    }

    int vote;
    while (total_voters--) {
        printf("\nEnter the candidate ID to vote: ");
        scanf("%d", &vote);

        for (int i = 0; i < total_candidates; i++) {
            if (vote == candidates[i].candidate_id) {
                candidates[i].vote_count++;
            }
        }
    }

    printf("\nResults:\n");
    printf("Candidate ID\tCandidate Name\tVote Count\n");
    for (int i = 0; i < total_candidates; i++) {
        printf("%d\t\t%s\t\t%d\n", candidates[i].candidate_id, candidates[i].candidate_name, candidates[i].vote_count);
    }

    int winner = 0;
    for (int i = 1; i < total_candidates; i++) {
        if (candidates[i].vote_count > candidates[winner].vote_count) {
            winner = i;
        }
    }

    printf("\nWinner: %s\n", candidates[winner].candidate_name);

    return 0;
}