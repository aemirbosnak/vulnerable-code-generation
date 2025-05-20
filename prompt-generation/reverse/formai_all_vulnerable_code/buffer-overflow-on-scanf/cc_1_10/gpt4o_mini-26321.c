//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[30];
    int votes;
} Candidate;

typedef struct {
    char voter_id[10];
    int has_voted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int total_candidates = 0;
int total_voters = 0;

void initialize_candidates() {
    printf("Enter number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &total_candidates);
    
    if (total_candidates > MAX_CANDIDATES) {
        printf("Exceeded maximum number of candidates. Setting to %d.\n", MAX_CANDIDATES);
        total_candidates = MAX_CANDIDATES;
    }

    for (int i = 0; i < total_candidates; i++) {
        printf("Enter candidate %d name: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void initialize_voters() {
    printf("Enter number of voters (max %d): ", MAX_VOTERS);
    scanf("%d", &total_voters);

    if (total_voters > MAX_VOTERS) {
        printf("Exceeded maximum number of voters. Setting to %d.\n", MAX_VOTERS);
        total_voters = MAX_VOTERS;
    }

    for (int i = 0; i < total_voters; i++) {
        printf("Enter voter %d ID: ", i + 1);
        scanf("%s", voters[i].voter_id);
        voters[i].has_voted = 0;
    }
}

void cast_vote() {
    for (int i = 0; i < total_voters; i++) {
        if (voters[i].has_voted == 0) {
            printf("Voter %s, cast your vote (enter candidate number 1-%d): ", voters[i].voter_id, total_candidates);
            int candidate_number;
            scanf("%d", &candidate_number);

            if (candidate_number < 1 || candidate_number > total_candidates) {
                printf("Invalid candidate number. You cannot vote.\n");
                continue;
            }

            candidates[candidate_number - 1].votes++;
            voters[i].has_voted = 1;
            printf("Thank you, %s! Your vote has been recorded for %s.\n", voters[i].voter_id, candidates[candidate_number - 1].name);
        } else {
            printf("Voter %s has already voted.\n", voters[i].voter_id);
        }
    }
}

void declare_results() {
    printf("\n--- Election Results ---\n");
    for (int i = 0; i < total_candidates; i++) {
        printf("Candidate: %s, Votes: %d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    printf("Welcome to the Electronic Voting System\n");
    
    initialize_candidates();
    initialize_voters();
    
    cast_vote();
    
    declare_results();
    
    return 0;
}