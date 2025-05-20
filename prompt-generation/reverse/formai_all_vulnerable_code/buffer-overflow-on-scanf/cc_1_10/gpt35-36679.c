//FormAI DATASET v1.0 Category: File system simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 32
#define MAX_FILES 100

struct file {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char data[1000];
};

struct file_system {
    struct file files[MAX_FILES];
    int num_files;
    int used_space;
};

void display_files(struct file_system fs) {
    printf("Total Files: %d\n", fs.num_files);
    for (int i = 0; i < fs.num_files; i++) {
        printf("%s\t\t%d bytes\n", fs.files[i].name, fs.files[i].size);
    }
    printf("Used space: %d bytes\n", fs.used_space);
}

void add_file(struct file_system *fs, char *name, int size, char *data) {
    if (fs->num_files == MAX_FILES) {
        printf("File system is full, unable to add file.\n");
        return;
    }
    if (fs->used_space + size > 1000000) {
        printf("File system is out of space, unable to add file.\n");
        return;
    }
    struct file new_file = {.size = size};
    strncpy(new_file.name, name, MAX_FILE_NAME_LENGTH);
    strncpy(new_file.data, data, 1000);
    fs->files[fs->num_files] = new_file;
    fs->num_files++;
    fs->used_space += size;
    printf("File added successfully.\n");
}

void delete_file(struct file_system *fs, char *name) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            fs->used_space -= fs->files[i].size;
            for (int j = i; j < fs->num_files-1; j++) {
                fs->files[j] = fs->files[j+1];
            }
            fs->num_files--;
            printf("File deleted successfully.\n");
            return;
        }
    }
    printf("File not found.\n");
}

int main() {
    struct file_system fs = {.num_files = 0, .used_space = 0};
    int choice;
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char data[1000];

    printf("Welcome to the Cyberpunk File System Simulator.\n");
    printf("Created by: [Your Name]\n");
    do {
        printf("\nMenu:\n");
        printf("1. Display Files\n");
        printf("2. Add File\n");
        printf("3. Delete File\n");
        printf("4. Quit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                display_files(fs);
                break;
            case 2:
                printf("Enter file name (max %d characters): ", MAX_FILE_NAME_LENGTH-1);
                scanf("%s", name);
                printf("Enter file size (in bytes): ");
                scanf("%d", &size);
                printf("Enter file data (max 1000 characters): ");
                scanf("%s", data);
                add_file(&fs, name, size, data);
                break;
            case 3:
                printf("Enter file name to delete: ");
                scanf("%s", name);
                delete_file(&fs, name);
                break;
            case 4:
                printf("Thanks for using Cyberpunk File System Simulator!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}