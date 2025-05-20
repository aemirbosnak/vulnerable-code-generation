//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define MAX_SIZE 1024

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE* f = fopen(argv[1], "rb");
    if (f == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    char* buffer = malloc(size);
    if (buffer == NULL) {
        printf("Error allocating memory for buffer\n");
        fclose(f);
        return 1;
    }

    fread(buffer, 1, size, f);
    fclose(f);

    // Get the file type by looking at the first few bytes
    char* filetype = NULL;
    if (memcmp(buffer, "JFIF", 4) == 0) {
        filetype = "JPEG";
    } else if (memcmp(buffer, "PNG", 3) == 0) {
        filetype = "PNG";
    } else if (memcmp(buffer, "GIF", 3) == 0) {
        filetype = "GIF";
    } else if (memcmp(buffer, "BMP", 2) == 0) {
        filetype = "BMP";
    } else {
        filetype = "Unknown";
    }

    printf("File type: %s\n", filetype);

    // Get the width and height of the image by looking at the EXIF data
    uint16_t width = 0;
    uint16_t height = 0;
    if (strcmp(filetype, "JPEG") == 0) {
        // Find the start of the EXIF data
        char* exif_start = buffer + 2;
        while (exif_start < buffer + size) {
            if (memcmp(exif_start, "Exif", 4) == 0) {
                break;
            }
            exif_start++;
        }

        // If we found the EXIF data, read the width and height
        if (exif_start < buffer + size) {
            width = *(uint16_t*)(exif_start + 20);
            height = *(uint16_t*)(exif_start + 22);
        }
    } else if (strcmp(filetype, "PNG") == 0) {
        // Find the start of the IHDR chunk
        char* ihdr_start = buffer + 8;
        while (ihdr_start < buffer + size) {
            if (memcmp(ihdr_start, "IHDR", 4) == 0) {
                break;
            }
            ihdr_start++;
        }

        // If we found the IHDR chunk, read the width and height
        if (ihdr_start < buffer + size) {
            width = *(uint32_t*)(ihdr_start + 4);
            height = *(uint32_t*)(ihdr_start + 8);
        }
    } else if (strcmp(filetype, "GIF") == 0) {
        // Read the width and height from the header
        width = *(uint16_t*)(buffer + 6);
        height = *(uint16_t*)(buffer + 8);
    } else if (strcmp(filetype, "BMP") == 0) {
        // Read the width and height from the header
        width = *(uint32_t*)(buffer + 18);
        height = *(uint32_t*)(buffer + 22);
    }

    printf("Width: %d\n", width);
    printf("Height: %d\n", height);

    free(buffer);

    return 0;
}