//FormAI DATASET v1.0 Category: Image Editor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// function to read image matrix from file
void readImage(FILE *fp, int rows, int cols, int image[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }
}

// function to write image matrix to file
void writeImage(FILE *fp, int rows, int cols, int image[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(fp, "%d ", image[i][j]);
        }
        fprintf(fp, "\n");
    }
}

// function to flip image horizontally
void flipHorizontal(int rows, int cols, int image[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][cols-j-1];
            image[i][cols-j-1] = temp;
        }
    }
}

// function to rotate image 90 degrees clockwise
void rotateClockwise(int rows, int cols, int image[MAX_ROWS][MAX_COLS]) {
    int temp[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            image[j][rows-i-1] = temp[i][j];
        }
    }
}

int main() {
    int rows, cols;
    int image[MAX_ROWS][MAX_COLS];

    // read image matrix from file
    FILE *fp = fopen("image.txt", "r");
    if (fp == NULL) {
        printf("Error: failed to open file\n");
        return 1;
    }
    fscanf(fp, "%d %d", &rows, &cols);
    readImage(fp, rows, cols, image);
    fclose(fp);

    // flip image horizontally
    flipHorizontal(rows, cols, image);

    // rotate image 90 degrees clockwise
    rotateClockwise(cols, rows, image);
    int temp = rows;
    rows = cols;
    cols = temp;

    // write new image matrix to file
    fp = fopen("new_image.txt", "w");
    if (fp == NULL) {
        printf("Error: failed to open file\n");
        return 1;
    }
    fprintf(fp, "%d %d\n", rows, cols);
    writeImage(fp, rows, cols, image);
    fclose(fp);

    return 0;
}