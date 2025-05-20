//FormAI DATASET v1.0 Category: Educational ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 10

typedef struct User {
    char username[20];
    char password[20];
} User;

User userList[MAX_USERS];
int numUsers = 0;

void addUser() {
    if(numUsers >= MAX_USERS) {
        printf("User limit reached.\n");
        return;
    }

    User newUser;

    printf("Enter username: ");
    scanf("%s", newUser.username);

    for(int i = 0; i < numUsers; i++) {
        if(strcmp(newUser.username, userList[i].username) == 0) {
            printf("Username already exists.\n");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", newUser.password);

    userList[numUsers] = newUser;
    numUsers++;

    printf("User added successfully.\n");
}

void showUsers() {
    if(numUsers == 0) {
        printf("No users found.\n");
        return;
    }

    printf("Username\tPassword\n");
    printf("------------------------\n");
    for(int i = 0; i < numUsers; i++) {
        printf("%s\t\t%s\n", userList[i].username, userList[i].password);
    }
}

int main() {
    int choice;

    while(1) {
        printf("------------------------\n");
        printf("Choose an option:\n");
        printf("1. Add user\n");
        printf("2. Show users\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addUser();
                break;
            case 2:
                showUsers();
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}