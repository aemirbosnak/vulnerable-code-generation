//FormAI DATASET v1.0 Category: Image Editor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_COMMAND_LENGTH 256

/* Struct definitions for image file */
typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

/* Function to read image from file */
Image* read_image(char* filename) {
    FILE* infile = fopen(filename, "rb");
    if (!infile) {
        printf("Failed to open image file %s\n", filename);
        return NULL;
    }

    // read the width and height from file
    int width, height;
    fread(&width, sizeof(int), 1, infile);
    fread(&height, sizeof(int), 1, infile);

    // allocate memory for image data
    unsigned char* data = (unsigned char*)malloc(width * height * 3);
    if (!data) {
        printf("Failed to allocate memory for image data\n");
        return NULL;
    }

    // read image data from file
    fread(data, sizeof(unsigned char), width * height * 3, infile);

    // create the image struct
    Image* img = (Image*)malloc(sizeof(Image));
    if (!img) {
        printf("Failed to allocate memory for image struct\n");
        return NULL;
    }
    img->width = width;
    img->height = height;
    img->data = data;

    // close the file and return the image struct
    fclose(infile);
    return img;
}

/* Function to write image to file */
void write_image(Image* img, char* filename) {
    FILE* outfile = fopen(filename, "wb");
    if (!outfile) {
        printf("Failed to open output file %s\n", filename);
        return;
    }

    // write the width and height to file
    fwrite(&img->width, sizeof(int), 1, outfile);
    fwrite(&img->height, sizeof(int), 1, outfile);

    // write image data to file
    fwrite(img->data, sizeof(unsigned char), img->width * img->height * 3, outfile);

    // close the file
    fclose(outfile);
}

/* Function to adjust the brightness of an image */
void adjust_brightness(Image* img, int value) {
    // loop through every pixel and adjust brightness
    for (int i = 0; i < img->width * img->height * 3; i++) {
        int new_val = (int)img->data[i] + value;
        img->data[i] = (unsigned char) (new_val > 255 ? 255 : (new_val < 0 ? 0 : new_val));
    }
}

/* Function to flip an image horizontally */
void flip_horizontal(Image* img) {
    // loop through each row of pixels and reverse the order
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            for (int c = 0; c < 3; c++) {
                unsigned char tmp = img->data[(y * img->width + x * 3) + c];
                img->data[(y * img->width + x * 3) + c] = img->data[(y * img->width + (img->width - x - 1) * 3) + c];
                img->data[(y * img->width + (img->width - x - 1) * 3) + c] = tmp;
            }
        }
    }
}

/* Function to apply a sepia tone filter to an image */
void apply_sepia(Image* img) {
    // loop through each pixel and apply sepia effect
    for (int i = 0; i < img->width * img->height * 3; i += 3) {
        int r = img->data[i];
        int g = img->data[i + 1];
        int b = img->data[i + 2];

        int tr = (int)(0.393 * r + 0.769 * g + 0.189 * b);
        int tg = (int)(0.349 * r + 0.686 * g + 0.168 * b);
        int tb = (int)(0.272 * r + 0.534 * g + 0.131 * b);

        img->data[i] = (unsigned char)(tr > 255 ? 255 : tr);
        img->data[i + 1] = (unsigned char)(tg > 255 ? 255 : tg);
        img->data[i + 2] = (unsigned char)(tb > 255 ? 255 : tb);
    }
}

int main() {
    char input_file[MAX_FILENAME_LENGTH];
    char output_file[MAX_FILENAME_LENGTH];
    char command[MAX_COMMAND_LENGTH];

    printf("Enter the name of the input file: ");
    fgets(input_file, MAX_FILENAME_LENGTH, stdin);
    input_file[strcspn(input_file, "\n")] = 0; // remove trailing newline character

    Image* img = read_image(input_file);
    if (!img) {
        printf("Failed to read input file %s\n", input_file);
        return 1;
    }

    while (1) {
        printf("Enter a command (brightness, flip, sepia, save, or exit): ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // remove trailing newline character

        if (strcmp(command, "brightness") == 0) {
            int value;
            printf("Enter brightness value (-255 to 255): ");
            scanf("%d", &value);
            getchar(); // remove newline character from input buffer
            adjust_brightness(img, value);
            printf("Brightness adjusted by %d\n", value);
        } else if (strcmp(command, "flip") == 0) {
            flip_horizontal(img);
            printf("Image flipped horizontally\n");
        } else if (strcmp(command, "sepia") == 0) {
            apply_sepia(img);
            printf("Sepia effect applied\n");
        } else if (strcmp(command, "save") == 0) {
            printf("Enter the name of the output file: ");
            fgets(output_file, MAX_FILENAME_LENGTH, stdin);
            output_file[strcspn(output_file, "\n")] = 0; // remove trailing newline character
            write_image(img, output_file);
            printf("Image saved to %s\n", output_file);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    free(img->data);
    free(img);

    return 0;
}