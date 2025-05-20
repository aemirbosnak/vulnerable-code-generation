//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} User;

User database[MAX_ENTRIES];
int userCount = 0;

void addUser();
void displayUsers();
void searchUser();
void updateUser();
void deleteUser();

int main() {
    int choice;

    while (1) {
        printf("\n--- Database Menu ---\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Search User\n");
        printf("4. Update User\n");
        printf("5. Delete User\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                displayUsers();
                break;
            case 3:
                searchUser();
                break;
            case 4:
                updateUser();
                break;
            case 5:
                deleteUser();
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void addUser() {
    if (userCount >= MAX_ENTRIES) {
        printf("Database is full. Cannot add more users.\n");
        return;
    }

    User newUser;
    newUser.id = userCount + 1; // Simple ID assignment
    printf("Enter name: ");
    getchar(); // Clear newline from input buffer
    fgets(newUser.name, NAME_LENGTH, stdin);
    newUser.name[strcspn(newUser.name, "\n")] = 0; // Remove trailing newline

    printf("Enter email: ");
    fgets(newUser.email, EMAIL_LENGTH, stdin);
    newUser.email[strcspn(newUser.email, "\n")] = 0; // Remove trailing newline

    database[userCount] = newUser;
    userCount++;
    printf("User added successfully with ID: %d\n", newUser.id);
}

void displayUsers() {
    if (userCount == 0) {
        printf("No users in the database.\n");
        return;
    }

    printf("\n--- User List ---\n");
    for (int i = 0; i < userCount; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", database[i].id, database[i].name, database[i].email);
    }
}

void searchUser() {
    int id;
    printf("Enter User ID to search: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > userCount) {
        printf("User not found.\n");
        return;
    }

    User user = database[id - 1];
    printf("User found: ID: %d, Name: %s, Email: %s\n", user.id, user.name, user.email);
}

void updateUser() {
    int id;
    printf("Enter User ID to update: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > userCount) {
        printf("User not found.\n");
        return;
    }

    User* userToUpdate = &database[id - 1];
    printf("Updating User ID: %d\n", userToUpdate->id);

    printf("Enter new name (leave empty for no change): ");
    getchar(); // Clear newline from input buffer
    char newName[NAME_LENGTH];
    fgets(newName, NAME_LENGTH, stdin);
    newName[strcspn(newName, "\n")] = 0; // Remove trailing newline
    if (strlen(newName) > 0) {
        strcpy(userToUpdate->name, newName);
    }

    printf("Enter new email (leave empty for no change): ");
    char newEmail[EMAIL_LENGTH];
    fgets(newEmail, EMAIL_LENGTH, stdin);
    newEmail[strcspn(newEmail, "\n")] = 0; // Remove trailing newline
    if (strlen(newEmail) > 0) {
        strcpy(userToUpdate->email, newEmail);
    }

    printf("User updated successfully.\n");
}

void deleteUser() {
    int id;
    printf("Enter User ID to delete: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > userCount) {
        printf("User not found.\n");
        return;
    }

    for (int i = id - 1; i < userCount - 1; i++) {
        database[i] = database[i + 1]; // Shift users left
    }

    userCount--;
    printf("User ID: %d deleted successfully.\n", id);
}