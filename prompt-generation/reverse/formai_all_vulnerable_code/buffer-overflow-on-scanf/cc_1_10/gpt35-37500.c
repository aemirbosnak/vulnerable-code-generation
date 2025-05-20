//FormAI DATASET v1.0 Category: File Backup System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100
#define MAX_FILES 100

struct FileInfo {
    char name[MAX_FILENAME_LEN];
    long size;
};

struct Backup {
    struct FileInfo files[MAX_FILES];
    int count;
};

void print_menu() {
    printf("1. Add file to backup\n");
    printf("2. Remove file from backup\n");
    printf("3. Display backup status\n");
    printf("4. Perform backup\n");
    printf("5. Exit\n");
}

void add_file(struct Backup *backup, char *filename) {
    if (backup->count >= MAX_FILES) {
        printf("Backup is full, cannot add more files\n");
        return;
    }
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("File not found: %s\n", filename);
        return;
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    strcpy(backup->files[backup->count].name, filename);
    backup->files[backup->count].size = size;
    backup->count++;
    printf("Added %s to backup\n", filename);
    fclose(file);
}

void remove_file(struct Backup *backup, char *filename) {
    int index = -1;
    for (int i = 0; i < backup->count; i++) {
        if (strcmp(backup->files[i].name, filename) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("File not found in backup: %s\n", filename);
        return;
    }
    for (int i = index; i < backup->count - 1; i++) {
        backup->files[i] = backup->files[i + 1];
    }
    backup->count--;
    printf("Removed %s from backup\n", filename);
}

void display_status(struct Backup *backup) {
    printf("Backup status:\n");
    for (int i = 0; i < backup->count; i++) {
        printf("%s (%ld bytes)\n", backup->files[i].name, backup->files[i].size);
    }
}

void perform_backup(struct Backup *backup) {
    printf("Performing backup...\n");
    long total_size = 0;
    for (int i = 0; i < backup->count; i++) {
        total_size += backup->files[i].size;
    }
    printf("Total size of backup: %ld bytes\n", total_size);
}

int main() {
    struct Backup backup = {0};
    int choice;
    char filename[MAX_FILENAME_LEN];
    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter filename to add: ");
                scanf("%s", filename);
                add_file(&backup, filename);
                break;
            case 2:
                printf("Enter filename to remove: ");
                scanf("%s", filename);
                remove_file(&backup, filename);
                break;
            case 3:
                display_status(&backup);
                break;
            case 4:
                perform_backup(&backup);
                break;
            case 5:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }
    return 0;
}