//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define FILE_NAME_LENGTH 50
#define FILE_CONTENT_LENGTH 256

typedef struct {
    char name[FILE_NAME_LENGTH];
    char content[FILE_CONTENT_LENGTH];
    int is_used; // Flag to check if the file is in use
} File;

File file_system[MAX_FILES];

// Function to create a new file
void create_file() {
    char name[FILE_NAME_LENGTH];
    printf("Enter the name of the file to create: ");
    scanf("%s", name);

    for (int i = 0; i < MAX_FILES; i++) {
        if (!file_system[i].is_used) { // Check for an empty spot
            strcpy(file_system[i].name, name);
            file_system[i].content[0] = '\0'; // Initialize content
            file_system[i].is_used = 1; // Mark file as used
            printf("File '%s' created successfully.\n", name);
            return;
        }
    }
    printf("File system is full. Cannot create more files.\n");
}

// Function to write content to a file
void write_file() {
    char name[FILE_NAME_LENGTH];
    char content[FILE_CONTENT_LENGTH];

    printf("Enter the name of the file to write to: ");
    scanf("%s", name);
    for (int i = 0; i < MAX_FILES; i++) {
        if (file_system[i].is_used && strcmp(file_system[i].name, name) == 0) {
            printf("Enter content to write: ");
            scanf(" %[^\n]", content); // Read multiple words
            strcpy(file_system[i].content, content);
            printf("Content written to file '%s'.\n", name);
            return;
        }
    }
    printf("File '%s' not found.\n", name);
}

// Function to read content from a file
void read_file() {
    char name[FILE_NAME_LENGTH];

    printf("Enter the name of the file to read from: ");
    scanf("%s", name);
    for (int i = 0; i < MAX_FILES; i++) {
        if (file_system[i].is_used && strcmp(file_system[i].name, name) == 0) {
            printf("Content of file '%s': %s\n", name, file_system[i].content);
            return;
        }
    }
    printf("File '%s' not found.\n", name);
}

// Function to list all files
void list_files() {
    printf("List of files:\n");
    for (int i = 0; i < MAX_FILES; i++) {
        if (file_system[i].is_used) {
            printf("- %s\n", file_system[i].name);
        }
    }
}

// Main program
int main() {
    int choice;

    // Initialize file system
    memset(file_system, 0, sizeof(file_system)); // Clear the file system

    while (1) {
        // Display menu
        printf("\nFile System Simulation Menu:\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Read from File\n");
        printf("4. List Files\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_file();
                break;
            case 2:
                write_file();
                break;
            case 3:
                read_file();
                break;
            case 4:
                list_files();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}