//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define ERROR_MSG_LENGTH 256

// Function prototypes
void create_file(const char *filename);
void read_file(const char *filename);
void delete_file(const char *filename);
void error_handler(const char *msg, int err_code);

// Main function
int main() {
    int choice;
    char filename[MAX_FILENAME_LENGTH];

    while (1) {
        printf("\n--- Simple File Management System ---\n");
        printf("1. Create a file\n");
        printf("2. Read a file\n");
        printf("3. Delete a file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                printf("Enter filename to create: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove the newline character
                create_file(filename);
                break;

            case 2:
                printf("Enter filename to read: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                read_file(filename);
                break;

            case 3:
                printf("Enter filename to delete: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                delete_file(filename);
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                error_handler("Invalid choice. Please select from the menu options.", 1);
        }
    }
    return 0;
}

// Create a file
void create_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        error_handler("Failed to create the file", 2);
        return;
    }
    fprintf(file, "This is a sample file named %s.\n", filename);
    fclose(file);
    printf("File '%s' created successfully.\n", filename);
}

// Read from a file
void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        error_handler("Failed to open the file for reading", 3);
        return;
    }

    char buffer[256];
    printf("Contents of the file '%s':\n", filename);
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

// Delete a file
void delete_file(const char *filename) {
    if (remove(filename) != 0) {
        error_handler("Failed to delete the file", 4);
        return;
    }
    printf("File '%s' deleted successfully.\n", filename);
}

// Custom error handler
void error_handler(const char *msg, int err_code) {
    char error_msg[ERROR_MSG_LENGTH];
    snprintf(error_msg, sizeof(error_msg), "Error %d: %s\n", err_code, msg);
    fprintf(stderr, "%s", error_msg);
}