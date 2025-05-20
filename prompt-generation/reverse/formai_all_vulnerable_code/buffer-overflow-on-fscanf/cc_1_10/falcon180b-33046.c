//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    int rows;
    int cols;
} Image;

void load_image(Image *img, char *filename)
{
    FILE *fp = fopen(filename, "r");
    fscanf(fp, "%d %d", &img->rows, &img->cols);
    img->data = (int *)malloc(img->rows * img->cols * sizeof(int));
    for (int i = 0; i < img->rows; i++) {
        for (int j = 0; j < img->cols; j++) {
            fscanf(fp, "%d", &img->data[i * img->cols + j]);
        }
    }
    fclose(fp);
}

void display_image(Image img)
{
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            printf("%d ", img.data[i * img.cols + j]);
        }
        printf("\n");
    }
}

void free_image(Image img)
{
    free(img.data);
}

int main()
{
    // Load image
    Image img;
    load_image(&img, "image.txt");

    // Display image
    display_image(img);

    // Free memory
    free_image(img);

    return 0;
}