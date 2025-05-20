//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants for number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// define structures for candidate and voter
typedef struct {
    int id;
    char name[20];
    int votes;
} Candidate;

typedef struct {
    int id;
    char name[20];
    int voted_for;
} Voter;

int main() {
    // initialize candidates and voters array
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    // initialize candidates
    candidates[0].id = 1;
    strcpy(candidates[0].name, "Alice");
    candidates[0].votes = 0;

    candidates[1].id = 2;
    strcpy(candidates[1].name, "Bob");
    candidates[1].votes = 0;

    // get number of voters
    int num_voters;
    printf("Enter number of voters: ");
    scanf("%d", &num_voters);

    // check if number of voters is not greater than maximum allowed
    if (num_voters > MAX_VOTERS) {
        printf("Error: Number of voters exceeds maximum allowed!\n");
        return 1;
    }

    // collect voter information
    for (int i = 0; i < num_voters; i++) {
        printf("Enter voter %d id and name: ", i + 1);
        int id;
        char name[20];
        scanf("%d %s", &id, name);

        // check if voter already exists in the list
        for (int j = 0; j < i; j++) {
            if (voters[j].id == id) {
                printf("Error: Voter with same id already exists!\n");
                return 1;
            }
        }

        // add voter to the list
        voters[i].id = id;
        strcpy(voters[i].name, name);
        voters[i].voted_for = 0;
    }

    // start voting process
    printf("Voting has started!\n");
    int num_votes = 0;
    while (num_votes < num_voters) {
        printf("Enter voter id and candidate id to cast your vote: ");
        int voter_id, candidate_id;
        scanf("%d %d", &voter_id, &candidate_id);

        // check if provided voter id is valid
        int voter_index = -1;
        for (int i = 0; i < num_voters; i++) {
            if (voters[i].id == voter_id) {
                voter_index = i;
                break;
            }
        }
        if (voter_index == -1) {
            printf("Error: Invalid voter id!\n");
            continue;
        }

        // check if provided candidate id is valid
        int candidate_index = -1;
        for (int i = 0; i < MAX_CANDIDATES; i++) {
            if (candidates[i].id == candidate_id) {
                candidate_index = i;
                break;
            }
        }
        if (candidate_index == -1) {
            printf("Error: Invalid candidate id!\n");
            continue;
        }

        // check if voter has already voted
        if (voters[voter_index].voted_for != 0) {
            printf("Error: This voter has already voted!\n");
            continue;
        }

        // cast vote and update vote count
        candidates[candidate_index].votes++;
        voters[voter_index].voted_for = candidate_id;
        num_votes++;

        printf("Vote casted successfully!\n");
    }

    // print final result
    printf("\nVoting result:\n\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}