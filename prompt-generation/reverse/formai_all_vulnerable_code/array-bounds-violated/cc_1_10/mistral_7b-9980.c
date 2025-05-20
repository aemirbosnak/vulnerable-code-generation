//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_LINES 10

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    int fd;
    char line[MAX_LINE_SIZE];
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        die("Failed to open file.");
    }

    fp = fdopen(fd, "r");
    if (!fp) {
        die("Failed to convert file descriptor to FILE *.");
    }

    int num_lines = 0;
    while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        num_lines++;

        size_t len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        if (strlen(line) > MAX_LINE_SIZE - 1) {
            fprintf(stderr, "Line %d is too long.\n", num_lines);
            continue;
        }

        printf("Line %d: %s\n", num_lines, line);
    }

    if (ferror(fp)) {
        die("Error reading file.");
    }

    if (fclose(fp) == EOF) {
        die("Failed to close file.");
    }

    close(fd);

    printf("Read %d lines from file.\n", num_lines);

    return 0;
}