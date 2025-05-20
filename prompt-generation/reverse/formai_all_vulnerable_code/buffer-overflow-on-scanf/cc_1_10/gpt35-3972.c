//FormAI DATASET v1.0 Category: File Backup System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LEN 256
#define MAX_BACKUP_TIMES 5

typedef struct backup_t {
    char filename[MAX_FILENAME_LEN];
    time_t backup_time[MAX_BACKUP_TIMES];
    int num_backups;
} Backup;

void backup_file(char* filename);

int main() {
    char filename[MAX_FILENAME_LEN];
    printf("Enter filename to backup: ");
    scanf("%s", filename);
    backup_file(filename);
    return 0;
}

void backup_file(char* filename) {
    // Check that file exists
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found!");
        return;
    }
    fclose(file);

    // Create backup filename
    char backup_filename[MAX_FILENAME_LEN];
    time_t current_time = time(NULL);
    strftime(backup_filename, sizeof(backup_filename), "%Y%m%d_%H%M%S", localtime(&current_time));
    strcat(backup_filename, "_");
    strcat(backup_filename, filename);

    // Open files for copying
    file = fopen(filename, "rb");
    FILE* backup_file = fopen(backup_filename, "wb");

    // Copy data
    unsigned char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    // Close files
    fclose(file);
    fclose(backup_file);

    // Log backup
    Backup backup;
    strncpy(backup.filename, filename, MAX_FILENAME_LEN);
    backup.backup_time[backup.num_backups] = current_time;
    ++backup.num_backups;

    // Write backup log to file
    FILE* log_file = fopen("backup_log.txt", "a");
    fprintf(log_file, "Filename: %s\n", backup.filename);
    for (int i = 0; i < backup.num_backups; ++i) {
        fprintf(log_file, "Backup %d: %s", i+1, ctime(&backup.backup_time[i]));
    }
    fclose(log_file);

    // Delete old backups
    if (backup.num_backups > MAX_BACKUP_TIMES) {
        // Get oldest backup time
        time_t oldest_time = backup.backup_time[0];
        int oldest_index = 0;
        for (int i = 1; i < backup.num_backups; ++i) {
            if (backup.backup_time[i] < oldest_time) {
                oldest_time = backup.backup_time[i];
                oldest_index = i;
            }
        }

        // Delete backup file
        char oldest_backup[MAX_FILENAME_LEN];
        strftime(oldest_backup, sizeof(oldest_backup), "%Y%m%d_%H%M%S", localtime(&oldest_time));
        strcat(oldest_backup, "_");
        strcat(oldest_backup, filename);
        remove(oldest_backup);

        // Remove oldest backup from log
        for (int i = oldest_index; i < backup.num_backups-1; ++i) {
            backup.backup_time[i] = backup.backup_time[i+1];
        }
        --backup.num_backups;
    }
}