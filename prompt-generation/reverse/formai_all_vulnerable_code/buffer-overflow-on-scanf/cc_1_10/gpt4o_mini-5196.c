//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_COMMAND_LENGTH 256

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    time_t last_login;
} User;

User users[MAX_USERS];
int user_count = 0;

void clear_screen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void greet() {
    clear_screen();
    printf("Welcome to the System Admin Utility!\n");
    printf("Manage users and monitor system activities.\n");
    printf("------------------------------------------\n");
}

void add_user() {
    if (user_count >= MAX_USERS) {
        printf("Max user limit reached. Cannot add more users.\n");
        return;
    }
    
    printf("Enter username: ");
    char username[MAX_USERNAME_LENGTH];
    scanf("%s", username);

    // Check for duplicate usernames
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("User %s already exists.\n", username);
            return;
        }
    }

    // Add the new user
    strcpy(users[user_count].username, username);
    users[user_count].last_login = time(NULL);
    user_count++;

    printf("User %s added successfully.\n", username);
}

void list_users() {
    printf("Registered Users:\n");
    for (int i = 0; i < user_count; i++) {
        printf("%s - Last login: %s", users[i].username, ctime(&users[i].last_login));
    }
    printf("\n");
}

void run_command() {
    char command[MAX_COMMAND_LENGTH];
    
    printf("Enter a shell command to execute (or 'exit' to return): ");
    scanf(" %[^\n]", command);
    
    if (strcmp(command, "exit") == 0) {
        return;
    }

    printf("Executing command: %s\n", command);
    int ret = system(command);
    if (ret == -1) {
        printf("Failed to execute command.\n");
    } else {
        printf("Command executed with return code: %d\n", ret);
    }
}

void login_user() {
    char username[MAX_USERNAME_LENGTH];
    
    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            users[i].last_login = time(NULL);
            printf("Welcome back, %s!\n", username);
            return;
        }
    }

    printf("User %s not found.\n", username);
}

void admin_menu() {
    int choice;
    
    do {
        printf("\nAdmin Menu:\n");
        printf("1. Add User\n");
        printf("2. List Users\n");
        printf("3. Login User\n");
        printf("4. Run Shell Command\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                list_users();
                break;
            case 3:
                login_user();
                break;
            case 4:
                run_command();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    greet();
    admin_menu();
    return 0;
}