//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

typedef struct {
    char *filename;
    char *backup_filename;
    FILE *file;
    FILE *backup_file;
    int file_size;
} FileBackup;

void initialize_backup_file(FileBackup *backup) {
    strcpy(backup->backup_filename, backup->filename);
    strcat(backup->backup_filename, ".bak");
    backup->backup_file = fopen(backup->backup_filename, "wb");
    if (backup->backup_file == NULL) {
        printf("Error: Could not create backup file.\n");
        exit(1);
    }
    backup->file_size = 0;
}

void backup_file(FileBackup *backup) {
    char buffer[BUFFER_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, backup->file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup->backup_file);
        backup->file_size += bytes_read;
    }
    fclose(backup->file);
    fclose(backup->backup_file);
    printf("Backup created successfully.\n");
}

int main() {
    FileBackup backup;
    printf("Enter the filename to backup: ");
    scanf("%s", backup.filename);
    backup.file = fopen(backup.filename, "rb");
    if (backup.file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    initialize_backup_file(&backup);
    backup_file(&backup);
    return 0;
}