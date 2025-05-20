//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_FILE_SIZE 100

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    char file_data[MAX_FILE_SIZE];
    int file_size;
} File;

void backup_file(File *file) {
    FILE *backup_file = fopen("backup.txt", "a");
    if (backup_file == NULL) {
        printf("Error: Could not open backup file.\n");
        return;
    }

    fwrite(file->file_name, sizeof(char), strlen(file->file_name), backup_file);
    fwrite(file->file_data, sizeof(char), file->file_size, backup_file);

    fclose(backup_file);
}

void restore_file(File *file) {
    FILE *backup_file = fopen("backup.txt", "r");
    if (backup_file == NULL) {
        printf("Error: Could not open backup file.\n");
        return;
    }

    char file_name[MAX_FILE_NAME_LEN];
    char file_data[MAX_FILE_SIZE];

    while (fscanf(backup_file, "%s %s", file_name, file_data)!= EOF) {
        if (strcmp(file_name, file->file_name) == 0) {
            strcpy(file->file_data, file_data);
            file->file_size = strlen(file->file_data);
        }
    }

    fclose(backup_file);
}

int main() {
    File file;

    printf("Enter file name: ");
    scanf("%s", file.file_name);

    printf("Enter file contents: ");
    scanf("%[^\n]", file.file_data);
    file.file_size = strlen(file.file_data);

    backup_file(&file);

    printf("File backed up successfully.\n");

    strcpy(file.file_data, "New file contents");
    file.file_size = strlen(file.file_data);

    restore_file(&file);

    printf("File restored successfully.\n");

    printf("File name: %s\n", file.file_name);
    printf("File contents: %s\n", file.file_data);

    return 0;
}