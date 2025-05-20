//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50
#define MAX_VOTES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int voter_id;
} Voter;

int main() {
    int num_candidates, num_voters;
    scanf("%d %d", &num_candidates, &num_voters);

    // Read in candidate information
    Candidate candidates[MAX_CANDIDATES];
    for (int i = 0; i < num_candidates; i++) {
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Read in voter information
    Voter voters[MAX_VOTERS];
    for (int i = 0; i < num_voters; i++) {
        scanf("%s", voters[i].name);
        voters[i].voter_id = i + 1;
    }

    // Voters cast their ballots
    for (int i = 0; i < num_voters; i++) {
        printf("Voter %d, please enter your ballot:\n", voters[i].voter_id);
        char ballot[MAX_CANDIDATES];
        scanf("%s", ballot);
        int num_votes = strlen(ballot);
        for (int j = 0; j < num_votes; j++) {
            if (ballot[j] >= 'A' && ballot[j] <= 'Z') {
                int candidate_index = ballot[j] - 'A';
                if (candidate_index >= 0 && candidate_index < num_candidates) {
                    candidates[candidate_index].votes++;
                }
            }
        }
    }

    // Print election results
    printf("Election results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}