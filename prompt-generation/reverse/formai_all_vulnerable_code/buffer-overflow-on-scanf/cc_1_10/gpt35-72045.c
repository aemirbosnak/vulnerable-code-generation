//FormAI DATASET v1.0 Category: System administration ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASSWORD_LENGTH 20

/* A struct to hold user information */
struct User {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

/* Function prototypes */
void printMenu();
void login(struct User* users, int* numUsers);
void addUser(struct User* users, int* numUsers);
void removeUser(struct User* users, int* numUsers);

int main() {
    struct User users[MAX_USERS];
    int numUsers = 0;
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                login(users, &numUsers);
                break;
            case 2:
                addUser(users, &numUsers);
                break;
            case 3:
                removeUser(users, &numUsers);
                break;
            case 4:
                printf("Program exited\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

/* Function to print the menu */
void printMenu() {
    printf("\n\n");
    printf("1. Login\n");
    printf("2. Add User\n");
    printf("3. Remove User\n");
    printf("4. Exit\n");
    printf("\nEnter choice: ");
}

/* Function to handle the login functionality */
void login(struct User* users, int* numUsers) {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int found = 0;

    printf("\n\n");
    printf("Enter username: ");
    scanf("%s", username);
    getchar(); // Consume newline character

    printf("Enter password: ");
    scanf("%s", password);
    getchar(); // Consume newline character

    for (int i = 0; i < *numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Incorrect username or password\n");
    }
}

/* Function to handle adding a user */
void addUser(struct User* users, int* numUsers) {
    if (*numUsers == MAX_USERS) {
        printf("\n\n");
        printf("Max number of users reached\n");
        return;
    }

    printf("\n\n");
    printf("Enter username: ");
    scanf("%s", users[*numUsers].username);
    getchar(); // Consume newline character

    printf("Enter password: ");
    scanf("%s", users[*numUsers].password);
    getchar(); // Consume newline character

    (*numUsers)++;
    printf("User added successfully\n");
}

/* Function to handle removing a user */
void removeUser(struct User* users, int* numUsers) {
    char username[MAX_PASSWORD_LENGTH];
    int index = -1;

    printf("\n\n");
    printf("Enter username: ");
    scanf("%s", username);
    getchar(); // Consume newline character

    for (int i = 0; i < *numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("User not found\n");
    } else {
        // Shift the elements to the left
        for (int i = index; i < *numUsers - 1; i++) {
            users[i] = users[i + 1];
        }

        (*numUsers)--;
        printf("User removed successfully\n");
    }
}