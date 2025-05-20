//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backup_system()
{
    char source_file[256];
    char destination_file[256];
    FILE *source_file_ptr;
    FILE *destination_file_ptr;

    printf("Enter the source file name: ");
    scanf("%s", source_file);

    printf("Enter the destination file name: ");
    scanf("%s", destination_file);

    source_file_ptr = fopen(source_file, "r");
    if (source_file_ptr == NULL)
    {
        printf("Error opening source file.\n");
        exit(1);
    }

    destination_file_ptr = fopen(destination_file, "w");
    if (destination_file_ptr == NULL)
    {
        printf("Error opening destination file.\n");
        fclose(source_file_ptr);
        exit(1);
    }

    char buffer[1024];
    int bytes_read;

    while ((bytes_read = fread(buffer, 1, 1024, source_file_ptr)) > 0)
    {
        fwrite(buffer, 1, bytes_read, destination_file_ptr);
    }

    fclose(source_file_ptr);
    fclose(destination_file_ptr);

    printf("File backup complete.\n");
}

int main()
{
    backup_system();

    return 0;
}