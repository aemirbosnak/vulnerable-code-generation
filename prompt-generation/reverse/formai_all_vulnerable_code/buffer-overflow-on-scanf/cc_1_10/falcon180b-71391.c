//Falcon-180B DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USER 100
#define MAX_PASSWORD_LENGTH 30

struct User {
    char name[MAX_USER];
    char password[MAX_PASSWORD_LENGTH];
};

void addUser(struct User *users, int count, char *name, char *password) {
    if (count >= MAX_USER) {
        printf("Error: Maximum number of users reached.\n");
        return;
    }
    strcpy(users[count].name, name);
    strcpy(users[count].password, password);
    count++;
}

void deleteUser(struct User *users, int count, char *name) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(users[i].name, name) == 0) {
            memset(&users[i], 0, sizeof(struct User));
            count--;
            break;
        }
    }
}

void changePassword(struct User *users, int count, char *name, char *newPassword) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(users[i].name, name) == 0) {
            strcpy(users[i].password, newPassword);
            break;
        }
    }
}

void displayUsers(struct User *users, int count) {
    int i;
    for (i = 0; i < count; i++) {
        printf("Name: %s\nPassword: %s\n", users[i].name, users[i].password);
    }
}

int main() {
    struct User users[MAX_USER];
    int count = 0;
    char name[MAX_USER];
    char password[MAX_PASSWORD_LENGTH];
    int choice;

    do {
        printf("1. Add user\n2. Delete user\n3. Change password\n4. Display users\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter password: ");
                scanf("%s", password);
                addUser(users, count, name, password);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                deleteUser(users, count, name);
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter new password: ");
                scanf("%s", password);
                changePassword(users, count, name, password);
                break;
            case 4:
                displayUsers(users, count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}