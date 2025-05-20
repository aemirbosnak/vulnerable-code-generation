//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;      // Bitmap signature
    unsigned int bfSize;       // Size of the BMP file
    unsigned short bfReserved1; // Reserved, must be zero
    unsigned short bfReserved2; // Reserved, must be zero
    unsigned int bfOffBits;     // Offset to pixel data
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;        // Size of information header
    int biWidth;                // Width of the image
    int biHeight;               // Height of the image
    unsigned short biPlanes;     // Number of color planes
    unsigned short biBitCount;   // Number of bits per pixel
    unsigned int biCompression;  // Compression type
    unsigned int biSizeImage;    // Image size (optional)
    int biXPelsPerMeter;         // Horizontal resolution
    int biYPelsPerMeter;         // Vertical resolution
    unsigned int biClrUsed;      // Number of colors in color palette
    unsigned int biClrImportant;  // Important colors
} BITMAPINFOHEADER;

typedef struct {
    unsigned char blue;   // Blue value
    unsigned char green;  // Green value
    unsigned char red;    // Red value
} RGBTRIPLE;
#pragma pack(pop)

void apply_grayscale(RGBTRIPLE *pixel) {
    unsigned char gray_value = (unsigned char)(0.299 * pixel->red + 0.587 * pixel->green + 0.114 * pixel->blue);
    pixel->red = gray_value;
    pixel->green = gray_value;
    pixel->blue = gray_value;
}

void apply_negative(RGBTRIPLE *pixel) {
    pixel->red = 255 - pixel->red;
    pixel->green = 255 - pixel->green;
    pixel->blue = 255 - pixel->blue;
}

void process_image(const char *input_file, const char *output_file, void (*process_pixel)(RGBTRIPLE *)) {
    FILE *f_in = fopen(input_file, "rb");
    if (f_in == NULL) {
        fprintf(stderr, "Could not open input file %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, f_in);
    if (bf.bfType != 0x4d42) {
        fprintf(stderr, "Not a BMP file\n");
        fclose(f_in);
        exit(EXIT_FAILURE);
    }

    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, f_in);
    
    // Move file pointer to the start of the pixel array
    fseek(f_in, bf.bfOffBits, SEEK_SET);

    // Allocate memory for the pixel array
    RGBTRIPLE *pixels = malloc(bi.biWidth * bi.biHeight * sizeof(RGBTRIPLE));
    if (pixels == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(f_in);
        exit(EXIT_FAILURE);
    }

    // Read pixels from the file
    fread(pixels, sizeof(RGBTRIPLE), bi.biWidth * bi.biHeight, f_in);
    fclose(f_in);

    // Process each pixel
    for (int i = 0; i < bi.biWidth * bi.biHeight; i++) {
        process_pixel(&pixels[i]);
    }

    // Open the output file for writing
    FILE *f_out = fopen(output_file, "wb");
    if (f_out == NULL) {
        fprintf(stderr, "Could not open output file %s\n", output_file);
        free(pixels);
        exit(EXIT_FAILURE);
    }

    // Write the file header and info header back to the output file
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, f_out);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, f_out);
    fwrite(pixels, sizeof(RGBTRIPLE), bi.biWidth * bi.biHeight, f_out);
    
    fclose(f_out);
    free(pixels);
    printf("Image processing complete. Output saved to %s\n", output_file);
}

void menu() {
    printf("Simple Image Editor\n");
    printf("1. Convert to Grayscale\n");
    printf("2. Convert to Negative\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    char input_file[256];
    char output_file[256];

    printf("Enter the input BMP file name: ");
    scanf("%s", input_file);

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                snprintf(output_file, sizeof(output_file), "output_grayscale.bmp");
                process_image(input_file, output_file, apply_grayscale);
                break;
            case 2:
                snprintf(output_file, sizeof(output_file), "output_negative.bmp");
                process_image(input_file, output_file, apply_negative);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}