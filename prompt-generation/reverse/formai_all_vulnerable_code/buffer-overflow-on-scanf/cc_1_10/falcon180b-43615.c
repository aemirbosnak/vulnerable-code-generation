//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_FILES 50
#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_CONTENTS_LENGTH 1000000

typedef struct {
    char *filename;
    char *file_contents;
    int file_size;
} File;

void backup_file(File *file) {
    char *backup_filename = malloc(MAX_FILE_NAME_LENGTH);
    strcpy(backup_filename, file->filename);
    strcat(backup_filename, ".bak");

    FILE *backup_file = fopen(backup_filename, "w");
    if (backup_file == NULL) {
        printf("Error: Failed to open backup file %s\n", backup_filename);
        exit(1);
    }

    fwrite(file->file_contents, file->file_size, 1, backup_file);
    fclose(backup_file);

    printf("Backup of file %s created\n", backup_filename);
}

int main() {
    int num_files = 0;
    File files[MAX_NUM_FILES];

    while (num_files < MAX_NUM_FILES) {
        printf("Enter filename (or type 'done' to finish): ");
        char filename[MAX_FILE_NAME_LENGTH];
        scanf("%s", filename);

        if (strcmp(filename, "done") == 0) {
            break;
        }

        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error: File %s not found\n", filename);
            continue;
        }

        fseek(file, 0, SEEK_END);
        int file_size = ftell(file);
        rewind(file);

        char *file_contents = malloc(MAX_FILE_CONTENTS_LENGTH);
        fread(file_contents, file_size, 1, file);

        files[num_files].filename = malloc(strlen(filename) + 1);
        strcpy(files[num_files].filename, filename);
        files[num_files].file_contents = file_contents;
        files[num_files].file_size = file_size;

        num_files++;
        fclose(file);
    }

    printf("Backup files:\n");
    for (int i = 0; i < num_files; i++) {
        backup_file(&files[i]);
    }

    for (int i = 0; i < num_files; i++) {
        free(files[i].filename);
        free(files[i].file_contents);
    }

    return 0;
}