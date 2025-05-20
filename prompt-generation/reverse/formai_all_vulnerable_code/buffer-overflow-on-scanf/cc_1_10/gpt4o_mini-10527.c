//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LEN 50
#define MAX_CONTENT_LEN 1024

typedef struct {
    char name[MAX_FILENAME_LEN];
    char content[MAX_CONTENT_LEN];
    int is_open;
} File;

typedef struct {
    File files[MAX_FILES];
    int file_count;
} FileSystem;

FileSystem fs;

void initialize_file_system() {
    fs.file_count = 0;
}

int create_file(const char *name) {
    if (fs.file_count >= MAX_FILES) {
        printf("File system is full!\n");
        return -1;
    }

    for (int i = 0; i < fs.file_count; i++) {
        if (strcmp(fs.files[i].name, name) == 0) {
            printf("File already exists!\n");
            return -1;
        }
    }

    File new_file;
    strncpy(new_file.name, name, MAX_FILENAME_LEN);
    new_file.content[0] = '\0'; // Initialize content to empty
    new_file.is_open = 0;

    fs.files[fs.file_count++] = new_file;
    printf("File '%s' created successfully.\n", name);
    return 0;
}

int open_file(const char *name) {
    for (int i = 0; i < fs.file_count; i++) {
        if (strcmp(fs.files[i].name, name) == 0) {
            if (fs.files[i].is_open) {
                printf("File '%s' is already open.\n", name);
                return -1;
            }

            fs.files[i].is_open = 1;
            printf("File '%s' opened successfully.\n", name);
            return i; // Return file index
        }
    }

    printf("File '%s' not found!\n", name);
    return -1;
}

int close_file(int index) {
    if (index < 0 || index >= fs.file_count) {
        printf("Invalid file index!\n");
        return -1;
    }

    fs.files[index].is_open = 0;
    printf("File '%s' closed successfully.\n", fs.files[index].name);
    return 0;
}

int write_to_file(int index, const char *content) {
    if (index < 0 || index >= fs.file_count || !fs.files[index].is_open) {
        printf("File is not open or invalid index!\n");
        return -1;
    }

    strncat(fs.files[index].content, content, MAX_CONTENT_LEN - strlen(fs.files[index].content) - 1);
    printf("Written to file '%s': %s\n", fs.files[index].name, content);
    return 0;
}

void read_file(int index) {
    if (index < 0 || index >= fs.file_count) {
        printf("Invalid file index!\n");
        return;
    }

    if (fs.files[index].is_open) {
        printf("Reading from file '%s':\n%s\n", fs.files[index].name, fs.files[index].content);
    } else {
        printf("File '%s' is not open!\n", fs.files[index].name);
    }
}

void list_files() {
    if (fs.file_count == 0) {
        printf("No files in the system.\n");
        return;
    }

    printf("Files in the system:\n");
    for (int i = 0; i < fs.file_count; i++) {
        printf("- %s (status: %s)\n", fs.files[i].name, fs.files[i].is_open ? "OPEN" : "CLOSED");
    }
}

int main() {
    initialize_file_system();
    int option, index;

    do {
        printf("\nFile System Menu:\n");
        printf("1. Create file\n");
        printf("2. Open file\n");
        printf("3. Write to file\n");
        printf("4. Read from file\n");
        printf("5. Close file\n");
        printf("6. List files\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        char filename[MAX_FILENAME_LEN];
        char content[MAX_CONTENT_LEN];

        switch (option) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", filename);
                create_file(filename);
                break;
            case 2:
                printf("Enter file name to open: ");
                scanf("%s", filename);
                index = open_file(filename);
                break;
            case 3:
                if (index != -1) {
                    printf("Enter content to write: ");
                    scanf(" %[^\n]s", content);
                    write_to_file(index, content);
                } else {
                    printf("No file is currently open.\n");
                }
                break;
            case 4:
                if (index != -1) {
                    read_file(index);
                } else {
                    printf("No file is currently open.\n");
                }
                break;
            case 5:
                if (index != -1) {
                    close_file(index);
                    index = -1; // Reset the index after closing
                } else {
                    printf("No file is currently open.\n");
                }
                break;
            case 6:
                list_files();
                break;
            case 0:
                printf("Exiting system...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 0);

    return 0;
}