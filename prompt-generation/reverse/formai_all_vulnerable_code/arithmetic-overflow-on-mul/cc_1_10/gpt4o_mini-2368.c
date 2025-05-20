//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1) // Ensuring structure packing
typedef struct {
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset_data;
} BMPHeader;

typedef struct {
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bits_per_pixel;
    unsigned int compression;
    unsigned int size_image;
    int x_pixels_per_meter;
    int y_pixels_per_meter;
    unsigned int colors_used;
    unsigned int colors_important;
} BMPInfoHeader;

#pragma pack(pop) // Resetting structure packing

void invertColors(unsigned char *data, int width, int height) {
    for (int i = 0; i < width * height * 3; i++) {
        data[i] = 255 - data[i]; // Invert RGB values
    }
}

void toGrayscale(unsigned char *data, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        unsigned char r = data[i * 3 + 2]; // Red
        unsigned char g = data[i * 3 + 1]; // Green
        unsigned char b = data[i * 3];     // Blue

        // Calculate grayscale value
        unsigned char gray = (unsigned char)(0.299 * r + 0.587 * g + 0.114 * b);
        data[i * 3] = data[i * 3 + 1] = data[i * 3 + 2] = gray; // Set RGB to gray
    }
}

void loadBMP(char *filename, BMPHeader *header, BMPInfoHeader *info_header, unsigned char **data) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fread(header, sizeof(BMPHeader), 1, file);
    fread(info_header, sizeof(BMPInfoHeader), 1, file);
    
    if (header->type != 0x4D42) {
        fprintf(stderr, "Not a BMP file\n");
        exit(1);
    }

    *data = malloc(info_header->size_image);
    fseek(file, header->offset_data, SEEK_SET);
    fread(*data, info_header->size_image, 1, file);
    fclose(file);
}

void saveBMP(char *filename, BMPHeader header, BMPInfoHeader info_header, unsigned char *data) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error saving file");
        exit(1);
    }

    fwrite(&header, sizeof(BMPHeader), 1, file);
    fwrite(&info_header, sizeof(BMPInfoHeader), 1, file);
    fseek(file, header.offset_data, SEEK_SET);
    fwrite(data, info_header.size_image, 1, file);
    fclose(file);
}

void displayMenu() {
    printf("Welcome to the Super Simple BMP Image Editor!\n");
    printf("Choose an option:\n");
    printf("1. Invert Colors\n");
    printf("2. Convert to Grayscale\n");
    printf("3. Exit\n");
}

int main() {
    BMPHeader header;
    BMPInfoHeader info_header;
    unsigned char *data = NULL;

    char input_filename[100];
    char output_filename[100];

    printf("Enter the BMP file name to edit: ");
    scanf("%s", input_filename);

    loadBMP(input_filename, &header, &info_header, &data);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                invertColors(data, info_header.width, info_header.height);
                printf("Colors inverted!\n");
                break;
            case 2:
                toGrayscale(data, info_header.width, info_header.height);
                printf("Converted to grayscale!\n");
                break;
            case 3:
                break; // Exit the loop
            default:
                printf("Invalid option. Try again!\n");
        }

        if (choice == 1 || choice == 2) {
            printf("Enter the output file name to save: ");
            scanf("%s", output_filename);
            saveBMP(output_filename, header, info_header, data);
            printf("Image saved successfully as %s!\n", output_filename);
        }
    } while (choice != 3);

    free(data);
    printf("Thanks for using the Editor! Goodbye!\n");
    return 0;
}