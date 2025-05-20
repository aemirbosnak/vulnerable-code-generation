//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10

struct voter {
    int id;
    int voted_candidate;
};

struct candidate {
    int votes;
    char name[30];
};

int main() {

    struct voter voters[MAX_VOTERS];
    struct candidate candidates[MAX_CANDIDATES];

    int num_voters, num_candidates;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    printf("\nEnter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Initialize candidates
    for (int i = 0; i < num_candidates; i++) {
        candidates[i].votes = 0;
        printf("\nEnter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
    }

    // Register voters
    for (int i = 0; i < num_voters; i++) {
        voters[i].id = i+1;
        voters[i].voted_candidate = -1;
    }

    // Voting process
    int vote_count = 0, candidate_id;
    printf("\nVoting Begins..\n");
    while (vote_count < num_voters) {
        printf("\nVoter %d, please enter your candidate id (1 to %d, 0 to abstain): ",
              voters[vote_count].id, num_candidates);
        scanf("%d", &candidate_id);

        if (candidate_id == 0) {
            printf("\nThank you for your vote.\n");
            vote_count++;
            continue;
        }

        if (candidate_id < 1 || candidate_id > num_candidates) {
            printf("\nInvalid Candidate ID, please try again.\n");
            continue;
        }

        if (voters[vote_count].voted_candidate == -1) {
            voters[vote_count].voted_candidate = candidate_id-1;
            candidates[candidate_id-1].votes++;
            printf("\nThank you for your vote!\n");
            vote_count++;
        } else {
            printf("\nYou have already voted, please wait for the results.\n");
        }
    }

    // Compute Results and declare winner
    int max_votes = candidates[0].votes, max_index = 0;
    for (int i = 1; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            max_index = i;
        }
    }
    printf("\nResults:");
    printf("\nCandidate Name\tVotes Received");
    printf("\n--------------------------------");
    for (int i = 0; i < num_candidates; i++) {
        printf("\n%s\t\t%d", candidates[i].name, candidates[i].votes);
    }
    printf("\nWinner: %s", candidates[max_index].name);

    return 0;
}