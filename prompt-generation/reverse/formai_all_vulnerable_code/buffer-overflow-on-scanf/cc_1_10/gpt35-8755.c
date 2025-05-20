//FormAI DATASET v1.0 Category: File Backup System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILEPATH_LENGTH 100
#define MAX_BACKUP_FILE_COUNT 10

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char filepath[MAX_FILEPATH_LENGTH];
    time_t timestamp;
} file_snapshot;

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char filepath[MAX_FILEPATH_LENGTH];
    time_t curr_time;
    file_snapshot backups[MAX_BACKUP_FILE_COUNT];
    int backup_count = 0;

    while (1) {
        printf("Enter file name (or 'q' to quit): ");
        scanf("%s", filename);
        if (strcmp(filename, "q") == 0) break;

        printf("Enter file path: ");
        scanf("%s", filepath);

        if (backup_count == MAX_BACKUP_FILE_COUNT) {
            // no more space for backup, delete oldest one
            remove(backups[0].filepath);

            // shift backup records by 1 to accommodate new backup
            for (int i = 1; i < backup_count; i++) {
                backups[i - 1] = backups[i];
            }
            backup_count--;
        }

        curr_time = time(NULL);
        strcpy(backups[backup_count].filename, filename);
        strcpy(backups[backup_count].filepath, filepath);
        backups[backup_count].timestamp = curr_time;

        // make backup file name unique by appending timestamp
        char timestamp_str[20];
        sprintf(timestamp_str, "_%ld", curr_time);
        strcat(backups[backup_count].filename, timestamp_str);

        // create backup file
        FILE *src_file = fopen(filepath, "r");
        if (src_file == NULL) {
            printf("Error opening file %s.\n", filepath);
            continue;
        }

        FILE *dest_file = fopen(backups[backup_count].filename, "w");
        if (dest_file == NULL) {
            fclose(src_file);
            printf("Error creating backup file %s.\n", backups[backup_count].filename);
            continue;
        }

        char c;
        while ((c = fgetc(src_file)) != EOF) {
            fputc(c, dest_file);
        }

        fclose(src_file);
        fclose(dest_file);

        printf("Backup of %s created at %s.\n", filename, backups[backup_count].filename);
        backup_count++;
    }

    return 0;
}