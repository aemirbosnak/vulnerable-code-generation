//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

int main(int argc, char *argv[])
{
    FILE *fp;
    char *line;
    size_t len;
    ssize_t nread;
    int i, count;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    line = malloc(MAX_LOG_SIZE);
    if (line == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    count = 0;
    while ((nread = getline(&line, &len, fp)) != -1) {
        if (nread == (MAX_LOG_SIZE - 1)) {
            fprintf(stderr, "Line too long: %s\n", line);
        } else {
            for (i = 0; i < nread; i++) {
                if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' ||
                    line[i] == 'o' || line[i] == 'u') {
                    count++;
                }
            }
        }
    }

    free(line);
    fclose(fp);

    printf("%d vowels found\n", count);

    return EXIT_SUCCESS;
}