//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char sourceFile[100], backupFile[150];
    char backupDir[50];

    printf("Enter the source file path: ");
    scanf("%s", sourceFile);

    printf("Enter the backup directory path: ");
    scanf("%s", backupDir);

    strcat(backupDir, "/");
    strcat(backupDir, "backup_file.txt");

    FILE *source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Error: Unable to open source file.\n");
        return 1;
    }

    FILE *backup = fopen(backupFile, "w");
    if (backup == NULL) {
        printf("Error: Unable to open backup file.\n");
        fclose(source);
        return 1;
    }

    time_t now = time(NULL);
    char timestamp[15];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d_%H-%M-%S", localtime(&now));
    strcat(backupFile, "_");
    strcat(backupFile, timestamp);

    size_t bytesRead;
    char buffer[256];

    while ((bytesRead = fread(buffer, sizeof(char), sizeof(buffer), source)) > 0) {
        fwrite(buffer, sizeof(char), bytesRead, backup);
    }

    printf("File backup created successfully.\n");

    fclose(source);
    fclose(backup);

    return 0;
}