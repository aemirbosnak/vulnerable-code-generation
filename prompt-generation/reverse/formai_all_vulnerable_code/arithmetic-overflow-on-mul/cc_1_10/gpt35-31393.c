//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    // check if the user has provided the filename of the image
    if (argc < 2) {
        printf("Usage: %s <image_filename>\n", argv[0]);
        return 0;
    }

    // open the image file
    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Unable to open file: %s\n", argv[1]);
        return 0;
    }

    // read the header of the image file
    char header[54];
    fread(header, sizeof(char), 54, file);

    // get the width and height of the image
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // allocate memory to store the image data
    int size = 3 * width * height;
    unsigned char *data = (unsigned char*)malloc(size);

    // read the image data
    fread(data, sizeof(unsigned char), size, file);
    fclose(file);

    // print a funny message
    printf("Converting the image to ASCII art...\n\n");

    // convert the image to ASCII art
    for (int i = 0; i < size; i += 3) {
        // calculate the grayscale value of the pixel
        int grayscale = 0.2126 * data[i] + 0.7152 * data[i + 1] + 0.0722 * data[i + 2];

        // assign a character based on the grayscale value
        const char *ascii_chars = "@%#*+=-:. ";
        int index = (grayscale * strlen(ascii_chars)) / 255;

        // print the character
        printf("%c", ascii_chars[index]);
        if ((i + 3) % (3 * width) == 0) {
            printf("\n");
        }
    }

    // print a funny message
    printf("\nDone! Thank you for choosing our Image to ASCII art converter program!\n");
    free(data);

    return 0;
}