//FormAI DATASET v1.0 Category: System administration ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100

typedef struct {
    char* username;
    char* password;
    int isAdmin;
} User;

User users[MAX_USERS];
int numUsers = 0;

void addUser() {
    if (numUsers == MAX_USERS) {
        printf("Error: Maximum number of users exceeded.\n");
        return;
    }

    User newUser;

    printf("Enter username: ");
    char* username = (char*) malloc(sizeof(char) * 100);
    scanf("%s", username);
    newUser.username = username;

    printf("Enter password: ");
    char* password = (char*) malloc(sizeof(char) * 100);
    scanf("%s", password);
    newUser.password = password;

    printf("Is this user an admin? (1=yes, 0=no) ");
    int isAdmin;
    scanf("%d", &isAdmin);
    newUser.isAdmin = isAdmin;

    users[numUsers++] = newUser;
}

void displayUsers() {
    printf("Username\tPassword\tAdmin\n");
    for (int i = 0; i < numUsers; i++) {
        printf("%s\t%s\t%d\n", users[i].username, users[i].password, users[i].isAdmin);
    }
}

int main() {
    printf("Welcome to the User Management System.\n");

    while (1) {
        printf("Choose an option:\n");
        printf("1. Add a user\n");
        printf("2. Display all users\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                displayUsers();
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}