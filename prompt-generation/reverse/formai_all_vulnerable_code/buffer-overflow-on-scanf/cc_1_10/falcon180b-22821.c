//Falcon-180B DATASET v1.0 Category: System administration ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_USERS 100
#define MAX_USER_NAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_LOGIN_ATTEMPTS 3
#define MAX_COMMAND_LENGTH 100

typedef struct {
    char name[MAX_USER_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int is_admin;
} user;

user users[MAX_USERS];
int num_users = 0;

void add_user() {
    printf("Enter user name: ");
    scanf("%s", users[num_users].name);

    printf("Enter password: ");
    scanf("%s", users[num_users].password);

    printf("Is this user an admin? (y/n): ");
    char choice;
    scanf("%c", &choice);
    users[num_users].is_admin = (choice == 'y');

    num_users++;
}

void login() {
    printf("Enter user name: ");
    char name[MAX_USER_NAME_LENGTH];
    scanf("%s", name);

    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(name, users[i].name) == 0) {
            printf("Enter password: ");
            char password[MAX_PASSWORD_LENGTH];
            scanf("%s", password);

            if (strcmp(password, users[i].password) == 0) {
                printf("Login successful!\n");
                int is_admin = users[i].is_admin;
                return;
            } else {
                printf("Incorrect password.\n");
            }
        }
    }

    printf("User not found.\n");
}

void execute_command(char* command, int is_admin) {
    if (is_admin) {
        system(command);
    } else {
        printf("User does not have sufficient privileges to execute this command.\n");
    }
}

int main() {
    printf("Welcome to the futuristic system administration tool!\n");

    while (1) {
        printf("Enter command: ");
        char command[MAX_COMMAND_LENGTH];
        scanf("%s", command);

        if (strcmp(command, "add_user") == 0) {
            add_user();
        } else if (strcmp(command, "login") == 0) {
            login();
        } else if (strcmp(command, "logout") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}