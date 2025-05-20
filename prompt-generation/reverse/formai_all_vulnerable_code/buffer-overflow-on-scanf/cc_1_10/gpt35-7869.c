//FormAI DATASET v1.0 Category: File system simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of global variables and functions
#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 20

int current_size = 0;
int file_count = 0;
char root[MAX_FILENAME_LENGTH];
char files[MAX_FILES][MAX_FILENAME_LENGTH];

int createFileSystem();
int addFile(char fname[]);
int deleteFile(char fname[]);
void displayFileSystem();

// Main function
int main() {
    printf("Welcome to our peaceful C File System Simulation!\n");

    printf("Enter the name for root folder: ");
    scanf("%s", root);

    while(1) {
        int choice;
        printf("\nChoose from the following options:\n");
        printf("1. Create file system\n");
        printf("2. Add a file\n");
        printf("3. Delete a file\n");
        printf("4. Display file system\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createFileSystem();
                break;
            case 2:
                {
                    char fname[MAX_FILENAME_LENGTH];
                    printf("Enter the name of the file you want to add: ");
                    scanf("%s", fname);
                    addFile(fname);
                    break;
                }
            case 3:
                {
                    char fname[MAX_FILENAME_LENGTH];
                    printf("Enter the name of the file you want to delete: ");
                    scanf("%s", fname);
                    deleteFile(fname);
                    break;
                }
            case 4:
                displayFileSystem();
                break;
            case 5:
                printf("Thank you for using our peaceful C File System Simulation!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to create the file system and initialize the root node
int createFileSystem() {
    current_size = 0;
    file_count = 0;

    strcpy(files[file_count++], root);
    current_size += (strlen(root) + 1);

    printf("File system created successfully!\n");

    return 0;
}

// Function to add a file to the file system
int addFile(char fname[]) {
    if(current_size + strlen(fname) + 1 > MAX_FILES * MAX_FILENAME_LENGTH) {
        printf("Error: Not enough space to add file!\n");
        return -1;
    }

    int i;
    for(i = 0; i < file_count; i++) {
        if(strcmp(files[i], fname) == 0) {
            printf("Error: File with same name already exists!\n");
            return -1;
        }
    }

    strcpy(files[file_count++], fname);
    current_size += (strlen(fname) + 1);

    printf("File added successfully!\n");

    return 0;
}

// Function to delete a file from the file system
int deleteFile(char fname[]) {
    int i;

    for(i = 0; i < file_count; i++) {
        if(strcmp(files[i], fname) == 0) {
            break;
        }
    }

    if(i == file_count) {
        printf("Error: No such file exists in the file system!\n");
        return -1;
    }

    int j;
    for(j = i; j < file_count - 1; j++) {
        strcpy(files[j], files[j+1]);
    }

    file_count--;
    current_size -= (strlen(fname) + 1);

    printf("File deleted successfully!\n");

    return 0;
}

// Function to display the current file system state
void displayFileSystem() {
    printf("Current File System State:\n");

    printf("Root folder: %s\n", root);

    int i;
    for(i = 0; i < file_count; i++) {
        printf("File %d: %s\n", i+1, files[i]);
    }

    printf("Total space used: %d bytes\n", current_size);

    return;
}