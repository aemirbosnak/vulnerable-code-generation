//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

char* grayscale = " .:-=+*#%@";

int main() {
    FILE* fp;
    char filename[100];
    int i, j, width = 0, height = 0;
    unsigned char image[MAX_HEIGHT][MAX_WIDTH];

    // Get image filename
    printf("Enter image filename: ");
    scanf("%s", filename);

    // Open image file
    fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read image width and height from header
    fseek(fp, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    // Read image data into buffer
    fseek(fp, 54, SEEK_SET);
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            image[i][j] = fgetc(fp);
        }
        if(width % 4 != 0) {
            fseek(fp, 4 - (width % 4), SEEK_CUR);
        }
    }

    // Close image file
    fclose(fp);

    // Convert image to ASCII art
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            int index = (int)((image[i][j] / 255.0) * strlen(grayscale));
            printf("%c", grayscale[index]);
        }
        printf("\n");
    }

    return 0;
}