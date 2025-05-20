//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define NAME_LENGTH 50
#define FILE_NAME "database.txt"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[NAME_LENGTH];
} User;

void addUser();
void deleteUser();
void displayUsers();
void loadUsers(User users[], int *count);
void saveUsers(User users[], int count);

int main() {
    int choice;

    while (1) {
        printf("\n--- User Database Menu ---\n");
        printf("1. Add User\n");
        printf("2. Delete User\n");
        printf("3. Display Users\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                deleteUser();
                break;
            case 3:
                displayUsers();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void addUser() {
    User user;
    FILE *file;

    printf("Enter User ID: ");
    scanf("%d", &user.id);
    printf("Enter Name: ");
    scanf("%s", user.name);
    printf("Enter Email: ");
    scanf("%s", user.email);

    file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }
    fprintf(file, "%d %s %s\n", user.id, user.name, user.email);
    fclose(file);

    printf("User added successfully!\n");
}

void deleteUser() {
    User users[MAX_USERS];
    int count = 0;
    int idToDelete;
    FILE *file;

    loadUsers(users, &count);
    
    printf("Enter User ID to delete: ");
    scanf("%d", &idToDelete);

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Unable to open temporary file!");
        return;
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (users[i].id != idToDelete) {
            fprintf(tempFile, "%d %s %s\n", users[i].id, users[i].name, users[i].email);
        } else {
            found = 1;
        }
    }

    fclose(tempFile);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("User with ID %d deleted successfully!\n", idToDelete);
    } else {
        printf("User with ID %d not found!\n", idToDelete);
    }
}

void displayUsers() {
    User users[MAX_USERS];
    int count = 0;

    loadUsers(users, &count);
    
    printf("\n--- User List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", users[i].id, users[i].name, users[i].email);
    }
    if (count == 0) {
        printf("No users found.\n");
    }
}

void loadUsers(User users[], int *count) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        *count = 0;
        return;
    }

    while (fscanf(file, "%d %s %s", &users[*count].id, users[*count].name, users[*count].email) != EOF) {
        (*count)++;
    }
    fclose(file);
}

void saveUsers(User users[], int count) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %s\n", users[i].id, users[i].name, users[i].email);
    }
    fclose(file);
}