//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: synchronous
#include <stdio.h>

#define WIDTH 100 // Maximum width of the ASCII art in characters

// Structure representing an RGB color
typedef struct {
    unsigned char r, g, b;
} RGBColor;

// Calculate the brightness of a color
int brightness(RGBColor color) {
    return (color.r + color.g + color.b) / 3;
}

// Convert a brightness value to an ASCII character
char brightness2ascii(int brightness) {
    char ascii_chars[] = " .:-=+*#%@";
    int num_chars = sizeof(ascii_chars) / sizeof(ascii_chars[0]);
    int char_index = brightness * num_chars / 256;
    return ascii_chars[char_index];
}

// Read an image from a binary file in BMP format
RGBColor** read_bmp(char* filename, int* width_out, int* height_out) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("ERROR: Could not open file '%s'\n", filename);
        return NULL;
    }
    
    // Read header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);
    if (header[0] != 'B' || header[1] != 'M') {
        printf("ERROR: Not a BMP file\n");
        fclose(file);
        return NULL;
    }
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bits_per_pixel = *(int*)&header[28];
    if (bits_per_pixel != 24) {
        printf("ERROR: Only 24-bit BMP images are supported\n");
        fclose(file);
        return NULL;
    }
    int pixel_data_offset = *(int*)&header[10];
    
    // Read pixel data
    int row_size_bytes = (width * 3 + 3) & ~3; // row size rounded up to multiple of 4 bytes
    RGBColor** image = malloc(height * sizeof(RGBColor*));
    for (int y = 0; y < height; y++) {
        image[y] = malloc(width * sizeof(RGBColor));
        for (int x = 0; x < width; x++) {
            RGBColor color;
            fread(&color.b, 1, 1, file);
            fread(&color.g, 1, 1, file);
            fread(&color.r, 1, 1, file);
            image[y][x] = color;
        }
        for (int i = 0; i < row_size_bytes - width*3; i++) {
            unsigned char dummy;
            fread(&dummy, 1, 1, file); // padding bytes
        }
    }
    
    fclose(file);
    *width_out = width;
    *height_out = height;
    return image;
}

// Free memory allocated by read_bmp function
void free_image(RGBColor** image, int height) {
    for (int y = 0; y < height; y++) {
        free(image[y]);
    }
    free(image);
}

// Convert an RGB image to ASCII art
void convert_to_ascii(RGBColor** image, int width, int height) {
    int char_width = WIDTH;
    int char_height = height * WIDTH / width;
    if (char_height > 2*char_width) {
        char_height = 2*char_width;
        char_width = width * char_height / height;
    }
    for (int y_char = 0; y_char < char_height; y_char++) {
        int y_pixel = y_char * height / char_height;
        for (int x_char = 0; x_char < char_width; x_char++) {
            int x_pixel = x_char * width / char_width;
            RGBColor color = image[y_pixel][x_pixel];
            int b = brightness(color);
            char c = brightness2ascii(b);
            printf("%c", c);
        }
        printf("\n");
    }
}

// Main program
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename.bmp>\n", argv[0]);
        return 0;
    }
    char* filename = argv[1];
    int width, height;
    RGBColor** image = read_bmp(filename, &width, &height);
    if (!image) {
        return -1;
    }
    convert_to_ascii(image, width, height);
    free_image(image, height);
    return 0;
}