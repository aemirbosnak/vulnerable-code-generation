//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10MB

typedef struct {
    char filename[256];
    char backup_filename[256];
    time_t timestamp;
    FILE *file;
} File;

void create_backup_filename(char *filename, char *backup_filename) {
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");
}

void backup_file(File *file) {
    char backup_filename[256];
    create_backup_filename(file->filename, backup_filename);

    if ((file->file = fopen(backup_filename, "wb")) == NULL) {
        printf("Error: Could not create backup file %s\n", backup_filename);
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    while (fgets(buffer, MAX_FILE_SIZE, file->file)!= NULL) {
        fputs(buffer, file->file);
    }

    fclose(file->file);
    fclose(file->file);
}

int main() {
    File file;
    printf("Enter filename: ");
    scanf("%s", file.filename);

    if ((file.file = fopen(file.filename, "rb+")) == NULL) {
        printf("Error: Could not open file %s\n", file.filename);
        exit(1);
    }

    time_t timestamp = time(NULL);
    strftime(file.timestamp, 26, "%Y-%m-%d_%H-%M-%S", localtime(&timestamp));

    printf("Enter backup filename (leave blank for default): ");
    scanf("%s", file.backup_filename);

    if (strcmp(file.backup_filename, "") == 0) {
        create_backup_filename(file.filename, file.backup_filename);
    }

    backup_file(&file);

    printf("Backup complete!\n");

    return 0;
}