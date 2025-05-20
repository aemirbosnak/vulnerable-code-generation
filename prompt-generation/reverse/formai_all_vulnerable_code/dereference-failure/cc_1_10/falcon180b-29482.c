//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINE_LEN 1024

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char filename[MAX_LINE_LEN];
    strcpy(filename, argv[1]);

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    struct stat st;
    fstat(fd, &st);

    char *buffer = (char *) malloc(st.st_size + 1);
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }

    int bytes_read = read(fd, buffer, st.st_size);
    if (bytes_read!= st.st_size) {
        fprintf(stderr, "Error reading file %s\n", filename);
        exit(1);
    }

    buffer[st.st_size] = '\0';

    int line_num = 1;
    char *line = strtok(buffer, "\n");
    while (line!= NULL) {
        printf("%d: %s", line_num, line);
        line_num++;
        line = strtok(NULL, "\n");
    }

    free(buffer);
    close(fd);

    return 0;
}