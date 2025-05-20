//Falcon-180B DATASET v1.0 Category: Error handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <filename> <string>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *string = argv[2];

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        close(fd);
        return 1;
    }

    if (!S_ISREG(st.st_mode)) {
        fprintf(stderr, "File is not a regular file.\n");
        close(fd);
        return 1;
    }

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, fd)!= NULL) {
        if (strstr(buffer, string)!= NULL) {
            printf("Found string: %s\n", string);
        }
    }

    if (ferror(stdin)) {
        perror("fgets");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}