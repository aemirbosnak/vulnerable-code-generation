//FormAI DATASET v1.0 Category: System administration ; Style: modular
#include <stdio.h>

// Function prototypes
void displayMenu();
void createUser();
void deleteUser();
void changePassword();
void viewUsers();

// Global variables
int numUsers = 0;

struct User {
    int id;
    char username[20];
    char password[20];
} users[50];

int main() {
    displayMenu();
    return 0;
}

void displayMenu() {
    int choice;
    do {
        printf("Welcome to the User Administration program!\n");
        printf("1. Create User\n");
        printf("2. Delete User\n");
        printf("3. Change Password\n");
        printf("4. View Users\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                deleteUser();
                break;
            case 3:
                changePassword();
                break;
            case 4:
                viewUsers();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

void createUser() {
    struct User user;
    printf("Enter username: ");
    scanf("%s", user.username);
    printf("Enter password: ");
    scanf("%s", user.password);
    user.id = ++numUsers;
    users[numUsers-1] = user;
    printf("User created successfully!\n");
}

void deleteUser() {
    int id;
    printf("Enter user ID: ");
    scanf("%d", &id);
    if (id < 1 || id > numUsers) {
        printf("Invalid ID. Please try again.\n");
        return;
    }
    for (int i = id-1; i < numUsers-1; i++) {
        users[i] = users[i+1];
    }
    numUsers--;
    printf("User deleted successfully!\n");
}

void changePassword() {
    int id;
    printf("Enter user ID: ");
    scanf("%d", &id);
    if (id < 1 || id > numUsers) {
        printf("Invalid ID. Please try again.\n");
        return;
    }
    printf("Enter new password: ");
    scanf("%s", users[id-1].password);
    printf("Password changed successfully!\n");
}

void viewUsers() {
    printf("ID\tUsername\tPassword\n");
    for (int i = 0; i < numUsers; i++) {
        printf("%d\t%s\t\t%s\n", users[i].id, users[i].username, users[i].password);
    }
}