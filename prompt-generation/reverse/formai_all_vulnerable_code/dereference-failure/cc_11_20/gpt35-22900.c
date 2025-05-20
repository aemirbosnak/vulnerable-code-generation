//FormAI DATASET v1.0 Category: File Backup System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BACKUP_COUNT 10
#define MAX_BACKUP_FILENAME_LENGTH 270

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char backupFilename[MAX_BACKUP_FILENAME_LENGTH];
    char backupFilenames[MAX_BACKUP_COUNT][MAX_BACKUP_FILENAME_LENGTH];
    int backupCount = 0;

    printf("Enter the filename to backup: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = '\0'; // remove trailing newline

    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        return -1;
    }

    time_t timestamp;
    time(&timestamp);
    struct tm* timeinfo = localtime(&timestamp);
    sprintf(backupFilename, "%s_%04d%02d%02d%02d%02d%02d.bak",
            filename, timeinfo->tm_year+1900, timeinfo->tm_mon+1, timeinfo->tm_mday,
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

    FILE* backupFile = fopen(backupFilename, "wb");
    if (!backupFile) {
        printf("Error: could not create backup file %s\n", backupFilename);
        fclose(file);
        return -1;
    }

    char buffer[1024];
    size_t nread;
    while ((nread = fread(buffer, 1, sizeof buffer, file)) > 0) {
        fwrite(buffer, 1, nread, backupFile);
    }

    if (ferror(file)) {
        printf("Error: could not read from file %s\n", filename);
        fclose(file);
        fclose(backupFile);
        remove(backupFilename); // delete partial backup file
        return -1;
    }

    fclose(file);
    fclose(backupFile);

    printf("Backup created: %s\n", backupFilename);

    // store backup file names
    backupCount = 0;
    FILE* backupListFile = fopen("backup_list.txt", "r");
    if (backupListFile) {
        char backupListFilename[MAX_BACKUP_FILENAME_LENGTH];
        while (fgets(backupListFilename, MAX_BACKUP_FILENAME_LENGTH, backupListFile)) {
            backupListFilename[strcspn(backupListFilename, "\n")] = '\0'; // remove trailing newline
            strcpy(backupFilenames[backupCount], backupListFilename);
            backupCount++;
        }
        fclose(backupListFile);
    }

    // add new backup file name to list
    if (backupCount < MAX_BACKUP_COUNT) {
        strcpy(backupFilenames[backupCount], backupFilename);
        backupCount++;
    } else {
        // remove oldest backup file
        remove(backupFilenames[0]);
        // shift backup file names to make space for new backup
        for (int i = 0; i < backupCount-1; i++) {
            strcpy(backupFilenames[i], backupFilenames[i+1]);
        }
        strcpy(backupFilenames[backupCount-1], backupFilename);
    }

    // save backup file names to file
    backupListFile = fopen("backup_list.txt", "w");
    if (backupListFile) {
        for (int i = 0; i < backupCount; i++) {
            fprintf(backupListFile, "%s\n", backupFilenames[i]);
        }
        fclose(backupListFile);
    }
    
    return 0;
}