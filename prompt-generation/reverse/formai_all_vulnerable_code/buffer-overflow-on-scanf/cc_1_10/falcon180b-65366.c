//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int is_admin;
} User;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

User users[MAX_VOTERS];
Candidate candidates[MAX_CANDIDATES];

int num_users = 0;
int num_candidates = 0;

void add_user(User* user) {
    if (num_users >= MAX_VOTERS) {
        printf("Error: Maximum number of users reached.\n");
        return;
    }

    strcpy(users[num_users].name, user->name);
    strcpy(users[num_users].password, user->password);
    users[num_users].is_admin = user->is_admin;

    num_users++;
}

void add_candidate(Candidate* candidate) {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Error: Maximum number of candidates reached.\n");
        return;
    }

    strcpy(candidates[num_candidates].name, candidate->name);
    candidates[num_candidates].votes = 0;

    num_candidates++;
}

int authenticate_user(User* user) {
    for (int i = 0; i < num_users; i++) {
        if (!strcmp(users[i].name, user->name) &&!strcmp(users[i].password, user->password)) {
            return i;
        }
    }

    return -1;
}

int main() {
    srand(time(NULL));

    // Add admin user
    User admin = {"admin", "password", 1};
    add_user(&admin);

    // Add candidates
    Candidate candidate1 = {"Candidate 1", 0};
    add_candidate(&candidate1);

    Candidate candidate2 = {"Candidate 2", 0};
    add_candidate(&candidate2);

    // Add voters
    User voter1 = {"Voter 1", "password", 0};
    add_user(&voter1);

    User voter2 = {"Voter 2", "password", 0};
    add_user(&voter2);

    // Print candidates
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    // Vote
    int choice;
    printf("Enter candidate number to vote for: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > num_candidates) {
        printf("Invalid choice.\n");
        return 1;
    }

    candidates[choice - 1].votes++;

    // Print results
    printf("\nResults:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s - %d votes\n", i + 1, candidates[i].name, candidates[i].votes);
    }

    return 0;
}