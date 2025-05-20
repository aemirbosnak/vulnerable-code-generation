//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: brave
#include <stdio.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    int row;
    int col;
    int value;
} Pixel;

Pixel image[MAX_ROWS][MAX_COLS];

// Function to read image from file
void readImage(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    int row = 0;
    int col = 0;

    while (fscanf(fp, "%d %d %d", &row, &col, &image[row][col].value)!= EOF) {
        row++;
        if (row >= MAX_ROWS) {
            printf("Error: Image too large\n");
            exit(1);
        }
    }

    fclose(fp);
}

// Function to display image
void displayImage() {
    int minValue = image[0][0].value;
    int maxValue = image[0][0].value;

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (image[i][j].value < minValue) {
                minValue = image[i][j].value;
            }
            if (image[i][j].value > maxValue) {
                maxValue = image[i][j].value;
            }
        }
    }

    printf("Image:\n");
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            int intensity = (image[i][j].value - minValue) * 50 / (maxValue - minValue);
            printf("%3d ", intensity);
        }
        printf("\n");
    }
}

// Function to classify image
void classifyImage() {
    int threshold = 127; // Change this value to adjust classification

    int count = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (image[i][j].value > threshold) {
                count++;
            }
        }
    }

    if (count > (MAX_ROWS * MAX_COLS) / 2) {
        printf("Image is light\n");
    } else {
        printf("Image is dark\n");
    }
}

int main() {
    char filename[100];
    printf("Enter image filename: ");
    scanf("%s", filename);

    readImage(filename);
    displayImage();
    classifyImage();

    return 0;
}