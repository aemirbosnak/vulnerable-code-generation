//FormAI DATASET v1.0 Category: File Backup System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FILENAME_LEN 256
#define MAX_BACKUPS 10 

struct backup {
    char filename[MAX_FILENAME_LEN];
    time_t timestamp;
};

struct backup backups[MAX_BACKUPS];
int num_backups = 0;

bool is_file_exist(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

void backup_file(const char* filename) {
    char backup_filename[MAX_FILENAME_LEN];
    sprintf(backup_filename, "%s.bak", filename);

    // first, check if we already have this backup
    for (int i = 0; i < num_backups; i++) {
        if (strcmp(backups[i].filename, backup_filename) == 0) {
            // backup already exists, just update timestamp
            backups[i].timestamp = time(NULL);
            return;
        }
    }

    // if we get here, we need to create a new backup
    if (num_backups >= MAX_BACKUPS) {
        // too many backups, delete oldest one
        int oldest_index = 0;
        for (int i = 1; i < num_backups; i++) {
            if (backups[i].timestamp < backups[oldest_index].timestamp) {
                oldest_index = i;
            }
        }
        remove(backups[oldest_index].filename);
        num_backups--;
        memmove(&backups[oldest_index], &backups[oldest_index + 1], sizeof(struct backup) * (num_backups - oldest_index));
    }

    // create new backup
    time_t timestamp = time(NULL);
    if (!is_file_exist(backup_filename)) {
        // first time backing up this file
        if (rename(filename, backup_filename) != 0) {
            printf("Error: could not create backup file\n");
            return;
        }
    } else {
        // backup already exists, make copy with timestamp suffix
        char timestamp_str[20];
        strftime(timestamp_str, sizeof(timestamp_str), "%Y%m%d%H%M%S", localtime(&timestamp));
        char backup_timestamp_filename[MAX_FILENAME_LEN];
        sprintf(backup_timestamp_filename, "%s.%s", backup_filename, timestamp_str);
        if (rename(backup_filename, backup_timestamp_filename) != 0) {
            printf("Error: could not create backup file\n");
            return;
        }
        if (rename(filename, backup_filename) != 0) {
            printf("Error: could not create backup file\n");
            return;
        }
    }
    strcpy(backups[num_backups].filename, backup_filename);
    backups[num_backups].timestamp = timestamp;
    num_backups++;
}

int main() {
    char filename[MAX_FILENAME_LEN];
    printf("Enter filename to backup: ");
    fgets(filename, sizeof(filename), stdin);
    if (filename[strlen(filename) - 1] == '\n') {
        filename[strlen(filename) - 1] = '\0'; // remove newline character
    }
    backup_file(filename);
    return 0;
}