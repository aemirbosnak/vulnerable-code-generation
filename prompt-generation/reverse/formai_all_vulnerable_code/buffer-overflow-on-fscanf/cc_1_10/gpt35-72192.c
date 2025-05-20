//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_char_for_pixel(int pixel);

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input_image> <output_file>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    FILE *fp = fopen(input_file, "rb");
    if (!fp) {
        printf("Could not open input file: %s\n", input_file);
        return 1;
    }

    // Read header data
    char magic[2];
    int width, height, max_value;
    fscanf(fp, "%s\n%d %d\n%d\n", magic, &width, &height, &max_value);

    // Check that the magic number is P6 (binary RGB)
    if (strcmp(magic, "P6") != 0) {
        printf("Invalid input file: %s\n", input_file);
        fclose(fp);
        return 1;
    }

    // Allocate memory for the pixel data
    unsigned char *pixel_data = (unsigned char *) malloc(width * height * 3 * sizeof(unsigned char));
    if (!pixel_data) {
        printf("Could not allocate memory for pixel data.\n");
        fclose(fp);
        return 1;
    }

    // Read the pixel data
    if (fread(pixel_data, sizeof(unsigned char), width * height * 3, fp) != width * height * 3) {
        printf("Error reading pixel data from input file: %s\n", input_file);
        fclose(fp);
        free(pixel_data);
        return 1;
    }

    fclose(fp);

    fp = fopen(output_file, "w");
    if (!fp) {
        printf("Could not open output file: %s\n", output_file);
        free(pixel_data);
        return 1;
    }

    // Write the ASCII art
    fprintf(fp, "/*\n"
                " * This is an Alan Touring style ASCII art representation of the image.\n"
                " */\n\n");
    fprintf(fp, "const int OUTPUT_WIDTH = %d;\n", width);
    fprintf(fp, "const int OUTPUT_HEIGHT = %d;\n", height);
    fprintf(fp, "\nconst char *output =\n");

    for (int y = 0; y < height; y++) {
        fprintf(fp, "\"");

        for (int x = 0; x < width; x++) {
            int pixel_index = (y * width + x) * 3;
            int r = (int) pixel_data[pixel_index];
            int g = (int) pixel_data[pixel_index + 1];
            int b = (int) pixel_data[pixel_index + 2];
            int gray_value = (r + g + b) / 3;

            char *character = get_char_for_pixel(gray_value);
            fprintf(fp, "%s", character);
        }

        fprintf(fp, "\\n\"\n");
    }

    fprintf(fp, ";");

    fclose(fp);
    free(pixel_data);

    printf("Done! ASCII art stored in file: %s\n", output_file);

    return 0;
}

char *get_char_for_pixel(int pixel) {
    static const char *character_gradient = "#@%@%*+=-:. ";

    int characters = strlen(character_gradient);
    int gradient_step = 255 / characters;

    int index = pixel / gradient_step;

    if (index >= characters) {
        index = characters - 1;
    }

    return (char *) &character_gradient[index];
}