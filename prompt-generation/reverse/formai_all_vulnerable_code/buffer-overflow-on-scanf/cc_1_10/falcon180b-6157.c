//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_BACKUP_FILES 10

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    char backup_file_name[MAX_FILE_NAME_LEN];
} file_backup_t;

void backup_file(file_backup_t *backup_file) {
    char *file_content = NULL;
    size_t file_size = 0;
    FILE *file = fopen(backup_file->file_name, "rb");

    if (file == NULL) {
        printf("Error: File not found.\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    file_content = malloc(file_size + 1);
    if (file_content == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(file);
        return;
    }

    fread(file_content, file_size, 1, file);
    fclose(file);

    sprintf(backup_file->backup_file_name, "%s.bak", backup_file->file_name);
    FILE *backup_file_handle = fopen(backup_file->backup_file_name, "wb");

    if (backup_file_handle == NULL) {
        printf("Error: Backup file creation failed.\n");
        free(file_content);
        return;
    }

    fwrite(file_content, file_size, 1, backup_file_handle);
    fclose(backup_file_handle);

    printf("Backup complete.\n");
    free(file_content);
}

int main() {
    file_backup_t backup_files[MAX_BACKUP_FILES];
    int num_backup_files = 0;

    while (num_backup_files < MAX_BACKUP_FILES) {
        printf("Enter file name to backup (or type 'done' to finish): ");
        scanf("%s", backup_files[num_backup_files].file_name);

        if (strcmp(backup_files[num_backup_files].file_name, "done") == 0) {
            break;
        }

        num_backup_files++;
    }

    for (int i = 0; i < num_backup_files; i++) {
        backup_file(&backup_files[i]);
    }

    return 0;
}