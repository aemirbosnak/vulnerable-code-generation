//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USER_NUM 100
#define MAX_STEP_NUM 100

// User structure
typedef struct {
    char name[50];
    int steps[MAX_STEP_NUM];
    int num_steps;
} User;

// Function prototypes
void init_user(User* user);
void add_steps(User* user, int steps);
void print_user(User* user);
void sort_users(User users[], int num_users);

int main() {
    int num_users;
    User users[MAX_USER_NUM];

    printf("Enter number of users: ");
    scanf("%d", &num_users);

    // Initialize all users
    for (int i = 0; i < num_users; i++) {
        init_user(&users[i]);
    }

    // Add steps for each user
    for (int i = 0; i < num_users; i++) {
        printf("Enter steps for user %s: ", users[i].name);
        scanf("%d", &users[i].steps[0]);
        users[i].num_steps = 1;
    }

    // Sort users by number of steps
    sort_users(users, num_users);

    // Print all users
    for (int i = 0; i < num_users; i++) {
        printf("User %s took %d steps\n", users[i].name, users[i].num_steps);
    }

    return 0;
}

void init_user(User* user) {
    strcpy(user->name, "");
    user->num_steps = 0;
}

void add_steps(User* user, int steps) {
    user->steps[user->num_steps] = steps;
    user->num_steps++;
}

void print_user(User* user) {
    printf("Name: %s\n", user->name);
    printf("Steps:");
    for (int i = 0; i < user->num_steps; i++) {
        printf(" %d", user->steps[i]);
    }
    printf("\n");
}

void sort_users(User users[], int num_users) {
    for (int i = 0; i < num_users - 1; i++) {
        for (int j = i + 1; j < num_users; j++) {
            if (users[i].num_steps < users[j].num_steps) {
                User temp = users[i];
                users[i] = users[j];
                users[j] = temp;
            }
        }
    }
}