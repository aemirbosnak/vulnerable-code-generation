//FormAI DATASET v1.0 Category: File system simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10  // Define maximum number of files in the file system
#define MAX_NAME 20   // Define maximum length of file name

// Define a structure to represent a file
struct file {
    char name[MAX_NAME];
    int size;
};

// Declare global variables
struct file files[MAX_FILES];
int num_files = 0;
int total_size = 0;

// Function to create a new file
void create_file() {
    char name[MAX_NAME];
    int size;

    // Prompt user for file name
    printf("Enter file name: ");
    scanf("%s", name);

    // Check if file name already exists
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("File name already exists.\n");
            return;
        }
    }

    // Prompt user for file size
    printf("Enter file size (in bytes): ");
    scanf("%d", &size);

    // Check if file system has enough space
    if (total_size + size > MAX_FILES) {
        printf("File system is full.\n");
        return;
    }

    // Add file to file system
    struct file new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    files[num_files++] = new_file;
    total_size += size;

    printf("File created successfully.\n");
}

// Function to delete a file
void delete_file() {
    char name[MAX_NAME];

    // Prompt user for file name
    printf("Enter file name: ");
    scanf("%s", name);

    // Find file in array and remove it
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            total_size -= files[i].size;
            for (int j = i; j < num_files - 1; j++) {
                files[j] = files[j + 1];
            }
            num_files--;
            printf("File deleted successfully.\n");
            return;
        }
    }

    printf("File not found.\n");
}

// Function to display all files in file system
void display_files() {
    printf("File system contents:\n");
    for (int i = 0; i < num_files; i++) {
        printf("- %s (%d bytes)\n", files[i].name, files[i].size);
    }
}

// Main function
int main() {
    int choice;

    do {
        // Display menu
        printf("\n");
        printf("File System Simulation\n");
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. Display files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        // Get user choice
        scanf("%d", &choice);

        // Call appropriate function based on user choice
        switch(choice) {
            case 1:
                create_file();
                break;
            case 2:
                delete_file();
                break;
            case 3:
                display_files();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}