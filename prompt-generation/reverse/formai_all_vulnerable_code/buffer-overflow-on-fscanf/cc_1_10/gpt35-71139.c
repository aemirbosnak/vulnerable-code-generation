//FormAI DATASET v1.0 Category: Password management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 50
#define MAX_NUM_USERS 10

typedef struct {
    char username[20];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_NUM_USERS];
int numUsers = 0;

// function prototypes
void displayMenu();
void addNewUser();
void changePassword();
void listUsers();
void saveToFile();
void loadFromFile();

int main() {

    loadFromFile(); // load existing users

    while (1) {
        displayMenu();

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewUser();
                break;
            case 2:
                changePassword();
                break;
            case 3:
                listUsers();
                break;
            case 4:
                saveToFile();
                printf("Passwords saved to file.\n");
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void displayMenu() {
    printf("\nPassword Management System\n");
    printf("--------------------------\n");
    printf("1. Add new user\n");
    printf("2. Change password\n");
    printf("3. List users\n");
    printf("4. Save to file\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
}

void addNewUser() {
    if (numUsers >= MAX_NUM_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    char username[20];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);

    // check if username already exists
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, users[i].username) == 0) {
            printf("Username already exists. Please choose another.\n");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", password);

    // add new user to array
    User newUser;
    strcpy(newUser.username, username);
    strcpy(newUser.password, password);
    users[numUsers++] = newUser;
    printf("User added successfully.\n");
}

void changePassword() {
    char username[20];
    char currentPassword[MAX_PASSWORD_LENGTH];
    char newPassword[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    int userIndex = -1;
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, users[i].username) == 0) {
            userIndex = i;
            break;
        }
    }

    if (userIndex == -1) {
        printf("User %s does not exist.\n", username);
        return;
    }

    printf("Enter current password: ");
    scanf("%s", currentPassword);

    if (strcmp(currentPassword, users[userIndex].password) != 0) {
        printf("Incorrect password. Please try again.\n");
        return;
    }

    printf("Enter new password: ");
    scanf("%s", newPassword);
    strcpy(users[userIndex].password, newPassword);
    printf("Password changed successfully.\n");
}

void listUsers() {
    if (numUsers == 0) {
        printf("No users yet.\n");
        return;
    }

    printf("List of users:\n");
    for (int i = 0; i < numUsers; i++) {
        printf("%s\n", users[i].username);
    }
}

void saveToFile() {
    FILE* file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    for (int i = 0; i < numUsers; i++) {
        fprintf(file, "%s %s\n", users[i].username, users[i].password);
    }

    fclose(file);
}

void loadFromFile() {
    FILE* file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    char username[20];
    char password[MAX_PASSWORD_LENGTH];
    while (fscanf(file, "%s %s", username, password) == 2) {
        User newUser;
        strcpy(newUser.username, username);
        strcpy(newUser.password, password);
        users[numUsers++] = newUser;
    }

    fclose(file);
}