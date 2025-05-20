//Falcon-180B DATASET v1.0 Category: File handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_LINE_SIZE 1024

char *filename = "example.txt";
int file_descriptor;
char buffer[MAX_LINE_SIZE];

void read_file(void)
{
    int bytes_read;
    int line_count = 0;
    char *line_buffer = malloc(MAX_LINE_SIZE);

    if (line_buffer == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    if ((file_descriptor = open(filename, O_RDONLY)) == -1)
    {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while ((bytes_read = read(file_descriptor, buffer, MAX_LINE_SIZE)) > 0)
    {
        buffer[bytes_read - 1] = '\0';
        strcat(line_buffer, buffer);
        line_count++;

        if (line_count == 10)
        {
            printf("The first 10 lines of the file are:\n\n%s", line_buffer);
            free(line_buffer);
            line_buffer = malloc(MAX_LINE_SIZE);
            line_count = 0;
        }
    }

    if (bytes_read == -1)
    {
        printf("Error: Unable to read from file.\n");
        exit(1);
    }

    if (line_count > 0)
    {
        printf("The last %d lines of the file are:\n\n%s", line_count, line_buffer);
    }

    free(line_buffer);
    close(file_descriptor);
}

int main(void)
{
    read_file();

    return 0;
}