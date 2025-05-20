//FormAI DATASET v1.0 Category: Image Editor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

struct color {
    int r, g, b;
};

void read_image(char filename[], struct color image[100][100], int* height, int* width) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    fscanf(fp, "%d %d", height, width);
    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            fscanf(fp, "%d %d %d", &image[i][j].r, &image[i][j].g, &image[i][j].b);
        }
    }
    fclose(fp);
}

void write_image(char filename[], struct color image[100][100], int height, int width) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    fprintf(fp, "%d %d\n", height, width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(fp, "%d %d %d ", image[i][j].r, image[i][j].g, image[i][j].b);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void grayscale(struct color image[100][100], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int average = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
            image[i][j].r = average;
            image[i][j].g = average;
            image[i][j].b = average;
        }
    }
}

void flip_horizontally(struct color image[100][100], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            struct color temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

void blur(struct color image[100][100], int height, int width) {
    struct color temp[100][100];
    int kernel[3][3] = {{1, 2, 1},
                        {2, 4, 2},
                        {1, 2, 1}};
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            int sum_r = 0, sum_g = 0, sum_b = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    sum_r += kernel[k + 1][l + 1] * image[i + k][j + l].r;
                    sum_g += kernel[k + 1][l + 1] * image[i + k][j + l].g;
                    sum_b += kernel[k + 1][l + 1] * image[i + k][j + l].b;
                }
            }
            temp[i][j].r = sum_r / 16;
            temp[i][j].g = sum_g / 16;
            temp[i][j].b = sum_b / 16;
        }
    }
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            image[i][j] = temp[i][j];
        }
    }
}

int main() {
    struct color image[100][100];
    int height, width;
    read_image("input.txt", image, &height, &width);

    printf("Commands:\n");
    printf("1. Grayscale\n");
    printf("2. Flip Horizontally\n");
    printf("3. Blur\n");
    printf("Enter command: ");
    int command;
    scanf("%d", &command);

    switch (command) {
        case 1:
            grayscale(image, height, width);
            break;
        case 2:
            flip_horizontally(image, height, width);
            break;
        case 3:
            blur(image, height, width);
            break;
        default:
            printf("Error: invalid command\n");
            exit(1);
    }

    write_image("output.txt", image, height, width);

    return 0;
}