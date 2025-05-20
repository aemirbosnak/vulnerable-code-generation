//FormAI DATASET v1.0 Category: File system simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constant definitions
#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_COUNT 10
#define MAX_FILE_SIZE 1024

// Struct definitions
typedef struct {
    char name[MAX_FILENAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size;
} File;

// Function prototypes
void list_files(File* files, int file_count);
int find_file_index(File* files, int file_count, char* filename);
void create_file(File* files, int* file_count, char* filename);
void read_file(File* files, int file_count, char* filename);
void write_file(File* files, int file_count, char* filename);
void delete_file(File* files, int* file_count, char* filename);

// Main function
int main() {
    File files[MAX_FILE_COUNT];
    int file_count = 0;
    int loop = 1;
    char input[20];
    char filename[MAX_FILENAME_LENGTH];

    printf("Welcome to the File System Simulation\n");

    while (loop) {
        printf("\nPlease enter a command (list/create/read/write/delete/exit): ");
        scanf("%s", input);

        if (strcmp(input, "list") == 0) {
            list_files(files, file_count);
        }
        else if (strcmp(input, "create") == 0) {
            printf("Please enter the filename: ");
            scanf("%s", filename);
            create_file(files, &file_count, filename);
        }
        else if (strcmp(input, "read") == 0) {
            printf("Please enter the filename: ");
            scanf("%s", filename);
            read_file(files, file_count, filename);
        }
        else if (strcmp(input, "write") == 0) {
            printf("Please enter the filename: ");
            scanf("%s", filename);
            write_file(files, file_count, filename);
        }
        else if (strcmp(input, "delete") == 0) {
            printf("Please enter the filename: ");
            scanf("%s", filename);
            delete_file(files, &file_count, filename);
        }
        else if (strcmp(input, "exit") == 0) {
            printf("Exiting the program...\n");
            loop = 0;
        }
        else {
            printf("Invalid input, please try again.\n");
        }

        // Clear input buffer
        while (getchar() != '\n');
    }

    return 0;
}

// Function to list all files in the file system
void list_files(File* files, int file_count) {
    if (file_count == 0) {
        printf("There are no files in the file system.\n");
    }
    else {
        printf("File system contents:\n");
        for (int i = 0; i < file_count; i++) {
            printf("- %s (%d bytes)\n", files[i].name, files[i].size);
        }
    }
}

// Function to find the index of a file in the file system
// Returns -1 if file not found
int find_file_index(File* files, int file_count, char* filename) {
    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, filename) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to create a new file in the file system
void create_file(File* files, int* file_count, char* filename) {
    // Check if file already exists
    if (find_file_index(files, *file_count, filename) != -1) {
        printf("File already exists.\n");
        return;
    }

    // Check if maximum file count reached
    if (*file_count == MAX_FILE_COUNT) {
        printf("Cannot create file, maximum file count reached.\n");
        return;
    }

    // Create new file
    File new_file;
    strcpy(new_file.name, filename);
    new_file.size = 0;
    files[*file_count] = new_file;
    *file_count += 1;
    printf("File successfully created.\n");
}

// Function to read the contents of a file
void read_file(File* files, int file_count, char* filename) {
    int file_index = find_file_index(files, file_count, filename);
    if (file_index == -1) {
        printf("File not found.\n");
        return;
    }
    printf("%s contains:\n%s\n", filename, files[file_index].data);
}

// Function to write to a file
void write_file(File* files, int file_count, char* filename) {
    int file_index = find_file_index(files, file_count, filename);
    if (file_index == -1) {
        printf("File not found.\n");
        return;
    }
    printf("Please enter the new contents of the file:\n");
    fgets(files[file_index].data, MAX_FILE_SIZE, stdin);
    files[file_index].size = strlen(files[file_index].data);
    printf("File successfully updated.\n");
}

// Function to delete a file from the file system
void delete_file(File* files, int* file_count, char* filename) {
    int file_index = find_file_index(files, *file_count, filename);
    if (file_index == -1) {
        printf("File not found.\n");
        return;
    }
    // Shift all files after the deleted file to fill the gap
    for (int i = file_index; i < *file_count - 1; i++) {
        files[i] = files[i + 1];
    }
    *file_count -= 1;
    printf("File successfully deleted.\n");
}