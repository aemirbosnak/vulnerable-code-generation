//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define FILE_TO_BACKUP "fileToBackup.txt"
#define BACKUP_FILE "backupFile.txt"
#define BUFFER_SIZE 1024

int main(void) {
    FILE *fileToBackup = NULL;
    FILE *backupFile = NULL;
    char buffer[BUFFER_SIZE];
    char *content = NULL;
    size_t fileSize = 0;

    if ((fileToBackup = fopen(FILE_TO_BACKUP, "r")) == NULL) {
        perror("Error opening fileToBackup.txt for reading.");
        goto error;
    }

    fseek(fileToBackup, 0, SEEK_END);
    fileSize = ftell(fileToBackup);
    rewind(fileToBackup);

    if ((content = malloc(fileSize + 1)) == NULL) {
        perror("Error allocating memory for char array.");
        goto error;
    }

    if (fread(content, fileSize, 1, fileToBackup) != 1) {
        perror("Error reading fileToBackup.txt.");
        goto error;
    }

    content[fileSize] = '\0'; // Null-terminate the char array

    if ((backupFile = fopen(BACKUP_FILE, "w")) == NULL) {
        perror("Error opening backupFile.txt for writing.");
        goto error;
    }

    if (fprintf(backupFile, "%s", content) < 0) {
        perror("Error writing to backupFile.txt.");
        goto error;
    }

    if (fclose(fileToBackup) != 0) {
        perror("Error closing fileToBackup.txt.");
        goto error;
    }

    if (fclose(backupFile) != 0) {
        perror("Error closing backupFile.txt.");
        goto error;
    }

    printf("Backup completed successfully.\n");

    free(content);

    return EXIT_SUCCESS;

error:
    if (fileToBackup != NULL) fclose(fileToBackup);
    if (backupFile != NULL) fclose(backupFile);
    if (content != NULL) free(content);

    perror("Error:");
    return EXIT_FAILURE;
}