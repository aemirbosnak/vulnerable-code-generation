//FormAI DATASET v1.0 Category: File Backup System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 32
#define MAX_FILES 100

typedef struct {
    char filename[MAX_FILENAME_LENGTH]; 
    time_t last_modified;
} file_t;

file_t backup[MAX_FILES]; // array of files to backup
int num_files = 0; // number of files in backup array

void add_file_to_backup(char *filename) {
    if (num_files >= MAX_FILES) {
        printf("Max number of files reached!\n");
        return;
    }
    strncpy(backup[num_files].filename, filename, MAX_FILENAME_LENGTH-1);
    backup[num_files].last_modified = time(NULL);
    num_files++;
}

void backup_files() {
    FILE *backup_file;
    backup_file = fopen("backup.txt", "w");
    if (backup_file == NULL) {
        printf("Error opening backup file\n");
        return;
    }
    for (int i = 0; i < num_files; i++) {
        fprintf(backup_file, "%s %ld\n", backup[i].filename, backup[i].last_modified);
    }
    fclose(backup_file);
    printf("Backup complete!\n");
}

void restore_files() {
    FILE *backup_file;
    backup_file = fopen("backup.txt", "r");
    if (backup_file == NULL) {
        printf("Error opening backup file\n");
        return;
    }
    char filename[MAX_FILENAME_LENGTH];
    time_t last_modified;
    while (fscanf(backup_file, "%s %ld", filename, &last_modified) != EOF) {
        printf("Restoring file: %s\n", filename);
        // code to copy file contents from backup to original location goes here
    }
    fclose(backup_file);
    printf("Restore complete!\n");
}

// main function for testing
int main() {
    add_file_to_backup("file1.txt");
    add_file_to_backup("file2.txt");
    add_file_to_backup("file3.txt");
    backup_files();
    restore_files();
    return 0;
}