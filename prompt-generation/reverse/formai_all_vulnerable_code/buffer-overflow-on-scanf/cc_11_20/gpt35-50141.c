//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 25

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} candidate;

int main(void) {
    int num_voters, num_candidates;

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Initialize candidates
    candidate candidates[MAX_CANDIDATES];
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Initialize voters
    char voter_names[MAX_VOTERS][MAX_NAME_LENGTH];
    int votes[MAX_VOTERS][MAX_CANDIDATES];
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i+1);
        scanf("%s", voter_names[i]);

        for (int j = 0; j < num_candidates; j++) {
            printf("Enter the vote for candidate %d: ", j+1);
            scanf("%d", &votes[i][j]);
        }
    }

    // Count votes
    for (int i = 0; i < num_voters; i++) {
        int max_vote = -1, max_index = -1;

        for (int j = 0; j < num_candidates; j++) {
            int vote = votes[i][j];

            if (vote > max_vote) {
                max_vote = vote;
                max_index = j;
            }
        }

        candidates[max_index].votes++;
    }

    // Print results
    printf("Results:\n");
    int total_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].votes);
        total_votes += candidates[i].votes;
    }

    printf("Total votes: %d\n", total_votes);

    if (total_votes > num_voters) {
        printf("Invalid election: more votes than voters!\n");
        return 1;
    }

    candidate winner = candidates[0];
    for (int i = 1; i < num_candidates; i++) {
        if (candidates[i].votes > winner.votes) {
            winner = candidates[i];
        }
    }

    printf("Winner: %s\n", winner.name);

    return 0;
}