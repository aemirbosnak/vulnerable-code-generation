//Falcon-180B DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20
#define MAX_USERS 10

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int numUsers = 0;

void addUser() {
    printf("Enter name: ");
    scanf("%s", &users[numUsers].name);

    printf("Enter password: ");
    scanf("%s", &users[numUsers].password);

    numUsers++;
}

int login() {
    printf("Enter name: ");
    char name[MAX_PASSWORD_LENGTH];
    scanf("%s", &name);

    int i;
    for (i = 0; i < numUsers; i++) {
        if (strcmp(name, users[i].name) == 0) {
            printf("Enter password: ");
            char password[MAX_PASSWORD_LENGTH];
            scanf("%s", &password);

            if (strcmp(password, users[i].password) == 0) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    int choice;
    while (1) {
        printf("1. Add user\n2. Login\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                if (login()) {
                    printf("Login successful!\n");
                } else {
                    printf("Login failed.\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}