//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <jpeglib.h>
#include <math.h>

#define MAX_WIDTH 100 // Maximum output width for ASCII art
#define MAX_HEIGHT 100 // Maximum output height for ASCII art

// Character array for ASCII representation
const char* ascii_chars = "@%#*+=-:. "; // Dark to light characters

// Structure to hold pixel data
typedef struct {
    unsigned char r, g, b;
} Pixel;

// Function to read the JPEG image
int read_jpeg_file(const char* filename, Pixel image[MAX_HEIGHT][MAX_WIDTH], int* width, int* height) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    
    FILE* infile = fopen(filename, "rb");
    if (!infile) {
        fprintf(stderr, "Could not open JPEG file %s\n", filename);
        return -1;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);
    
    *width = cinfo.output_width;
    *height = cinfo.output_height;

    // Ensure the dimensions fit within MAX_WIDTH and MAX_HEIGHT
    if (*width > MAX_WIDTH || *height > MAX_HEIGHT) {
        fprintf(stderr, "Image dimensions exceed the maximum size.\n");
        jpeg_destroy_decompress(&cinfo);
        fclose(infile);
        return -1;
    }

    // Read scanlines
    JSAMPROW row_pointer[1];
    int row_stride = *width * cinfo.output_components;
    for (int y = 0; y < *height; y++) {
        row_pointer[0] = (unsigned char*) malloc(row_stride);
        jpeg_read_scanlines(&cinfo, row_pointer, 1);
        for (int x = 0; x < *width; x++) {
            image[y][x].r = row_pointer[0][x * 3];
            image[y][x].g = row_pointer[0][x * 3 + 1];
            image[y][x].b = row_pointer[0][x * 3 + 2];
        }
        free(row_pointer[0]);
    }

    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(infile);
    return 0;
}

// Function to convert the pixel to an ASCII character
char pixel_to_ascii(Pixel pixel) {
    // Compute brightness based on RGB values
    double brightness = (0.299 * pixel.r + 0.587 * pixel.g + 0.114 * pixel.b) / 255.0;
    int index = (int)(brightness * (strlen(ascii_chars) - 1));
    return ascii_chars[index];
}

// Function to convert the image to ASCII art
void convert_to_ascii(Pixel image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            char ascii_char = pixel_to_ascii(image[y][x]);
            putchar(ascii_char);
        }
        putchar('\n');
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <jpeg-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Pixel image[MAX_HEIGHT][MAX_WIDTH];
    int width, height;

    // Read the JPEG file
    if (read_jpeg_file(argv[1], image, &width, &height) != 0) {
        return EXIT_FAILURE;
    }

    // Print the header in a Romeo and Juliet style
    printf("Behold, fair lords and ladies, upon this canvas bright,\n");
    printf("Where pixels dance in colors, brought to life in ASCII light.\n\n");
    
    // Convert the image to ASCII art
    convert_to_ascii(image, width, height);
    
    // Farewell to the noble audience
    printf("\nThus drawn by light reflected, in this humble digital art,\n");
    printf("We bid thee goodbye, keep thy heart where beauty shall never part.\n");

    return EXIT_SUCCESS;
}