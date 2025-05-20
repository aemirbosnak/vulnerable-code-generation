//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main()
{
    char source_file_path[1024];
    char destination_file_path[1024];
    char buffer[BUFFER_SIZE];
    int read_size, write_size;
    FILE *source_file, *destination_file;
    struct stat file_stat;

    printf("Enter the source file path: ");
    scanf("%s", source_file_path);

    printf("Enter the destination file path: ");
    scanf("%s", destination_file_path);

    if ((source_file = fopen(source_file_path, "r")) == NULL)
    {
        perror("Error opening source file");
        exit(1);
    }

    if ((destination_file = fopen(destination_file_path, "w")) == NULL)
    {
        perror("Error opening destination file");
        fclose(source_file);
        exit(1);
    }

    stat(source_file_path, &file_stat);
    write_size = file_stat.st_size;

    while ((read_size = read(source_file, buffer, BUFFER_SIZE)) > 0)
    {
        write(destination_file, buffer, read_size);
    }

    fclose(source_file);
    fclose(destination_file);

    printf("File backup complete.\n");

    return 0;
}