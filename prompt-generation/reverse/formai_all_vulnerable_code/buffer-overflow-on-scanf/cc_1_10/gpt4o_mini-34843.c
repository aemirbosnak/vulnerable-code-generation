//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define MAX_FILENAME_LENGTH 256
#define BACKUP_EXTENSION ".bak"

// Function to check if a file exists
int file_exists(const char *filename) {
    struct stat buffer;   
    return (stat(filename, &buffer) == 0);
}

// Function to leave a friendly message
void welcome_message() {
    printf("********************************************\n");
    printf("           Welcome to File Backup System    \n");
    printf("********************************************\n");
}

// Function to backup the file
void backup_file(const char *source_file, const char *backup_file) {
    FILE *source, *destination;
    char buffer[BUFFER_SIZE];
    size_t bytes;

    source = fopen(source_file, "rb");
    if (source == NULL) {
        printf("Error: Could not open source file %s for reading.\n", source_file);
        return;
    }

    destination = fopen(backup_file, "wb");
    if (destination == NULL) {
        printf("Error: Could not open backup file %s for writing.\n", backup_file);
        fclose(source);
        return;
    }

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    printf("Backup created successfully: %s\n", backup_file);

    fclose(source);
    fclose(destination);
}

// Function to get the backup filename
void generate_backup_filename(const char *filename, char *backup_file) {
    strcpy(backup_file, filename);
    strcat(backup_file, BACKUP_EXTENSION);
}

int main() {
    welcome_message();

    char filename[MAX_FILENAME_LENGTH];
    char backup_filename[MAX_FILENAME_LENGTH + sizeof(BACKUP_EXTENSION)];

    printf("Please enter the filename you want to backup: ");
    scanf("%s", filename);

    if (!file_exists(filename)) {
        printf("Error: The file '%s' does not exist. Please check and try again.\n", filename);
        return EXIT_FAILURE;
    }

    generate_backup_filename(filename, backup_filename);
    
    backup_file(filename, backup_filename);

    printf("Backup process completed!\n");
    printf("Enjoy your day!\n");

    return EXIT_SUCCESS;
}