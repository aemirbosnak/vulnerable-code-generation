//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LEN];
    char *buffer = NULL;
    size_t buffer_size = 0;

    while (fgets(line, MAX_LINE_LEN, file)!= NULL) {
        if (buffer) {
            char *new_buffer = realloc(buffer, buffer_size + strlen(line));
            if (!new_buffer) {
                printf("Error: Memory allocation failed\n");
                free(buffer);
                fclose(file);
                return 1;
            }
            buffer = new_buffer;
            strcat(buffer, line);
        } else {
            buffer = strdup(line);
        }
        buffer_size += strlen(line);
    }

    fclose(file);

    unsigned char checksum = 0;
    for (int i = 0; i < buffer_size; i++) {
        checksum += buffer[i];
    }

    printf("Checksum: %02X\n", checksum);

    free(buffer);
    return 0;
}