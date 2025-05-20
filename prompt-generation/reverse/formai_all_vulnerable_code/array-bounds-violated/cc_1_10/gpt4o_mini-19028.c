//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define JPG_HEADER_SIZE 512

typedef struct {
    uint16_t marker;            // JPEG marker
    uint16_t length;            // Length of the segment
    uint16_t width;             // Image width
    uint16_t height;            // Image height
} JPEGMetadata;

void readBytes(FILE *file, void *buffer, size_t size) {
    if (fread(buffer, size, 1, file) != 1) {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }
}

void extractJPEGMetadata(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    unsigned char header[JPG_HEADER_SIZE];
    fread(header, sizeof(unsigned char), JPG_HEADER_SIZE, file);

    // Skip to the start of the DQT, SOF0, or other markers
    size_t offset = 0;
    while (offset < JPG_HEADER_SIZE) {
        if (header[offset] == 0xFF) {
            uint16_t marker = (header[offset] << 8) + header[offset + 1];
            if (marker >= 0xC0 && marker <= 0xC3) { // SOF0, SOF1, SOF2, SOF3
                JPEGMetadata metadata;
                metadata.marker = marker;
                metadata.length = (header[offset + 2] << 8) + header[offset + 3];
                metadata.height = (header[offset + 5] << 8) + header[offset + 6];
                metadata.width = (header[offset + 7] << 8) + header[offset + 8];

                printf("JPEG Metadata for %s:\n", filename);
                printf("  Image Width: %d pixels\n", metadata.width);
                printf("  Image Height: %d pixels\n", metadata.height);
                fclose(file);
                return;
            }
            offset += 2 + (header[offset + 2] << 8) + header[offset + 3]; // Move to next marker
        } else {
            offset++;
        }
    }

    printf("No SOF0/1/2/3 marker found in %s\n", filename);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image_file.jpg>\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        printf("Processing file: %s\n", argv[i]);
        extractJPEGMetadata(argv[i]);
    }

    return EXIT_SUCCESS;
}