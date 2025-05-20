//FormAI DATASET v1.0 Category: System administration ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
    char username[20];
    char password[20];
    char privileges[20];
};

void addUser(struct user users[], int *userCount) {
    char username[20], password[20], privileges[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    printf("Enter privileges: ");
    scanf("%s", privileges);
    strcpy(users[*userCount].username, username);
    strcpy(users[*userCount].password, password);
    strcpy(users[*userCount].privileges, privileges);
    *userCount += 1;
    printf("User added!\n\n");
}

void listUsers(struct user users[], int userCount) {
    printf("LIST OF USERS:\n");
    for (int i = 0; i < userCount; i++) {
        printf("Username: %s\t Password: %s\t Privileges: %s\n", users[i].username, users[i].password, users[i].privileges);
    }
    printf("\n");
}

void deleteUser(struct user users[], int *userCount) {
    char username[20];
    printf("Enter username to delete: ");
    scanf("%s", username);
    int indexToDelete = -1;
    for (int i = 0; i < *userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            indexToDelete = i;
            break;
        }
    }
    if (indexToDelete == -1) {
        printf("User not found!\n\n");
        return;
    }
    for (int i = indexToDelete; i < *userCount - 1; i++) {
        users[i] = users[i + 1];
    }
    *userCount -= 1;
    printf("User deleted!\n\n");
}

int main() {
    struct user users[100];
    int userCount = 0;
    char input[20];
    printf("*** RETRO USER MANAGEMENT ***\n\n");

    while (1) {
        printf("Enter 'ADD' to add a user, 'LIST' to list all users, 'DELETE' to delete a user or 'EXIT' to quit: ");
        scanf("%s", input);
        if (strcmp(input, "ADD") == 0) {
            addUser(users, &userCount);
        }
        else if (strcmp(input, "LIST") == 0) {
            listUsers(users, userCount);
        }
        else if (strcmp(input, "DELETE") == 0) {
            deleteUser(users, &userCount);
        }
        else if (strcmp(input, "EXIT") == 0) {
            printf("Goodbye!");
            return 0;
        }
        else {
            printf("Invalid input!\n\n");
        }
    }
    return 0;
}