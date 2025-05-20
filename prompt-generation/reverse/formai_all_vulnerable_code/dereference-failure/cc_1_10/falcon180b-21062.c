//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if(argc!= 3)
    {
        printf("Usage:./program <input_file> <output_file>\n");
        exit(1);
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    int input_fd = open(input_file, O_RDONLY);
    if(input_fd == -1)
    {
        printf("Error opening input file.\n");
        exit(1);
    }

    struct stat input_stat;
    fstat(input_fd, &input_stat);

    char *buffer = malloc(BUFFER_SIZE);
    if(buffer == NULL)
    {
        printf("Error allocating memory.\n");
        exit(1);
    }

    int output_fd = open(output_file, O_CREAT | O_WRONLY);
    if(output_fd == -1)
    {
        printf("Error opening output file.\n");
        exit(1);
    }

    int total_bytes_read = 0;
    int bytes_read;
    while((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0)
    {
        total_bytes_read += bytes_read;
        if(write(output_fd, buffer, bytes_read)!= bytes_read)
        {
            printf("Error writing to output file.\n");
            exit(1);
        }
    }

    if(total_bytes_read!= input_stat.st_size)
    {
        printf("Error reading input file.\n");
        exit(1);
    }

    close(input_fd);
    close(output_fd);

    printf("Data recovery completed successfully.\n");

    return 0;
}