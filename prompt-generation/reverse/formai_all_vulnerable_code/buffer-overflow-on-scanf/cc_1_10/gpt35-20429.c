//FormAI DATASET v1.0 Category: System administration ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createUser(char* user, char* password) {
    // Create user account with given username and password
    char command[256];
    sprintf(command, "sudo useradd %s -p $(openssl passwd -1 %s)", user, password);
    system(command);
}

void deleteUser(char* user) {
    // Delete user account with given username
    char command[256];
    sprintf(command, "sudo userdel -r %s", user);
    system(command);
}

void changePassword(char* user, char* newPassword) {
    // Change password for user account with given username
    char command[256];
    sprintf(command, "echo \"%s:%s\" | sudo chpasswd", user, newPassword);
    system(command);
}

int main() {
    int choice;
    char user[20];
    char password[20];
    char newPassword[20];

    while (1) {
        printf("Select an option:\n");
        printf("1. Create user account\n");
        printf("2. Delete user account\n");
        printf("3. Change password\n");
        printf("4. Exit\n");
        
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", user);

                printf("Enter password: ");
                scanf("%s", password);

                createUser(user, password);
                printf("User account created successfully.\n");
                break;

            case 2:
                printf("Enter username: ");
                scanf("%s", user);

                deleteUser(user);
                printf("User account deleted successfully.\n");
                break;

            case 3:
                printf("Enter username: ");
                scanf("%s", user);

                printf("Enter new password: ");
                scanf("%s", newPassword);

                changePassword(user, newPassword);
                printf("Password changed successfully.\n");
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
}