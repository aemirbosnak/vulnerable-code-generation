//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main()
{
    // Declare variables
    FILE *source_file, *target_file;
    char source_file_name[50], target_file_name[50];
    char buffer[BUFFER_SIZE];
    int num_bytes_read;

    // Get the source and target file names from the user
    printf("Enter the name of the source file: ");
    scanf("%s", source_file_name);
    printf("Enter the name of the target file: ");
    scanf("%s", target_file_name);

    // Open the source file
    source_file = fopen(source_file_name, "r");
    if (source_file == NULL)
    {
        printf("Error opening the source file.\n");
        return 1;
    }

    // Open the target file
    target_file = fopen(target_file_name, "w");
    if (target_file == NULL)
    {
        printf("Error opening the target file.\n");
        return 1;
    }

    // Read the source file and write to the target file
    printf("Copying data from %s to %s...\n", source_file_name, target_file_name);
    while ((num_bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0)
    {
        fwrite(buffer, 1, num_bytes_read, target_file);
    }

    // Close the source and target files
    fclose(source_file);
    fclose(target_file);

    printf("File backup complete!\n");
    return 0;
}