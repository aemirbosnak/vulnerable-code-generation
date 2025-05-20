//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000 // Maximum size of the file

typedef struct {
    char filename[100];
    char backup_filename[100];
    FILE *file;
    FILE *backup_file;
} File;

void backup_file(File *file) {
    char *buffer = malloc(MAX_SIZE);
    int bytes_read = 0;

    file->backup_file = fopen(file->backup_filename, "w");

    if (file->backup_file == NULL) {
        printf("Error opening backup file: %s\n", file->backup_filename);
        exit(1);
    }

    while ((bytes_read = fread(buffer, sizeof(char), MAX_SIZE, file->file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, file->backup_file);
    }

    fclose(file->backup_file);
    free(buffer);
}

int main() {
    char filename[100];
    char backup_filename[100];
    File file;

    printf("Enter filename to backup: ");
    scanf("%s", filename);

    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");

    file.file = fopen(filename, "r");

    if (file.file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    file.backup_file = fopen(backup_filename, "w");

    if (file.backup_file == NULL) {
        printf("Error opening backup file: %s\n", backup_filename);
        exit(1);
    }

    backup_file(&file);

    fclose(file.file);
    fclose(file.backup_file);

    printf("Backup complete!\n");

    return 0;
}