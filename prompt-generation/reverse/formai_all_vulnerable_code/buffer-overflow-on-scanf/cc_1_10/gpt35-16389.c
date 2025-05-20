//FormAI DATASET v1.0 Category: File system simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 // Maximum file size
#define MAX_FILE_COUNT 10 // Maximum number of files
#define MAX_FILENAME_SIZE 20 // Maximum size of file name

// Structure to represent file data
struct file {
    char name[MAX_FILENAME_SIZE];
    char contents[MAX_FILE_SIZE];
    int size;
};

// Initialize file data
struct file file_system[MAX_FILE_COUNT] = {
    { "file1.txt", "Hello, World!", 13 },
    { "file2.txt", "This is a file.", 17 }
};

int file_count = 2; // Current number of files in the file system

// Function to read file data
void read_file(char *filename) {
    int i;
    for (i = 0; i < file_count; i++) {
        if (strcmp(file_system[i].name, filename) == 0) {
            printf("File Contents:\n");
            printf("%s\n", file_system[i].contents);
            return;
        }
    }
    printf("File not found.\n");
}

// Function to write file data
void write_file(char *filename, char *data) {
    int i;
    for (i = 0; i < file_count; i++) {
        if (strcmp(file_system[i].name, filename) == 0) {
            strncpy(file_system[i].contents, data, MAX_FILE_SIZE);
            file_system[i].contents[MAX_FILE_SIZE - 1] = '\0';
            file_system[i].size = strlen(file_system[i].contents);
            printf("File updated.\n");
            return;
        }
    }
    if (file_count < MAX_FILE_COUNT) {
        struct file new_file;
        strncpy(new_file.name, filename, MAX_FILENAME_SIZE);
        new_file.name[MAX_FILENAME_SIZE - 1] = '\0';
        strncpy(new_file.contents, data, MAX_FILE_SIZE);
        new_file.contents[MAX_FILE_SIZE - 1] = '\0';
        new_file.size = strlen(new_file.contents);
        file_system[file_count] = new_file;
        file_count++;
        printf("File created.\n");
    } else {
        printf("File system is full.\n");
    }
}

// Function to delete file data
void delete_file(char *filename) {
    int i;
    for (i = 0; i < file_count; i++) {
        if (strcmp(file_system[i].name, filename) == 0) {
            int j;
            for (j = i; j < file_count - 1; j++) {
                file_system[j] = file_system[j+1];
            }
            file_count--;
            printf("File deleted.\n");
            return;
        }
    }
    printf("File not found.\n");
}

// Main program loop
int main() {
    char command[10], filename[MAX_FILENAME_SIZE], data[MAX_FILE_SIZE];
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);
        if (strcmp(command, "read") == 0) {
            printf("Enter file name: ");
            scanf("%s", filename);
            read_file(filename);
        } else if (strcmp(command, "write") == 0) {
            printf("Enter file name: ");
            scanf("%s", filename);
            printf("Enter file contents: ");
            scanf(" %[^\n]", data);
            write_file(filename, data);
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter file name: ");
            scanf("%s", filename);
            delete_file(filename);
        } else if (strcmp(command, "exit") == 0) {
            return 0;
        } else {
            printf("Invalid command.\n");
        }
    }
}