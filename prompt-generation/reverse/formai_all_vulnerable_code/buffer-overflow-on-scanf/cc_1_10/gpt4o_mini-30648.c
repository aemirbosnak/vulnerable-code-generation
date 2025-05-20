//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 100

// Structure to hold a user record
typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} User;

// Function prototypes
void displayMenu();
void addUser(User *users, int *count);
void displayUsers(User *users, int count);
void searchUser(User *users, int count);
void deleteUser(User *users, int *count);
void saveToFile(User *users, int count);
void loadFromFile(User *users, int *count);

int main() {
    User users[MAX_RECORDS];
    int count = 0;
    int choice;

    loadFromFile(users, &count); // Load existing users from file

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after entering the choice

        switch (choice) {
            case 1:
                addUser(users, &count);
                break;
            case 2:
                displayUsers(users, count);
                break;
            case 3:
                searchUser(users, count);
                break;
            case 4:
                deleteUser(users, &count);
                break;
            case 5:
                saveToFile(users, count);
                printf("Data saved successfully.\n");
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n=== User Database Menu ===\n");
    printf("1. Add User\n");
    printf("2. Display Users\n");
    printf("3. Search User\n");
    printf("4. Delete User\n");
    printf("5. Save to File\n");
    printf("6. Exit\n");
}

void addUser(User *users, int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Database is full. Cannot add more users.\n");
        return;
    }
    User newUser;

    newUser.id = *count + 1; // Simple auto-increment logic
    printf("Enter name: ");
    fgets(newUser.name, NAME_LENGTH, stdin);
    newUser.name[strcspn(newUser.name, "\n")] = '\0'; // Remove newline character

    printf("Enter email: ");
    fgets(newUser.email, EMAIL_LENGTH, stdin);
    newUser.email[strcspn(newUser.email, "\n")] = '\0'; // Remove newline character

    users[*count] = newUser;
    (*count)++;
    printf("User added successfully.\n");
}

void displayUsers(User *users, int count) {
    printf("\n=== User List ===\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", users[i].id, users[i].name, users[i].email);
    }
}

void searchUser(User *users, int count) {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("Found User - ID: %d, Name: %s, Email: %s\n", users[i].id, users[i].name, users[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("User not found.\n");
    }
}

void deleteUser(User *users, int *count) {
    int id;
    printf("Enter ID of user to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > *count) {
        printf("Invalid ID.\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        users[i] = users[i + 1]; // Shift records left
    }
    (*count)--;
    printf("User deleted successfully.\n");
}

void saveToFile(User *users, int count) {
    FILE *file = fopen("users.dat", "wb");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(users, sizeof(User), count, file);
    fclose(file);
}

void loadFromFile(User *users, int *count) {
    FILE *file = fopen("users.dat", "rb");
    if (!file) {
        *count = 0; // No file means no users initially
        return;
    }
    *count = fread(users, sizeof(User), MAX_RECORDS, file);
    fclose(file);
}