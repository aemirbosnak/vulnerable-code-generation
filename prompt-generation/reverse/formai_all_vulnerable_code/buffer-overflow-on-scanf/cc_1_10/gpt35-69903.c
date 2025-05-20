//FormAI DATASET v1.0 Category: File Backup System ; Style: calm
#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_LEN 100   // Maximum file name length
#define MAX_NUM_FILES 10       // Maximum number of files to be backed up
#define MAX_FILE_SIZE 1000000  // Maximum file size in bytes

int main() {
    char filenames[MAX_NUM_FILES][MAX_FILENAME_LEN];  // Array to hold file names
    int num_files;  // Number of files to be backed up
    char backup_filename[MAX_FILENAME_LEN];  // Name of backup file
    FILE* backup_file;  // Pointer to backup file
    FILE* source_file;  // Pointer to source file
    char file_buffer[MAX_FILE_SIZE];  // Buffer to read/write files
    int i, j;  // Loop counters

    // Get input from user
    printf("Enter number of files to backup (up to %d): ", MAX_NUM_FILES);
    scanf("%d", &num_files);
    printf("Enter names of files to backup:\n");
    for (i = 0; i < num_files; i++) {
        scanf("%s", filenames[i]);
    }
    printf("Enter name of backup file: ");
    scanf("%s", backup_filename);

    // Open backup file for writing
    backup_file = fopen(backup_filename, "wb");
    if (backup_file == NULL) {
        printf("Error: Could not open backup file for writing.\n");
        return 1;
    }

    // Write number of files to backup to backup file
    fwrite(&num_files, sizeof(int), 1, backup_file);

    // Loop through files to backup
    for (i = 0; i < num_files; i++) {
        // Open source file for reading
        source_file = fopen(filenames[i], "rb");
        if (source_file == NULL) {
            printf("Error: Could not open source file %s.\n", filenames[i]);
            fclose(backup_file);
            return 1;
        }

        // Write file name length and file name to backup file
        int filename_len = strlen(filenames[i]);
        fwrite(&filename_len, sizeof(int), 1, backup_file);
        fwrite(filenames[i], sizeof(char), filename_len, backup_file);

        // Loop through source file and write to backup file
        int bytes_read = 0;
        while ((bytes_read = fread(file_buffer, sizeof(char), MAX_FILE_SIZE, source_file)) > 0) {
            fwrite(file_buffer, sizeof(char), bytes_read, backup_file);
        }

        // Close source file
        fclose(source_file);
    }

    // Close backup file
    fclose(backup_file);

    printf("Backup complete.\n");

    return 0;
}