//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int rows;
    int cols;
    int **image;
} Image;

void error(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

void initialize_image(Image *image) {
    image->rows = 0;
    image->cols = 0;
    image->image = NULL;
}

void resize_image(Image *image, int new_rows, int new_cols) {
    int **new_image;

    if (new_rows > 0 && new_cols > 0) {
        new_image = (int **)malloc(sizeof(int *) * new_rows);
        for (int i = 0; i < new_rows; i++) {
            new_image[i] = (int *)malloc(sizeof(int) * new_cols);
        }

        image->rows = new_rows;
        image->cols = new_cols;
        image->image = new_image;
    }
}

void display_image(Image *image) {
    for (int i = 0; i < image->rows; i++) {
        for (int j = 0; j < image->cols; j++) {
            printf("%d ", image->image[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Image image;
    initialize_image(&image);

    printf("Enter the number of rows: ");
    int rows;
    scanf("%d", &rows);

    if (rows > MAX_ROWS) {
        error("Maximum number of rows reached");
    }

    resize_image(&image, rows, MAX_COLS);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("Enter the pixel value at (%d, %d): ", i, j);
            int pixel_value;
            scanf("%d", &pixel_value);
            image.image[i][j] = pixel_value;
        }
    }

    display_image(&image);

    return 0;
}