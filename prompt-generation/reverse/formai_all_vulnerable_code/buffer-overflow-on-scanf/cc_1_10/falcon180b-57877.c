//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define CHAR_SET ".,-~:;=!*#@"

void print_image(char* image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", CHAR_SET[image[y * width + x]]);
        }
        printf("\n");
    }
}

int main() {
    char* image_data = NULL;
    int width = 0, height = 0;

    printf("Enter the path to the image file: ");
    scanf("%s", image_data);

    FILE* fp = fopen(image_data, "rb");
    if (!fp) {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    if (file_size <= 0) {
        printf("Error reading file.\n");
        exit(1);
    }

    width = file_size / (3 * HEIGHT);
    height = HEIGHT;

    char* image = malloc(width * height);
    if (!image) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int byte_index = (y * width + x) * 3;
            unsigned char r, g, b;

            fread(&r, 1, 1, fp);
            fread(&g, 1, 1, fp);
            fread(&b, 1, 1, fp);

            int value = (int)r + (int)g + (int)b;
            image[y * width + x] = CHAR_SET[value % strlen(CHAR_SET)];
        }
    }

    fclose(fp);
    print_image(image, width, height);

    free(image);
    return 0;
}