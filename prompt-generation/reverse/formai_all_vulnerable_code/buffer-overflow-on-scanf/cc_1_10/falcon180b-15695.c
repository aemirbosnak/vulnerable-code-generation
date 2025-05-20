//Falcon-180B DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char username[50];
    char password[50];
} User;

void addUser(User *user) {
    printf("Enter username: ");
    scanf("%s", user->username);
    printf("Enter password: ");
    scanf("%s", user->password);
}

void displayUsers(User *userList, int numUsers) {
    printf("\nUser List:\n");
    for (int i = 0; i < numUsers; i++) {
        printf("%s - %s\n", userList[i].username, userList[i].password);
    }
}

int main() {
    User userList[100];
    int numUsers = 0;
    char choice;
    do {
        printf("\nPassword Management System\n");
        printf("1. Add User\n2. Display Users\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                if (numUsers >= 100) {
                    printf("Maximum number of users reached.\n");
                } else {
                    addUser(&userList[numUsers]);
                    numUsers++;
                }
                break;
            case '2':
                displayUsers(userList, numUsers);
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '3');
    return 0;
}