//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB
#define BACKUP_DIR "backup"

typedef struct backup_file_t {
    char filename[MAX_FILE_NAME_LENGTH];
    time_t timestamp;
    size_t size;
} backup_file_t;

void create_backup_dir() {
    char backup_path[MAX_FILE_NAME_LENGTH];
    strcpy(backup_path, BACKUP_DIR);
    mkdir(backup_path, 0777);
}

void backup_file(const char *filename, size_t size) {
    char backup_filename[MAX_FILE_NAME_LENGTH];
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");

    char backup_path[MAX_FILE_NAME_LENGTH];
    strcpy(backup_path, BACKUP_DIR);
    strcat(backup_path, "/");
    strcat(backup_path, backup_filename);

    FILE *backup_file = fopen(backup_path, "wb");
    if (backup_file == NULL) {
        printf("Error: could not create backup file %s\n", backup_path);
        exit(1);
    }

    fwrite(filename, 1, size, backup_file);
    fclose(backup_file);
}

int main() {
    create_backup_dir();

    char filename[MAX_FILE_NAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    backup_file(filename, size);

    printf("Backup created: %s\n", filename);

    fclose(file);
    return 0;
}