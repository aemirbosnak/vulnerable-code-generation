//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int userID;
} User;

User users[MAX_USERS];
int userCount = 0;

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot add more users.\n");
        return;
    }

    User newUser;
    printf("Enter name: ");
    fgets(newUser.name, MAX_NAME_LENGTH, stdin);
    newUser.name[strcspn(newUser.name, "\n")] = '\0'; // Remove newline character

    printf("Enter email: ");
    fgets(newUser.email, MAX_EMAIL_LENGTH, stdin);
    newUser.email[strcspn(newUser.email, "\n")] = '\0'; // Remove newline character

    newUser.userID = userCount + 1; // Assign user ID starting from 1
    users[userCount] = newUser; // Store the new user
    userCount++;

    printf("User added successfully! User ID: %d\n", newUser.userID);
}

void listUsers() {
    if (userCount == 0) {
        printf("No users to display.\n");
        return;
    }

    printf("List of Users:\n");
    for (int i = 0; i < userCount; i++) {
        printf("User ID: %d, Name: %s, Email: %s\n", users[i].userID, users[i].name, users[i].email);
    }
}

void saveUsersToFile(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(users, sizeof(User), userCount, file);
    fclose(file);
    printf("Users saved to file successfully.\n");
}

void loadUsersFromFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }

    userCount = fread(users, sizeof(User), MAX_USERS, file);
    fclose(file);
    printf("Users loaded from file successfully. Count: %d\n", userCount);
}

void searchUserByID(int userID) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].userID == userID) {
            printf("User found: User ID: %d, Name: %s, Email: %s\n", users[i].userID, users[i].name, users[i].email);
            return;
        }
    }
    printf("User with ID %d not found.\n", userID);
}

int main() {
    int choice;
    char filename[] = "users.dat";

    while (1) {
        printf("\nUser Management System\n");
        printf("1. Add User\n");
        printf("2. List Users\n");
        printf("3. Save Users to File\n");
        printf("4. Load Users from File\n");
        printf("5. Search User by ID\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }
        getchar(); // Clear the newline character from input buffer

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                listUsers();
                break;
            case 3:
                saveUsersToFile(filename);
                break;
            case 4:
                loadUsersFromFile(filename);
                break;
            case 5: {
                int userID;
                printf("Enter User ID to search: ");
                if (scanf("%d", &userID) != 1) {
                    printf("Invalid ID. Please enter a number.\n");
                } else {
                    searchUserByID(userID);
                }
                getchar(); // Clear the newline character from input buffer
                break;
            }
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}