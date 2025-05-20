//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define PIPE_SIZE 1024

int main(int argc, char *argv[]) {
    char buf[PIPE_SIZE];
    int fd[2], status;

    if (argc!= 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fd[0] = pipe(fd)) == -1) {
        perror("pipe()");
        exit(EXIT_FAILURE);
    }

    if ((fd[1] = pipe(fd)) == -1) {
        perror("pipe()");
        exit(EXIT_FAILURE);
    }

    if (dup2(fd[1], 1) == -1) {
        perror("dup2()");
        exit(EXIT_FAILURE);
    }

    if (dup2(fd[0], 0) == -1) {
        perror("dup2()");
        exit(EXIT_FAILURE);
    }

    if (close(fd[0]) == -1) {
        perror("close()");
        exit(EXIT_FAILURE);
    }

    if (close(fd[1]) == -1) {
        perror("close()");
        exit(EXIT_FAILURE);
    }

    FILE *source_file = fopen(argv[1], "r");
    FILE *destination_file = fopen(argv[2], "w");

    while (fread(buf, sizeof(char), PIPE_SIZE, source_file) > 0) {
        if (write(1, buf, strlen(buf)) == -1) {
            perror("write()");
            exit(EXIT_FAILURE);
        }
    }

    if (fclose(source_file) == -1) {
        perror("fclose()");
        exit(EXIT_FAILURE);
    }

    if (fclose(destination_file) == -1) {
        perror("fclose()");
        exit(EXIT_FAILURE);
    }

    close(fd[0]);
    close(fd[1]);
    return 0;
}