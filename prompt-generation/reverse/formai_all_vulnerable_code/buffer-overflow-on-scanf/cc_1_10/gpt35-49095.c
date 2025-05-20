//FormAI DATASET v1.0 Category: Database simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char email[50];
} User;

void add_user(User* users, int* count) {
    int id;
    char name[50], email[50];
    printf("Enter user ID: ");
    scanf("%d", &id);
    printf("Enter user name: ");
    scanf("%s", name);
    printf("Enter user email: ");
    scanf("%s", email);
    User new_user = {id, name, email};
    users[*count] = new_user;
    (*count)++;
    printf("User added successfully.\n");
}

void list_users(User* users, int count) {
    if (count == 0) {
        printf("No users found.\n");
        return;
    }
    printf("ID\tName\t\tEmail\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-15s\t%s\n", users[i].id, users[i].name, users[i].email);
    }
}

void find_user(User* users, int count) {
    int id;
    printf("Enter user ID: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (users[i].id == id) {
            printf("User found!\n");
            printf("ID: %d\nName: %s\nEmail: %s\n", users[i].id, users[i].name, users[i].email);
            return;
        }
    }
    printf("User not found.\n");
}

int main() {
    User* users = malloc(sizeof(User) * 100);
    int count = 0;
    while (1) {
        printf("Enter command (add, list, find, exit): ");
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            add_user(users, &count);
        } else if (strcmp(command, "list") == 0) {
            list_users(users, count);
        } else if (strcmp(command, "find") == 0) {
            find_user(users, count);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    free(users);
    return 0;
}