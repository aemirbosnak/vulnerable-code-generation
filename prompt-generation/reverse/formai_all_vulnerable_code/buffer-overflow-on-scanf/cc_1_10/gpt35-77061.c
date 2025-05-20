//FormAI DATASET v1.0 Category: File Backup System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_SIZE 1024
#define MAX_BACKUP_FILES 10

int main() {

    char filename[MAX_FILENAME_SIZE];
    char backupFilename[MAX_FILENAME_SIZE];
    char backupFolder[20] = "backup/";
    int fileExists = 0;
    int numBackupFiles = 0;
    FILE *file, *backupFile;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char timestamp[20];

    strftime(timestamp, sizeof(timestamp), "%Y%m%d%H%M%S", tm);

    printf("Welcome to the C File Backup System!\n\n");

    printf("Enter the file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return 0;
    }

    printf("\nChecking for existing backup files...\n");
    for (int i = 1; i <= MAX_BACKUP_FILES; i++) {
        sprintf(backupFilename, "%s%s.bak%d", backupFolder, filename, i);
        backupFile = fopen(backupFilename, "r");
        if (backupFile != NULL) {
            fclose(backupFile);
            numBackupFiles++;
        } else {
            break;
        }
    }

    if (numBackupFiles == 0) {
        sprintf(backupFilename, "%s%s.bak1", backupFolder, filename);
    } else {
        sprintf(backupFilename, "%s%s.bak%d", backupFolder, filename, numBackupFiles + 1);
    }
    printf("Creating backup file: %s\n", backupFilename);

    backupFile = fopen(backupFilename, "w");
    if (backupFile == NULL) {
        printf("Error: Could not create backup file\n");
        fclose(file);
        return 0;
    }

    char c = fgetc(file);
    while (c != EOF) {
        fputc(c, backupFile);
        c = fgetc(file);
    }
    printf("Backup complete!\n");

    fclose(file);
    fclose(backupFile);
    return 0;
}