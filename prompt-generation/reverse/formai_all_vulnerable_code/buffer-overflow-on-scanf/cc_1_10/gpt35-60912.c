//FormAI DATASET v1.0 Category: File system simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_FILES 100

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int size;
    bool used;
} file_metadata_t;

file_metadata_t files[MAX_FILES];
int num_files = 0;
int total_size_used = 0;

void create_file() {
    if (num_files == MAX_FILES) {
        printf("Sorry, there is no more space left for new files.\n");
        return;
    }

    printf("Please enter the name of the file: ");
    char filename[MAX_FILENAME_LENGTH];
    scanf("%s", filename);

    for (int i = 0; i < strlen(filename); i++) {
        if ((filename[i] >= 'A' && filename[i] <= 'Z') || 
            (filename[i] >= 'a' && filename[i] <= 'z') || 
            (filename[i] >= '0' && filename[i] <= '9') || 
            filename[i] == '.') {
            continue;
        } else {
            printf("Sorry, the filename can only contain letters, numbers, and periods.\n");
            return;
        }
    }

    int size;
    printf("Please enter the size of the file (in bytes): ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Sorry, the size of the file must be greater than zero.\n");
        return;
    }

    if (total_size_used + size > MAX_FILES * MAX_FILENAME_LENGTH) {
        printf("Sorry, there is not enough space left in the file system for this file.\n");
        return;
    }

    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            printf("Sorry, there is already a file with that name.\n");
            return;
        }
    }

    int index = -1;

    for (int i = 0; i < MAX_FILES; i++) {
        if (!files[i].used) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Sorry, there is no more space left for new files.\n");
        return;
    }

    strcpy(files[index].filename, filename);
    files[index].size = size;
    files[index].used = true;
    num_files++;
    total_size_used += size;

    printf("The file \"%s\" with size %d bytes has been created successfully.\n", filename, size);
}

void delete_file() {
    printf("Please enter the name of the file you want to delete: ");
    char filename[MAX_FILENAME_LENGTH];
    scanf("%s", filename);

    int index = -1;

    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Sorry, there is no file with that name.\n");
        return;
    }

    printf("Are you sure you want to delete the file \"%s\" with size %d bytes? (y/n) ", files[index].filename, files[index].size);
    char c;
    scanf(" %c", &c);

    if (c == 'y' || c == 'Y') {
        files[index].used = false;
        total_size_used -= files[index].size;
        printf("The file has been deleted successfully.\n");
    }
}

void show_files() {
    printf("The file system currently has the following files:\n");

    for (int i = 0; i < num_files; i++) {
        printf("\"%s\" with size %d bytes\n", files[i].filename, files[i].size);
    }

    printf("There are %d file(s) using %d bytes of space in total.\n", num_files, total_size_used);
}

void show_menu() {
    printf("Welcome to the C File System Simulation!\n");
    printf("1. Create a new file\n");
    printf("2. Delete a file\n");
    printf("3. Show all files\n");
    printf("4. Exit\n");
}

int main() {
    int choice = 0;

    while (true) {
        show_menu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_file();
                break;
            case 2:
                delete_file();
                break;
            case 3:
                show_files();
                break;
            case 4:
                printf("Thank you for using the C File System Simulation!\n");
                exit(0);
            default:
                printf("Sorry, that is not a valid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}