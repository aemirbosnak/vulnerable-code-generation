//FormAI DATASET v1.0 Category: File system simulation ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

#define MAX_FILES 50        // Maximum number of files that can be stored
#define MAX_FILE_NAME 20    // Maximum length of file name
#define MAX_FILE_SIZE 1024  // Maximum size of file

typedef struct file {
    char name[MAX_FILE_NAME];
    int size;
    char *data;
} File;

int num_files = 0;

File files[MAX_FILES];

// Function to create a new file
void create_file() {
    File new_file;
    printf("Enter the file name:\n");
    scanf("%s", new_file.name);
    printf("Enter the file size:\n");
    scanf("%d", &new_file.size);
    if (num_files < MAX_FILES) {
        new_file.data = malloc(new_file.size);
        printf("Enter the file data:\n");
        scanf("%s", new_file.data);
        files[num_files++] = new_file;
        printf("File created successfully!\n");
    }
    else {
        printf("No space to create a new file!\n");
    }
}

// Function to delete an existing file
void delete_file() {
    char file_name[MAX_FILE_NAME];
    printf("Enter the file name to delete:\n");
    scanf("%s", file_name);
    for (int i=0; i<num_files; i++) {
        if (strcmp(files[i].name, file_name) == 0) {
            free(files[i].data);
            for (int j=i; j<num_files-1; j++) {
                files[j] = files[j+1];
            }
            num_files--;
            printf("File deleted successfully!\n");
            return;
        }
    }
    printf("File not found!\n");
}

// Function to display all the files in the file system
void display_files() {
    printf("Total files: %d\n", num_files);
    for (int i=0; i<num_files; i++) {
        printf("File name: %s\n", files[i].name);
        printf("File size: %d\n", files[i].size);
    }
}

int main() {
    int choice;
    do {
        printf("\nFile System Simulation:\n");
        printf("1. Create a new file\n");
        printf("2. Delete an existing file\n");
        printf("3. Display all files\n");
        printf("4. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
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
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again...\n");
                break;
        }
    } while (choice != 4);
    return 0;
}