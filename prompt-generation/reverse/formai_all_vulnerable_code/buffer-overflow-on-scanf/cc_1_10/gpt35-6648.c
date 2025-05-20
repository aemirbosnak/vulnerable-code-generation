//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    int candidate_id;
    int vote_count;
} candidate;

typedef struct {
    int voter_id;
    int candidate_id;
    bool has_voted;
} voter;

void print_candidates(candidate *candidates, int num_candidates);
void print_voters(voter *voters, int num_voters);
int get_candidate_count();
int get_voter_count();
int get_candidate_vote(candidate *candidates, int num_candidates, int candidate_id);
int get_num_votes(candidate *candidates, int num_candidates);
bool is_voter_valid(voter *voters, int num_voters, int voter_id);
bool is_vote_valid(candidate *candidates, int num_candidates, voter *voters, int num_voters, int candidate_id, int voter_id);
void cast_vote(candidate *candidates, int num_candidates, voter *voters, int num_voters, int candidate_id, int voter_id);

int main() {
    candidate candidates[MAX_CANDIDATES];
    int num_candidates = get_candidate_count();
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter name of candidate %d: ", i+1);
        char *candidate_name = (char*)malloc(sizeof(char)*50);
        scanf("%s", candidate_name);
        candidates[i].candidate_id = i+1;
        candidates[i].vote_count = 0;
    }
    print_candidates(candidates, num_candidates);
    
    voter voters[MAX_VOTERS];
    int num_voters = get_voter_count();
    for (int i = 0; i < num_voters; i++) {
        voters[i].voter_id = i+1;
        voters[i].candidate_id = 0;
        voters[i].has_voted = false;
    }
    print_voters(voters, num_voters);
    
    int vote_count = 0;
    while (vote_count < num_voters) {
        printf("Enter voter ID who wants to cast vote: ");
        int voter_id;
        scanf("%d", &voter_id);
        if (!is_voter_valid(voters, num_voters, voter_id)) {
            printf("Invalid voter ID. Please enter valid voter ID.\n");
            continue;
        }
        if (voters[voter_id-1].has_voted) {
            printf("This voter has already cast a vote. Please select another voter ID.\n");
            continue;
        }
        printf("Enter candidate ID for whom the voter wants to cast vote: ");
        int candidate_id;
        scanf("%d", &candidate_id);
        if (!is_vote_valid(candidates, num_candidates, voters, num_voters, candidate_id, voter_id)) {
            printf("Invalid candidate ID. Please enter valid candidate ID.\n");
            continue;
        }
        cast_vote(candidates, num_candidates, voters, num_voters, candidate_id, voter_id);
        vote_count++;
        printf("Vote casted successfully.\n");
    }
    printf("All votes casted. Resuling counts:\n");
    print_candidates(candidates, num_candidates);
    return 0;
}

void print_candidates(candidate *candidates, int num_candidates) {
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d: %d\n", candidates[i].candidate_id, candidates[i].vote_count);
    }
}

void print_voters(voter *voters, int num_voters) {
    printf("Voters:\n");
    for (int i = 0; i < num_voters; i++) {
        printf("%d: %d\n", voters[i].voter_id, voters[i].candidate_id);
    }
}

int get_candidate_count() {
    int num_candidates;
    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);
    return num_candidates;
}

int get_voter_count() {
    int num_voters;
    printf("Enter number of voters: ");
    scanf("%d", &num_voters);
    return num_voters;
}

int get_candidate_vote(candidate *candidates, int num_candidates, int candidate_id) {
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].candidate_id == candidate_id) {
            return candidates[i].vote_count;
        }
    }
    return -1;
}

int get_num_votes(candidate *candidates, int num_candidates) {
    int num_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        num_votes += candidates[i].vote_count;
    }
    return num_votes;
}

bool is_voter_valid(voter *voters, int num_voters, int voter_id) {
    if (voter_id < 1 || voter_id > num_voters) {
        return false;
    }
    return true;
}

bool is_vote_valid(candidate *candidates, int num_candidates, voter *voters, int num_voters, int candidate_id, int voter_id) {
    if (candidate_id < 1 || candidate_id > num_candidates) {
        return false;
    }
    if (voters[voter_id-1].has_voted) {
        return false;
    }
    return true;
}

void cast_vote(candidate *candidates, int num_candidates, voter *voters, int num_voters, int candidate_id, int voter_id) {
    int candidate_vote = get_candidate_vote(candidates, num_candidates, candidate_id);
    if (candidate_vote != -1) {
        candidates[candidate_id-1].vote_count += 1;
    }
    voters[voter_id-1].candidate_id = candidate_id;
    voters[voter_id-1].has_voted = true;
}