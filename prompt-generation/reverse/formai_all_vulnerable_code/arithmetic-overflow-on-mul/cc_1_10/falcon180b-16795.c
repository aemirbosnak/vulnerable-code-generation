//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 40
#define CHAR_SET ".,-~:;=+*#@"

int main(int argc, char *argv[]) {
    FILE *fp;
    char filename[100];
    int width, height, i, j, x, y, c;
    char *buffer;
    char ascii_art[MAX_WIDTH * MAX_HEIGHT];

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Get image dimensions
    fseek(fp, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Image is too large.\n");
        fclose(fp);
        exit(1);
    }

    // Allocate memory for image buffer
    buffer = (char *)malloc(width * height * 3);
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        fclose(fp);
        exit(1);
    }

    // Read image data
    fseek(fp, 54, SEEK_SET);
    fread(buffer, width * height * 3, 1, fp);
    fclose(fp);

    // Convert image to ASCII art
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            c = (int)buffer[(i * width + j) * 3 + 2];
            x = j * (MAX_WIDTH / width);
            y = i * (MAX_HEIGHT / height);
            ascii_art[y * MAX_WIDTH + x] = CHAR_SET[c / 16];
        }
    }

    // Print ASCII art
    for (i = 0; i < MAX_HEIGHT; i++) {
        for (j = 0; j < MAX_WIDTH; j++) {
            printf("%c", ascii_art[i * MAX_WIDTH + j]);
        }
        printf("\n");
    }

    free(buffer);
    return 0;
}