//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} User;

User users[MAX_USERS];
int userCount = 0;

void addUser();
void displayUsers();
void editUser();
void deleteUser();
void saveToFile();
void loadFromFile();

int main() {
    int choice;

    loadFromFile();

    while (1) {
        printf("\n--- User Database Simulation ---\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Edit User\n");
        printf("4. Delete User\n");
        printf("5. Save to File\n");
        printf("6. Load from File\n");
        printf("7. Exit\n");
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
                editUser();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                saveToFile();
                break;
            case 6:
                loadFromFile();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot add more users.\n");
        return;
    }

    User newUser;
    printf("Enter User ID: ");
    scanf("%d", &newUser.id);
    printf("Enter User Name: ");
    getchar(); // consume newline
    fgets(newUser.name, NAME_LENGTH, stdin);
    newUser.name[strcspn(newUser.name, "\n")] = 0; // remove newline
    printf("Enter User Email: ");
    fgets(newUser.email, EMAIL_LENGTH, stdin);
    newUser.email[strcspn(newUser.email, "\n")] = 0; // remove newline
    
    users[userCount++] = newUser;
    printf("User added successfully!\n");
}

void displayUsers() {
    if (userCount == 0) {
        printf("No users to display.\n");
        return;
    }

    printf("\n--- User List ---\n");
    for (int i = 0; i < userCount; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", users[i].id, users[i].name, users[i].email);
    }
}

void editUser() {
    int id, found = 0;
    printf("Enter User ID to edit: ");
    scanf("%d", &id);

    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            found = 1;
            printf("Editing User: %s\n", users[i].name);
            printf("Enter new Name: ");
            getchar(); 
            fgets(users[i].name, NAME_LENGTH, stdin);
            users[i].name[strcspn(users[i].name, "\n")] = 0;

            printf("Enter new Email: ");
            fgets(users[i].email, EMAIL_LENGTH, stdin);
            users[i].email[strcspn(users[i].email, "\n")] = 0;

            printf("User updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("User with ID %d not found.\n", id);
    }
}

void deleteUser() {
    int id, found = 0;
    printf("Enter User ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            found = 1;
            for (int j = i; j < userCount - 1; j++) {
                users[j] = users[j + 1];
            }
            userCount--;
            printf("User deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("User with ID %d not found.\n", id);
    }
}

void saveToFile() {
    FILE *file = fopen("users.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(users, sizeof(User), userCount, file);
    fclose(file);
    printf("Users saved to file successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("No previous data found, starting fresh!\n");
        return;
    }
    userCount = fread(users, sizeof(User), MAX_USERS, file);
    fclose(file);
    printf("Users loaded from file successfully!\n");
}