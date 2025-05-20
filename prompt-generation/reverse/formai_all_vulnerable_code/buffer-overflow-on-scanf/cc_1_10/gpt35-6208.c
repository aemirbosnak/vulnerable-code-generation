//FormAI DATASET v1.0 Category: File system simulation ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define MAX_FILES 10 // Maximum number of files that can be stored
#define MAX_FILE_SIZE 100 // Maximum size of each file
#define MAX_FILE_NAME 20 // Maximum length of file name

// Definition of the file structure
struct file {
    char name[MAX_FILE_NAME];
    char content[MAX_FILE_SIZE];
};

// Global variables
struct file files[MAX_FILES]; // Array to store the files
int num_files = 0; // Counter for number of files

// Function to create a new file
void create_file() {
    struct file new_file;
    printf("Enter file name: ");
    scanf("%s", new_file.name);
    // Check if file already exists
    for (int i = 0; i < num_files; i++) {
        if (strcmp(new_file.name, files[i].name) == 0) {
            printf("File already exists\n");
            return;
        }
    }
    printf("Enter file content: ");
    scanf("%s", new_file.content);
    if (num_files < MAX_FILES) {
        files[num_files] = new_file;
        num_files++;
        printf("File created successfully\n");
    } else {
        printf("Maximum number of files reached\n");
    }
}

// Function to list all files
void list_files() {
    if (num_files == 0) {
        printf("No files\n");
    } else {
        printf("Files:\n");
        for (int i = 0; i < num_files; i++) {
            printf("%s\n", files[i].name);
        }
    }
}

// Function to print the contents of a file
void print_file_contents() {
    char file_name[MAX_FILE_NAME];
    printf("Enter file name: ");
    scanf("%s", file_name);
    int found = 0;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_name, files[i].name) == 0) {
            printf("Content of %s: %s\n", file_name, files[i].content);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("File not found\n");
    }
}

// Function to delete a file
void delete_file() {
    char file_name[MAX_FILE_NAME];
    printf("Enter file name: ");
    scanf("%s", file_name);
    int found = 0;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_name, files[i].name) == 0) {
            // Shift all files after this file one position to the left
            for (int j = i + 1; j < num_files; j++) {
                files[j - 1] = files[j];
            }
            num_files--;
            found = 1;
            printf("File deleted successfully\n");
            break;
        }
    }
    if (!found) {
        printf("File not found\n");
    }
}

int main() {
    int choice;
    do {
        // Display menu
        printf("Menu:\n");
        printf("1. Create file\n");
        printf("2. List all files\n");
        printf("3. Print file contents\n");
        printf("4. Delete file\n");
        printf("0. Exit\n");
        // Get user choice
        printf("Enter choice: ");
        scanf("%d", &choice);
        // Perform action based on user choice
        switch (choice) {
            case 1:
                create_file();
                break;
            case 2:
                list_files();
                break;
            case 3:
                print_file_contents();
                break;
            case 4:
                delete_file();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}