//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_FILENAME_LENGTH 256
#define BUFFER_SIZE 1024

// Function prototypes
void display_file_contents(const char *filename);
void synchronize_files(const char *source, const char *destination);
int file_exists(const char *filename);
void create_file_backup(const char *filename);

// Main function
int main() {
    char source[MAX_FILENAME_LENGTH], destination[MAX_FILENAME_LENGTH];

    printf("Enter source file path: ");
    scanf("%s", source);

    printf("Enter destination file path: ");
    scanf("%s", destination);

    // Check if source file exists
    if (!file_exists(source)) {
        printf("Source file does not exist.\n");
        return 1;
    }

    // Backup destination file if it exists
    if (file_exists(destination)) {
        create_file_backup(destination);
    }

    // Display contents of source file
    printf("Contents of source file:\n");
    display_file_contents(source);

    // Synchronize files
    synchronize_files(source, destination);
    printf("Synchronization complete.\n");

    return 0;
}

// Check if a file exists
int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

// Create a backup of a file
void create_file_backup(const char *filename) {
    char backup_filename[MAX_FILENAME_LENGTH];
    sprintf(backup_filename, "%s.bak", filename);
    rename(filename, backup_filename);
    printf("Backup created: %s\n", backup_filename);
}

// Display the contents of a file
void display_file_contents(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

// Synchronize the source file with the destination file
void synchronize_files(const char *source, const char *destination) {
    FILE *src = fopen(source, "r");
    if (!src) {
        printf("Error opening source file: %s\n", source);
        return;
    }

    FILE *dest = fopen(destination, "w");
    if (!dest) {
        printf("Error opening destination file: %s\n", destination);
        fclose(src);
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, src) != NULL) {
        fputs(buffer, dest);
    }

    fclose(src);
    fclose(dest);
}

// Additional functionality to check for file modifications
void check_for_modifications(const char *source, const char *destination) {
    struct stat source_stat, dest_stat;

    stat(source, &source_stat);
    stat(destination, &dest_stat);

    if (difftime(source_stat.st_mtime, dest_stat.st_mtime) > 0) {
        printf("Source file has been modified. Synchronizing...\n");
        synchronize_files(source, destination);
    } else {
        printf("No modifications detected in source file.\n");
    }
}