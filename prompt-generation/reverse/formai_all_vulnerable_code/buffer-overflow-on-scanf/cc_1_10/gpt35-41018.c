//FormAI DATASET v1.0 Category: File system simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max file size
#define MAX_FILE_SIZE 1024

// Max file name length
#define MAX_FILE_NAME_LENGTH 50

// Max number of files
#define MAX_NUM_FILES 10

// Struct for a file
struct file {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_SIZE];
};

// Safe implementation of fgets to prevent buffer overflow
char *safe_fgets(char *buf, int bufsize, FILE *stream) {
    if (fgets(buf, bufsize, stream) != NULL) {
        buf[strcspn(buf, "\n")] = '\0'; // Remove trailing newline character
        return buf;
    }
    return NULL;
}

// Function to create a new file 
void create_file(struct file files[], int *num_files) {
    if (*num_files == MAX_NUM_FILES) {
        printf("Error: Maximum number of files reached\n");
        return;
    }

    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter file name: ");
    safe_fgets(file_name, MAX_FILE_NAME_LENGTH, stdin);

    // Check if file name already exists
    for (int i = 0; i < *num_files; i++) {
        if (strcmp(files[i].name, file_name) == 0) {
            printf("Error: File already exists\n");
            return;
        }
    }

    struct file new_file;
    strcpy(new_file.name, file_name);

    printf("Enter file content: ");
    safe_fgets(new_file.content, MAX_FILE_SIZE, stdin);

    files[*num_files] = new_file;
    (*num_files)++;
    printf("File created successfully\n");
}

// Function to delete a file 
void delete_file(struct file files[], int *num_files) {
    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter file name: ");
    safe_fgets(file_name, MAX_FILE_NAME_LENGTH, stdin);

    // Find file index
    int file_index = -1;
    for (int i = 0; i < *num_files; i++) {
        if (strcmp(files[i].name, file_name) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        printf("Error: File not found\n");
        return;
    }

    // Delete file
    for (int i = file_index + 1; i < *num_files; i++) {
        files[i - 1] = files[i];
    }
    (*num_files)--;
    printf("File deleted successfully\n");
}

// Function to list all files 
void list_files(struct file files[], int *num_files) {
    if (*num_files == 0) {
        printf("No files found\n");
        return;
    }

    printf("Files:\n");
    for (int i = 0; i < *num_files; i++) {
        printf("%s\n", files[i].name);
    }
}

int main() {
    struct file files[MAX_NUM_FILES];
    int num_files = 0;

    // Main menu loop
    while (1) {
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. List files\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // Remove trailing newline character

        switch (choice) {
            case 1:
                create_file(files, &num_files);
                break;
            case 2:
                delete_file(files, &num_files);
                break;
            case 3:
                list_files(files, &num_files);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}