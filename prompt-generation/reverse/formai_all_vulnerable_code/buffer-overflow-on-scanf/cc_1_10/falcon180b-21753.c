//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define CHAR_SET_SIZE 95

char char_set[CHAR_SET_SIZE] = "./:-=+*#%@";

void print_image(char *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", char_set[(int)image[i * width + j]]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char filename[50];
    char *image_data;
    int width, height, size;

    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    image_data = malloc(size);
    if (image_data == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    fread(image_data, size, 1, fp);
    fclose(fp);

    width = *(int *)image_data;
    height = *(int *)(image_data + 4);

    printf("Image size: %dx%d\n", width, height);

    print_image(image_data + 8, width, height);

    return 0;
}