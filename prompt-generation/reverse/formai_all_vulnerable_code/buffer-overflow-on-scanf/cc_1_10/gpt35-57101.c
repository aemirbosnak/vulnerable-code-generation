//FormAI DATASET v1.0 Category: File system simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 20
#define MAX_FILE_SIZE 10000
#define MAX_FILE_COUNT 50

typedef struct file {
    char file_name[MAX_FILE_NAME_SIZE];
    char file_contents[MAX_FILE_SIZE];
    int file_size;
    int is_deleted;
} File;

int total_files = 0;
File file_system[MAX_FILE_COUNT];

void add_file() {
    char file_name[MAX_FILE_NAME_SIZE];
    char file_contents[MAX_FILE_SIZE];
    int file_size;

    // Take user input for file name and contents
    printf("Enter file name (Max length %d characters): ", MAX_FILE_NAME_SIZE);
    scanf("%s", file_name);

    // Check if file with same name already exists
    for(int i = 0; i < total_files; i++) {
        if(strcmp(file_system[i].file_name, file_name) == 0) {
            printf("Error: File with same name already exists. Please choose another name.\n\n");
            return;
        }
    }

    printf("Enter file contents: ");
    scanf("%s", file_contents);
    file_size = strlen(file_contents);

    // Check if file size is within limit
    if(file_size > MAX_FILE_SIZE) {
        printf("Error: File size exceeds maximum limit. Please reduce file size.\n\n");
        return;
    }

    // Add new file to file system
    File new_file;
    strcpy(new_file.file_name, file_name);
    strcpy(new_file.file_contents, file_contents);
    new_file.file_size = file_size;
    new_file.is_deleted = 0;
    file_system[total_files] = new_file;
    total_files++;

    printf("\nFile added successfully.\n\n");

}

void delete_file() {
    char file_name[MAX_FILE_NAME_SIZE];
    int file_deleted = 0;

    // Take user input for file name
    printf("Enter file name to delete: ");
    scanf("%s", file_name);

    for(int i = 0; i < total_files; i++) {
        if(strcmp(file_system[i].file_name, file_name) == 0) {
            // Mark file as deleted
            file_system[i].is_deleted = 1;
            file_deleted = 1;
            printf("\nFile deleted successfully.\n\n");
        }
    }

    if(!file_deleted) {
        printf("Error: File not found.\n\n");
    }
}

void display_files() {
    int file_count = 0;

    printf("\nFile system contents:\n\n");

    for(int i = 0; i < total_files; i++) {
        if(!file_system[i].is_deleted) {
            printf("%s\n", file_system[i].file_name);
            file_count++;
        }
    }

    if(file_count == 0) {
        printf("File system is empty.\n");
    }

    printf("\n");
}

int main() {
    int choice;

    printf("Welcome to paranoid file system simulation!\n");

    while(1) {
        printf("Enter operation:\n");
        printf("1. Add file\n");
        printf("2. Delete file\n");
        printf("3. Display files\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_file();
                break;
            case 2:
                delete_file();
                break;
            case 3:
                display_files();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }
}