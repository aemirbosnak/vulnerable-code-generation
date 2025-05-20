//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_VOTES 10

typedef struct {
    int voter_id;
    char* name;
    int age;
} Voter;

typedef struct {
    int candidate_id;
    char* name;
} Candidate;

typedef struct {
    int votes[MAX_VOTES];
    int num_votes;
} Vote;

int main() {
    Voter voters[MAX_VOTERS];
    Candidate candidates[MAX_VOTES];
    Vote votes[MAX_VOTERS];

    int num_voters, num_candidates, num_votes, i, j, k, l;
    char choice, input[100];

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the number of voters: ");
    scanf("%d", &num_voters);

    printf("Please enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (i = 0; i < num_voters; i++) {
        printf("Please enter voter %d's details:\n", i + 1);
        printf("Voter ID: ");
        scanf("%d", &(voters[i].voter_id));
        printf("Name: ");
        scanf("%s", input);
        voters[i].name = (char*)malloc(strlen(input) + 1);
        strcpy(voters[i].name, input);
        printf("Age: ");
        scanf("%d", &(voters[i].age));
    }

    for (j = 0; j < num_candidates; j++) {
        printf("Please enter candidate %d's details:\n", j + 1);
        printf("Candidate ID: ");
        scanf("%d", &(candidates[j].candidate_id));
        printf("Name: ");
        scanf("%s", input);
        candidates[j].name = (char*)malloc(strlen(input) + 1);
        strcpy(candidates[j].name, input);
    }

    printf("Please enter the number of votes: ");
    scanf("%d", &num_votes);

    for (k = 0; k < num_votes; k++) {
        printf("Please enter vote %d's details:\n", k + 1);
        printf("Candidate ID: ");
        scanf("%d", &(votes[k].votes[0]));
        printf("Votes: ");
        for (l = 1; l < MAX_VOTES; l++) {
            scanf("%d", &(votes[k].votes[l]));
        }
    }

    printf("Voting complete!\n");
    printf("Voter details:\n");
    for (i = 0; i < num_voters; i++) {
        printf("%d: %s (Age: %d)\n", i + 1, voters[i].name, voters[i].age);
    }

    printf("Candidate details:\n");
    for (j = 0; j < num_candidates; j++) {
        printf("%d: %s\n", j + 1, candidates[j].name);
    }

    printf("Vote details:\n");
    for (k = 0; k < num_votes; k++) {
        printf("%d: ", k + 1);
        for (l = 0; l < MAX_VOTES; l++) {
            printf("%d ", votes[k].votes[l]);
        }
        printf("\n");
    }

    return 0;
}