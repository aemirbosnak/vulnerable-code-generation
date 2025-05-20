#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    unsigned char *buffer;
    long int offset = -1;

    fp = fopen("audio.wav", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    buffer = (unsigned char *)malloc(1024);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return 1;
    }

    // Out-of-bounds read
    offset = rand() % 1024;
    fread(buffer, 1, 1024, fp);
    buffer[offset] = 0xdeadbeef;

    fclose(fp);
    free(buffer);

    return 0;
}
