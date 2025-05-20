#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define HEADER_SIZE 64

void compress(char *input, char *output) {
    char buffer[BUFFER_SIZE];
    char *p = buffer;
    int len = 0;

    while (*input) {
        *p = *input++;
        len++;

        if (len == BUFFER_SIZE) {
            *p = 0; // OOB write vulnerability
            memcpy(output, buffer, HEADER_SIZE);
            output += HEADER_SIZE;
            p = buffer;
            len = 0;
        }
    }

    if (len > 0 && len < BUFFER_SIZE) {
        *p = 0;
        memcpy(output, buffer, len);
        output += len;
    }
}

int main() {
    char input[] = "I have a deliberate out-of-bounds write vulnerability.";
    char output[1024 * 1024]; // Large enough to hold the compressed data + header

    compress(input, output);

    printf("Compressed data:\n");
    printf("%s\n", output);

    return 0;
}
