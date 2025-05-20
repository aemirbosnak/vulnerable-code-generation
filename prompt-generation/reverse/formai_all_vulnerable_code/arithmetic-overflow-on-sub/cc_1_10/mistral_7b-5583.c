//MISTRAL-7B DATASET v1.0 Category: File Synchronizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define DEFAULT_BUFFER_SIZE 8192

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    char buffer1[DEFAULT_BUFFER_SIZE], buffer2[DEFAULT_BUFFER_SIZE];
    int buffer_size = DEFAULT_BUFFER_SIZE;
    size_t bytes_read;
    int identical = 1;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <file1> <file2> <buffer_size>\n", argv[0]);
        return EXIT_FAILURE;
    }

    fp1 = fopen(argv[1], "rb");
    if (!fp1) die("Could not open file1");

    fp2 = fopen(argv[2], "rb");
    if (!fp2) {
        fclose(fp1);
        die("Could not open file2");
    }

    if (argc > 3 && strtol(argv[3], NULL, 10) > 0) {
        buffer_size = atoi(argv[3]);
    }

    do {
        bytes_read = fread(buffer1, 1, buffer_size, fp1);
        if (bytes_read == 0) break;

        bytes_read = fread(buffer2, 1, buffer_size, fp2);
        if (bytes_read != bytes_read) { // Error occurred
            fprintf(stderr, "Error reading file2\n");
            identical = 0;
            break;
        }

        if (bytes_read && memcmp(buffer1, buffer2, bytes_read) != 0) {
            fprintf(stderr, "Files differ\n");
            identical = 0;
            break;
        }
    } while (bytes_read == buffer_size);

    if (feof(fp1) && feof(fp2)) {
        if (identical) printf("Files are identical\n");
        else printf("Files differ\n");
    } else {
        fprintf(stderr, "Unexpected EOF\n");
        identical = 0;
    }

    fclose(fp1);
    fclose(fp2);

    return identical ? EXIT_SUCCESS : EXIT_FAILURE;
}