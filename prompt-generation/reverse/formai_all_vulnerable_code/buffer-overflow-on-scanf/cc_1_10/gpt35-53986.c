//FormAI DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_NAME_LENGTH 50
#define MAX_USERS 10

typedef struct User {
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int num_users = 0;

void add_user() {
    if (num_users == MAX_USERS) {
        printf("Error: maximum number of users reached\n");
        return;
    }

    printf("Enter a name for the new user: ");
    fgets(users[num_users].name, MAX_NAME_LENGTH, stdin);
    printf("Enter a password for the new user: ");
    fgets(users[num_users].password, MAX_PASSWORD_LENGTH, stdin);

    // remove newline characters
    users[num_users].name[strcspn(users[num_users].name, "\n")] = '\0';
    users[num_users].password[strcspn(users[num_users].password, "\n")] = '\0';

    printf("User %s added successfully\n", users[num_users].name);
    num_users++;
}

void print_users() {
    if (num_users == 0) {
        printf("No users to display\n");
        return;
    }

    printf("Current users:\n");
    for (int i = 0; i < num_users; i++) {
        printf("%s\n", users[i].name);
    }
}

void delete_user(char *name) {
    int user_index = -1;
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0) {
            user_index = i;
            break;
        }
    }

    if (user_index == -1) {
        printf("Error: user %s not found\n", name);
        return;
    }

    // shift all users after deleted user to the left
    for (int i = user_index; i < num_users - 1; i++) {
        users[i] = users[i + 1];
    }

    num_users--;
    printf("User %s deleted successfully\n", name);
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];

    while (1) {
        printf("Password Manager\n");
        printf("1. Add User\n");
        printf("2. Print Users\n");
        printf("3. Delete User\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getchar(); // discard newline character left in stdin
                add_user();
                break;
            case 2:
                print_users();
                break;
            case 3:
                getchar(); // discard newline character left in stdin
                printf("Enter the name of the user to delete: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // remove newline character
                delete_user(name);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}