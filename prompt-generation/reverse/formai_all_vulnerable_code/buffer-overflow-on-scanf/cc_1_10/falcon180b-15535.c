//Falcon-180B DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int numUsers = 0;

void addUser() {
    printf("Enter username: ");
    scanf("%s", users[numUsers].username);
    printf("Enter password: ");
    scanf("%s", users[numUsers].password);
    numUsers++;
}

void removeUser() {
    printf("Enter username to remove: ");
    char username[MAX_PASSWORD_LENGTH];
    scanf("%s", username);
    int i;
    for (i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            numUsers--;
            break;
        }
    }
}

void changePassword() {
    printf("Enter username to change password: ");
    char username[MAX_PASSWORD_LENGTH];
    scanf("%s", username);
    printf("Enter new password: ");
    char newPassword[MAX_PASSWORD_LENGTH];
    scanf("%s", newPassword);
    int i;
    for (i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            strcpy(users[i].password, newPassword);
            break;
        }
    }
}

void login() {
    printf("Enter username: ");
    char username[MAX_PASSWORD_LENGTH];
    scanf("%s", username);
    printf("Enter password: ");
    char password[MAX_PASSWORD_LENGTH];
    scanf("%s", password);
    int i;
    for (i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            break;
        } else {
            printf("Login failed.\n");
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nPassword Management System\n");
        printf("1. Add user\n");
        printf("2. Remove user\n");
        printf("3. Change password\n");
        printf("4. Login\n");
        printf("0. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                removeUser();
                break;
            case 3:
                changePassword();
                break;
            case 4:
                login();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}