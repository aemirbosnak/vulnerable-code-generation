//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define the maximum number of candidates
#define MAX_CANDIDATES 5

// define the maximum number of voters
#define MAX_VOTERS 50

// define the maximum number of votes per voter
#define MAX_VOTES_PER_VOTER 3

// define the candidate structure
typedef struct {
    int id;
    char name[50];
    int votes;
} Candidate;

// define the voter structure
typedef struct {
    int id;
    char name[50];
    int votes[MAX_VOTES_PER_VOTER];
    int num_votes;
    bool voted;
} Voter;

// declare global variables for candidates and voters
Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];

// function to add candidate
void add_candidate(int id, char *name) {
    Candidate candidate;
    candidate.id = id;
    strcpy(candidate.name, name);
    candidate.votes = 0;
    candidates[id] = candidate;
}

// function to add voter
void add_voter(int id, char *name) {
    Voter voter;
    voter.id = id;
    strcpy(voter.name, name);
    voter.num_votes = 0;
    voter.voted = false;
    voters[id] = voter;
}

// function to display candidates
void display_candidates() {
    printf("\n*** List of Candidates ***\n");
    for(int i = 0; i < MAX_CANDIDATES; i++) {
        if(candidates[i].id != 0) {
            printf("%d. %s\n", candidates[i].id, candidates[i].name);
        }
    }
}

// function to cast vote
void cast_vote(int voter_id) {
    if(voters[voter_id].voted == true) {
        printf("Error: You have already voted.\n");
        return;
    }
    printf("Enter your %d choice: ", voters[voter_id].num_votes+1);
    int candidate_id;
    scanf("%d", &candidate_id);
    if(candidate_id < 1 || candidate_id > MAX_CANDIDATES) {
        printf("Error: Invalid candidate id.\n");
        return;
    }
    for(int i = 0; i < voters[voter_id].num_votes; i++) {
        if(voters[voter_id].votes[i] == candidate_id) {
            printf("Error: You have already voted for this candidate.\n");
            return;
        }
    }
    candidates[candidate_id-1].votes++;
    voters[voter_id].votes[voters[voter_id].num_votes] = candidate_id;
    voters[voter_id].num_votes++;
    printf("Thank you for your vote.\n");
    voters[voter_id].voted = true;
}

// function to display results
void display_results() {
    printf("\n*** Results ***\n");
    bool tie = true;
    int max_votes = 0;
    for(int i = 0; i < MAX_CANDIDATES; i++) {
        if(candidates[i].id != 0) {
            if(candidates[i].votes > max_votes) {
                max_votes = candidates[i].votes;
                tie = false;
            } else if(candidates[i].votes == max_votes) {
                tie = true;
            }
        }
    }
    if(tie) {
        printf("Tie between multiple candidates.\n");
        return;
    }
    for(int i = 0; i < MAX_CANDIDATES; i++) {
        if(candidates[i].id != 0) {
            if(candidates[i].votes == max_votes) {
                printf("%s: %d vote(s)\n", candidates[i].name, candidates[i].votes);
            }
        }
    }
}

// main function
int main() {
    // add candidates
    add_candidate(1, "Candidate 1");
    add_candidate(2, "Candidate 2");
    add_candidate(3, "Candidate 3");
    add_candidate(4, "Candidate 4");
    add_candidate(5, "Candidate 5");

    // add voters
    add_voter(1, "Voter 1");
    add_voter(2, "Voter 2");
    add_voter(3, "Voter 3");
    add_voter(4, "Voter 4");
    add_voter(5, "Voter 5");

    // display candidates
    display_candidates();

    // let voters cast their votes
    cast_vote(1);
    cast_vote(2);
    cast_vote(3);
    cast_vote(4);
    cast_vote(5);

    // display results
    display_results();

    return 0;
}