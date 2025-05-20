//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define ASCII characters for different grayscale values
const char *ASCII_CHARS = " .,:irs?@9B&#";

// Get grayscale value of a pixel
int get_grayscale_value(char *pixel) {
    int R = pixel[0];
    int G = pixel[1];
    int B = pixel[2];
    return 0.21*R + 0.72*G + 0.07*B;
}

// Resize image and get aspect ratio
void resize_image(char *filename, int *rows, int *cols, float *aspect_ratio) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error: File not found\n");
        exit(0);
    }
    
    char header[54];
    fread(header, sizeof(char), 54, f);
    
    *cols = *(int*)&header[18];
    *rows = *(int*)&header[22];
    
    *aspect_ratio = (float)*cols / *rows;
    
    while (*cols > 150) {
        *cols /= 2;
        *rows /= 2;
    }
    fclose(f);
}

// Convert image to ASCII art
void convert_to_ascii(char *filename) {
    int rows, cols;
    float aspect_ratio;
    
    resize_image(filename, &rows, &cols, &aspect_ratio);
    
    // Allocate memory for image data
    char **image = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        image[i] = malloc(cols * 3 * sizeof(char));
    }
    
    // Load image data into memory
    FILE *f = fopen(filename, "rb");
    fseek(f, 54, SEEK_SET);
    for (int i = 0; i < rows; i++) {
        fread(image[i], sizeof(char), cols * 3, f);
        fseek(f, cols * 3, SEEK_CUR);
    }
    fclose(f);
    
    // Convert image to ASCII and print
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int grayscale_value = get_grayscale_value(&image[i][j*3]);
            int char_index = (int)(grayscale_value / 25.5);
            printf("%c%c", ASCII_CHARS[char_index], ASCII_CHARS[char_index]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Free memory
    for (int i = 0; i < rows; i++) {
        free(image[i]);
    }
    free(image);
}

int main() {
    char *filename = "image.jpg";
    convert_to_ascii(filename);
    return 0;
}