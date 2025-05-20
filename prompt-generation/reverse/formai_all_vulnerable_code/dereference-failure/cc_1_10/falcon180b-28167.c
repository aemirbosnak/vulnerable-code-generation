//Falcon-180B DATASET v1.0 Category: System administration ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE_LEN 1024

void print_file_info(const char *filename) {
    struct stat st;
    stat(filename, &st);

    printf("File name: %s\n", filename);
    printf("File size: %ld bytes\n", (long int)st.st_size);
    printf("Last modified: %s", ctime(&st.st_mtime));
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [file] [command]\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *command = argv[2];

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fd)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (strcmp(token, command) == 0) {
                printf("Command found in file\n");
                break;
            }
            token = strtok(NULL, " ");
        }
    }

    close(fd);

    return 0;
}