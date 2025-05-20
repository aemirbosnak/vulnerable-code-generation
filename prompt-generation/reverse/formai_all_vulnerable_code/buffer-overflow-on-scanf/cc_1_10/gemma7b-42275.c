//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

int main()
{
    // Define the directory where the backups will be stored
    char backup_dir[256];

    // Get the current directory
    getcwd(backup_dir, sizeof(backup_dir));

    // Append the backup directory to the end of the backup_dir string
    strcat(backup_dir, "/backup");

    // Create the backup directory if it does not already exist
    if (stat(backup_dir, NULL) != 0)
    {
        mkdir(backup_dir, 0755);
    }

    // Define the file to be backed up
    char file_to_backup[256];

    // Get the file to be backed up from the user
    printf("Enter the file to be backed up: ");
    scanf("%s", file_to_backup);

    // Open the file to be backed up
    FILE *file_ptr = fopen(file_to_backup, "r");

    // Check if the file is open
    if (file_ptr == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    // Define the buffer for the file data
    char buffer[MAX_BUFFER_SIZE];

    // Read the file data from the file
    int read_bytes = read(fileno(file_ptr), buffer, MAX_BUFFER_SIZE);

    // Check if the file data was read successfully
    if (read_bytes == -1)
    {
        printf("Error reading file.\n");
        exit(1);
    }

    // Write the file data to the backup file
    FILE *backup_file = fopen(backup_dir, "a");

    // Check if the backup file is open
    if (backup_file == NULL)
    {
        printf("Error writing file.\n");
        exit(1);
    }

    fwrite(buffer, read_bytes, 1, backup_file);

    // Close the file pointers
    fclose(file_ptr);
    fclose(backup_file);

    // Print a confirmation message
    printf("File successfully backed up.\n");

    return 0;
}