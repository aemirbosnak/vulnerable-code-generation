//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 100
#define JPEG_HEADER_SIZE 20
#define PNG_HEADER_SIZE 8
#define BMP_HEADER_SIZE 54

void extract_jpeg_metadata(FILE *file) {
    unsigned char header[JPEG_HEADER_SIZE];
    fread(header, sizeof(unsigned char), JPEG_HEADER_SIZE, file);
    int width = (header[0x60] << 8) + header[0x61];
    int height = (header[0x5E] << 8) + header[0x5F];
    printf("JPEG Image\n");
    printf("Width: %d, Height: %d\n", width, height);
}

void extract_png_metadata(FILE *file) {
    unsigned char header[PNG_HEADER_SIZE];
    fread(header, sizeof(unsigned char), PNG_HEADER_SIZE, file);
    int width = (header[16] << 24) + (header[17] << 16) + (header[18] << 8) + header[19];
    int height = (header[20] << 24) + (header[21] << 16) + (header[22] << 8) + header[23];
    printf("PNG Image\n");
    printf("Width: %d, Height: %d\n", width, height);
}

void extract_bmp_metadata(FILE *file) {
    unsigned char header[BMP_HEADER_SIZE];
    fread(header, sizeof(unsigned char), BMP_HEADER_SIZE, file);
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    printf("BMP Image\n");
    printf("Width: %d, Height: %d\n", width, height);
}

void extract_metadata(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return;
    }

    unsigned char buffer[8];
    fread(buffer, sizeof(unsigned char), 8, file);
    fseek(file, 0, SEEK_SET); // Reset file pointer to beginning

    if (buffer[0] == 0xFF && buffer[1] == 0xD8) {
        extract_jpeg_metadata(file);
    } else if (buffer[0] == 0x89 && strncmp((const char *)buffer + 1, "PNG", 3) == 0) {
        extract_png_metadata(file);
    } else if (buffer[0] == 'B' && buffer[1] == 'M') {
        extract_bmp_metadata(file);
    } else {
        printf("Unsupported file format or not an image file\n");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    extract_metadata(argv[1]);
    
    return EXIT_SUCCESS;
}