//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10

typedef struct {
    int id;
    char name[50];
    int votes;
} candidate;

int num_voters = 0;
int num_candidates = 0;
int voter_voted[MAX_VOTERS] = {0};
int candidate_win[MAX_CANDIDATES] = {0};
candidate candidates[MAX_CANDIDATES];

void display_menu() {
    printf("\nWelcome to the Electronic Voting System!\n");
    printf("---------------------------------------\n");
    printf("1. Register a candidate\n");
    printf("2. View list of candidates\n");
    printf("3. Start voting\n");
    printf("4. View election results\n");
    printf("5. End election\n");
}

void register_candidate() {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("\nSorry, the maximum number of candidates has been reached.\n");
    }
    else {
        candidate new_candidate;
        printf("\nEnter candidate name: ");
        scanf("%s", new_candidate.name);
        new_candidate.id = num_candidates + 1;
        new_candidate.votes = 0;
        candidates[num_candidates] = new_candidate;
        num_candidates++;
        printf("\nCandidate registered successfully!\n");
    }
}

void view_candidates() {
    printf("\nList of Candidates\n");
    printf("------------------\n");
    for (int i = 0; i < num_candidates; i++) {
        candidate c = candidates[i];
        printf("Candidate %d: %s\n", c.id, c.name);
    }
}

void cast_vote() {
    printf("\nEnter your voter ID: ");
    int voter_id;
    scanf("%d", &voter_id);
    if (voter_id <= 0 || voter_id > MAX_VOTERS) {
        printf("\nInvalid voter ID.\n");
    }
    else if (voter_voted[voter_id - 1] == 1) {
        printf("\nSorry, you have already voted.\n");
    }
    else {
        printf("\nCandidates\n");
        printf("----------\n");
        for (int i = 0; i < num_candidates; i++) {
            candidate c = candidates[i];
            printf("%d. %s\n", c.id, c.name);
        }
        printf("\nEnter candidate ID to vote for: ");
        int candidate_id;
        scanf("%d", &candidate_id);
        if (candidate_id < 1 || candidate_id > num_candidates) {
            printf("\nInvalid candidate ID.\n");
        }
        else {
            candidates[candidate_id - 1].votes++;
            voter_voted[voter_id - 1] = 1;
            printf("\nThank you for voting!\n");
        }
    }
}

void tally_votes() {
    printf("\nElection Results\n");
    printf("----------------\n");
    int total_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        candidate c = candidates[i];
        printf("%d. %s - %d votes\n", c.id, c.name, c.votes);
        total_votes += c.votes;
    }
    printf("\nTotal votes cast: %d\n", total_votes);
}

void end_election() {
    printf("\nElection ended. Here are the final results:\n");
    printf("------------------------------------------\n");
    int max_votes = 0;
    int winner_id = 0;
    for (int i = 0; i < num_candidates; i++) {
        candidate c = candidates[i];
        if (c.votes > max_votes) {
            max_votes = c.votes;
            winner_id = c.id;
        }
        candidate_win[i] = c.votes;
        printf("%d. %s - %d votes\n", c.id, c.name, c.votes);
    }
    printf("\nWinner: Candidate %d\n", winner_id);
}

int main() {
    int choice = 0;
    do {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: register_candidate(); break;
            case 2: view_candidates(); break;
            case 3: cast_vote(); break;
            case 4: tally_votes(); break;
            case 5: end_election(); break;
            default: printf("\nInvalid choice. Please try again.\n"); break;
        }
    } while (choice != 5);
    return 0;
}