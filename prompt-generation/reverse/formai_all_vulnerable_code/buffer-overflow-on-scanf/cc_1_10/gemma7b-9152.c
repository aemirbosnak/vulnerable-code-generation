//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char filename[256];
    char backup_filename[256];
    char buffer[MAX_BUFFER_SIZE];
    int read_bytes, write_bytes;
    FILE *file, *backup_file;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Create the backup filename
    sprintf(backup_filename, "%s.bak", filename);

    // Open the file
    file = fopen(filename, "r");

    // If the file is not opened, exit
    if (file == NULL)
    {
        printf("Error opening file: %s", filename);
        exit(1);
    }

    // Open the backup file
    backup_file = fopen(backup_filename, "w");

    // If the backup file is not opened, exit
    if (backup_file == NULL)
    {
        printf("Error opening backup file: %s", backup_filename);
        fclose(file);
        exit(1);
    }

    // Read the file in chunks of MAX_BUFFER_SIZE
    while ((read_bytes = fread(buffer, MAX_BUFFER_SIZE, 1, file)) > 0)
    {
        // Write the data to the backup file
        write_bytes = fwrite(buffer, read_bytes, 1, backup_file);

        // If there is an error writing the data, exit
        if (write_bytes < read_bytes)
        {
            printf("Error writing data to backup file: %s", backup_filename);
            fclose(file);
            fclose(backup_file);
            exit(1);
        }
    }

    // Close the file and the backup file
    fclose(file);
    fclose(backup_file);

    // Print a success message
    printf("File successfully backed up: %s", filename);

    return 0;
}