//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LEN 100
#define BACKUP_FILE_EXTENSION ".bak"

// Function to create a backup of a file
void create_backup(char* file_name) {
    time_t current_time;
    char backup_file_name[MAX_FILE_NAME_LEN];
    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, BACKUP_FILE_EXTENSION);

    // Get current time
    current_time = time(NULL);

    // Convert current time to string format
    char* time_str = ctime(&current_time);

    // Remove newline character from time string
    time_str[strcspn(time_str, "\n")] = '\0';

    // Append time string to backup file name
    strcat(backup_file_name, time_str);

    // Create backup file
    FILE* backup_file = fopen(backup_file_name, "w");
    if (backup_file == NULL) {
        printf("Error creating backup file %s\n", backup_file_name);
        exit(1);
    }

    // Open original file for reading
    FILE* original_file = fopen(file_name, "r");
    if (original_file == NULL) {
        printf("Error opening original file %s\n", file_name);
        exit(1);
    }

    // Copy contents of original file to backup file
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), original_file)!= NULL) {
        fputs(buffer, backup_file);
    }

    // Close files
    fclose(original_file);
    fclose(backup_file);

    printf("Backup file %s created successfully\n", backup_file_name);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    // Create backup of file
    create_backup(argv[1]);

    return 0;
}