#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define ASCII_CHARS " .:+*@#%&~-_=+<> "

void display_image(unsigned char* data, int width, int height) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            printf("%c", ASCII_CHARS[data[y * width + x]]);
        }
        printf("\n");
    }
}

int main() {
    unsigned char header[MAX_WIDTH + 3];
    unsigned char* data;
    int width, height;

    FILE* file = fopen("input.pgm", "r");
    fscanf(file, "%s %d %d\n%*[^\n]", header, &height);
    width = atoi(header);

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Image too large.\n");
        return 1;
    }

    data = (unsigned char*)malloc(width * height);
    fread(data, 1, width * height, file);
    fclose(file);

    display_image(data, width, height);

    free(data);
    return 0;
}
