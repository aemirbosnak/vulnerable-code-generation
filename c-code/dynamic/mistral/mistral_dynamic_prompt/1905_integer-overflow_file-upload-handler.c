#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define MAX_FILE_SIZE 512 // Set the maximum file size for exploitation

int main(int argc, char *argv[]) {
    char buffer[BUF_SIZE];
    char filename[100];
    int fd, size;

    if (argc != 3) {
        printf("Usage: ./upload <filename> <filesize>\n");
        return 1;
    }

    strcpy(filename, argv[1]);
    size = atoi(argv[2]);

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd < 0) {
        perror("Error opening file");
        return 2;
    }

    printf("File creation successful. File size limit: %d bytes.\n", MAX_FILE_SIZE);

    int bytes_read;
    while ((bytes_read = read(0, buffer, BUF_SIZE)) > 0) {
        write(fd, buffer, bytes_read);
        if ((size - MAX_FILE_SIZE) < bytes_read) {
            printf("Buffer overflow detected.\n");
            // Uncomment this line for integer overflow
            //size = 0;
        }
        if (size - MAX_FILE_SIZE <= 0) break;
    }

    close(fd);
    return 0;
}
