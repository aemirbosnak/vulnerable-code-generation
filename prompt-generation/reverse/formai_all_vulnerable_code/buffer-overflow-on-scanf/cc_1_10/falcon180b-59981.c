//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

// Function to print the ASCII art
void print_ascii_art(char *ascii_art) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", ascii_art[i * WIDTH + j]);
        }
        printf("\n");
    }
}

// Function to convert image to ASCII art
void image_to_ascii_art(char *filename, char *ascii_art) {
    FILE *fp;
    unsigned char c;
    int i, j, k;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    fseek(fp, 54, SEEK_SET); // Skip header
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fread(&c, 1, 1, fp);
            ascii_art[i * WIDTH + j] = (c / 32) + 32; // Convert pixel value to ASCII character
        }
    }

    fclose(fp);
}

// Function to save ASCII art to a file
void save_ascii_art(char *filename, char *ascii_art) {
    FILE *fp;

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Cannot create file.\n");
        exit(1);
    }

    fwrite(ascii_art, 1, strlen(ascii_art), fp);
    fclose(fp);
}

int main() {
    char input_filename[100], output_filename[100];
    char *ascii_art;

    printf("Enter input filename: ");
    scanf("%s", input_filename);

    printf("Enter output filename: ");
    scanf("%s", output_filename);

    ascii_art = malloc(HEIGHT * WIDTH);
    if (ascii_art == NULL) {
        printf("Error: Out of memory.\n");
        exit(1);
    }

    image_to_ascii_art(input_filename, ascii_art);

    printf("ASCII art generated successfully.\n");
    print_ascii_art(ascii_art);

    save_ascii_art(output_filename, ascii_art);

    printf("ASCII art saved to file.\n");

    free(ascii_art);

    return 0;
}