//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CANDIDATES 5

typedef struct {
    char name[20];
    int votes;
} candidate;

int cast_vote(candidate candidates[]) {
    int vote;
    printf("\n\nEnter candidate number to vote for: ");
    scanf("%d", &vote);

    if(vote < 1 || vote > MAX_CANDIDATES) {
        printf("Invalid candidate number!\n");
        return 0;
    }

    candidates[vote - 1].votes++;
    printf("\nThank you for voting!\n");
    return 1;
}

void display_results(candidate candidates[]) {
    int i;
    printf("\n\nResults:\n");
    for(i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d. %s - %d votes\n", i+1, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int voters, i, vote_count = 0;
    candidate candidates[MAX_CANDIDATES];
    char candidate_name[20];

    //Initialize candidates
    for(i = 0; i < MAX_CANDIDATES; i++) {
        printf("Enter candidate %d name: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("\nEnter number of voters: ");
    scanf("%d", &voters);

    //Start voting
    for(i = 0; i < voters; i++) {
        printf("\n\nVoter %d\n", i+1);
        if(cast_vote(candidates)) vote_count++;
    }

    if(vote_count < voters) printf("\n\nVoting ended early.");

    //Display results
    display_results(candidates);

    //Find winner
    int max_votes = 0, winner;
    for(i = 0; i < MAX_CANDIDATES; i++) {
        if(candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner = i;
        }
    }
    printf("\n\nWinner: %s with %d votes\n", candidates[winner].name, candidates[winner].votes);

    return 0;
}