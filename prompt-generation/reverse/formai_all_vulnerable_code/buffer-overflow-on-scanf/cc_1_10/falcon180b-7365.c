//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_BACKUP_DIR_LEN 100
#define MAX_BACKUP_FILE_NAME_LEN MAX_FILE_NAME_LEN + 10

// Function to get current date and time in string format
char* getDateTime() {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    char dt[20];
    strftime(dt, sizeof(dt), "%Y%m%d_%H%M%S", t);
    return strdup(dt);
}

// Function to create backup directory if it doesn't exist
void createBackupDir(char* backupDir) {
    char cmd[MAX_BACKUP_DIR_LEN + 20];
    sprintf(cmd, "mkdir -p %s", backupDir);
    system(cmd);
}

// Function to backup a file
void backupFile(char* srcFile, char* backupDir) {
    char dstFile[MAX_BACKUP_FILE_NAME_LEN];
    strcpy(dstFile, backupDir);
    strcat(dstFile, "/");
    strcat(dstFile, getDateTime());
    strcat(dstFile, "_");
    strcat(dstFile, srcFile);

    char cmd[MAX_BACKUP_DIR_LEN + MAX_FILE_NAME_LEN + 20];
    sprintf(cmd, "cp %s %s", srcFile, dstFile);
    system(cmd);
}

// Function to restore a file
void restoreFile(char* backupDir, char* dstFile) {
    char srcFile[MAX_BACKUP_FILE_NAME_LEN];
    strcpy(srcFile, backupDir);
    strcat(srcFile, "/");
    strcat(srcFile, dstFile);

    char cmd[MAX_BACKUP_DIR_LEN + MAX_FILE_NAME_LEN + 20];
    sprintf(cmd, "cp %s %s", srcFile, dstFile);
    system(cmd);
}

// Function to list all backup files in a directory
void listBackupFiles(char* backupDir) {
    char cmd[MAX_BACKUP_DIR_LEN + 20];
    sprintf(cmd, "ls %s", backupDir);
    system(cmd);
}

int main() {
    char srcFile[MAX_FILE_NAME_LEN];
    printf("Enter the name of the file to backup: ");
    scanf("%s", srcFile);

    char backupDir[MAX_BACKUP_DIR_LEN];
    printf("Enter the name of the backup directory: ");
    scanf("%s", backupDir);

    createBackupDir(backupFile);
    backupFile(srcFile, backupDir);
    printf("File backed up successfully.\n");

    return 0;
}