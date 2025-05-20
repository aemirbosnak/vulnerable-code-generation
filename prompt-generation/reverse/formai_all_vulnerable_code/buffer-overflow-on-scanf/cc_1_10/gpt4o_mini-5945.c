//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define MAX_PATH_LENGTH 256
#define MAX_BACKUP_FILES 100

void get_timestamp(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, size, "%Y%m%d_%H%M%S", t);
}

void create_backup(const char *source, const char *destination) {
    char timestamp[20];
    get_timestamp(timestamp, sizeof(timestamp));

    // Create a backup filename
    char backup_filename[MAX_PATH_LENGTH];
    snprintf(backup_filename, sizeof(backup_filename), "%s_backup_%s", destination, timestamp);

    FILE *source_file = fopen(source, "rb");
    if (!source_file) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        return;
    }

    FILE *backup_file = fopen(backup_filename, "wb");
    if (!backup_file) {
        fprintf(stderr, "Error creating backup file: %s\n", strerror(errno));
        fclose(source_file);
        return;
    }

    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    fclose(source_file);
    fclose(backup_file);
    printf("Backup created successfully: %s\n", backup_filename);
}

void list_backups(const char *backup_dir) {
    printf("Backups in directory %s:\n", backup_dir);
    char command[100];
    snprintf(command, sizeof(command), "ls %s*.backup*", backup_dir);
    system(command);
}

int main() {
    char source_file[MAX_PATH_LENGTH];
    char backup_dir[MAX_PATH_LENGTH];

    printf("Enter the path of the file you want to backup: ");
    scanf("%s", source_file);

    printf("Enter the directory where you want to save the backups: ");
    scanf("%s", backup_dir);

    create_backup(source_file, backup_dir);
    list_backups(backup_dir);

    return 0;
}