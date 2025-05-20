//FormAI DATASET v1.0 Category: System administration ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
void addNewUser();
void deleteUser();
void resetPassword();
void viewUsers();
int searchUserID();

// Struct to store user information
struct User {
    int userID;
    char name[30];
    char password[30];
};

// Global variables
int numUsers = 0; // Number of users currently in system
struct User userList[10]; // Array to store user information

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addNewUser();
                break;
            case 2:
                deleteUser();
                break;
            case 3:
                resetPassword();
                break;
            case 4:
                viewUsers();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please enter a number from 1 to 5.\n");
        }
    } while (choice != 5);
    return 0;
}

void displayMenu() {
    printf("\n==== System Administration Menu ====\n");
    printf("1. Add New User\n");
    printf("2. Delete User\n");
    printf("3. Reset Password\n");
    printf("4. View Users\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void addNewUser() {
    if (numUsers < 10) {
        printf("\nEnter User ID: ");
        scanf("%d", &userList[numUsers].userID);
        printf("Enter User Name: ");
        scanf("%s", userList[numUsers].name);
        printf("Enter User Password: ");
        scanf("%s", userList[numUsers].password);
        numUsers++;
        printf("User added successfully.\n");
    } else {
        printf("\nUnable to add user, maximum number of users already in system.\n");
    }
}

void deleteUser() {
    int userID, userIndex;
    printf("\nEnter User ID to delete: ");
    scanf("%d", &userID);
    userIndex = searchUserID(userID);
    if (userIndex == -1) {
        printf("User not found.\n");
    } else {
        for (int i = userIndex; i < numUsers - 1; i++) {
            userList[i] = userList[i + 1];
        }
        numUsers--;
        printf("User deleted successfully.\n");
    }
}

void resetPassword() {
    int userID, userIndex;
    char newPassword[30];
    printf("\nEnter User ID to reset password: ");
    scanf("%d", &userID);
    userIndex = searchUserID(userID);
    if (userIndex == -1) {
        printf("User not found.\n");
    } else {
        printf("Enter new password: ");
        scanf("%s", newPassword);
        strcpy(userList[userIndex].password, newPassword);
        printf("Password reset successfully.\n");
    }
}

void viewUsers() {
    if (numUsers == 0) {
        printf("\nNo users in system.\n");
    } else {
        printf("\n=== User List ===\n");
        for (int i = 0; i < numUsers; i++) {
            printf("User ID: %d\n", userList[i].userID);
            printf("Name: %s\n", userList[i].name);
            printf("Password: %s\n\n", userList[i].password);
        }
    }
}

int searchUserID(int userID) {
    for (int i = 0; i < numUsers; i++) {
        if (userID == userList[i].userID) {
            return i;
        }
    }
    return -1;
}