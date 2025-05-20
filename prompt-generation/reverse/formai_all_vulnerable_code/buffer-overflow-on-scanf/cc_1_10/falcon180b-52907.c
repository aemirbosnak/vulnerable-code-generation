//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10000000 // 10 MB

typedef struct {
    char filename[50];
    char backup_filename[50];
    FILE *file;
} File;

void create_backup(File *file) {
    strcat(file->backup_filename, "_backup");
    file->file = fopen(file->backup_filename, "wb");

    if (file->file == NULL) {
        printf("Error creating backup file!\n");
        exit(1);
    }
}

void backup_file(File *file) {
    char buffer[MAX_FILE_SIZE];
    int bytes_read;

    rewind(file->file);
    rewind(file->file);

    while ((bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, file->file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, file->file);
    }

    fclose(file->file);
    fclose(file->file);
}

int main() {
    File file;

    printf("Enter filename: ");
    scanf("%s", file.filename);

    file.file = fopen(file.filename, "rb+");

    if (file.file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    create_backup(&file);
    backup_file(&file);

    printf("Backup complete!\n");

    return 0;
}