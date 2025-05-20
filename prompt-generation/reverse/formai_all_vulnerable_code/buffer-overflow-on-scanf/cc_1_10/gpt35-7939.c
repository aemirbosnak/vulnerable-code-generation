//FormAI DATASET v1.0 Category: File system simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#define MAX_FILES 10

// Struct for the file system
struct file_system {
    char* file_names[MAX_FILES];
    int file_sizes[MAX_FILES];
    int num_files;
};

// Function to create a new file in the file system
void create_file(struct file_system* fs, char* file_name, int file_size) {
    // Check if the file already exists
    for(int i = 0; i < fs->num_files; i++) {
        if(fs->file_names[i] == file_name) {
            printf("File with name '%s' already exists.\n", file_name);
            return;
        }
    }
    // Check if the file system has enough space
    if(fs->num_files == MAX_FILES) {
        printf("Cannot create file. Maximum file limit reached.\n");
        return;
    }
    // Add the file to the file system
    fs->file_names[fs->num_files] = file_name;
    fs->file_sizes[fs->num_files] = file_size;
    fs->num_files++;
    printf("File '%s' with size %d created successfully.\n", file_name, file_size);
}

// Function to delete a file from the file system
void delete_file(struct file_system* fs, char* file_name) {
    int file_index = -1;
    // Find the index of the file to delete
    for(int i = 0; i < fs->num_files; i++) {
        if(fs->file_names[i] == file_name) {
            file_index = i;
            break;
        }
    }
    if(file_index == -1) {
        printf("File with name '%s' not found.\n", file_name);
        return;
    }
    // Shift the file names and sizes to overwrite the deleted file
    for(int i = file_index; i < fs->num_files-1; i++) {
        fs->file_names[i] = fs->file_names[i+1];
        fs->file_sizes[i] = fs->file_sizes[i+1];
    }
    fs->file_names[fs->num_files-1] = NULL;
    fs->file_sizes[fs->num_files-1] = 0;
    fs->num_files--;
    printf("File '%s' deleted successfully.\n", file_name);
}

// Function to display the current state of the file system
void display_file_system(struct file_system* fs) {
    printf("Current state of file system:\n");
    for(int i = 0; i < fs->num_files; i++) {
        printf("File name: %s, File size: %d\n", fs->file_names[i], fs->file_sizes[i]);
    }
}

int main() {
    struct file_system fs;
    fs.num_files = 0;
    int choice, file_size;
    char file_name[20];
    while(1) {
        printf("File System Menu:\n");
        printf("1. Create a new file\n");
        printf("2. Delete a file\n");
        printf("3. Display current file system\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", file_name);
                printf("Enter file size: ");
                scanf("%d", &file_size);
                create_file(&fs, file_name, file_size);
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%s", file_name);
                delete_file(&fs, file_name);
                break;
            case 3:
                display_file_system(&fs);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}