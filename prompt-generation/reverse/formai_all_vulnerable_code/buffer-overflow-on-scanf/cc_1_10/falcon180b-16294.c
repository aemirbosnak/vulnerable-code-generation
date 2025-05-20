//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: synchronous
// File Backup System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_SIZE 256
#define BACKUP_FILE_EXTENSION ".bak"

// Function to backup a file
void backup_file(char *file_name) {
    time_t current_time;
    char backup_file_name[MAX_FILE_NAME_SIZE];

    // Get current time
    current_time = time(NULL);

    // Convert current time to string
    strftime(backup_file_name, MAX_FILE_NAME_SIZE, "%Y-%m-%d_%H-%M-%S", localtime(&current_time));

    // Append backup file extension
    strcat(backup_file_name, BACKUP_FILE_EXTENSION);

    // Backup the file
    rename(file_name, backup_file_name);
}

// Function to restore a file
void restore_file(char *file_name) {
    char backup_file_name[MAX_FILE_NAME_SIZE];

    // Get backup file name
    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, BACKUP_FILE_EXTENSION);

    // Restore the file
    rename(backup_file_name, file_name);
}

// Function to prompt user for input
void prompt_user(char *prompt) {
    printf("%s", prompt);
    fflush(stdout);
    scanf("%s", prompt);
}

int main() {
    char file_name[MAX_FILE_NAME_SIZE];

    // Prompt user for file name
    printf("Enter the name of the file to backup or restore: ");
    scanf("%s", file_name);

    // Backup the file
    backup_file(file_name);
    printf("File backed up successfully.\n");

    // Prompt user for action
    char action;
    printf("Do you want to restore the file? (Y/N): ");
    scanf(" %c", &action);

    // Restore the file if user chooses to
    if (action == 'Y' || action == 'y') {
        restore_file(file_name);
        printf("File restored successfully.\n");
    }

    return 0;
}