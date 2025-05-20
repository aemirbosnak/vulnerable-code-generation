//FormAI DATASET v1.0 Category: File system simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 20 // Maximum number of files

struct file {
    char* name;
    int size;
};

int numFiles = 0; // Counter for number of files created
struct file files[MAX_FILES]; // Array of files

// Function to create a new file
void createFile() {
    // Check if maximum number of files has been reached
    if (numFiles >= MAX_FILES) {
        printf("Error: Maximum number of files reached!\n");
        return;
    }

    // Allocate memory for new file's name
    char* name = (char*) malloc(20 * sizeof(char));
    printf("Enter name for new file: ");
    scanf("%s", name);

    // Check if file with the same name already exists
    for (int i = 0; i < numFiles; i++) {
        if (strcmp(name, files[i].name) == 0) {
            printf("Error: File with the same name already exists!\n");
            return;
        }
    }

    // Assign size to new file
    int size;
    printf("Enter size of new file: ");
    scanf("%d", &size);

    // Create new file and add to array
    files[numFiles].name = name;
    files[numFiles].size = size;
    numFiles++;
    printf("File created successfully!\n");
}

// Function to delete a file
void deleteFile() {
    // Check if any files exist
    if (numFiles == 0) {
        printf("Error: No files found!\n");
        return;
    }

    // Get name of file to delete
    char* name = (char*) malloc(20 * sizeof(char));
    printf("Enter name of file to delete: ");
    scanf("%s", name);

    // Find file in array and remove
    for (int i = 0; i < numFiles; i++) {
        if (strcmp(name, files[i].name) == 0) {
            // Shift all files after this one back by 1 index
            for (int j = i; j < numFiles - 1; j++) {
                files[j] = files[j + 1];
            }
            numFiles--;
            printf("File deleted successfully!\n");
            return;
        }
    }

    // File not found
    printf("Error: File not found!\n");
}

// Function to list all files and their sizes
void listFiles() {
    // Check if any files exist
    if (numFiles == 0) {
        printf("No files found!\n");
        return;
    }

    printf("List of files:\n");
    for (int i = 0; i < numFiles; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

int main() {
    int choice;

    // Main loop
    while (1) {
        printf("\n");
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. List files\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                deleteFile();
                break;
            case 3:
                listFiles();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}