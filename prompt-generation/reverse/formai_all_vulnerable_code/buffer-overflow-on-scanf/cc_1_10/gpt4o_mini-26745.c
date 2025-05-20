//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} User;

User database[MAX_RECORDS];
int recordCount = 0;

void displayMenu() {
    printf("\n--- User Database Menu ---\n");
    printf("1. Add User\n");
    printf("2. View Users\n");
    printf("3. Search User\n");
    printf("4. Delete User\n");
    printf("5. Exit\n");
    printf("-------------------------\n");
    printf("Select an option: ");
}

void addUser() {
    if (recordCount >= MAX_RECORDS) {
        printf("Database is full. Cannot add more users.\n");
        return;
    }
    User newUser;
    newUser.id = recordCount + 1; // Simple ID assignment
    printf("Enter name: ");
    scanf(" %[^\n]", newUser.name);
    printf("Enter email: ");
    scanf(" %[^\n]", newUser.email);

    database[recordCount++] = newUser;
    printf("User added successfully!\n");
}

void viewUsers() {
    if (recordCount == 0) {
        printf("No users to display.\n");
        return;
    }
    printf("\n--- User List ---\n");
    for (int i = 0; i < recordCount; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", database[i].id, database[i].name, database[i].email);
    }
}

void searchUser() {
    char searchName[NAME_LENGTH];
    printf("Enter the name of the user to search: ");
    scanf(" %[^\n]", searchName);

    for (int i = 0; i < recordCount; i++) {
        if (strcmp(database[i].name, searchName) == 0) {
            printf("User found! ID: %d, Name: %s, Email: %s\n", database[i].id, database[i].name, database[i].email);
            return;
        }
    }
    printf("User not found.\n");
}

void deleteUser() {
    int id;
    printf("Enter the ID of the user to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > recordCount) {
        printf("Invalid user ID.\n");
        return;
    }

    for (int i = id - 1; i < recordCount - 1; i++) {
        database[i] = database[i + 1]; // Shift records left
    }
    recordCount--;
    printf("User with ID %d deleted successfully!\n", id);
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                viewUsers();
                break;
            case 3:
                searchUser();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}