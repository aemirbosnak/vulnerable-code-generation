//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50
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
int num_candidates;
int num_voters;

void init() {
    num_candidates = 0;
    num_voters = 0;
}

void add_candidate(char* name) {
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void add_user(char* name, char* password, int is_admin) {
    strcpy(users[num_voters].name, name);
    strcpy(users[num_voters].password, password);
    users[num_voters].is_admin = is_admin;
    num_voters++;
}

int authenticate_user(char* name, char* password) {
    int i;
    for (i = 0; i < num_voters; i++) {
        if (!strcmp(name, users[i].name) &&!strcmp(password, users[i].password)) {
            return i;
        }
    }
    return -1; // User not found
}

int main() {
    init();
    add_candidate("Alice");
    add_candidate("Bob");
    add_candidate("Charlie");
    add_user("admin", "password", 1);
    add_user("user1", "password1", 0);
    int user_id = authenticate_user("user1", "password1");
    if (user_id >= 0) {
        int candidate_id = 0;
        printf("Welcome, %s! Please select a candidate:\n", users[user_id].name);
        printf("1. Alice\n");
        printf("2. Bob\n");
        printf("3. Charlie\n");
        scanf("%d", &candidate_id);
        candidates[candidate_id].votes++;
        printf("Thank you for voting, %s!\n", users[user_id].name);
    } else {
        printf("Invalid username or password.\n");
    }
    return 0;
}