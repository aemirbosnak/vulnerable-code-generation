//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_SITUPS 10
#define MAX_PUSHUPS 25

typedef struct {
    char name[20];
    int situps[MAX_SITUPS];
    int pushups[MAX_PUSHUPS];
    int num_situps;
    int num_pushups;
} user;

user users[MAX_USERS];
int num_users = 0;

void add_user() {
    if (num_users == MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }
    printf("Enter user name: ");
    scanf("%s", users[num_users].name);
    users[num_users].num_situps = 0;
    users[num_users].num_pushups = 0;
    num_users++;
}

void add_situps(int user_index, int num) {
    if (user_index >= num_users) {
        printf("User does not exist.\n");
        return;
    }
    if (users[user_index].num_situps >= MAX_SITUPS) {
        printf("Maximum number of situps reached for user.\n");
        return;
    }
    users[user_index].situps[users[user_index].num_situps] = num;
    users[user_index].num_situps++;
}

void add_pushups(int user_index, int num) {
    if (user_index >= num_users) {
        printf("User does not exist.\n");
        return;
    }
    if (users[user_index].num_pushups >= MAX_PUSHUPS) {
        printf("Maximum number of pushups reached for user.\n");
        return;
    }
    users[user_index].pushups[users[user_index].num_pushups] = num;
    users[user_index].num_pushups++;
}

void print_user(int user_index) {
    printf("Name: %s\n", users[user_index].name);
    printf("Situps (%d): ", users[user_index].num_situps);
    for (int i = 0; i < users[user_index].num_situps; i++) {
        printf("%d ", users[user_index].situps[i]);
    }
    printf("\nPushups (%d): ", users[user_index].num_pushups);
    for (int i = 0; i < users[user_index].num_pushups; i++) {
        printf("%d ", users[user_index].pushups[i]);
    }
    printf("\n");
}

void print_all_users() {
    for (int i = 0; i < num_users; i++) {
        print_user(i);
    }
}

int main() {
    char command[20];
    int user_index, num;

    while (1) {
        printf("Enter command (add_user, add_situps, add_pushups, print_user, print_all_users, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add_user") == 0) {
            add_user();
        } else if (strcmp(command, "add_situps") == 0) {
            printf("Enter user index: ");
            scanf("%d", &user_index);
            printf("Enter number of situps: ");
            scanf("%d", &num);
            add_situps(user_index, num);
        } else if (strcmp(command, "add_pushups") == 0) {
            printf("Enter user index: ");
            scanf("%d", &user_index);
            printf("Enter number of pushups: ");
            scanf("%d", &num);
            add_pushups(user_index, num);
        } else if (strcmp(command, "print_user") == 0) {
            printf("Enter user index: ");
            scanf("%d", &user_index);
            print_user(user_index);
        } else if (strcmp(command, "print_all_users") == 0) {
            print_all_users();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}