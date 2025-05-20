//FormAI DATASET v1.0 Category: Password management ; Style: Ada Lovelace
/*
** Password Manager Program
** By Ada Lovelace
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global Variables
int validUserCount = 0;
int invalidUserCount = 0;

// Function Prototypes
void login();
void addNewUser();
void changePassword();
void printPassword();

// User Struct
struct User {
    char username[20];
    char password[20];
};

// Array of Users
struct User users[20];

// Main Function
int main() {
    int option;
    do {
        printf("Password Manager:\n");
        printf("-----------------------\n");
        printf("1. Login\n");
        printf("2. Add New User\n");
        printf("3. Change Password\n");
        printf("4. Print Password\n");
        printf("5. Exit\n");
        printf("-----------------------\n");

        printf("Please enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                login();
                break;
            case 2:
                addNewUser();
                break;
            case 3:
                changePassword();
                break;
            case 4:
                printPassword();
                break;
        }
    } while(option != 5);

    return 0;
}

// Login Function
void login() {
    char username[20];
    char password[20];
    int found = 0;
    int i;

    printf("Login\n");
    printf("-----------------------\n");

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    for(i = 0; i < validUserCount; i++) {
        if(strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Welcome %s\n", username);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Invalid Username or Password\n");
        invalidUserCount++;
    }
}

// Add New User Function
void addNewUser() {
    char username[20];
    char password[20];

    printf("Add New User\n");
    printf("-----------------------\n");

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    strcpy(users[validUserCount].username, username);
    strcpy(users[validUserCount].password, password);

    validUserCount++;
}

// Change Password Function
void changePassword() {
    char username[20];
    char password[20];
    char newPassword[20];
    int found = 0;
    int i;

    printf("Change Password\n");
    printf("-----------------------\n");

    printf("Username: ");
    scanf("%s", username);
    printf("Old Password: ");
    scanf("%s", password);
    printf("New Password: ");
    scanf("%s", newPassword);

    for(i = 0; i < validUserCount; i++) {
        if(strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            strcpy(users[i].password, newPassword);
            printf("Password Changed Successfully\n");
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Invalid Username or Password\n");
        invalidUserCount++;
    }
}

// Print Password Function
void printPassword() {
    char username[20];
    char password[20];
    int found = 0;
    int i;

    printf("Print Password\n");
    printf("-----------------------\n");

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    for(i = 0; i < validUserCount; i++) {
        if(strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Password: %s\n", users[i].password);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Invalid Username or Password\n");
        invalidUserCount++;
    }
}