//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_LINE_LENGTH 1024
#define MAX_BACKUP_DIR_LENGTH 256

typedef struct {
    char *file_name;
    char *backup_dir;
} FileBackup;

int read_file(const char *file_name, char **buffer) {
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: unable to open file %s\n", file_name);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    char *temp_buffer = malloc(file_size + 1);
    if (temp_buffer == NULL) {
        printf("Error: unable to allocate memory\n");
        fclose(fp);
        return 1;
    }

    fread(temp_buffer, file_size, 1, fp);
    temp_buffer[file_size] = '\0';
    *buffer = temp_buffer;

    fclose(fp);
    return 0;
}

int write_backup_file(const char *backup_dir, const char *file_name, const char *buffer) {
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    snprintf(backup_file_name, MAX_FILE_NAME_LENGTH, "%s/%s.bak", backup_dir, file_name);

    FILE *fp = fopen(backup_file_name, "w");
    if (fp == NULL) {
        printf("Error: unable to open backup file %s\n", backup_file_name);
        return 1;
    }

    fwrite(buffer, strlen(buffer), 1, fp);
    fclose(fp);

    return 0;
}

int backup_file(FileBackup *backup_info) {
    char *file_buffer = NULL;
    if (read_file(backup_info->file_name, &file_buffer)!= 0) {
        return 1;
    }

    if (write_backup_file(backup_info->backup_dir, backup_info->file_name, file_buffer)!= 0) {
        return 1;
    }

    free(file_buffer);
    return 0;
}

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    while (fgets(input_buffer, MAX_LINE_LENGTH, stdin)!= NULL) {
        char *line = input_buffer;
        while (isspace(*line)) {
            line++;
        }

        char file_name[MAX_FILE_NAME_LENGTH];
        char backup_dir[MAX_BACKUP_DIR_LENGTH];
        if (sscanf(line, "%s %s", file_name, backup_dir)!= 2) {
            printf("Error: invalid input\n");
            continue;
        }

        FileBackup backup_info = {
           .file_name = strdup(file_name),
           .backup_dir = strdup(backup_dir)
        };

        if (backup_file(&backup_info)!= 0) {
            printf("Error: backup failed\n");
        } else {
            printf("Backup successful\n");
        }

        free(backup_info.file_name);
        free(backup_info.backup_dir);
    }

    return 0;
}