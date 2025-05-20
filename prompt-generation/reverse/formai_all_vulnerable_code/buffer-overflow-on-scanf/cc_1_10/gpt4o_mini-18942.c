//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define FILENAME "users.txt"

typedef struct User {
    int id;
    char name[50];
    char email[50];
} User;

int loadUsers(User users[], int maxUsers) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Failed to open file for reading");
        return -1; // Error code for file opening
    }

    int count = 0;
    while (count < maxUsers && fscanf(file, "%d %49s %49s", &users[count].id, users[count].name, users[count].email) == 3) {
        count++;
    }

    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return -2; // Error code for reading
    }

    fclose(file);
    return count;
}

int saveUsers(const User users[], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Failed to open file for writing");
        return -1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %s\n", users[i].id, users[i].name, users[i].email);
    }

    if (ferror(file)) {
        perror("Error writing to file");
        fclose(file);
        return -2;
    }

    fclose(file);
    return 0;
}

void printUser(const User *user) {
    printf("ID: %d, Name: %s, Email: %s\n", user->id, user->name, user->email);
}

void listUsers(const User users[], int count) {
    if (count == 0) {
        printf("No users found.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printUser(&users[i]);
    }
}

int addUser(User users[], int *count) {
    if (*count >= MAX_USERS) {
        fprintf(stderr, "User limit reached. Cannot add more users.\n");
        return -1;
    }

    User newUser;
    printf("Enter user ID: ");
    if (scanf("%d", &newUser.id) != 1) {
        fprintf(stderr, "Invalid input. User ID must be an integer.\n");
        return -2; // Error code for invalid input
    }
    printf("Enter user name: ");
    scanf("%s", newUser.name);
    printf("Enter user email: ");
    scanf("%s", newUser.email);

    users[*count] = newUser;
    (*count)++;
    return 0;
}

void displayMenu() {
    printf("\nUser Management System\n");
    printf("1. List Users\n");
    printf("2. Add User\n");
    printf("3. Save Users\n");
    printf("4. Load Users\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    User users[MAX_USERS];
    int userCount = 0;
    int choice;

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number between 1 and 5.\n");
            // clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                listUsers(users, userCount);
                break;
            case 2:
                if (addUser(users, &userCount) < 0) {
                    fprintf(stderr, "Failed to add user.\n");
                }
                break;
            case 3:
                if (saveUsers(users, userCount) < 0) {
                    fprintf(stderr, "Failed to save users.\n");
                } else {
                    printf("Users saved successfully.\n");
                }
                break;
            case 4:
                {
                    int loadedCount = loadUsers(users, MAX_USERS);
                    if (loadedCount >= 0) {
                        userCount = loadedCount;
                        printf("%d users loaded successfully.\n", userCount);
                    } else {
                        fprintf(stderr, "Failed to load users.\n");
                    }
                }
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                fprintf(stderr, "Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}