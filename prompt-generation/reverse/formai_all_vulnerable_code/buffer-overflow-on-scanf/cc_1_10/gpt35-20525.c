//FormAI DATASET v1.0 Category: File Backup System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BACKUP_FILES 10

typedef struct backupFile {
    char filename[MAX_FILENAME_LENGTH];
    char backupVersions[MAX_BACKUP_FILES][MAX_FILENAME_LENGTH];
    int numBackupVersions;
} backupFile;

void printMenu() {
    printf("\nFile Backup System\n\n");
    printf("1. Add file to backup\n");
    printf("2. List all backup files\n");
    printf("3. Restore file from backup\n");
    printf("4. Exit\n\n");
}

void addFile(backupFile* files, int numFiles) {
    if(numFiles == MAX_BACKUP_FILES) {
        printf("Maximum number of backup files reached.\n");
        return;
    }
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    for(int i=0; i<numFiles; i++) {
        if(strcmp(files[i].filename, filename) == 0) {
            printf("File already exists in backup.\n");
            return;
        }
    }
    strncpy(files[numFiles].filename, filename, MAX_FILENAME_LENGTH-1);
    files[numFiles].filename[MAX_FILENAME_LENGTH-1] = '\0';
    printf("File added to backup.\n");
}

void listFiles(backupFile* files, int numFiles) {
    printf("Backup Files:\n");
    for(int i=0; i<numFiles; i++) {
        printf("%d. %s (%d backups)\n", i+1, files[i].filename, files[i].numBackupVersions);
    }
}

void restoreFile(backupFile* files, int numFiles) {
    if(numFiles == 0) {
        printf("No backup files available.\n");
        return;
    }
    printf("Select file to restore:\n");
    listFiles(files, numFiles);
    int fileIndex = 0;
    while(fileIndex < 1 || fileIndex > numFiles) {
        printf("Enter file number (1-%d): ", numFiles);
        scanf("%d", &fileIndex);
    }
    backupFile* selectedFile = &files[fileIndex-1];
    if(selectedFile->numBackupVersions == 0) {
        printf("No backup versions available for this file.\n");
        return;
    }
    printf("Select backup version to restore:\n");
    for(int i=0; i<selectedFile->numBackupVersions; i++) {
        printf("%d. %s\n", i+1, selectedFile->backupVersions[i]);
    }
    int versionIndex = 0;
    while(versionIndex < 1 || versionIndex > selectedFile->numBackupVersions) {
        printf("Enter backup version number (1-%d): ", selectedFile->numBackupVersions);
        scanf("%d", &versionIndex);
    }
    char systemCall[MAX_FILENAME_LENGTH*3 + 40];
    sprintf(systemCall, "cp -p %s %s.restored", selectedFile->backupVersions[versionIndex-1], selectedFile->filename);
    if(system(systemCall) < 0) {
        printf("Error restoring file.\n");
        return;
    }
    printf("File restored to %s.restored\n", selectedFile->filename);
}

int main() {
    backupFile files[MAX_BACKUP_FILES];
    int numFiles = 0;
    int option = 0;
    while(option != 4) {
        printMenu();
        printf("Enter option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                addFile(files, numFiles);
                numFiles++;
                break;
            case 2:
                listFiles(files, numFiles);
                break;
            case 3:
                restoreFile(files, numFiles);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option selected.\n");
                break;
        }
    }
    return 0;
}