//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Ken Thompson
//C File Backup System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_BACKUP_FILES 10

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    time_t timestamp;
} backup_file_t;

backup_file_t backup_files[MAX_BACKUP_FILES];
int num_backup_files = 0;

void backup_file(char *filename) {
    backup_file_t new_backup_file;
    strncpy(new_backup_file.filename, filename, MAX_FILE_NAME_LENGTH);
    new_backup_file.timestamp = time(NULL);

    if (num_backup_files >= MAX_BACKUP_FILES) {
        backup_files[0].timestamp = 0;
        num_backup_files = 0;
    }

    backup_files[num_backup_files] = new_backup_file;
    num_backup_files++;
}

void restore_file(char *filename) {
    int i;
    for (i = 0; i < num_backup_files; i++) {
        if (strcmp(backup_files[i].filename, filename) == 0) {
            printf("Restoring %s from backup...\n", filename);
            FILE *backup_file = fopen(backup_files[i].filename, "rb");
            FILE *original_file = fopen(filename, "wb");

            if (backup_file == NULL || original_file == NULL) {
                printf("Error: Could not open file.\n");
                exit(1);
            }

            char buffer[1024];
            while (fread(buffer, sizeof(char), sizeof(buffer), backup_file) > 0) {
                fwrite(buffer, sizeof(char), sizeof(buffer), original_file);
            }

            fclose(backup_file);
            fclose(original_file);
            break;
        }
    }
}

int main() {
    char filename[MAX_FILE_NAME_LENGTH];
    printf("Enter filename to backup: ");
    scanf("%s", filename);
    backup_file(filename);

    printf("Backup complete.\n");

    char restore_filename[MAX_FILE_NAME_LENGTH];
    printf("Enter filename to restore: ");
    scanf("%s", restore_filename);
    restore_file(restore_filename);

    printf("Restore complete.\n");

    return 0;
}