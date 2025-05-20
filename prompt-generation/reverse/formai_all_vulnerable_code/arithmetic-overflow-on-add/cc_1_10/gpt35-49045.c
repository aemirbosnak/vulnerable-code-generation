//FormAI DATASET v1.0 Category: File Backup System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BACKUP_FILES 10

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    time_t last_modified;
} File;

File backup_files[MAX_BACKUP_FILES];
int num_backup_files = 0;

void backup_file(char* filename) {
    // Check if backup_files array is full
    if (num_backup_files == MAX_BACKUP_FILES) {
        printf("Error: Too many backup files. Delete some old backups before creating new ones.\n");
        return;
    }
    // Create backup file name with timestamp
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char backup_filename[MAX_FILENAME_LENGTH];
    sprintf(backup_filename, "%s_backup_%d-%02d-%02d_%02d-%02d-%02d", filename, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    // Create backup file
    FILE* original_file = fopen(filename, "rb");
    FILE* backup_file = fopen(backup_filename, "wb");
    if (original_file == NULL || backup_file == NULL) {
        printf("Error: Failed to create backup file.\n");
        return;
    }
    char buffer[1024];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), original_file)) > 0) {
        fwrite(buffer, 1, n, backup_file);
    }
    fclose(original_file);
    fclose(backup_file);
    // Update backup_files array
    strcpy(backup_files[num_backup_files].filename, backup_filename);
    backup_files[num_backup_files].last_modified = t;
    num_backup_files++;
    printf("Backup created: %s\n", backup_filename);
}

void list_backup_files() {
    printf("Backup files:\n");
    for (int i = 0; i < num_backup_files; i++) {
        printf("%d. %s (last modified: %s)", i + 1, backup_files[i].filename, ctime(&backup_files[i].last_modified));
    }
}

void delete_backup_file(int index) {
    if (index < 0 || index >= num_backup_files) {
        printf("Error: Invalid backup file index.\n");
        return;
    }
    if (remove(backup_files[index].filename) != 0) {
        printf("Error: Failed to delete backup file.\n");
        return;
    }
    printf("Backup file deleted: %s\n", backup_files[index].filename);
    // Shift backup_files array down to remove deleted file
    for (int i = index; i < num_backup_files - 1; i++) {
        backup_files[i] = backup_files[i + 1];
    }
    num_backup_files--;
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter file name to backup: ");
    scanf("%s", filename);
    backup_file(filename);
    list_backup_files();
    int index;
    printf("Enter index of backup file to delete (0 to cancel): ");
    scanf("%d", &index);
    if (index > 0 && index <= num_backup_files) {
        delete_backup_file(index - 1);
        list_backup_files();
    }
    return 0;
}