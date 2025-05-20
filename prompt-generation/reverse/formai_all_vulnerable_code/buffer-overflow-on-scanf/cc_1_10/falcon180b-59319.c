//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 100 // 100 MB

// Function to create a backup of the file
void createBackup(FILE* file, char* backupFile) {
    char buffer[MAX_FILE_SIZE];
    int bytesRead;

    // Open backup file for writing
    FILE* backup = fopen(backupFile, "wb");
    if (backup == NULL) {
        printf("Error creating backup file.\n");
        exit(1);
    }

    // Read file and write to backup file
    while ((bytesRead = fread(buffer, 1, MAX_FILE_SIZE, file)) > 0) {
        fwrite(buffer, 1, bytesRead, backup);
    }

    // Close files
    fclose(file);
    fclose(backup);
}

// Function to restore the file from backup
void restoreFile(FILE* backup, FILE* file) {
    char buffer[MAX_FILE_SIZE];
    int bytesRead;

    // Open file for writing
    file = fopen(file, "wb");
    if (file == NULL) {
        printf("Error restoring file.\n");
        exit(1);
    }

    // Read backup file and write to file
    while ((bytesRead = fread(buffer, 1, MAX_FILE_SIZE, backup)) > 0) {
        fwrite(buffer, 1, bytesRead, file);
    }

    // Close files
    fclose(backup);
    fclose(file);
}

int main() {
    char file[100], backupFile[100];

    // Get file name from user
    printf("Enter file name: ");
    scanf("%s", file);

    // Create backup file name
    strcpy(backupFile, file);
    strcat(backupFile, ".bak");

    // Open file for reading
    FILE* f = fopen(file, "rb");
    if (f == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Create backup of file
    createBackup(f, backupFile);

    // Close file
    fclose(f);

    printf("Backup created successfully.\n");

    return 0;
}