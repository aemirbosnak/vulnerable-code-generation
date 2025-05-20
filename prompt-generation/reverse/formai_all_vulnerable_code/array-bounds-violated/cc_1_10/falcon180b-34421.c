//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int vote_count;
} Candidate;

User users[MAX_VOTERS];
Candidate candidates[MAX_CANDIDATES];
int num_users = 0;
int num_candidates = 0;

void add_user(User* user) {
    strcpy(users[num_users].name, user->name);
    strcpy(users[num_users].password, user->password);
    users[num_users].is_admin = user->is_admin;
    num_users++;
}

void add_candidate(Candidate* candidate) {
    strcpy(candidates[num_candidates].name, candidate->name);
    candidates[num_candidates].vote_count = 0;
    num_candidates++;
}

int authenticate_user(char* username, char* password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    // Initialize users and candidates
    User admin = {"admin", "admin", 1};
    add_user(&admin);

    Candidate candidate1 = {"Sir Lancelot", 0};
    add_candidate(&candidate1);

    Candidate candidate2 = {"Sir Galahad", 0};
    add_candidate(&candidate2);

    // Authenticate user
    int user_id = authenticate_user("admin", "admin");

    // Cast vote
    int candidate_id = 0;
    scanf("%d", &candidate_id);
    candidates[candidate_id].vote_count++;

    // View results
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }

    return 0;
}