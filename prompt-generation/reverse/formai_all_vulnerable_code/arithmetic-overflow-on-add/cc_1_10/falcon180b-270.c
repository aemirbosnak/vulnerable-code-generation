//Falcon-180B DATASET v1.0 Category: System administration ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int create_file(char* filename) {
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        printf("Error creating file\n");
        return 1;
    }
    close(fd);
    return 0;
}

int write_to_file(char* filename, char* content) {
    int fd = open(filename, O_WRONLY);
    if (fd == -1) {
        printf("Error opening file for writing\n");
        return 1;
    }
    int bytes_written = write(fd, content, strlen(content));
    if (bytes_written == -1) {
        printf("Error writing to file\n");
        return 1;
    }
    close(fd);
    return 0;
}

int read_from_file(char* filename, char** content) {
    struct stat statbuf;
    if (stat(filename, &statbuf) == -1) {
        printf("Error getting file status\n");
        return 1;
    }
    int filesize = statbuf.st_size;
    char* buffer = malloc(filesize + 1);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file for reading\n");
        free(buffer);
        return 1;
    }
    int bytes_read = read(fd, buffer, filesize);
    if (bytes_read == -1) {
        printf("Error reading from file\n");
        free(buffer);
        return 1;
    }
    buffer[bytes_read] = '\0';
    *content = buffer;
    free(buffer);
    close(fd);
    return 0;
}

int main() {
    char* filename = "test.txt";
    char* content = "Hello, world!\n";
    int ret = create_file(filename);
    if (ret!= 0) {
        return ret;
    }
    ret = write_to_file(filename, content);
    if (ret!= 0) {
        return ret;
    }
    char* read_content = NULL;
    ret = read_from_file(filename, &read_content);
    if (ret!= 0) {
        return ret;
    }
    printf("Read content: %s\n", read_content);
    free(read_content);
    return 0;
}