//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_STEPS 100

struct user {
    char name[20];
    int steps[MAX_STEPS];
};

struct user users[MAX_USERS];
int num_users = 0;

void add_user() {
    if (num_users >= MAX_USERS) {
        printf("Error: Maximum number of users reached.\n");
        return;
    }

    printf("Enter user name: ");
    scanf("%s", users[num_users].name);
    num_users++;
}

void remove_user() {
    if (num_users == 0) {
        printf("Error: No users found.\n");
        return;
    }

    printf("Enter user name to remove: ");
    char name[20];
    scanf("%s", name);

    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0) {
            memmove(&users[i], &users[i + 1], sizeof(struct user) * (num_users - i - 1));
            num_users--;
            break;
        }
    }
}

void add_step(char* name, int steps) {
    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0) {
            if (users[i].steps[MAX_STEPS - 1]!= 0) {
                users[i].steps[MAX_STEPS - 1] += steps;
            } else {
                users[i].steps[MAX_STEPS - 1] = steps;
            }
            break;
        }
    }
}

void view_steps() {
    printf("User\tSteps\n");
    for (int i = 0; i < num_users; i++) {
        printf("%s\t", users[i].name);
        int total_steps = 0;
        for (int j = 0; j < MAX_STEPS; j++) {
            total_steps += users[i].steps[j];
        }
        printf("%d\n", total_steps);
    }
}

int main() {
    add_user();
    add_user();
    add_step("John", 100);
    add_step("John", 200);
    add_step("Jane", 300);
    view_steps();
    remove_user();
    view_steps();

    return 0;
}