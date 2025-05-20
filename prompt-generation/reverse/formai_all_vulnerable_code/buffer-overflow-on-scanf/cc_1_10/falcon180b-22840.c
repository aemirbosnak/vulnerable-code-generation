//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB

typedef struct {
    char filename[100];
    char backup_filename[200];
    time_t timestamp;
    FILE *file;
} FileBackup;

void create_backup_folder(char *folder_path) {
    char backup_folder_path[200];
    strcpy(backup_folder_path, folder_path);
    strcat(backup_folder_path, "\\Backup");

    if (mkdir(backup_folder_path) == -1) {
        perror("Error creating backup folder");
        exit(1);
    }
}

void create_backup_filename(char *filename, char *backup_filename) {
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");
}

void backup_file(FileBackup *file_backup) {
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read;

    rewind(file_backup->file);

    FILE *backup_file = fopen(file_backup->backup_filename, "wb");

    if (backup_file == NULL) {
        perror("Error opening backup file");
        exit(1);
    }

    while ((bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, file_backup->file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, backup_file);
    }

    fclose(backup_file);
}

int main() {
    char folder_path[100];
    printf("Enter the folder path to backup: ");
    scanf("%s", folder_path);

    create_backup_folder(folder_path);

    FILE *file;
    FileBackup file_backup;

    file = fopen("file_list.txt", "w");

    if (file == NULL) {
        perror("Error opening file list");
        exit(1);
    }

    char filename[100];
    while (fscanf(file, "%s", filename)!= EOF) {
        strcpy(file_backup.filename, filename);
        create_backup_filename(filename, file_backup.backup_filename);

        file_backup.timestamp = time(NULL);
        file_backup.file = fopen(filename, "rb");

        if (file_backup.file == NULL) {
            perror("Error opening file");
            exit(1);
        }

        backup_file(&file_backup);

        fclose(file_backup.file);
        fclose(file);

        file = fopen("file_list.txt", "a");
    }

    fclose(file);

    return 0;
}