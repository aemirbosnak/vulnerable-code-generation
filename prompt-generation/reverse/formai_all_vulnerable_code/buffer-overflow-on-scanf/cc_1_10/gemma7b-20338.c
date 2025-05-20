//Gemma-7B DATASET v1.0 Category: System administration ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER_NAME_LENGTH 255
#define MAX_PASSWORD_LENGTH 255

typedef struct User {
    char name[MAX_USER_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int id;
} User;

User users[100];

void createUser(int id) {
    users[id].id = id;
    printf("Enter your name: ");
    scanf("%s", users[id].name);
    printf("Enter your password: ");
    scanf("%s", users[id].password);
}

void listUsers() {
    for (int i = 0; i < 100; i++) {
        if (users[i].name[0] != '\0') {
            printf("%d. %s\n", users[i].id, users[i].name);
        }
    }
}

int main() {
    int choice;

    printf("Welcome to the C System Administration program!\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createUser(101);
                break;
            case 2:
                listUsers();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}