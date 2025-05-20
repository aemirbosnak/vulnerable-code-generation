//FormAI DATASET v1.0 Category: File Backup System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 40
#define MAX_BACKUP_FILES 3

// Struct to store file information
typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char timestamp[30];
} backup_file;

// Function to print backup files
void print_backup_files(backup_file *backup_files) {
    printf("\nBackup Files:\n");
    for (int i = 0; i < MAX_BACKUP_FILES; i++) {
        printf("%s", backup_files[i].filename);
        if (strcmp(backup_files[i].filename, "") != 0) {
            printf("\t%s", backup_files[i].timestamp);
        }
        printf("\n");
    }
}

// Function to create a backup file with timestamp
void create_backup_file(char *filename, backup_file *backup_files) {
    // Get current timestamp
    time_t current_time;
    time(&current_time);
    char timestamp[30];
    strftime(timestamp, 30, "%Y-%m-%d %H:%M:%S", localtime(&current_time));

    // Create backup file
    FILE *original_file = fopen(filename, "r");
    char backup_filename[MAX_FILENAME_LENGTH + 20];
    sprintf(backup_filename, "backup_%s_%s", timestamp, filename);
    FILE *backup_file = fopen(backup_filename, "w");

    // Copy contents from original file to backup file
    char c;
    while ((c = fgetc(original_file)) != EOF) {
        fputc(c, backup_file);
    }

    // Close files
    fclose(original_file);
    fclose(backup_file);

    // Update backup files array
    for (int i = MAX_BACKUP_FILES - 1; i > 0; i--) {
        strcpy(backup_files[i].filename, backup_files[i - 1].filename);
        strcpy(backup_files[i].timestamp, backup_files[i - 1].timestamp);
    }
    strcpy(backup_files[0].filename, backup_filename);
    strcpy(backup_files[0].timestamp, timestamp);
}

int main() {
    // Initialize backup files array
    backup_file backup_files[MAX_BACKUP_FILES];
    for (int i = 0; i < MAX_BACKUP_FILES; i++) {
        strcpy(backup_files[i].filename, "");
        strcpy(backup_files[i].timestamp, "");
    }
    
    // Get input file from user
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename to backup: ");
    scanf("%s", filename);

    // Create backup file
    create_backup_file(filename, backup_files);
    printf("\nBackup created!\n");

    // Print backup files
    print_backup_files(backup_files);

    return 0;
}