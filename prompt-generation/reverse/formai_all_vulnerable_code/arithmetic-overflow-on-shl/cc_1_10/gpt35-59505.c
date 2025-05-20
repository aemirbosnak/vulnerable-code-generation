//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BUFFER_SIZE 8192

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("File not found\n");
        return 1;
    }

    uint8_t buffer[BUFFER_SIZE];
    size_t read_count;
    size_t offset = 0;
    uint32_t tag;
    uint32_t length;
    uint32_t value;

    while ((read_count = fread(buffer, 1, BUFFER_SIZE, file))) {
        for (size_t i = 0; i < read_count; ) {
            tag = (buffer[i] << 24) | (buffer[i+1] << 16) | (buffer[i+2] << 8) | buffer[i+3];
            i += 4;
            length = (buffer[i] << 24) | (buffer[i+1] << 16) | (buffer[i+2] << 8) | buffer[i+3];
            i += 4;

            if (length > 4) {
                printf("Tag: %08X\nOffset: %08lX\nLength: %lu bytes\n\n", tag, offset + i - 8, length);
                i += length - 8;
            } else {
                value = 0;
                for (size_t j = 0; j < length; j++) {
                    value |= buffer[i+j] << (8*(length-j-1));
                }
                printf("Tag: %08X\nOffset: %08lX\nLength: %lu bytes\nValue: %08X\n\n", tag, offset + i - 8, length, value);
                i += length;
            }
        }
        offset += read_count;
    }

    fclose(file);
    return 0;
}