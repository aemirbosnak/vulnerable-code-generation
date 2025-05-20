//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 255
#define MAX_NUMBER_OF_FILES 1000

typedef struct FileEntry
{
    char filename[MAX_FILE_NAME_LENGTH];
    long size;
    time_t last_modified_time;
} FileEntry;

FileEntry files[MAX_NUMBER_OF_FILES];

void backup_file(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return;
    }

    long file_size = 0;
    while (!feof(file))
    {
        file_size++;
        fseek(file, file_size, SEEK_CUR);
    }

    files[files[MAX_NUMBER_OF_FILES].size].size = file_size;
    strcpy(files[files[MAX_NUMBER_OF_FILES].size].filename, filename);
    files[files[MAX_NUMBER_OF_FILES].size].last_modified_time = time(NULL);

    fclose(file);
}

int main()
{
    backup_file("my_file.txt");
    backup_file("another_file.doc");

    for (int i = 0; i < MAX_NUMBER_OF_FILES; i++)
    {
        if (files[i].filename[0] != '\0')
        {
            printf("File: %s, Size: %ld, Last Modified: %s\n", files[i].filename, files[i].size, ctime(&files[i].last_modified_time));
        }
    }

    return 0;
}