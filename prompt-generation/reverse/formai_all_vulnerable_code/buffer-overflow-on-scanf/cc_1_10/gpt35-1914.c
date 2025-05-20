//FormAI DATASET v1.0 Category: File system simulation ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000 // Maximum size of file system

// Structure to define each file
struct file {
    char name[50]; // Name of the file
    int size; // Size of the file
};

// Structure to define the file system
struct file_system {
    struct file files[MAX_SIZE]; // Array of files
    int count; // Number of files in the system
};

// Function to add a new file to the system
void add_file(struct file_system* fs, char* name, int size) {
    if (fs->count >= MAX_SIZE) {
        printf("Unable to add new file. File system is full.\n");
        return;
    }
    struct file new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    fs->files[fs->count++] = new_file;
    printf("File added successfully.\n");
}

// Function to delete a file from the system
void delete_file(struct file_system* fs, char* name) {
    int i;
    for (i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            int j;
            for (j = i; j < fs->count; j++) {
                fs->files[j] = fs->files[j+1]; // Shift all elements to the left
            }
            fs->count--; // Decrement count as one file is deleted
            printf("File deleted successfully.\n");
            return;
        }
    }
    printf("File not found.\n");
}

// Function to display all files in the system
void display_files(struct file_system* fs) {
    if (fs->count == 0) {
        printf("No files in the system.\n");
        return;
    }
    int i;
    printf("Name\tSize\n");
    for (i = 0; i < fs->count; i++) {
        printf("%s\t%d\n", fs->files[i].name, fs->files[i].size);
    }
}

int main() {
    struct file_system fs;
    fs.count = 0; // Initialize count to 0
    int choice;
    do {
        printf("1. Add new file\n");
        printf("2. Delete file\n");
        printf("3. Display all files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                {
                    char name[50];
                    int size;
                    printf("Enter file name: ");
                    scanf("%s", name);
                    printf("Enter file size: ");
                    scanf("%d", &size);
                    add_file(&fs, name, size);
                    break;
                }
            case 2:
                {
                    char name[50];
                    printf("Enter file name to delete: ");
                    scanf("%s", name);
                    delete_file(&fs, name);
                    break;
                }
            case 3:
                {
                    display_files(&fs);
                    break;
                }
            case 4:
                {
                    printf("Exiting.\n");
                    exit(0);
                }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}