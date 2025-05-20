//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define USERNAME_LEN 30
#define PASSWORD_LEN 30
#define FILE_NAME "passwords.dat"

typedef struct {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
} User;

void displayMenu();
void addUser();
void viewUsers();
void deleteUser();
void saveUsers(User users[], int count);
int loadUsers(User users[]);
void passwordStrengthCheck(char *password);

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                viewUsers();
                break;
            case 3:
                deleteUser();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n==== Password Management System ====\n");
    printf("1. Add new user and password\n");
    printf("2. View all users\n");
    printf("3. Delete a user\n");
    printf("4. Exit\n");
    printf("====================================\n");
}

void addUser() {
    User user;
    FILE *file = fopen(FILE_NAME, "ab");  // open file in binary append mode
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    printf("Enter username: ");
    scanf("%s", user.username);
    printf("Enter password: ");
    scanf("%s", user.password);

    passwordStrengthCheck(user.password);
    
    fwrite(&user, sizeof(User), 1, file);  // write the new user to file
    fclose(file);
    printf("User added successfully!\n");
}

void viewUsers() {
    User users[MAX_USERS];
    int count = loadUsers(users);
    
    if (count == 0) {
        printf("No users found.\n");
        return;
    }

    printf("==== List of Users ====\n");
    for (int i = 0; i < count; ++i) {
        printf("Username: %s\n", users[i].username);
    }
    printf("========================\n");
}

void deleteUser() {
    User users[MAX_USERS];
    int count = loadUsers(users);
    char username[USERNAME_LEN];
    int found = 0;

    if (count == 0) {
        printf("No users to delete.\n");
        return;
    }

    printf("Enter the username to delete: ");
    scanf("%s", username);

    FILE *file = fopen(FILE_NAME, "wb");  // open file in binary write mode
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    for (int i = 0; i < count; ++i) {
        if (strcmp(users[i].username, username) == 0) {
            found = 1;
            continue;  // skip copying this user
        }
        fwrite(&users[i], sizeof(User), 1, file);  // write remaining users
    }
    fclose(file);

    if (found) {
        printf("User deleted successfully!\n");
    } else {
        printf("User not found.\n");
    }
}

void saveUsers(User users[], int count) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }
    fwrite(users, sizeof(User), count, file);
    fclose(file);
}

int loadUsers(User users[]) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        return 0;  // file doesn't exist, return 0
    }
    int count = fread(users, sizeof(User), MAX_USERS, file);
    fclose(file);
    return count;
}

void passwordStrengthCheck(char *password) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0, length = strlen(password);
    
    for (int i = 0; i < length; ++i) {
        if (password[i] >= 'A' && password[i] <= 'Z') hasUpper = 1;
        if (password[i] >= 'a' && password[i] <= 'z') hasLower = 1;
        if (password[i] >= '0' && password[i] <= '9') hasDigit = 1;
    }
    
    if (length < 8 || !hasUpper || !hasLower || !hasDigit) {
        printf("Warning: Password is weak! Must be at least 8 characters and include upper, lower, and digit.\n");
    } else {
        printf("Password strength is strong.\n");
    }
}