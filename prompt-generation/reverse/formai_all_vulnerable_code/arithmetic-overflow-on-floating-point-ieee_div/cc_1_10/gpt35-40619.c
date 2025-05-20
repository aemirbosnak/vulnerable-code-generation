//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define WIDTH 80
#define HEIGHT 80

// function to convert RGB value to grayscale
int rgb_to_gray(int r, int g, int b) {
    return 0.21*r + 0.72*g + 0.07*b;
}

int main() {
    // read the image file into memory
    FILE* fp = fopen("image.png", "rb");
    if (fp == NULL) {
        printf("Error in opening file\n");
        return 1;
    }
    fseek(fp, 18, SEEK_SET);
    unsigned int width = 0, height = 0;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    fseek(fp, 54, SEEK_SET);
    unsigned char* data = (unsigned char*)malloc(width * height * 3 * sizeof(unsigned char));
    fread(data, sizeof(unsigned char), width * height * 3, fp);
    fclose(fp);

    // resize the image to fit the console window
    double s1 = WIDTH / (double)width;
    double s2 = HEIGHT / (double)height;
    double s = fmin(s1, s2);
    int new_w = (int)(s * width);
    int new_h = (int)(s * height);

    // convert RGB data to grayscale
    int* gray_data = (int*)malloc(new_w * new_h * sizeof(int));
    for (int i = 0; i < new_w * new_h; i++) {
        int r = data[i * 3];
        int g = data[i * 3 + 1];
        int b = data[i * 3 + 2];
        gray_data[i] = rgb_to_gray(r, g, b);
    }

    // convert grayscale data to ASCII art
    char* ascii_data = (char*)malloc(new_w * new_h * sizeof(char));
    char chars[] = " .:-=+*#%@";
    int num_chars = strlen(chars);
    for (int i = 0; i < new_w * new_h; i++) {
        int val = gray_data[i];
        int cindex = (int)((double)val / 255 * (num_chars - 1));
        ascii_data[i] = chars[cindex];
    }

    // print the ASCII art to console
    for (int y = 0; y < new_h; y++) {
        for (int x = 0; x < new_w; x++) {
            char c = ascii_data[y * new_w + x];
            putchar(c);
        }
        putchar('\n');
    }

    // free the memory
    free(data);
    free(gray_data);
    free(ascii_data);

    return 0;
}