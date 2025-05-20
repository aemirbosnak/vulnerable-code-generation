//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char grayscale[] = " .:-=+*#%@";
// grayscale gradient values

int main(int argc, char* argv[]) {
    if (argc != 2) {
        // check for file argument
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "rb");

    if (fp == NULL) {
        // check if file can be opened
        printf("Error: could not open file\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);

    char* buffer = (char*) malloc(sizeof(char) * file_size);

    if (buffer == NULL) {
        // check if buffer was allocated correctly
        printf("Error: failed to allocate memory\n");
        return 1;
    }

    fread(buffer, sizeof(char), file_size, fp);
    fclose(fp);

    int width = *(int*)(buffer + 18);
    int height = *(int*)(buffer + 22);
    int bit_depth = *(buffer + 28);

    char* image_data = buffer + *(int*)(buffer + 10);

    if (bit_depth != 8) {
        // check if bit_depth is correct
        printf("Error: unsupported bit depth\n");
        return 1;
    }

    for (int i = height - 1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            // get pixel value and map to corresponding grayscale value
            int pixel_value = *(unsigned char*)(image_data + i * width + j);
            int index = pixel_value * (strlen(grayscale) - 1) / 255;
            putchar(grayscale[index]);
        }
        putchar('\n');
    }

    free(buffer);
    return 0;
}