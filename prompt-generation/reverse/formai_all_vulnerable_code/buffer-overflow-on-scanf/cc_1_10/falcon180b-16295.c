//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_VOTES 10

typedef struct {
    char name[100];
    int votes[MAX_CANDIDATES];
} Candidate;

typedef struct {
    char name[100];
    int voter_id;
    int votes[MAX_CANDIDATES];
} Voter;

void initialize_candidates(Candidate candidates[]) {
    int i;
    for(i=0; i<MAX_CANDIDATES; i++) {
        strcpy(candidates[i].name, "Candidate ");
        sprintf(candidates[i].name+strlen("Candidate "), "%d", i+1);
        candidates[i].votes[i] = 0;
    }
}

void initialize_voters(Voter voters[]) {
    int i;
    for(i=0; i<MAX_VOTERS; i++) {
        strcpy(voters[i].name, "Voter ");
        sprintf(voters[i].name+strlen("Voter "), "%d", i+1);
        voters[i].voter_id = i+1;
        voters[i].votes[0] = 0;
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int num_candidates, num_voters, i, j, k, candidate_index, voter_index;
    char choice;
    int total_votes = 0;

    printf("Welcome to the Electronic Voting System!\n");
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    initialize_candidates(candidates);

    printf("Enter the name of candidate 1: ");
    scanf("%s", candidates[0].name);
    printf("Enter the name of candidate 2: ");
    scanf("%s", candidates[1].name);
    // add more candidates

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    initialize_voters(voters);

    printf("Voting has started!\n");
    for(i=0; i<num_voters; i++) {
        voter_index = rand() % num_voters;
        printf("Voter %d is casting their vote...\n", voters[voter_index].voter_id);
        for(j=0; j<num_candidates; j++) {
            printf("Candidate %s has %d votes.\n", candidates[j].name, candidates[j].votes[j]);
        }
        printf("Please enter your choice (1-%d): ", num_candidates);
        scanf("%d", &choice);
        candidate_index = choice - 1;
        candidates[candidate_index].votes[candidate_index]++;
        voters[voter_index].votes[candidate_index]++;
        total_votes++;
    }

    printf("Voting has ended!\n");
    printf("Total votes cast: %d\n", total_votes);
    for(i=0; i<num_candidates; i++) {
        printf("Candidate %s has %d votes.\n", candidates[i].name, candidates[i].votes[i]);
    }

    return 0;
}