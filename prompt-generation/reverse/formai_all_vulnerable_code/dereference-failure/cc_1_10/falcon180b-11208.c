//Falcon-180B DATASET v1.0 Category: System administration ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_COMMAND_LENGTH 100

// User structure
typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char *command;
} User;

// User management functions
void create_user(User *user) {
    printf("Enter username: ");
    scanf("%s", user->username);

    printf("Enter password: ");
    scanf("%s", user->password);

    user->command = (char *)malloc(MAX_COMMAND_LENGTH * sizeof(char));
    memset(user->command, 0, MAX_COMMAND_LENGTH);
}

void delete_user(User *user) {
    free(user->command);
    memset(user->command, 0, MAX_COMMAND_LENGTH);
}

void login(User *user) {
    char input_password[MAX_PASSWORD_LENGTH];

    printf("Enter password: ");
    scanf("%s", input_password);

    if (strcmp(user->password, input_password) == 0) {
        printf("Login successful!\n");
    } else {
        printf("Login failed!\n");
    }
}

void execute_command(User *user) {
    printf("Enter command: ");
    scanf("%s", user->command);

    int command_length = strlen(user->command);

    if (command_length > 0) {
        if (user->command[0] == 'c' || user->command[0] == 'C') {
            system(user->command);
        } else {
            printf("Invalid command!\n");
        }
    } else {
        printf("Command cannot be empty!\n");
    }
}

// Main function
int main() {
    int choice;
    User user;

    do {
        printf("1. Create user\n");
        printf("2. Login\n");
        printf("3. Execute command\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            create_user(&user);
            break;

        case 2:
            login(&user);
            break;

        case 3:
            execute_command(&user);
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}