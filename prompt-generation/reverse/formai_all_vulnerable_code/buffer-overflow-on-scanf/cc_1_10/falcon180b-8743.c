//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_BACKUP_DIR 100

typedef struct {
    char file_name[MAX_FILE_NAME];
    char backup_dir[MAX_BACKUP_DIR];
} file_info;

void backup_file(file_info file) {
    char backup_file_name[MAX_FILE_NAME];
    strcpy(backup_file_name, file.backup_dir);
    strcat(backup_file_name, "/");
    strcat(backup_file_name, file.file_name);

    FILE *backup_file = fopen(backup_file_name, "wb");
    if (backup_file == NULL) {
        printf("Error: Could not create backup file.\n");
        exit(1);
    }

    FILE *original_file = fopen(file.file_name, "rb");
    if (original_file == NULL) {
        printf("Error: Could not open original file.\n");
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, 1024, original_file)!= NULL) {
        fputs(buffer, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);
}

int main() {
    file_info file;
    printf("Enter the name of the file to be backed up: ");
    scanf("%s", file.file_name);

    printf("Enter the directory to store backups: ");
    scanf("%s", file.backup_dir);

    backup_file(file);

    printf("Backup complete.\n");

    return 0;
}