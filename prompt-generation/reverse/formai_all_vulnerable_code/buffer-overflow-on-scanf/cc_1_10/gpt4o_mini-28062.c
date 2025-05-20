//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_USERS 100
#define MAX_LOG_SIZE 1024
#define LOG_FILE "system_admin_log.txt"

typedef struct {
    char username[256];
    char homeDirectory[512];
    bool isActive;
} User;

User userList[MAX_USERS];
int userCount = 0;

void logActivity(const char *action) {
    FILE *logFile = fopen(LOG_FILE, "a");
    if (logFile == NULL) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }
    fprintf(logFile, "%s: %s\n", action, ctime(&(time_t){time(NULL)}));
    fclose(logFile);
}

void addUser(const char *username) {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot add more users.\n");
        return;
    }
    
    struct passwd *pwd = getpwnam(username);
    if (pwd != NULL) {
        printf("User '%s' already exists!\n", username);
        return;
    }

    struct stat st = {0};
    snprintf(userList[userCount].homeDirectory, sizeof(userList[userCount].homeDirectory), "/home/%s", username);

    if (stat(userList[userCount].homeDirectory, &st) == -1) {
        mkdir(userList[userCount].homeDirectory, 0700);
        printf("Created home directory for user: %s\n", username);
    }

    strncpy(userList[userCount].username, username, sizeof(userList[userCount].username));
    userList[userCount].isActive = true;
    userCount++;

    printf("User '%s' added successfully.\n", username);
    logActivity("Added user");
}

void deleteUser(const char *username) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(userList[i].username, username) == 0) {
            userList[i].isActive = false;
            printf("User '%s' deleted successfully.\n", username);
            logActivity("Deleted user");
            return;
        }
    }
    printf("User '%s' not found!\n", username);
}

void listUsers() {
    printf("Active Users:\n");
    for (int i = 0; i < userCount; i++) {
        if (userList[i].isActive) {
            printf("- %s (Home: %s)\n", userList[i].username, userList[i].homeDirectory);
        }
    }
}

void displayMenu() {
    printf("\n===== System Administration Menu =====\n");
    printf("1. Add User\n");
    printf("2. Delete User\n");
    printf("3. List Users\n");
    printf("4. Exit\n");
    printf("======================================\n");
}

int main() {
    int choice;
    char username[256];

    while (true) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1:
                printf("Enter username to add: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // remove newline
                addUser(username);
                break;
            case 2:
                printf("Enter username to delete: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // remove newline
                deleteUser(username);
                break;
            case 3:
                listUsers();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}