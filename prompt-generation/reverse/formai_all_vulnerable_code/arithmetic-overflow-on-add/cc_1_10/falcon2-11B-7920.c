//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int vote;
    char* name;
} Candidate;

typedef struct {
    int num_candidates;
    Candidate* candidates;
} Election;

int main() {
    Election election;
    int num_candidates;

    printf("How many candidates are there in the election? ");
    scanf("%d", &num_candidates);

    election.num_candidates = num_candidates;
    election.candidates = (Candidate*)malloc(num_candidates * sizeof(Candidate));

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d's name: ", i + 1);
        fgets(election.candidates[i].name, sizeof(election.candidates[i].name), stdin);
        election.candidates[i].vote = 0;
    }

    printf("Enter candidate %d's vote: ", num_candidates);
    scanf("%d", &election.candidates[num_candidates].vote);

    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s - %d\n", i + 1, election.candidates[i].name, election.candidates[i].vote);
    }

    int winner_index;
    int max_vote = election.candidates[0].vote;

    for (int i = 1; i < num_candidates; i++) {
        if (election.candidates[i].vote > max_vote) {
            winner_index = i;
            max_vote = election.candidates[i].vote;
        }
    }

    printf("The winner is candidate %d with %d votes.\n", winner_index + 1, max_vote);

    free(election.candidates);
    return 0;
}