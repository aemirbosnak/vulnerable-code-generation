//FormAI DATASET v1.0 Category: File Backup System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char last_modified[20];
    int size;
} file_info_t;

typedef struct {
    int num_files;
    file_info_t *files;
} backup_t;

void print_menu() {
    printf("1. Add a file\n");
    printf("2. Delete a file\n");
    printf("3. Display backup information\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void add_file(backup_t *backup) {
    char filename[MAX_FILENAME_LENGTH];
    char date_modified[20];
    int size;
    printf("Enter file name: ");
    scanf("%s", filename);
    printf("Enter date modified (dd/mm/yyyy): ");
    scanf("%s", date_modified);
    printf("Enter file size: ");
    scanf("%d", &size);
    backup->num_files++;
    backup->files = (file_info_t *)realloc(backup->files, backup->num_files * sizeof(file_info_t));
    strcpy(backup->files[backup->num_files - 1].filename, filename);
    strcpy(backup->files[backup->num_files - 1].last_modified, date_modified);
    backup->files[backup->num_files - 1].size = size;
    printf("File added successfully!\n");
}

void delete_file(backup_t *backup) {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", filename);
    int i;
    for (i = 0; i < backup->num_files; i++) {
        if (strcmp(filename, backup->files[i].filename) == 0) {
            int j;
            for (j = i; j < backup->num_files - 1; j++) {
                backup->files[j] = backup->files[j + 1];
            }
            backup->num_files--;
            backup->files = (file_info_t *)realloc(backup->files, backup->num_files * sizeof(file_info_t));
            printf("File deleted successfully!\n");
            return;
        }
    }
    printf("File not found in backup.\n");
}

void display_backup_info(backup_t *backup) {
    printf("Backup contains %d files:\n", backup->num_files);
    int i;
    for (i = 0; i < backup->num_files; i++) {
        printf("Filename: %s, Last modified: %s, Size: %d\n", backup->files[i].filename, backup->files[i].last_modified, backup->files[i].size);
    }
}

int main() {
    backup_t backup;
    backup.num_files = 0;
    backup.files = NULL;
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_file(&backup);
                break;
            case 2:
                delete_file(&backup);
                break;
            case 3:
                display_backup_info(&backup);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    free(backup.files);
    return 0;
}