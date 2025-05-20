//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int votes;
} candidate_t;

typedef struct {
    char name[MAX_NAME_LEN];
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
    voters[num_voters].voter_id = num_voters + 1;
    num_voters++;
}

int main() {
    srand(time(NULL));

    add_candidate("Alice");
    add_candidate("Bob");
    add_candidate("Charlie");

    add_voter("Dave");
    add_voter("Eve");

    int choice;
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please select an option:\n");
    printf("1. Cast your vote\n");
    printf("2. View results\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    if (choice == 1) {
        int voter_id = rand() % num_voters + 1;
        printf("You are voter #%d. Please select a candidate to vote for:\n", voter_id);

        for (int i = 0; i < num_candidates; i++) {
            printf("%d. %s\n", i + 1, candidates[i].name);
        }

        scanf("%d", &choice);

        candidates[choice - 1].votes++;
        printf("Your vote has been cast for %s.\n", candidates[choice - 1].name);
    } else if (choice == 2) {
        printf("Voting is still in progress...\n");
    } else if (choice == 3) {
        printf("Thank you for using the Electronic Voting System.\n");
    } else {
        printf("Invalid option selected.\n");
    }

    return 0;
}