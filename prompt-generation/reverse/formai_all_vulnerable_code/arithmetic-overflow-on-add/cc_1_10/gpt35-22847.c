//FormAI DATASET v1.0 Category: Password management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASSWORD_LENGTH 20

struct User {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct PasswordDatabase {
    struct User users[MAX_USERS];
    int numberOfUsers;
};

void printMenu() {
    printf("1. Add user\n");
    printf("2. View users\n");
    printf("3. Change password\n");
    printf("4. Delete user\n");
    printf("5. Quit\n");
}

void addUser(struct PasswordDatabase *db) {
    if (db->numberOfUsers >= MAX_USERS) {
        printf("Cannot add more users.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", db->users[db->numberOfUsers].username);

    printf("Enter password: ");
    scanf("%s", db->users[db->numberOfUsers].password);

    db->numberOfUsers++;
}

void viewUsers(struct PasswordDatabase *db) {
    printf("Users:\n");
    for (int i = 0; i < db->numberOfUsers; i++) {
        printf("%s\n", db->users[i].username);
    } 
}

void changePassword(struct PasswordDatabase *db) {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int found = 0;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter new password: ");
    scanf("%s", password);

    for (int i = 0; i < db->numberOfUsers; i++) {
        if (strcmp(db->users[i].username, username) == 0) {
            strcpy(db->users[i].password, password);
            printf("Password changed.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("User not found.\n");
    }
}

void deleteUser(struct PasswordDatabase *db) {
    char username[MAX_PASSWORD_LENGTH];
    int found = 0;

    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < db->numberOfUsers; i++) {
        if (strcmp(db->users[i].username, username) == 0) {
            for (int j = i; j < db->numberOfUsers - 1; j++) {
                strcpy(db->users[j].username, db->users[j+1].username);
                strcpy(db->users[j].password, db->users[j+1].password);
            }
            db->numberOfUsers--;
            printf("User deleted.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("User not found.\n");
    }
}

int main() {
    struct PasswordDatabase db;
    db.numberOfUsers = 0;

    int choice = 0;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addUser(&db);
                break;
            case 2:
                viewUsers(&db);
                break;
            case 3:
                changePassword(&db);
                break;
            case 4:
                deleteUser(&db);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 5);

    return 0;
}