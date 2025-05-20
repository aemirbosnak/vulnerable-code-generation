//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <output_file>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *output_file = argv[2];

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        printf("Error getting file size: %s\n", filename);
        return 1;
    }

    char *buffer = malloc(sb.st_size);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    int bytes_read = 0;
    while (bytes_read < sb.st_size) {
        int bytes_to_read = BUFFER_SIZE;
        if (bytes_to_read > sb.st_size - bytes_read) {
            bytes_to_read = sb.st_size - bytes_read;
        }

        int bytes_read_this_time = read(fd, buffer + bytes_read, bytes_to_read);
        if (bytes_read_this_time == -1) {
            printf("Error reading file: %s\n", filename);
            return 1;
        }
        bytes_read += bytes_read_this_time;
    }

    close(fd);

    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error creating output file: %s\n", output_file);
        return 1;
    }

    fwrite(buffer, sb.st_size, 1, output);
    fclose(output);

    free(buffer);

    printf("File recovery successful!\n");

    return 0;
}