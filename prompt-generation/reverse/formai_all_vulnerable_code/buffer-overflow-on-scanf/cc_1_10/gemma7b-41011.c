//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void backup_file(char *filename)
{
    FILE *file_ptr = fopen(filename, "r");
    if (file_ptr == NULL)
    {
        perror("Error opening file");
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    int bytes_read = 0;

    // Read file contents into buffer
    while ((bytes_read = fread(buffer, MAX_BUFFER_SIZE, 1, file_ptr)) > 0)
    {
        // Write buffer contents to backup file
        FILE *backup_file_ptr = fopen("backup.txt", "a");
        if (backup_file_ptr == NULL)
        {
            perror("Error opening backup file");
            return;
        }

        fwrite(buffer, bytes_read, 1, backup_file_ptr);
        fclose(backup_file_ptr);
    }

    fclose(file_ptr);
}

int main()
{
    char filename[256];

    // Get file name from user
    printf("Enter file name: ");
    scanf("%s", filename);

    // Backup file
    backup_file(filename);

    // Print confirmation message
    printf("File backed up successfully.\n");

    return 0;
}