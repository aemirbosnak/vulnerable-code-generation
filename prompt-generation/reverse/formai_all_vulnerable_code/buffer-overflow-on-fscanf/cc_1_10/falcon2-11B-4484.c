//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_image_to_ascii(const char* image_file, char* output_file) {
    FILE* image_fp = fopen(image_file, "r");
    FILE* output_fp = fopen(output_file, "w");

    if (image_fp == NULL || output_fp == NULL) {
        printf("Error opening files.\n");
        return;
    }

    int width, height;
    fscanf(image_fp, "%d %d", &width, &height);
    if (width == 0 || height == 0) {
        printf("Image dimensions are invalid.\n");
        fclose(image_fp);
        fclose(output_fp);
        return;
    }

    char* buffer = (char*)malloc(sizeof(char) * width * height);
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        fclose(image_fp);
        fclose(output_fp);
        return;
    }

    int pixels = 0;
    int char_index = 0;
    char* current_char = buffer;

    while (fscanf(image_fp, "%d", &pixels) == 1) {
        for (int y = 0; y < height; y++) {
            char* line = buffer + y * width;
            int char_count = 0;
            for (int x = 0; x < width; x++) {
                fscanf(image_fp, "%d", &pixels);
                if (pixels!= 0) {
                    line[x] = '*';
                    char_count++;
                }
            }
            if (char_count > 0) {
                strncpy(current_char, &line[0], char_count);
                current_char += char_count;
                char_index += char_count;
            }
        }
    }

    fclose(image_fp);
    fclose(output_fp);
    printf("ASCII art generated with %d characters.\n", char_index);
    free(buffer);
}

int main() {
    const char* image_file = "example.jpg";
    char* output_file = "example.txt";

    convert_image_to_ascii(image_file, output_file);

    return 0;
}