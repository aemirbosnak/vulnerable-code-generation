//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define USERNAME_LENGTH 30
#define USER_FILE "users.txt"

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape sequence to clear the screen
}

void add_user(const char *username) {
    FILE *file = fopen(USER_FILE, "a");
    if (!file) {
        perror("Failed to open the user file");
        return;
    }
    fprintf(file, "%s\n", username);
    fclose(file);
    printf("User '%s' added successfully!\n", username);
}

void remove_user(const char *username) {
    FILE *file = fopen(USER_FILE, "r");
    if (!file) {
        perror("Failed to open the user file");
        return;
    }

    char *temp_filename = "temp.txt";
    FILE *temp_file = fopen(temp_filename, "w");
    if (!temp_file) {
        perror("Failed to create a temporary file");
        fclose(file);
        return;
    }

    char line[USERNAME_LENGTH + 1];
    int found = 0;
    
    while (fgets(line, sizeof(line), file)) {
        // Remove the newline character
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, username) != 0) {
            fprintf(temp_file, "%s\n", line);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp_file);

    if (found) {
        remove(USER_FILE);
        rename(temp_filename, USER_FILE);
        printf("User '%s' removed successfully!\n", username);
    } else {
        printf("User '%s' not found.\n", username);
        remove(temp_filename); // Cleanup
    }
}

void list_users() {
    FILE *file = fopen(USER_FILE, "r");
    if (!file) {
        perror("Failed to open the user file");
        return;
    }

    printf("Users:\n");
    char line[USERNAME_LENGTH + 1];
    while (fgets(line, sizeof(line), file)) {
        printf(" - %s", line);
    }
    fclose(file);
}

int main() {
    while (1) {
        clear_screen();
        printf("Welcome to the Simple User Management System!\n");
        printf("1. Add User\n");
        printf("2. Remove User\n");
        printf("3. List Users\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the buffer

        switch (choice) {
            case 1: {
                char username[USERNAME_LENGTH];
                printf("Enter username to add: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = '\0'; // Remove newline
                add_user(username);
                break;
            }
            case 2: {
                char username[USERNAME_LENGTH];
                printf("Enter username to remove: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = '\0'; // Remove newline
                remove_user(username);
                break;
            }
            case 3:
                list_users();
                printf("Press Enter to continue...");
                getchar(); // Wait for the user to press Enter
                break;
            case 4:
                printf("Exiting the program. Have a nice day!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                printf("Press Enter to continue...");
                getchar(); // Wait for the user to press Enter
        }
    }

    return 0;
}