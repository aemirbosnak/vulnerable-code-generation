//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024
#define HEADER_SIZE 20

// Function to read the JPEG header
void read_jpeg_header(FILE *file, unsigned char *header) {
    fread(header, 1, HEADER_SIZE, file);
}

// Function to extract basic metadata
void extract_metadata(unsigned char *header) {
    // JPEG marker detection
    if (header[0] != 0xFF || header[1] != 0xD8) {
        printf("This is not a valid JPEG file\n");
        return;
    }

    // Width and Height extraction from the JPEG header
    size_t idx = 0x10; // Start of SOF0 section (Start of Frame 0)
    while (header[idx] != 0xC0 && header[idx] != 0xC2) {
        idx++;
    }

    int height = header[idx + 1] << 8 | header[idx + 2];
    int width = header[idx + 3] << 8 | header[idx + 4];

    printf("Metadata extracted:\n");
    printf("Image Width: %d px\n", width);
    printf("Image Height: %d px\n", height);

    // Dummy additional metadata for fun
    printf("Magic number: %x\n", header[0]);
    printf("Mysterious byte at offset 4: %x\n", header[4]);
    printf("Counting bytes bursting in colors: %d\n", height * width);
}

// Function to display usage
void display_usage() {
    printf("Usage: ./metadata_extractor <image_file>\n");
}

// Main function that drives the puzzle
int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_usage();
        return EXIT_FAILURE;
    }

    // File handling
    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Could not open file '%s'.\n", argv[1]);
        return EXIT_FAILURE;
    }

    unsigned char header[HEADER_SIZE];
    read_jpeg_header(file, header);
    extract_metadata(header);

    fclose(file);
    return EXIT_SUCCESS;
}