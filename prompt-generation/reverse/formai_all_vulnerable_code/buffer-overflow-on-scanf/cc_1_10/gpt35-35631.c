//FormAI DATASET v1.0 Category: File Backup System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_NUM_FILES 1000

typedef struct file {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
} File;

File files[MAX_NUM_FILES];
int num_files = 0;

void add_file(char* file_name, int file_size) {
    if (num_files == MAX_NUM_FILES) {
        printf("Error: Maximum number of files exceeded");
        return;
    }
    strcpy(files[num_files].file_name, file_name);
    files[num_files].file_size = file_size;
    num_files++;
}

void delete_file(char* file_name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].file_name, file_name) == 0) {
            for (int j = i; j < num_files - 1; j++) {
                strcpy(files[j].file_name, files[j + 1].file_name);
                files[j].file_size = files[j + 1].file_size;
            }
            num_files--;
            return;
        }
    }
    printf("Error: File not found");
}

void list_files() {
    if (num_files == 0) {
        printf("No files found");
        return;
    }
    printf("Files:\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s\t%d bytes\n", files[i].file_name, files[i].file_size);
    }
}

void backup_files() {
    FILE* fp;
    fp = fopen("backup.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not open backup file");
        return;
    }
    for (int i = 0; i < num_files; i++) {
        fprintf(fp, "%s %d\n", files[i].file_name, files[i].file_size);
    }
    fclose(fp);
    printf("Files backed up successfully");
}

void restore_files() {
    FILE* fp;
    fp = fopen("backup.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open backup file");
        return;
    }
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    num_files = 0;
    while (fscanf(fp, "%s %d", file_name, &file_size) != EOF) {
        add_file(file_name, file_size);
    }
    fclose(fp);
    printf("Files restored successfully");
}

int main() {
    int option;
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    while (1) {
        printf("\n1. Add file\n2. Delete file\n3. List files\n4. Backup files\n5. Restore files\n6. Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", file_name);
                printf("Enter file size in bytes: ");
                scanf("%d", &file_size);
                add_file(file_name, file_size);
                break;
            case 2:
                printf("Enter file name to delete: ");
                scanf("%s", file_name);
                delete_file(file_name);
                break;
            case 3:
                list_files();
                break;
            case 4:
                backup_files();
                break;
            case 5:
                restore_files();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option");
        }
    }
    return 0;
}