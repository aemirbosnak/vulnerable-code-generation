//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define LINE_LENGTH 256

void display_menu() {
    printf("System User Management:\n");
    printf("1. List Users\n");
    printf("2. Add User\n");
    printf("3. Delete User\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void list_users() {
    FILE *file = fopen("/etc/passwd", "r");
    if (file == NULL) {
        perror("Failed to open /etc/passwd");
        return;
    }
    
    char line[LINE_LENGTH];
    printf("\nList of Users:\n");
    while (fgets(line, sizeof(line), file)) {
        char *username = strtok(line, ":");
        printf("User: %s\n", username);
    }
    fclose(file);
}

void add_user() {
    char username[50];
    printf("Enter username to add: ");
    scanf("%s", username);

    char command[100];
    snprintf(command, sizeof(command), "sudo useradd %s", username);
    
    // Execute the command to add the user
    int status = system(command);
    if (status == -1) {
        perror("Error adding user");
    } else {
        printf("User %s added successfully!\n", username);
    }
}

void delete_user() {
    char username[50];
    printf("Enter username to delete: ");
    scanf("%s", username);

    char command[100];
    snprintf(command, sizeof(command), "sudo userdel %s", username);
    
    // Execute the command to delete the user
    int status = system(command);
    if (status == -1) {
        perror("Error deleting user");
    } else {
        printf("User %s deleted successfully!\n", username);
    }
}

int main() {
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                list_users();
                break;
            case 2:
                add_user();
                break;
            case 3:
                delete_user();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}