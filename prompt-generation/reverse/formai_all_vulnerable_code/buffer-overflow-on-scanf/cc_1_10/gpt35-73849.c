//FormAI DATASET v1.0 Category: File Backup System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length for file name
#define MAX_FILE_NAME_LENGTH 100

// Function to backup a file
void backupFile(char *file_name) {
    // Get original file extension
    char *extension = strrchr(file_name, '.');
    if (!extension) {
        printf("[ERROR] File has no extension.\n");
        return;
    }

    // Create backup file name
    char backup_name[MAX_FILE_NAME_LENGTH];
    memset(backup_name, '\0', sizeof(backup_name));
    strncpy(backup_name, file_name, strlen(file_name) - strlen(extension));
    strcat(backup_name, "_backup");
    strcat(backup_name, extension);

    // Open original file
    FILE *original_file = fopen(file_name, "rb");

    if (!original_file) {
        printf("[ERROR] Could not open original file.\n");
        return;
    }

    // Open backup file
    FILE *backup_file = fopen(backup_name, "wb");

    if (!backup_file) {
        printf("[ERROR] Could not create backup file.\n");
        fclose(original_file);
        return;
    }

    // Copy contents of original file to backup file
    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), original_file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    // Close files
    fclose(original_file);
    fclose(backup_file);

    printf("File backed up successfully.\n");
}

// Main function to test backup system
int main() {
    char file_name[MAX_FILE_NAME_LENGTH];

    printf("Enter file name: ");
    scanf("%s", file_name);

    backupFile(file_name);

    return 0;
}