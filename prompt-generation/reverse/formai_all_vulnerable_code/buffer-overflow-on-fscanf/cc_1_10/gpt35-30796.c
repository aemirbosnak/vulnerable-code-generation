//FormAI DATASET v1.0 Category: Image Editor ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define WIDTH 256
#define HEIGHT 256

// Function to read the PGM image file
void readPGM(char* filename, int img[WIDTH][HEIGHT], int* width, int* height)
{
    char ch, str[100];
    int maxVal, i, j;

    FILE* fp = fopen(filename, "r");

    // Checking if file exists
    if (fp == NULL) {
        printf("File does not exist.\n");
        return;
    }

    // Reading header information
    fscanf(fp, "%c%s\n", &ch, str);
    fscanf(fp, "%d %d\n", width, height);
    fscanf(fp, "%d\n", &maxVal);

    // Reading image
    for (i = 0; i < *height; i++) {
        for (j = 0; j < *width; j++) {
            fscanf(fp, "%d", &img[i][j]);
        }
    }

    // Closing the file
    fclose(fp);
}

// Function to write the PGM image file
void writePGM(char* filename, int img[WIDTH][HEIGHT], int width, int height)
{
    int i, j;

    FILE* fp = fopen(filename, "w");

    // Writing header information
    fprintf(fp, "P2\n");
    fprintf(fp, "%d %d\n", width, height);
    fprintf(fp, "255\n");

    // Writing image
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fprintf(fp, "%d ", img[i][j]);
        }
        fprintf(fp, "\n");
    }

    // Closing the file
    fclose(fp);
}

int main()
{
    int img[WIDTH][HEIGHT];
    int width, height, i, j;
    char filename[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Reading the PGM image file
    readPGM(filename, img, &width, &height);

    // Applying image editing operations here
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {

            // Inverting the image
            img[i][j] = 255 - img[i][j];
        }
    }

    // Writing the modified PGM image file
    writePGM("output.pgm", img, width, height);

    printf("Image editing successful. Output file saved as output.pgm.\n");

    return 0;
}