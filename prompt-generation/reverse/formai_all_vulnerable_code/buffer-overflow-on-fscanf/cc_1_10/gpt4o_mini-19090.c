//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_WIDTH  100
#define ASCII_HEIGHT 30
#define MAX_NIGHT_MODE 100

const char *grayscale_chars = "@#S%?*+;:,.";

void convert_to_ascii(const char *input_image, int width, int height) {
    FILE *fp = fopen(input_image, "rb");
    if (!fp) {
        perror("Cannot open file");
        exit(1);
    }

    // Simplistic header read for PPM format
    char header[3];
    int img_width, img_height, max_val;
    fscanf(fp, "%s\n%d %d\n%d\n", header, &img_width, &img_height, &max_val);

    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported image format: %s\n", header);
        fclose(fp);
        return;
    }

    unsigned char *image_data = (unsigned char *)malloc(img_width * img_height * 3);
    fread(image_data, sizeof(unsigned char), img_width * img_height * 3, fp);
    fclose(fp);

    int new_width = ASCII_WIDTH;
    int new_height = ASCII_HEIGHT;
    char ascii_image[ASCII_HEIGHT][ASCII_WIDTH + 1];

    // Scaling factors
    double width_scale = (double)img_width / new_width;
    double height_scale = (double)img_height / new_height;

    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            int orig_x = (int)(x * width_scale);
            int orig_y = (int)(y * height_scale);
            int pixel_index = (orig_y * img_width + orig_x) * 3;

            // Calculate grayscale value
            unsigned char r = image_data[pixel_index];
            unsigned char g = image_data[pixel_index + 1];
            unsigned char b = image_data[pixel_index + 2];
            int gray = (r + g + b) / 3;

            // Map to ASCII character
            int char_index = (gray * (strlen(grayscale_chars) - 1)) / 255;
            ascii_image[y][x] = grayscale_chars[char_index];
        }
        ascii_image[y][new_width] = '\0'; // Null-terminate the string
    }

    free(image_data);

    // Print the ASCII art
    printf("\n");
    for (int y = 0; y < new_height; y++) {
        printf("%s\n", ascii_image[y]);
    }
}

void save_ascii_to_file(const char *output_file, char ascii_image[ASCII_HEIGHT][ASCII_WIDTH + 1]) {
    FILE *fp = fopen(output_file, "w");
    if (!fp) {
        perror("Cannot open output file");
        return;
    }

    for (int y = 0; y < ASCII_HEIGHT; y++) {
        fprintf(fp, "%s\n", ascii_image[y]);
    }
    
    fclose(fp);
}

void print_intro() {
    printf("===================================\n");
    printf("   C Image to ASCII Art Converter  \n");
    printf("===================================\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: %s <input_image.ppm> [output_file.txt]\n", argv[0]);
        exit(1);
    }

    const char *input_image = argv[1];
    const char *output_file = (argc == 3) ? argv[2] : "output.txt";

    print_intro();
    
    char ascii_image[ASCII_HEIGHT][ASCII_WIDTH + 1];
    
    // Convert the image to ASCII
    convert_to_ascii(input_image, ASCII_WIDTH, ASCII_HEIGHT);
    
    // Optionally save to file
    save_ascii_to_file(output_file, ascii_image);
    
    printf("ASCII art saved to %s\n", output_file);
    
    return 0;
}