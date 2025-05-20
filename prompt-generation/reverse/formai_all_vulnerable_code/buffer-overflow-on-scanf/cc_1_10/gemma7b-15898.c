//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    char filename[256];
    char backup_filename[256];
    int file_size;
    FILE *file_ptr;
    FILE *backup_ptr;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Get the file size
    file_size = getSize(filename);

    // Allocate memory for the backup file
    backup_filename[0] = '\0';
    backup_filename[1] = '\0';
    backup_filename[2] = 'b';
    backup_filename[3] = '\0';
    strcat(backup_filename, filename);
    backup_ptr = fopen(backup_filename, "w");

    // Open the file
    file_ptr = fopen(filename, "r");

    // Copy the file data to the backup file
    char buffer[1024];
    int read_bytes;
    while ((read_bytes = fread(buffer, 1, 1024, file_ptr)) > 0)
    {
        fwrite(buffer, 1, read_bytes, backup_ptr);
    }

    // Close the file and backup file
    fclose(file_ptr);
    fclose(backup_ptr);

    // Print a confirmation message
    printf("File backup complete.\n");

    return 0;
}

int getSize(char *filename)
{
    FILE *file_ptr;
    int size = 0;

    file_ptr = fopen(filename, "r");
    if (file_ptr)
    {
        fseek(file_ptr, 0L, SEEK_END);
        size = ftell(file_ptr);
        fclose(file_ptr);
    }

    return size;
}