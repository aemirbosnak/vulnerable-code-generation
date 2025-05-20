//FormAI DATASET v1.0 Category: File Backup System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_BACKUP_FILES 5 // Number of backup files to keep

void generateBackupFileName(char *file, char *backupFile, int version) {
    char *extension = strrchr(file, '.'); // Get the file extension
    int len = strlen(file) - strlen(extension);
    strncpy(backupFile, file, len); // Copy the file name without the extension
    sprintf(backupFile + len, "_v%d%s", version, extension); // Append version number and extension
}

int main() {
    char fileName[MAX_FILE_NAME_SIZE];
    printf("Enter the name of the file to backup: ");
    scanf("%s", fileName);

    FILE *originalFile = fopen(fileName, "rb"); // Open the original file in binary read mode
    if (originalFile == NULL) {
        printf("Error: Unable to open file %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    fseek(originalFile, 0, SEEK_END); // Move to the end of the file
    int fileSize = ftell(originalFile); // Get the size of the file
    fseek(originalFile, 0, SEEK_SET); // Move back to the start of the file

    char backupFiles[MAX_BACKUP_FILES][MAX_FILE_NAME_SIZE];
    int backupFileVersions[MAX_BACKUP_FILES];
    int numBackupFiles = 0;

    // Find and load all existing backup files for the original file
    char *extension = strrchr(fileName, '.'); // Get the file extension
    char backupFileRegex[MAX_FILE_NAME_SIZE];
    int len = strlen(fileName) - strlen(extension);
    strncpy(backupFileRegex, fileName, len); // Copy the file name without the extension
    sprintf(backupFileRegex + len, "_v*%s", extension); // Append wildcard and extension
    char command[MAX_FILE_NAME_SIZE + 20]; // Max command length for Unix platform
    sprintf(command, "ls %s", backupFileRegex); // Prepare command to list backup files
    FILE *output = popen(command, "r"); // Execute the command and open the output stream
    if (output != NULL) {
        char backupFile[MAX_FILE_NAME_SIZE];
        while (fgets(backupFile, MAX_FILE_NAME_SIZE, output) != NULL) {
            backupFile[strcspn(backupFile, "\n")] = '\0'; // Remove trailing newline
            char *versionStr = strrchr(backupFile, 'v') + 1; // Get the version number from the file name
            int version = atoi(versionStr);
            if (version != 0) { // Only load backup files that have a valid version number
                strcpy(backupFiles[numBackupFiles], backupFile);
                backupFileVersions[numBackupFiles] = version;
                numBackupFiles++;
            }
        }
        pclose(output); // Close the output stream
    }
    
    // Sort backup files in descending order of version number
    for (int i = 0; i < numBackupFiles - 1; i++) {
        for (int j = i + 1; j < numBackupFiles; j++) {
            if (backupFileVersions[j] > backupFileVersions[i]) {
                int tempVersion = backupFileVersions[i];
                backupFileVersions[i] = backupFileVersions[j];
                backupFileVersions[j] = tempVersion;
                char tempFile[MAX_FILE_NAME_SIZE];
                strcpy(tempFile, backupFiles[i]);
                strcpy(backupFiles[i], backupFiles[j]);
                strcpy(backupFiles[j], tempFile);
            }
        }
    }

    // Backup the original file with a version number
    time_t now = time(NULL);
    char backupFileName[MAX_FILE_NAME_SIZE];
    generateBackupFileName(fileName, backupFileName, backupFileVersions[0] + 1);
    FILE *backupFile = fopen(backupFileName, "wb"); // Open the backup file in binary write mode
    if (backupFile == NULL) {
        printf("Error: Unable to create backup file %s\n", backupFileName);
        exit(EXIT_FAILURE);
    }

    // Copy the original file to the backup file
    unsigned char buffer[1024];
    while (1) {
        size_t bytesRead = fread(buffer, 1, sizeof(buffer), originalFile);
        if (bytesRead == 0) {
            if (feof(originalFile)) { // End of file
                break;
            } else if (ferror(originalFile)) { // Error reading file
                printf("Error: Unable to read file %s\n", fileName);
                exit(EXIT_FAILURE);
            }
        }
        fwrite(buffer, 1, bytesRead, backupFile);
    }

    fclose(originalFile);
    fclose(backupFile);

    // Remove excess backup files if necessary
    if (numBackupFiles >= MAX_BACKUP_FILES) {
        for (int i = MAX_BACKUP_FILES; i < numBackupFiles; i++) {
            sprintf(command, "rm %s", backupFiles[i]); // Prepare command to remove backup file
            system(command); // Execute the command
        }
    }

    printf("Backup successful: %s\n", backupFileName);
    
    return 0;
}