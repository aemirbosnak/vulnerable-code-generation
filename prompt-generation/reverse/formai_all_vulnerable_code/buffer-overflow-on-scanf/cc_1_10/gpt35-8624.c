//FormAI DATASET v1.0 Category: File system simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_SIZE 1000

// Structure for a file
struct file {
    char name[MAX_FILENAME_LENGTH];
    char data[MAX_FILE_SIZE];
    bool is_active;
} files[MAX_FILES];

// Function to create a new file
void create_file() {
    int i = 0;
    while (files[i].is_active == true) {
        i++;
    }
    if (i >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }
    printf("Enter file name: ");
    scanf("%s", files[i].name);
    printf("Enter file data: ");
    scanf("%s", files[i].data);
    files[i].is_active = true;
    printf("File created successfully!\n");
}

// Function to delete a file
void delete_file() {
    int i = 0;
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", filename);
    while (i < MAX_FILES) {
        if (strcmp(files[i].name, filename) == 0) {
            files[i].is_active = false;
            printf("File deleted successfully!\n");
            return;
        }
        i++;
    }
    printf("Error: File not found.\n");
}

// Function to view all files
void view_files() {
    printf("List of active files:\n");
    int i = 0;
    while (i < MAX_FILES) {
        if (files[i].is_active == true) {
            printf("%s\n", files[i].name);
        }
        i++;
    }
}

int main() {
    int choice;
    while (true) {
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. View all files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            create_file();
            break;
        case 2:
            delete_file();
            break;
        case 3:
            view_files();
            break;
        case 4:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    return 0;
}