//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: curious
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
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

int authenticate_user(char* username, char* password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // Add users and candidates here
    add_user(&(User) {"admin", "password", 1});
    add_candidate(&(Candidate) {"Alice", 0});
    add_candidate(&(Candidate) {"Bob", 0});
    add_candidate(&(Candidate) {"Charlie", 0});

    // Authenticate user
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (!authenticate_user(username, password)) {
        printf("Invalid credentials.\n");
        return 1;
    }

    // Cast vote
    int candidate_index;
    printf("Enter candidate index: ");
    scanf("%d", &candidate_index);

    if (candidate_index < 0 || candidate_index >= num_candidates) {
        printf("Invalid candidate index.\n");
        return 1;
    }

    candidates[candidate_index].votes++;

    return 0;
}