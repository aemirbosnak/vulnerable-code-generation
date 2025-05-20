//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_NAME_LEN 256
#define BACKUP_DIR "backup"

typedef struct {
    char *file_name;
    char *backup_file_name;
    char *file_content;
    size_t file_size;
} File;

bool create_dir(const char *dir_name) {
    char cmd[256];
    sprintf(cmd, "mkdir -p %s", dir_name);
    system(cmd);
    return true;
}

bool backup_file(const char *file_name, const char *backup_dir) {
    char backup_file_name[MAX_FILE_NAME_LEN];
    strcpy(backup_file_name, backup_dir);
    strcat(backup_file_name, "/");
    strcat(backup_file_name, file_name);

    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error: File %s not found.\n", file_name);
        return false;
    }

    File file;
    file.file_name = strdup(file_name);
    file.backup_file_name = strdup(backup_file_name);
    file.file_content = malloc(file.file_size = fread(NULL, 1, 0, fp));
    file.file_size = fread(file.file_content, 1, file.file_size, fp);
    fclose(fp);

    FILE *bfp = fopen(backup_file_name, "wb");
    if (bfp == NULL) {
        printf("Error: Failed to create backup file %s.\n", backup_file_name);
        free(file.file_name);
        free(file.backup_file_name);
        free(file.file_content);
        return false;
    }

    fwrite(file.file_content, 1, file.file_size, bfp);
    fclose(bfp);

    printf("Backup of file %s created in %s.\n", file_name, backup_dir);

    free(file.file_name);
    free(file.backup_file_name);
    free(file.file_content);

    return true;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <file_name> <backup_dir>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    char *backup_dir = argv[2];

    if (strcmp(backup_dir, BACKUP_DIR)!= 0) {
        if (!create_dir(backup_dir)) {
            return 1;
        }
    }

    backup_file(file_name, backup_dir);

    return 0;
}