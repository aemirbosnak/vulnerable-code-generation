//FormAI DATASET v1.0 Category: System administration ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_COMMANDS 1000
#define MAX_COMMAND_LENGTH 100

// Global variables
char users[MAX_USERS][50];
int numUsers = 0;
char commands[MAX_COMMANDS][MAX_COMMAND_LENGTH];
int numCommands = 0;

// Function prototypes
void addUser();
void printUsers();
void addCommand();
void printCommands();

int main() {
    int choice;

    do {
        printf("\n========================\n");
        printf("1. Add user\n");
        printf("2. Print users\n");
        printf("3. Add command\n");
        printf("4. Print commands\n");
        printf("5. Exit\n");
        printf("========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                printUsers();
                break;
            case 3:
                addCommand();
                break;
            case 4:
                printCommands();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void addUser() {
    char newUser[50];

    printf("Enter new user: ");
    scanf("%s", newUser);

    int i;
    for (i = 0; i < numUsers; i++) {
        if (strcmp(users[i], newUser) == 0) {
            printf("User %s already exists.\n", newUser);
            return;
        }
    }

    if (numUsers >= MAX_USERS) {
        printf("Error: Maximum number of users reached.\n");
        return;
    }

    strcpy(users[numUsers++], newUser);
    printf("User %s added.\n", newUser);
}

void printUsers() {
    printf("List of users:\n");

    int i;
    for (i = 0; i < numUsers; i++) {
        printf("%s\n", users[i]);
    }
}

void addCommand() {
    char newCommand[MAX_COMMAND_LENGTH];

    printf("Enter new command: ");
    scanf("%s", newCommand);

    if (numCommands >= MAX_COMMANDS) {
        printf("Error: Maximum number of commands reached.\n");
        return;
    }

    strcpy(commands[numCommands++], newCommand);
    printf("Command %s added.\n", newCommand);
}

void printCommands() {
    printf("List of commands:\n");

    int i;
    for (i = 0; i < numCommands; i++) {
        printf("%s\n", commands[i]);
    }
}