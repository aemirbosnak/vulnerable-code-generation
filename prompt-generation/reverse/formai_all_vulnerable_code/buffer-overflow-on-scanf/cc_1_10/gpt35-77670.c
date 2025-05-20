//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 60

char ascii[HEIGHT][WIDTH+1];

void print_ascii() {
    for(int i=0; i<HEIGHT; i++) {
        printf("%s\n", ascii[i]);
    }
}

void convert_to_ascii(char* image_path) {
    FILE* fp = fopen(image_path, "rb");
    if(!fp) {
        printf("Could not open image file.\n");
        return;
    }

    int pixel_size = 3; // RGB
    unsigned char* image = (unsigned char*)malloc(WIDTH * HEIGHT * pixel_size);

    fread(image, pixel_size, WIDTH * HEIGHT, fp);

    for(int y=0; y<HEIGHT; y++) {
        for(int x=0; x<WIDTH; x++) {
            int pos = (y * WIDTH + x) * pixel_size;
            int r = image[pos];
            int g = image[pos+1];
            int b = image[pos+2];
            float gray = (0.2126*r + 0.7152*g + 0.0722*b);
            int symbol_index = (int)(gray * 69 / 255); // Map value to ASCII symbol
            ascii[y][x] = "@%#*+=-:. "[symbol_index];
        }
        ascii[y][WIDTH] = '\0';
    }

    free(image);
    fclose(fp);

    print_ascii();
}

int main() {
    printf("Welcome to the Image to ASCII Art converter!\n");
    printf("Please enter the path of your image file: ");

    char image_path[100];
    scanf("%s", image_path);

    printf("\nHere is your ASCII Art:\n");
    convert_to_ascii(image_path);

    return 0;
}