//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    char filename[256] = "";
    char buffer[4096] = "";
    int file_descriptor = -1;
    int read_bytes = -1;
    int file_size = -1;
    struct stat file_stat;

    printf("Enter the name of the file you want to recover:");
    scanf("%s", filename);

    if (stat(filename, &file_stat) == 0) {
        file_size = file_stat.st_size;
    } else {
        perror("Error stat()ing file");
        return 1;
    }

    if ((file_descriptor = open(filename, O_RDONLY)) == -1) {
        perror("Error opening file");
        return 1;
    }

    read_bytes = read(file_descriptor, buffer, file_size);

    if (read_bytes == -1) {
        perror("Error reading file");
        return 1;
    }

    close(file_descriptor);

    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    fwrite(buffer, read_bytes, 1, file);

    fclose(file);

    printf("File recovered successfully: %s\n", filename);

    return 0;
}