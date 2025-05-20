//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_USERS 100
#define USERNAME_LENGTH 32

void createUser(const char *username) {
    char command[100];
    snprintf(command, sizeof(command), "sudo useradd %s", username);
    if (system(command) == -1) {
        perror("Error creating user");
    } else {
        printf("User '%s' created successfully.\n", username);
    }
}

void deleteUser(const char *username) {
    char command[100];
    snprintf(command, sizeof(command), "sudo userdel %s", username);
    if (system(command) == -1) {
        perror("Error deleting user");
    } else {
        printf("User '%s' deleted successfully.\n", username);
    }
}

void listUsers() {
    printf("Listing all users:\n");
    FILE *fp = popen("cut -d: -f1 /etc/passwd", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return;
    }

    char username[USERNAME_LENGTH];
    while (fgets(username, sizeof(username), fp) != NULL) {
        printf("%s", username);
    }

    pclose(fp);
}

void displayMenu() {
    printf("System Administration Tool\n");
    printf("1. Create a user\n");
    printf("2. Delete a user\n");
    printf("3. List all users\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    char username[USERNAME_LENGTH];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username to create: ");
                scanf("%s", username);
                createUser(username);
                break;
            case 2:
                printf("Enter username to delete: ");
                scanf("%s", username);
                deleteUser(username);
                break;
            case 3:
                listUsers();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}