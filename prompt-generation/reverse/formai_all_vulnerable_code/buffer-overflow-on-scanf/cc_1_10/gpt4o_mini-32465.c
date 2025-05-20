//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define NAME_LENGTH 30
#define EMAIL_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} User;

User users[MAX_USERS];
int userCount = 0;

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("Database is full! Cannot add more users.\n");
        return;
    }

    User newUser;
    newUser.id = userCount + 1;
    
    printf("Enter name: ");
    scanf("%s", newUser.name);
    
    printf("Enter email: ");
    scanf("%s", newUser.email);
    
    users[userCount] = newUser;
    userCount++;
    printf("User added successfully! (ID: %d)\n", newUser.id);
}

void displayUsers() {
    if (userCount == 0) {
        printf("No users to display.\n");
        return;
    }

    printf("\nList of users:\n");
    printf("ID\tName\t\tEmail\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < userCount; i++) {
        printf("%d\t%s\t\t%s\n", users[i].id, users[i].name, users[i].email);
    }
}

void findUser() {
    int id;
    printf("Enter user ID to find: ");
    scanf("%d", &id);
    
    if (id < 1 || id > userCount) {
        printf("User with ID %d not found.\n", id);
        return;
    }
    
    User foundUser = users[id - 1];
    printf("User found: ID: %d, Name: %s, Email: %s\n", foundUser.id, foundUser.name, foundUser.email);
}

void deleteUser() {
    int id;
    printf("Enter user ID to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > userCount) {
        printf("User with ID %d not found.\n", id);
        return;
    }
    
    for (int i = id - 1; i < userCount - 1; i++) {
        users[i] = users[i + 1];
    }
    
    userCount--;
    printf("User with ID %d deleted successfully!\n", id);
}

void saveDataToFile() {
    FILE *file = fopen("users.dat", "wb");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(users, sizeof(User), userCount, file);
    fclose(file);
    printf("Data saved to file successfully.\n");
}

void loadDataFromFile() {
    FILE *file = fopen("users.dat", "rb");
    if (!file) {
        printf("Error opening file for reading. Starting with an empty database.\n");
        return;
    }
    
    userCount = fread(users, sizeof(User), MAX_USERS, file);
    fclose(file);
    printf("Data loaded from file successfully. %d users loaded.\n", userCount);
}

void displayMenu() {
    printf("\n--- User Database Menu ---\n");
    printf("1. Add User\n");
    printf("2. Display Users\n");
    printf("3. Find User\n");
    printf("4. Delete User\n");
    printf("5. Save Data\n");
    printf("6. Load Data\n");
    printf("7. Exit\n");
}

int main() {
    int choice;
    
    loadDataFromFile();
    
    while (1) {
        displayMenu();
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
                findUser();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                saveDataToFile();
                break;
            case 6:
                loadDataFromFile();
                break;
            case 7:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}