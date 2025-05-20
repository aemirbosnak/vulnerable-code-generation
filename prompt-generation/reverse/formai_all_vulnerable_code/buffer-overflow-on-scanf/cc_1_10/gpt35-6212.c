//FormAI DATASET v1.0 Category: File Backup System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 20

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    char data[1000];
    int size;
    time_t date;
} File;

typedef struct {
    File files[MAX_FILES];
    int count;
} FileArchive;

void backupFiles(FileArchive *archive, char *filename);

void restoreFiles(FileArchive *archive, char *filename);

int main(void) {
    FileArchive archive;
    archive.count = 0;
    char command[10];
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);
        if (strcmp(command, "backup") == 0) {
            char filename[MAX_FILENAME_LENGTH];
            printf("Enter filename: ");
            scanf("%s", filename);
            backupFiles(&archive, filename);
        } else if (strcmp(command, "restore") == 0) {
            char filename[MAX_FILENAME_LENGTH];
            printf("Enter filename: ");
            scanf("%s", filename);
            restoreFiles(&archive, filename);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}

void backupFiles(FileArchive *archive, char *filename) {
    if (archive->count == MAX_FILES) {
        printf("Error: Maximum number of files reached\n");
        return;
    }
    printf("Backing up file...\n");
    File file;
    strncpy(file.name, filename, MAX_FILENAME_LENGTH);
    printf("Enter file data: ");
    scanf("%s", file.data);
    file.size = strlen(file.data);
    file.date = time(NULL);
    archive->files[archive->count++] = file;
    printf("File backed up successfully!\n");
}

void restoreFiles(FileArchive *archive, char *filename) {
    for (int i = 0; i < archive->count; i++) {
        if (strcmp(archive->files[i].name, filename) == 0) {
            printf("Restoring file...\n");
            printf("Data: %s\n", archive->files[i].data);
            printf("Size: %d bytes\n", archive->files[i].size);
            printf("Date: %s", ctime(&archive->files[i].date));
            printf("File restored successfully!\n");
            return;
        }
    }
    printf("Error: File not found in archive\n");
}