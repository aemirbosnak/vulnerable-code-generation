//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_LINE_LEN 200
#define MAX_ASCII_ART_LEN 5000

/**
 * convert pixels to ASCII art value
 * @param pixel_value: value of pixel in 0-255 range
 * @return char: ASCII art value
 */
char pixel_to_ascii(uint8_t pixel_value) {
    if (pixel_value < 25) {
        return '@';
    } else if (pixel_value < 50) {
        return '#';
    } else if (pixel_value < 75) {
        return '0';
    } else if (pixel_value < 100) {
        return '&';
    } else if (pixel_value < 125) {
        return '8';
    } else if (pixel_value < 150) {
        return 'o';
    } else if (pixel_value < 175) {
        return ':';
    } else if (pixel_value < 200) {
        return '*';
    } else if (pixel_value < 225) {
        return '.';
    } else if (pixel_value < 250) {
        return ' ';
    } else {
        return ' ';
    }
}

/**
 * convert image to ascii art buffer
 * @param filepath: path to image
 * @return char*: pointer to ascii art buffer
 */
char* image_to_ascii(const char* filepath) {
    //open file in binary mode
    FILE *fp = fopen(filepath, "rb");
    if (!fp) {
        printf("Could not open file: %s\n", filepath);
        return NULL;
    }

    //read and discard BMP file header
    fseek(fp, 54, SEEK_SET);

    //get image width and height
    uint16_t width;
    uint16_t height;
    fread(&width, sizeof(uint16_t), 1, fp);
    fread(&height, sizeof(uint16_t), 1, fp);

    //calculate row padding
    uint32_t padding = (4 - (width * sizeof(uint32_t)) % 4) % 4;

    //calculate total image size
    uint32_t image_size = height * (width + padding);

    //allocate memory for bmp image
    uint32_t* bmp_image = malloc(image_size);
    if (!bmp_image) {
        printf("Failed to allocate memory for bmp image.\n");
        return NULL;
    }

    //read image pixel data
    fread(bmp_image, sizeof(uint32_t), width * height, fp);

    //close file
    fclose(fp);

    //allocate memory for ascii art buffer
    char* ascii_art = malloc(MAX_ASCII_ART_LEN);
    if (!ascii_art) {
        printf("Failed to allocate memory for ascii art buffer.\n");
        return NULL;
    }

    //create ascii art from bmp image
    int index = 0;
    for (int i = height-1; i >= 0; i--) { //iterate image rows from bottom to top
        for (int j = 0; j < width; j++) { //iterate image columns from left to right
            //get pixel value
            uint8_t pixel_value = (bmp_image[i*width + j] & 0x000000ff);

            //convert pixel to ascii art value
            ascii_art[index] = pixel_to_ascii(pixel_value);
            index++;
        }

        //add padding to ascii art
        for (int k = 0; k < padding; k++) {
            ascii_art[index] = ' ';
            index++;
        }

        //add newline to ascii art
        ascii_art[index] = '\n';
        index++;
    }

    //add null terminator to ascii art
    ascii_art[index] = '\0';

    //free bmp image memory
    free(bmp_image);

    return ascii_art;
}

int main() {
    char filepath[MAX_LINE_LEN];

    //get image filepath from user
    printf("Enter the path to the image you want to convert to ASCII art:\n");
    fgets(filepath, MAX_LINE_LEN, stdin);
    filepath[strcspn(filepath, "\n")] = '\0';

    //convert image to ascii art
    char* ascii_art = image_to_ascii(filepath);
    if (!ascii_art) {
        printf("An error occurred while creating ASCII art.\n");
        return -1;
    }

    //print ascii art to console
    printf("%s", ascii_art);

    //free ascii art memory
    free(ascii_art);

    return 0;
}