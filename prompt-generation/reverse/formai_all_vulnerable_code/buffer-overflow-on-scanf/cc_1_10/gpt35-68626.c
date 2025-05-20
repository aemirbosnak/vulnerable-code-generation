//FormAI DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASSWORD_LEN 16

struct User {
    char username[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];
};

struct User users[MAX_USERS];
int num_users = 0;

void display_menu() {
    printf("Password Manager\n");
    printf("1. Add User\n");
    printf("2. Remove User\n");
    printf("3. Change Password\n");
    printf("4. Display All Users\n");
    printf("5. Exit\n");
}

void add_user() {
    printf("Enter username: ");
    scanf("%s", users[num_users].username);
    printf("Enter password: ");
    scanf("%s", users[num_users].password);
    num_users++;
    printf("User added successfully!\n");
}

void remove_user() {
    printf("Enter username: ");
    char username[MAX_PASSWORD_LEN];
    scanf("%s", username);
    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Are you sure you want to remove user '%s'? (y/n): ", users[i].username);
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'y') {
                int j;
                for (j = i; j < num_users - 1; j++) {
                    strcpy(users[j].username, users[j + 1].username);
                    strcpy(users[j].password, users[j + 1].password);
                }
                num_users--;
                printf("User removed successfully!\n");
            } else {
                printf("User not removed.\n");
            }
            return;
        }
    }
    printf("User '%s' not found.\n", username);
}

void change_password() {
    printf("Enter username: ");
    char username[MAX_PASSWORD_LEN];
    scanf("%s", username);
    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Enter new password: ");
            scanf("%s", users[i].password);
            printf("Password changed successfully!\n");
            return;
        }
    }
    printf("User '%s' not found.\n", username);
}

void display_users() {
    printf("\nAll Users:\n");
    int i;
    for (i = 0; i < num_users; i++) {
        printf("Username: %s\n", users[i].username);
        printf("Password: %s\n", users[i].password);
        printf("\n");
    }
}

int main() {
    int choice = 0;
    while (choice != 5) {
        display_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                remove_user();
                break;
            case 3:
                change_password();
                break;
            case 4:
                display_users();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}