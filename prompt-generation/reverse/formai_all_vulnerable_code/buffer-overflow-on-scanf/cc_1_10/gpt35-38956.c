//FormAI DATASET v1.0 Category: File system simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_COUNT 100

// Define our file struct, which consists of a name, size, and data
typedef struct file {
    char name[MAX_FILENAME_LENGTH];
    int size;
    char *data;
} File;

// Define our file system struct, which keeps track of all files
typedef struct file_system {
    int num_files;
    File files[MAX_FILE_COUNT];
} FileSystem;

// Define the function to create a new file
void create_file(FileSystem *fs) {
    // Check if we have hit the maximum file count already
    if (fs->num_files >= MAX_FILE_COUNT) {
        printf("Error: Maximum file count exceeded.\n");
        return;
    }

    // Prompt the user for the filename and check its length
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the file name: ");
    scanf("%s", filename);
    if (strlen(filename) > MAX_FILENAME_LENGTH) {
        printf("Error: File name too long.\n");
        return;
    }

    // Check if a file with that name already exists
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            printf("Error: File already exists.\n");
            return;
        }
    }

    // Prompt the user for the file size
    int size;
    printf("Enter the file size: ");
    scanf("%d", &size);

    // Allocate memory for the file data
    char *data = malloc(size);
    if (data == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    // Prompt the user for the file data
    printf("Enter the file data: ");
    scanf("%s", data);

    // Create the new file and add it to the file system
    File new_file = {0};
    strncpy(new_file.name, filename, MAX_FILENAME_LENGTH);
    new_file.size = size;
    new_file.data = data;
    fs->files[fs->num_files++] = new_file;

    printf("File created successfully.\n");
}

// Define the function to read a file from the file system
void read_file(FileSystem *fs) {
    // Prompt the user for the file name
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the file name: ");
    scanf("%s", filename);

    // Find the file with the matching name
    int match = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            match = i;
            break;
        }
    }

    // Check if the file was found
    if (match == -1) {
        printf("Error: File not found.\n");
        return;
    }

    // Print out the file data
    printf("File data: %s\n", fs->files[match].data);
}

// Define the function to delete a file from the file system
void delete_file(FileSystem *fs) {
    // Prompt the user for the file name
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the file name: ");
    scanf("%s", filename);

    // Find the file with the matching name
    int match = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            match = i;
            break;
        }
    }

    // Check if the file was found
    if (match == -1) {
        printf("Error: File not found.\n");
        return;
    }

    // Free the file data and remove it from the file system
    free(fs->files[match].data);
    for (int i = match; i < (fs->num_files - 1); i++) {
        fs->files[i] = fs->files[i + 1];
    }
    fs->num_files--;

    printf("File deleted successfully.\n");
}

// Define the main program, which allows the user to interact with the file system
int main() {
    FileSystem fs = {0};

    while (true) {
        printf("\n");
        printf("Select an option:\n");
        printf("1. Create a new file\n");
        printf("2. Read a file\n");
        printf("3. Delete a file\n");
        printf("4. Exit\n");

        // Prompt the user for their choice
        int choice;
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                create_file(&fs);
                break;
            case 2:
                read_file(&fs);
                break;
            case 3:
                delete_file(&fs);
                break;
            case 4:
                return 0;
            default:
                printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}