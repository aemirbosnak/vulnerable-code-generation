//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 20
#define MAX_VOTERS 1000
#define MAX_NAME_LENGTH 30
#define MAX_PARTY_LENGTH 20

typedef struct candidate {
    char name[MAX_NAME_LENGTH];
    char party[MAX_PARTY_LENGTH];
    int votes;
} candidate;

typedef struct voter {
    char name[MAX_NAME_LENGTH];
    int voted;
} voter;

void initialize_candidates(candidate candidates[MAX_CANDIDATES], int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        candidates[i].votes = 0;
        printf("Enter candidate %d's name: ", i+1);
        scanf("%s", candidates[i].name);
        printf("Enter candidate %d's party: ", i+1);
        scanf("%s", candidates[i].party);
    }
}

void display_candidates(candidate candidates[MAX_CANDIDATES], int num_candidates) {
    printf("List of candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s (%s)\n", i+1, candidates[i].name, candidates[i].party);
    }
}

void cast_vote(candidate candidates[MAX_CANDIDATES], int num_candidates, voter voters[MAX_VOTERS], int num_voters) {
    char name[MAX_NAME_LENGTH];
    int found = 0;
    printf("Enter your name: ");
    scanf("%s", name);
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(voters[i].name, name) == 0) {
            if (voters[i].voted == 1) {
                printf("You have already voted.\n");
                return;
            } else {
                printf("Welcome back, %s.\n", voters[i].name);
                voters[i].voted = 1;
            }
            found = 1;
        }
    }
    if (!found) {
        printf("You are not registered as a voter.\n");
        return;
    }
    printf("Enter the number of the candidate you wish to vote for: ");
    int candidate_num;
    scanf("%d", &candidate_num);
    if (candidate_num < 1 || candidate_num > num_candidates) {
        printf("Invalid candidate number.\n");
        return;
    }
    candidates[candidate_num-1].votes++;
    printf("Thank you for voting for %s.\n", candidates[candidate_num-1].name);
}

void display_results(candidate candidates[MAX_CANDIDATES], int num_candidates) {
    candidate winner = candidates[0];
    printf("Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s (%s): %d votes\n", candidates[i].name, candidates[i].party, candidates[i].votes);
        if (candidates[i].votes > winner.votes) {
            winner = candidates[i];
        }
    }
    printf("Winner: %s (%s)\n", winner.name, winner.party);
}

int main() {
    srand(time(NULL));
    int num_candidates = 0;
    while (num_candidates <= 0 || num_candidates > MAX_CANDIDATES) {
        printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
        scanf("%d", &num_candidates);
    }
    candidate candidates[num_candidates];
    initialize_candidates(candidates, num_candidates);
    display_candidates(candidates, num_candidates);
    int num_voters = 0;
    while (num_voters <= 0 || num_voters > MAX_VOTERS) {
        printf("Enter the number of voters (max %d): ", MAX_VOTERS);
        scanf("%d", &num_voters);
    }
    voter voters[num_voters];
    for (int i = 0; i < num_voters; i++) {
        voters[i].voted = 0;
        printf("Enter voter %d's name: ", i+1);
        scanf("%s", voters[i].name);
    }
    int voting_open = 1;
    while (voting_open) {
        printf("Enter '0' to display election results.\n");
        printf("Enter '1' to cast a vote.\n");
        printf("Enter any other number to exit.\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                display_results(candidates, num_candidates);
                break;
            case 1:
                cast_vote(candidates, num_candidates, voters, num_voters);
                break;
            default:
                printf("Thanks for using the electronic voting system!\n");
                voting_open = 0;
                break;
        }
    }
    return 0;
}