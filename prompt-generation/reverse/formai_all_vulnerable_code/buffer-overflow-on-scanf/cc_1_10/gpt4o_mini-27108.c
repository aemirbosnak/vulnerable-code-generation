//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

#define MAX_PATH 256
#define MAX_USERS 100

typedef struct {
    char username[50];
    char homeDir[MAX_PATH];
    time_t lastLogin;
} User;

User users[MAX_USERS];
int userCount = 0;

void listUsers() {
    printf("Registered Users:\n");
    for(int i = 0; i < userCount; i++) {
        printf("Username: %s, Home Directory: %s, Last Login: %s",
               users[i].username, users[i].homeDir, ctime(&users[i].lastLogin));
    }
}

void addUser(const char* username) {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot add more users.\n");
        return;
    }

    strcpy(users[userCount].username, username);
    snprintf(users[userCount].homeDir, MAX_PATH, "/home/%s", username);
    users[userCount].lastLogin = time(NULL);
    userCount++;

    printf("User '%s' added with home directory '%s'.\n", username, users[userCount-1].homeDir);
}

void deleteUser(const char* username) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            for (int j = i; j < userCount - 1; j++) {
                users[j] = users[j + 1]; // Shift users left
            }
            userCount--;
            printf("User '%s' deleted successfully.\n", username);
            return;
        }
    }
    printf("User '%s' not found.\n", username);
}

void loginUser(const char* username) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            users[i].lastLogin = time(NULL);
            printf("User '%s' logged in. Last login updated to now.\n", username);
            return;
        }
    }
    printf("User '%s' not found for login.\n", username);
}

void displayMenu() {
    printf("\n--- User Management System ---\n");
    printf("1. List Users\n");
    printf("2. Add User\n");
    printf("3. Delete User\n");
    printf("4. Login User\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int option;
    char username[50];

    while (1) {
        displayMenu();
        scanf("%d", &option);
        getchar(); // Clear newline from buffer

        switch (option) {
            case 1:
                listUsers();
                break;
            case 2:
                printf("Enter a username to add: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // Remove newline
                addUser(username);
                break;
            case 3:
                printf("Enter a username to delete: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // Remove newline
                deleteUser(username);
                break;
            case 4:
                printf("Enter a username to login: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // Remove newline
                loginUser(username);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}