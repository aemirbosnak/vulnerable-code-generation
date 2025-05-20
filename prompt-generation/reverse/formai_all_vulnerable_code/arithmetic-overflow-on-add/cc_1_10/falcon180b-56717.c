//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_VOTES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes[MAX_CANDIDATES];
} Voter;

int main() {
    int num_candidates, num_voters;
    char input_buffer[1024];
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int i, j, k, vote_index, candidate_index;

    printf("Welcome to the Electronic Voting System!\n");
    printf("How many candidates are running for the election? ");
    fgets(input_buffer, 1024, stdin);
    num_candidates = atoi(input_buffer);

    printf("Enter the names of the candidates:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("Candidate %d: ", i + 1);
        fgets(input_buffer, 1024, stdin);
        strcpy(candidates[i].name, input_buffer);
    }

    printf("How many voters are registered? ");
    fgets(input_buffer, 1024, stdin);
    num_voters = atoi(input_buffer);

    printf("Enter the names of the voters:\n");
    for (i = 0; i < num_voters; i++) {
        printf("Voter %d: ", i + 1);
        fgets(input_buffer, 1024, stdin);
        strcpy(voters[i].name, input_buffer);
        for (j = 0; j < num_candidates; j++) {
            printf("Vote for %s: ", candidates[j].name);
            fgets(input_buffer, 1024, stdin);
            voters[i].votes[j] = atoi(input_buffer);
        }
    }

    printf("Votes cast:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d\n", candidates[i].name, 0);
    }

    for (i = 0; i < num_voters; i++) {
        for (j = 0; j < num_candidates; j++) {
            candidates[j].votes += voters[i].votes[j];
        }
    }

    printf("\nElection results:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}