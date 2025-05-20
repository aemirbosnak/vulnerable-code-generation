//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

// Function to print an ASCII art representation of the image
void print_ascii_art(char *image, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", image[i * width + j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char filename[100];
    char buffer[MAX_WIDTH * MAX_HEIGHT];

    // Prompt the user for the filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Read the image data from the file
    fread(buffer, sizeof(char), MAX_WIDTH * MAX_HEIGHT, fp);

    // Convert the image data to ASCII art
    int width, height;
    int i, j;
    for (i = 0; i < MAX_HEIGHT; i++) {
        for (j = 0; j < MAX_WIDTH; j++) {
            if (buffer[(i * MAX_WIDTH) + j] == 0) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }

    // Close the file
    fclose(fp);

    return 0;
}