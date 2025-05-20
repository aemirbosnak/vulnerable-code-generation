//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define HEADER_SIZE 54  // BMP header size
#define MAX_IMG_SIZE 1024 // Maximum image size

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;

typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset_data;
    uint32_t size_header;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bit_count;
    uint32_t compression;
    uint32_t size_image;
    int32_t x_ppm;
    int32_t y_ppm;
    uint32_t colors_used;
    uint32_t colors_important;
} BMPHeader;

void invertColors(Pixel *image, int width, int height) {
    int totalPixels = width * height;
    for (int i = 0; i < totalPixels; i++) {
        image[i].red = 255 - image[i].red;
        image[i].green = 255 - image[i].green;
        image[i].blue = 255 - image[i].blue;
    }
}

void readImage(const char* filename, BMPHeader *header, Pixel *image) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    fread(header, sizeof(BMPHeader), 1, file);
    
    // Check if it's a BMP file
    if (header->type != 0x4D42) {
        fprintf(stderr, "Not a BMP file.\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fseek(file, header->offset_data, SEEK_SET);
    fread(image, sizeof(Pixel), header->width * header->height, file);
    fclose(file);
}

void writeImage(const char* filename, BMPHeader header, Pixel *image) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Could not write to file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fwrite(&header, sizeof(BMPHeader), 1, file);
    fseek(file, header.offset_data, SEEK_SET);
    fwrite(image, sizeof(Pixel), header.width * header.height, file);
    
    fclose(file);
}

void printInstructions() {
    printf("Sherlock Holmes Image Editor\n");
    printf("Use the following commands to edit your BMP image:\n");
    printf("1. Invert Colors\n");
    printf("2. Exit\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    BMPHeader header;
    Pixel image[MAX_IMG_SIZE * MAX_IMG_SIZE];   

    // Read the original image
    readImage(argv[1], &header, image);
    
    // Adjust the header for the BMP format specifics
    printf("Loaded '%s' with dimensions: %dx%d\n", argv[1], header.width, header.height);
    
    char choice;
    while (1) {
        printInstructions();
        printf("Choose an option (1 or 2): ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                // Perform the image transformation
                invertColors(image, header.width, header.height);
                printf("Colors inverted!\n");
                break;
            case '2':
                // Exit the editor
                printf("Exiting the editor.\n");
                writeImage(argv[2], header, image);
                printf("Saved the edited image as '%s'\n", argv[2]);
                return EXIT_SUCCESS;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return EXIT_SUCCESS;
}