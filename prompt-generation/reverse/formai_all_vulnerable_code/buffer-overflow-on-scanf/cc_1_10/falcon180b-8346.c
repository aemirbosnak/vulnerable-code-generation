//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} candidate_t;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int voter_id;
} voter_t;

candidate_t candidates[MAX_CANDIDATES];
voter_t voters[MAX_VOTERS];
int num_candidates = 0;
int num_voters = 0;

void add_candidate(char* name) {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Error: Maximum number of candidates reached.\n");
        return;
    }
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void add_voter(char* name) {
    if (num_voters >= MAX_VOTERS) {
        printf("Error: Maximum number of voters reached.\n");
        return;
    }
    strcpy(voters[num_voters].name, name);
    voters[num_voters].voter_id = num_voters;
    num_voters++;
}

int authenticate_voter(char* name) {
    for (int i = 0; i < num_voters; i++) {
        if (!strcmp(name, voters[i].name)) {
            return i;
        }
    }
    return -1;
}

int main() {
    add_candidate("John Doe");
    add_candidate("Jane Doe");
    add_candidate("Bob Smith");
    add_candidate("Alice Smith");

    add_voter("John Smith");
    add_voter("Jane Smith");
    add_voter("Bob Johnson");

    int voter_id = authenticate_voter("John Smith");
    if (voter_id == -1) {
        printf("Error: Voter not found.\n");
        return 1;
    }

    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }

    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > num_candidates) {
        printf("Error: Invalid choice.\n");
        return 1;
    }

    candidates[choice-1].votes++;
    printf("Thank you for voting for %s!\n", candidates[choice-1].name);

    return 0;
}