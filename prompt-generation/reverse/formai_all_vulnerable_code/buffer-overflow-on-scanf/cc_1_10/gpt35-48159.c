//FormAI DATASET v1.0 Category: File Backup System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants
#define MAX_FILENAME_LEN 50
#define MAX_FILESIZE 10000

// function prototypes
int backupFile(char fileName[MAX_FILENAME_LEN], char backupDir[MAX_FILENAME_LEN]);
void copyFile(char sourcePath[MAX_FILENAME_LEN], char destPath[MAX_FILENAME_LEN]);

int main() {

    // get input from user
    char fileName[MAX_FILENAME_LEN];
    char backupDir[MAX_FILENAME_LEN];
    printf("Enter the name of the file to backup: ");
    scanf("%s", fileName);
    printf("Enter the directory to save the backup file: ");
    scanf("%s", backupDir);

    // backup the file
    int result = backupFile(fileName, backupDir);

    // print output to user
    if (result == 0) {
        printf("File backup successful!\n");
    } else {
        printf("File backup failed.\n");
    }

    return 0;
}

/**
 * Function that copies a file from source path to destination path. 
 * Uses binary mode to copy in chunks of 1024 bytes at a time.
 */
void copyFile(char sourcePath[MAX_FILENAME_LEN], char destPath[MAX_FILENAME_LEN]) {
    FILE *source; 
    FILE *dest; 
    char buffer[1024]; 
    size_t bytesRead; 

    // open files in binary mode
    source = fopen(sourcePath, "rb");
    dest = fopen(destPath, "wb");

    if (source == NULL) {
        printf("Error opening source file.\n");
        exit(1);
    }

    if (dest == NULL) {
        printf("Error opening destination file.\n");
        exit(1);
    }

    // copy file in 1024 byte chunks
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source))) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    // close files
    fclose(source);
    fclose(dest);
}

/**
 * Function that creates a backup of a file with the given filename
 * in the specified directory.
 */
int backupFile(char fileName[MAX_FILENAME_LEN], char backupDir[MAX_FILENAME_LEN]) {

    // create file paths
    char sourcePath[MAX_FILENAME_LEN + 3] = "./";
    strcat(sourcePath, fileName);
    char destPath[MAX_FILENAME_LEN + MAX_FILESIZE] = "";
    strcat(destPath, backupDir);
    strcat(destPath, "/");

    // create backup filename
    char backupFileName[MAX_FILENAME_LEN + 5] = "";
    strcat(backupFileName, fileName);
    strcat(backupFileName, ".bak");

    // check if backup file already exists
    char existingBackupPath[MAX_FILENAME_LEN + MAX_FILESIZE] = "";
    strcat(existingBackupPath, backupDir);
    strcat(existingBackupPath, "/");
    strcat(existingBackupPath, backupFileName);
    FILE *existingBackupFile;
    if ((existingBackupFile = fopen(existingBackupPath, "r"))) {
        fclose(existingBackupFile);
        printf("Backup file already exists. Overwrite? (y/n): ");
        char overwrite;
        scanf(" %c", &overwrite);
        if (overwrite != 'y') {
            return 1;
        } else {
            remove(existingBackupPath);
        }
    }

    // create backup file and copy contents from original file
    strcat(destPath, backupFileName);
    copyFile(sourcePath, destPath);

    return 0;
}