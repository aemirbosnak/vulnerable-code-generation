//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_CANDIDATES 100

typedef struct candidate {
    int id;
    char name[50];
    int votes;
} Candidate;

typedef struct ballot {
    int voter_id;
    int candidate_id;
} Ballot;

Candidate candidates[MAX_CANDIDATES];
Ballot *ballots;
int num_candidates, num_voters;

void get_candidates() {
    printf("Enter number of candidates:");
    scanf("%d", &num_candidates);

    for (int i=0; i<num_candidates; i++) {
        printf("\nEnter details for candidate %d:\n", i+1);
        candidates[i].id = i+1;
        printf("ID: %d\n", candidates[i].id);
        printf("Name: ");
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void get_voters() {
    printf("\nEnter number of voters:");
    scanf("%d", &num_voters);

    ballots = (Ballot*) malloc(num_voters * sizeof(Ballot));

    for (int i=0; i<num_voters; i++) {
        printf("\nEnter details for voter %d:\n", i+1);
        ballots[i].voter_id = i+1;
        printf("ID: %d\n", ballots[i].voter_id);
        printf("Enter candidate ID (1-%d): ", num_candidates);
        scanf("%d", &ballots[i].candidate_id);

        if (ballots[i].candidate_id < 1 || ballots[i].candidate_id > num_candidates) {
            printf("Invalid candidate ID. Please try again.\n");
            i--;
        }
    }
}

void cast_votes() {
    for (int i=0; i<num_voters; i++) {
        int candidate_id = ballots[i].candidate_id;
        candidates[candidate_id-1].votes++;
    }
}

void display_results() {
    printf("\nELECTION RESULTS\n");
    printf("-------------------------------------------------\n");
    printf("Candidate\t\tVotes Received\t\tPercentage\n");
    printf("-------------------------------------------------\n");

    for (int i=0; i<num_candidates; i++) {
        float percent = ((float) candidates[i].votes / num_voters) * 100;
        printf("%s\t\t\t%d\t\t\t%.2f %%\n", candidates[i].name, candidates[i].votes, percent);
    }

    printf("-------------------------------------------------\n");
    printf("Winner: ");

    int max_votes = -1, winner_id;
    for (int i=0; i<num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_id = i;
        }
    }

    printf("%s\n", candidates[winner_id].name);
}

int main() {
    printf("WELCOME TO THE ELECTRONIC VOTING SYSTEM\n");
    printf("--------------------------------------\n");

    get_candidates();
    get_voters();

    printf("\nCAST YOUR VOTES\n");
    printf("----------------\n");

    cast_votes();
    display_results();

    return 0;
}