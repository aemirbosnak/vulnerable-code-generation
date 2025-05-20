//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the JPEG header and extract metadata
void extract_metadata(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return;
    }

    unsigned char buf[5];
    // JPEG files start with the bytes FF D8
    fread(buf, 1, 2, file);
    if (buf[0] != 0xFF || buf[1] != 0xD8) {
        printf("This is not a valid JPEG file.\n");
        fclose(file);
        return;
    }

    int width = 0, height = 0, color_components = 0;
    // Read through the JPEG file and look for the SOF0 marker
    while (fread(buf, 1, 1, file) && buf[0] != 0xDA) {
        if (buf[0] == 0xC0 || buf[0] == 0xC2) { // Check for SOF0 or SOF2
            fread(buf, 1, 3, file); // Skip length and sample precision
            height = (fgetc(file) << 8) | fgetc(file); // Read height
            width = (fgetc(file) << 8) | fgetc(file);  // Read width
            color_components = fgetc(file);             // Number of components
            
            break; // We found our metadata, break the loop
        }
        
        // Skip to the next marker
        int length = (fgetc(file) << 8) | fgetc(file);
        fseek(file, length - 2, SEEK_CUR);
    }

    fclose(file);

    // Display extracted metadata
    if (width > 0 && height > 0) {
        printf("Width: %d pixels\n", width);
        printf("Height: %d pixels\n", height);
        printf("Color Components: %d\n", color_components);
    } else {
        printf("Could not extract metadata from the JPEG file.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <path_to_jpeg_file>\n", argv[0]);
        return 1;
    }

    extract_metadata(argv[1]);

    return 0;
}