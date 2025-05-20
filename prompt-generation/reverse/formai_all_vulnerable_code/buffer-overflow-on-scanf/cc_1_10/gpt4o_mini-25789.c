//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define MAX_FILENAME_LENGTH 256

void create_backup(const char *source_file, const char *backup_file) {
    FILE *source = fopen(source_file, "rb");
    if (source == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE *backup = fopen(backup_file, "wb");
    if (backup == NULL) {
        perror("Error creating backup file");
        fclose(source);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, sizeof(char), bytes, backup);
    }

    printf("Backup created: %s\n", backup_file);
    
    fclose(source);
    fclose(backup);
}

void backup_files(const char *directory) {
    char command[MAX_FILENAME_LENGTH * 2];
    
    // Loop through files in the specified directory
    snprintf(command, sizeof(command), "ls %s", directory);
    FILE *ls_output = popen(command, "r");
    if (ls_output == NULL) {
        perror("Error executing ls command");
        return;
    }

    char file_name[MAX_FILENAME_LENGTH];
    while (fgets(file_name, sizeof(file_name), ls_output) != NULL) {
        // Remove trailing new line character
        file_name[strcspn(file_name, "\n")] = 0;

        // Create backup file name
        char backup_file[MAX_FILENAME_LENGTH];
        snprintf(backup_file, sizeof(backup_file), "%s/%s.bak", directory, file_name);
        
        // Create a backup
        create_backup(file_name, backup_file);
    }

    pclose(ls_output);
}

int main() {
    char directory[MAX_FILENAME_LENGTH];

    printf("Welcome to the C File Backup System!\n");
    printf("Please enter the directory to backup files from: ");
    scanf("%s", directory);

    // Validate if the directory exists
    struct stat statbuf;
    if (stat(directory, &statbuf) != 0 || !S_ISDIR(statbuf.st_mode)) {
        fprintf(stderr, "Directory '%s' does not exist or is not a directory.\n", directory);
        return EXIT_FAILURE;
    }

    backup_files(directory);
    printf("Backup process completed successfully.\n");
    return EXIT_SUCCESS;
}