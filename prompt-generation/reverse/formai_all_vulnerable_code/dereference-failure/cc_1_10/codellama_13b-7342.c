//Code Llama-13B DATASET v1.0 Category: System administration ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *path = argv[1];
    char *file = argv[2];
    char *data = argv[3];
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }
    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        perror("Error getting file size");
        exit(1);
    }
    char *buffer = malloc(sb.st_size);
    if (buffer == NULL) {
        perror("Error allocating memory");
        exit(1);
    }
    if (read(fd, buffer, sb.st_size) == -1) {
        perror("Error reading file");
        exit(1);
    }
    if (close(fd) == -1) {
        perror("Error closing file");
        exit(1);
    }
    FILE *fp = fopen(file, "w");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    if (fwrite(data, 1, strlen(data), fp) == -1) {
        perror("Error writing to file");
        exit(1);
    }
    if (fclose(fp) == -1) {
        perror("Error closing file");
        exit(1);
    }
    return 0;
}