//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_LENGTH 100
#define BACKUP_DIR "backup"

typedef struct {
    char name[MAX_FILE_LENGTH];
    int size;
    char backup_name[MAX_FILE_LENGTH];
} file_t;

void create_backup_dir() {
    char command[50] = "mkdir ";
    strcat(command, BACKUP_DIR);
    system(command);
}

void backup_file(file_t *file) {
    char backup_path[100];
    strcpy(backup_path, BACKUP_DIR);
    strcat(backup_path, "/");
    strcat(backup_path, file->backup_name);

    FILE *backup_file = fopen(backup_path, "wb");

    if (backup_file == NULL) {
        printf("Error creating backup file: %s\n", backup_path);
        return;
    }

    FILE *original_file = fopen(file->name, "rb");

    if (original_file == NULL) {
        printf("Error opening original file: %s\n", file->name);
        fclose(backup_file);
        return;
    }

    char buffer[1024];
    int bytes_read;

    while ((bytes_read = fread(buffer, 1, 1024, original_file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);

    printf("Backup created: %s\n", backup_path);
}

int main() {
    file_t file;

    printf("Enter file name: ");
    scanf("%s", file.name);

    FILE *file_handle = fopen(file.name, "rb");

    if (file_handle == NULL) {
        printf("Error opening file: %s\n", file.name);
        return 1;
    }

    fseek(file_handle, 0, SEEK_END);
    file.size = ftell(file_handle);
    rewind(file_handle);

    strcpy(file.backup_name, file.name);
    strcat(file.backup_name, ".bak");

    backup_file(&file);

    fclose(file_handle);

    return 0;
}