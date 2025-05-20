//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    int* pixels;
} Image;

void load_image(const char* filename, Image* image) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file\n");
        exit(1);
    }
    
    fscanf(fp, "%d %d", &image->rows, &image->cols);
    image->pixels = (int*) malloc(image->rows * image->cols * sizeof(int));
    if (!image->pixels) {
        printf("Error allocating memory\n");
        exit(1);
    }
    
    for (int i = 0; i < image->rows * image->cols; i++) {
        fscanf(fp, "%d", &image->pixels[i]);
    }
    
    fclose(fp);
}

void save_image(const char* filename, Image* image) {
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file\n");
        exit(1);
    }
    
    fprintf(fp, "%d %d\n", image->rows, image->cols);
    for (int i = 0; i < image->rows * image->cols; i++) {
        fprintf(fp, "%d\n", image->pixels[i]);
    }
    
    fclose(fp);
}

void print_image(Image* image) {
    for (int i = 0; i < image->rows; i++) {
        for (int j = 0; j < image->cols; j++) {
            printf("%d ", image->pixels[i * image->cols + j]);
        }
        printf("\n");
    }
}

int main() {
    Image image;
    load_image("input.bmp", &image);
    print_image(&image);
    save_image("output.bmp", &image);
    return 0;
}