//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VOTERS 10000
#define MAX_CANDIDATES 5

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    int voter_id;
    int candidate_id;
    time_t timestamp;
} Vote;

Candidate candidates[MAX_CANDIDATES];
Vote votes[MAX_VOTERS];
int num_voters = 0;
int num_candidates = 0;

void register_candidate(char *name) {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Max number of candidates reached.\n");
        return;
    }

    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void vote(int voter_id, int candidate_id) {
    if (num_voters >= MAX_VOTERS) {
        printf("Max number of voters reached.\n");
        return;
    }

    if (voter_id < 1 || voter_id > num_voters || candidate_id < 1 || candidate_id > num_candidates) {
        printf("Invalid voter or candidate id.\n");
        return;
    }

    votes[num_voters].voter_id = voter_id;
    votes[num_voters].candidate_id = candidate_id;
    votes[num_voters].timestamp = time(NULL);
    candidates[candidate_id - 1].votes++;
    num_voters++;
}

void print_results() {
    printf("\n--- ELECTronic VOTING SYSTEM RESULTS ---\n");
    printf("\nCANDIDATE NAME\tTOTAL VOTES\n");

    for (int i = 0; i < num_candidates; i++) {
        printf("%s\t\t%d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to the FUTURISTIC ELECTRONIC VOTING SYSTEM.\n");
    printf("Please register candidates.\n");

    char candidate_name[50];

    for (int i = 0; i < 10; i++) {
        printf("Enter candidate %d name: ", i + 1);
        scanf("%s", candidate_name);
        register_candidate(candidate_name);
    }

    printf("\nNow let's start the voting process.\n");

    int voter_id, candidate_id;

    for (int i = 0; i < 1000; i++) {
        voter_id = rand() % (num_voters + 1);
        candidate_id = rand() % (num_candidates + 1);
        vote(voter_id, candidate_id);
    }

    printf("\nVoting completed.\n");
    print_results();

    return 0;
}