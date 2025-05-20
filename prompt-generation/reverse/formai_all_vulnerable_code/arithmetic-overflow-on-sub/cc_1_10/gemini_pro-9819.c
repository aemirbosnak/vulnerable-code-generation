//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1024

// Structure to store file information
typedef struct {
    char name[MAX_FILE_SIZE];
    char path[MAX_FILE_SIZE];
    unsigned long size;
    time_t modified;
} FileInfo;

// Array of file information
FileInfo files[MAX_FILES];

// Number of files in the array
int num_files = 0;

// Function to add a file to the array
void add_file(char *name, char *path, unsigned long size, time_t modified) {
    // Check if the array is full
    if (num_files >= MAX_FILES) {
        printf("Error: The array is full.\n");
        return;
    }

    // Copy the file information to the array
    strcpy(files[num_files].name, name);
    strcpy(files[num_files].path, path);
    files[num_files].size = size;
    files[num_files].modified = modified;

    // Increment the number of files in the array
    num_files++;
}

// Function to compare two files by their modified time
int compare_files(const void *a, const void *b) {
    FileInfo *file1 = (FileInfo *)a;
    FileInfo *file2 = (FileInfo *)b;

    return file1->modified - file2->modified;
}

// Function to backup the files to a specified directory
void backup_files(char *backup_dir) {
    // Create the backup directory if it doesn't exist
    if (mkdir(backup_dir, 0755) != 0) {
        printf("Error: Could not create the backup directory.\n");
        return;
    }

    // Iterate over the files in the array
    for (int i = 0; i < num_files; i++) {
        // Open the file
        FILE *file = fopen(files[i].path, "rb");
        if (file == NULL) {
            printf("Error: Could not open the file %s.\n", files[i].path);
            continue;
        }

        // Get the file size
        fseek(file, 0, SEEK_END);
        unsigned long size = ftell(file);
        fseek(file, 0, SEEK_SET);

        // Allocate a buffer to hold the file data
        char *buffer = malloc(size);
        if (buffer == NULL) {
            printf("Error: Could not allocate a buffer for the file %s.\n", files[i].path);
            fclose(file);
            continue;
        }

        // Read the file data into the buffer
        fread(buffer, size, 1, file);
        fclose(file);

        // Create the backup file
        char backup_file[MAX_FILE_SIZE];
        sprintf(backup_file, "%s/%s", backup_dir, files[i].name);
        FILE *backup = fopen(backup_file, "wb");
        if (backup == NULL) {
            printf("Error: Could not create the backup file %s.\n", backup_file);
            free(buffer);
            continue;
        }

        // Write the file data to the backup file
        fwrite(buffer, size, 1, backup);
        fclose(backup);

        // Free the buffer
        free(buffer);
    }

    // Print a success message
    printf("Files backed up successfully to %s.\n", backup_dir);
}

// Main function
int main() {
    // Add some files to the array
    add_file("file1.txt", "/home/user/file1.txt", 1024, time(NULL));
    add_file("file2.txt", "/home/user/file2.txt", 2048, time(NULL) - 60);
    add_file("file3.txt", "/home/user/file3.txt", 4096, time(NULL) - 120);

    // Sort the files by their modified time
    qsort(files, num_files, sizeof(FileInfo), compare_files);

    // Backup the files to a specified directory
    backup_files("/home/user/backup");

    return 0;
}