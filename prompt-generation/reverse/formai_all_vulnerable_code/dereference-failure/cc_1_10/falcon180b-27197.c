//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LEN 256
#define BACKUP_DIR_NAME "backup"

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    time_t backup_time;
} BackupFile;

void create_backup_dir(void) {
    char backup_dir_path[MAX_FILE_NAME_LEN];
    strcpy(backup_dir_path, BACKUP_DIR_NAME);
    mkdir(backup_dir_path, 0755);
}

void backup_file(char* file_path) {
    BackupFile backup_file;
    strcpy(backup_file.file_name, file_path);
    time(&backup_file.backup_time);

    char backup_file_path[MAX_FILE_NAME_LEN];
    strcpy(backup_file_path, BACKUP_DIR_NAME);
    strcat(backup_file_path, "/");
    strcat(backup_file_path, backup_file.file_name);
    strcat(backup_file_path, ".bak");

    FILE* backup_file_handle = fopen(backup_file_path, "w");
    if (backup_file_handle == NULL) {
        printf("Error creating backup file: %s\n", backup_file_path);
        return;
    }

    FILE* input_file_handle = fopen(file_path, "r");
    if (input_file_handle == NULL) {
        printf("Error reading input file: %s\n", file_path);
        fclose(backup_file_handle);
        remove(backup_file_path);
        return;
    }

    char input_buffer[1024];
    while (fgets(input_buffer, sizeof(input_buffer), input_file_handle)!= NULL) {
        fputs(input_buffer, backup_file_handle);
    }

    fclose(input_file_handle);
    fclose(backup_file_handle);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char* file_path = argv[1];
    create_backup_dir();

    backup_file(file_path);
    printf("Backup created: %s\n", file_path);

    return 0;
}