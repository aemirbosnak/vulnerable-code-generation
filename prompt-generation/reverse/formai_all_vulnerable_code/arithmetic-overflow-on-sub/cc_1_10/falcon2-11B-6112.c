//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    int fd;
    struct stat file_stat;
    char filename[100];

    sprintf(filename, "%s", argv[1]);

    if ((fd = open(filename, O_RDONLY)) < 0) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    if (fstat(fd, &file_stat) < 0) {
        fprintf(stderr, "Error getting file stats: %s\n", strerror(errno));
        exit(1);
    }

    char buffer[MAX_LINE_LENGTH];
    char *line;

    while (1) {
        if (read(fd, buffer, file_stat.st_size - 1) < 0) {
            fprintf(stderr, "Error reading file: %s\n", strerror(errno));
            exit(1);
        }

        buffer[file_stat.st_size - 1] = '\0';

        line = strtok(buffer, "\n");
        while (line!= NULL) {
            printf("%s\n", line);
            line = strtok(NULL, "\n");
        }
    }

    return 0;
}