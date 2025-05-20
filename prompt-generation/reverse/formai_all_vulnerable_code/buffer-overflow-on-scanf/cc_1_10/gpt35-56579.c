//FormAI DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 50
#define MAX_PASSWORDS 100

typedef struct {
    char username[20];
    char password[20];
} User;

void menu();
void add_user(User users[], int *size);
void change_password(User users[], int size);
void list_users(User users[], int size);

int main() {
    User users[MAX_USERS];
    int size = 0;
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                add_user(users, &size);
                break;

            case 2:
                change_password(users, size);
                break;

            case 3:
                list_users(users, size);
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}

void menu() {
    printf("\n--- PASSWORD MANAGEMENT SYSTEM ---\n");
    printf("1. Add User\n");
    printf("2. Change Password\n");
    printf("3. List Users\n");
    printf("4. Exit\n");
}

void add_user(User users[], int *size) {
    if (*size == MAX_USERS) {
        printf("Maximum number of users reached (%d).\n", MAX_USERS);
        return;
    }

    User u;
    printf("Enter username: ");
    scanf("%s", u.username);

    for (int i = 0; i < *size; i++) {
        if (strcmp(users[i].username, u.username) == 0) {
            printf("Username already exists. Please choose a different one.\n");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", u.password);

    users[*size] = u;
    (*size)++;

    printf("User added successfully.\n");
}

void change_password(User users[], int size) {
    char username[20];
    char old_password[20];
    char new_password[20];

    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < size; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Enter old password: ");
            scanf("%s", old_password);

            if (strcmp(users[i].password, old_password) == 0) {
                printf("Enter new password: ");
                scanf("%s", new_password);

                strcpy(users[i].password, new_password);
                printf("Password changed successfully.\n");
                return;
            } else {
                printf("Incorrect password.\n");
                return;
            }
        }
    }

    printf("User not found.\n");
}

void list_users(User users[], int size) {
    if (size == 0) {
        printf("No users added yet.\n");
        return;
    }

    printf("\n--- LIST OF USERS ---\n");

    for (int i = 0; i < size; i++) {
        printf("%d. Username: %s, Password: %s\n", i+1, users[i].username, users[i].password);
    }
}