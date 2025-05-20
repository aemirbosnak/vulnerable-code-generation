//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_METADATA_SIZE 256

typedef struct {
    uint16_t marker; // JPEG marker
    char identifier[MAX_METADATA_SIZE]; // Metadata identifier
    char value[MAX_METADATA_SIZE]; // Metadata value
} Metadata;

void extract_metadata(FILE *file, Metadata *metadata) {
    fseek(file, 0, SEEK_SET);

    while (!feof(file)) {
        uint8_t byte = fgetc(file);
        
        if (byte == 0xFF) {
            uint8_t nextByte = fgetc(file);
            if (nextByte == 0xC0) { // Start of Frame (SOF0) marker
                fseek(file, 5, SEEK_CUR); // Skip to width/height
                uint16_t height = (fgetc(file) << 8) | fgetc(file);
                uint16_t width = (fgetc(file) << 8) | fgetc(file);
                snprintf(metadata->identifier, MAX_METADATA_SIZE, "Dimensions");
                snprintf(metadata->value, MAX_METADATA_SIZE, "%ux%u", width, height);
                break;
            }
        }
    }
}

void print_metadata(const Metadata *metadata) {
    printf("Metadata:\n");
    printf("%s: %s\n", metadata->identifier, metadata->value);
}

void cleanup_metadata(Metadata *metadata) {
    memset(metadata, 0, sizeof(Metadata));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image-file.jpg>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    Metadata metadata;
    cleanup_metadata(&metadata);
    extract_metadata(file, &metadata);
    print_metadata(&metadata);

    fclose(file);
    return 0;
}