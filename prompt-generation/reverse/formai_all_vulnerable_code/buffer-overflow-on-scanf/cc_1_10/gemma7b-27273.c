//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char filename[256];
    char filename_backup[256];
    FILE *file_ptr;
    FILE *file_ptr_backup;
    struct stat file_stat;
    int file_size;
    char *buffer;
    char *buffer_backup;
    int i = 0;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Create a backup filename
    sprintf(filename_backup, "%s.bak", filename);

    // Open the file
    file_ptr = fopen(filename, "r");

    // Get the file size
    fstat(fileno(file_ptr), &file_stat);
    file_size = file_stat.st_size;

    // Allocate memory for the buffer
    buffer = malloc(file_size);

    // Read the file into the buffer
    fread(buffer, file_size, 1, file_ptr);

    // Close the file
    fclose(file_ptr);

    // Open a backup file
    file_ptr_backup = fopen(filename_backup, "w");

    // Write the buffer to the backup file
    fwrite(buffer, file_size, 1, file_ptr_backup);

    // Close the backup file
    fclose(file_ptr_backup);

    // Free the memory
    free(buffer);

    // Print a success message
    printf("File synchronized successfully.\n");

    return 0;
}