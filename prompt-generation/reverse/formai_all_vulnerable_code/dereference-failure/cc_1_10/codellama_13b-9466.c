//Code Llama-13B DATASET v1.0 Category: Checksum Calculator ; Style: Ken Thompson
/*
 * A C Checksum Calculator program in the style of Ken Thompson
 *
 * This program calculates the checksum of a file using the XOR method.
 *
 * Usage:
 *      checksum <file>
 *
 * Example:
 *      checksum myfile.txt
 *
 * Output:
 *      0x12345678
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    uint32_t checksum = 0;
    FILE *fp;
    char *filename;
    char *buf;
    size_t len;
    size_t i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    filename = argv[1];

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    buf = malloc(BUFSIZ);
    if (buf == NULL) {
        fprintf(stderr, "Error allocating buffer: %s\n", strerror(errno));
        fclose(fp);
        return EXIT_FAILURE;
    }

    while ((len = fread(buf, 1, BUFSIZ, fp)) > 0) {
        for (i = 0; i < len; i++) {
            checksum ^= buf[i];
        }
    }

    fclose(fp);
    free(buf);

    printf("Checksum: 0x%08x\n", checksum);

    return EXIT_SUCCESS;
}