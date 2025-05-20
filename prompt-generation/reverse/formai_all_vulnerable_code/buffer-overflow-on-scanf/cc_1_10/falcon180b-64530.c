//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    char backup_filename[MAX_FILE_NAME_LENGTH];
    FILE *file;
} File;

int main() {
    int num_files;
    File files[MAX_FILES];
    printf("Enter the number of files to backup: ");
    scanf("%d", &num_files);

    for (int i = 0; i < num_files; i++) {
        printf("Enter the filename for file %d: ", i + 1);
        scanf("%s", files[i].filename);
        strcpy(files[i].backup_filename, files[i].filename);
        strcat(files[i].backup_filename, ".bak");
        files[i].file = fopen(files[i].filename, "r");
        if (files[i].file == NULL) {
            printf("Error opening file %s\n", files[i].filename);
            exit(1);
        }
    }

    printf("Enter the backup directory: ");
    char backup_dir[MAX_FILE_NAME_LENGTH];
    scanf("%s", backup_dir);

    for (int i = 0; i < num_files; i++) {
        char backup_path[MAX_FILE_NAME_LENGTH];
        sprintf(backup_path, "%s/%s", backup_dir, files[i].backup_filename);
        FILE *backup_file = fopen(backup_path, "w");
        if (backup_file == NULL) {
            printf("Error creating backup file %s\n", backup_path);
            exit(1);
        }

        char buffer[4096];
        int bytes_read;
        while ((bytes_read = fread(buffer, 1, sizeof(buffer), files[i].file)) > 0) {
            fwrite(buffer, 1, bytes_read, backup_file);
        }

        fclose(backup_file);
        fclose(files[i].file);
    }

    printf("Backup complete!\n");

    return 0;
}