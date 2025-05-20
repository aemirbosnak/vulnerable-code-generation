//FormAI DATASET v1.0 Category: File system simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_FILES 10
#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_SIZE 100

// Define file struct
typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size; // Size in bytes
} file_t;

// Define function prototypes
void create_file(file_t* files, int* num_files);
void delete_file(file_t* files, int* num_files);
void list_files(file_t* files, int num_files);
void read_file(file_t* files, int num_files);
void write_file(file_t* files, int num_files);

int main() {
    file_t files[MAX_FILES];
    int num_files = 0;
    int option;

    while (1) {
        printf("\nOptions:\n");
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. List files\n");
        printf("4. Read file\n");
        printf("5. Write file\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                create_file(files, &num_files);
                break;
            case 2:
                delete_file(files, &num_files);
                break;
            case 3:
                list_files(files, num_files);
                break;
            case 4:
                read_file(files, num_files);
                break;
            case 5:
                write_file(files, num_files);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }

    return 0;
}

void create_file(file_t* files, int* num_files) {
    if (*num_files == MAX_FILES) {
        printf("Maximum number of files reached. Unable to create file.\n");
        return;
    }

    file_t new_file;
    printf("Enter file name (up to %d characters): ", MAX_FILENAME_LENGTH - 1);
    scanf("%s", new_file.filename);

    // Check if file already exists
    for (int i = 0; i < *num_files; i++) {
        if (strcmp(files[i].filename, new_file.filename) == 0) {
            printf("File already exists. Please choose a different name.\n");
            return;
        }
    }

    // Initialize new file size to 0
    new_file.size = 0;

    // Add new file to files array
    files[*num_files] = new_file;
    (*num_files)++;

    printf("File created successfully.\n");
}

void delete_file(file_t* files, int* num_files) {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter file name to delete: ");
    scanf("%s", filename);

    int file_index = -1;

    // Find index of file to delete
    for (int i = 0; i < *num_files; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        printf("File not found. Unable to delete.\n");
        return;
    }

    // Shift all files after deleted file over by one position
    for (int i = file_index; i < *num_files - 1; i++) {
        files[i] = files[i + 1];
    }

    (*num_files)--;

    printf("File deleted successfully.\n");
}

void list_files(file_t* files, int num_files) {
    if (num_files == 0) {
        printf("No files to display.\n");
        return;
    }

    printf("Files:\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s\t%d bytes\n", files[i].filename, files[i].size);
    }
}

void read_file(file_t* files, int num_files) {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter file name to read: ");
    scanf("%s", filename);

    int file_index = -1;

    // Find index of file to read
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        printf("File not found. Unable to read.\n");
        return;
    }

    printf("File contents:\n");
    printf("%s\n", files[file_index].data);
}

void write_file(file_t* files, int num_files) {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter file name to write: ");
    scanf("%s", filename);

    int file_index = -1;

    // Find index of file to write
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        printf("File not found. Unable to write.\n");
        return;
    }

    printf("Enter text to write to file (up to %d characters): ", MAX_FILE_SIZE - 1);
    scanf("%s", files[file_index].data);
    files[file_index].size = strlen(files[file_index].data);
}