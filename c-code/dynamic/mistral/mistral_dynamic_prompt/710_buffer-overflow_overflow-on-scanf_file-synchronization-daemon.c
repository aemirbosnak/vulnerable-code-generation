#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void main(int argc, char **argv) {
    char buffer[10];
    int fd;
    char *filename;

    if (argc != 3) {
        printf("Usage: ./sync source destination\n");
        return;
    }

    filename = argv[1];
    scanf("%s", buffer);

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    write(fd, buffer, strlen(buffer));

    filename = argv[2];
    scanf("%s", buffer);
    fd = open(filename, O_RDONLY);

    char input[1000];
    read(fd, input, 1000);
    printf("Data synced: %s\n", input);
}
