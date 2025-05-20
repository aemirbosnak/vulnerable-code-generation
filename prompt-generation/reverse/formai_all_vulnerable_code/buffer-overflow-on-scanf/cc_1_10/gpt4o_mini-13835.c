//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "users.txt"
#define MAX_NAME_LENGTH 50
#define MAX_BUFFER_LENGTH 1024

void addUser(const char *username) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s\n", username);
    fclose(file);
    printf("User '%s' added successfully.\n", username);
}

void displayUsers() {
    char buffer[MAX_BUFFER_LENGTH];
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    printf("Current users:\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

void deleteUser(const char *username) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        fclose(file);
        perror("Error opening temp file for writing");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFFER_LENGTH];
    int found = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        // Remove trailing newline
        buffer[strcspn(buffer, "\n")] = 0;

        if (strcmp(buffer, username) != 0) {
            fprintf(tempFile, "%s\n", buffer);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);
    
    if (found) {
        remove(FILENAME); // Remove the original file
        rename("temp.txt", FILENAME); // Rename temp to original
        printf("User '%s' deleted successfully.\n", username);
    } else {
        remove("temp.txt"); // Clean up temp file
        printf("User '%s' not found.\n", username);
    }
}

void clearBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int choice;
    char username[MAX_NAME_LENGTH];

    do {
        printf("\nUser Management System\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Delete User\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear newline from buffer
        
        switch (choice) {
            case 1:
                printf("Enter username to add: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // Remove the newline character
                if (strlen(username) > 0 && strlen(username) < MAX_NAME_LENGTH) {
                    addUser(username);
                } else {
                    printf("Invalid username length.\n");
                }
                break;

            case 2:
                displayUsers();
                break;

            case 3:
                printf("Enter username to delete: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // Remove the newline character
                if (strlen(username) > 0 && strlen(username) < MAX_NAME_LENGTH) {
                    deleteUser(username);
                } else {
                    printf("Invalid username length.\n");
                }
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}