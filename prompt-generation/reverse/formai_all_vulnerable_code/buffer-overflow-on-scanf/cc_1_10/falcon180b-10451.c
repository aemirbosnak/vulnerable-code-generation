//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
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
} Candidate;

User users[MAX_VOTERS];
Candidate candidates[MAX_CANDIDATES];
int num_users = 0;
int num_candidates = 0;

void add_user(char* name, char* password, int is_admin) {
    strcpy(users[num_users].name, name);
    strcpy(users[num_users].password, password);
    users[num_users].is_admin = is_admin;
    num_users++;
}

int authenticate_user(char* name, char* password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0 && strcmp(users[i].password, password) == 0) {
            return i;
        }
    }
    return -1;
}

void add_candidate(char* name) {
    strcpy(candidates[num_candidates].name, name);
    num_candidates++;
}

int main() {
    add_user("admin", "password", 1);
    add_candidate("Alice");
    add_candidate("Bob");
    add_candidate("Charlie");

    int user_id = authenticate_user("admin", "password");

    int candidate_id = 0;
    while (1) {
        printf("Enter candidate ID: ");
        scanf("%d", &candidate_id);
        if (candidate_id >= 0 && candidate_id < num_candidates) {
            break;
        }
        printf("Invalid candidate ID.\n");
    }

    printf("You voted for %s.\n", candidates[candidate_id].name);

    return 0;
}