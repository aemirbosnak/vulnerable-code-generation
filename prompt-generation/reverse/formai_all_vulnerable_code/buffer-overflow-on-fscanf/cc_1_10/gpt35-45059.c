//FormAI DATASET v1.0 Category: Image Classification system ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Image Classifier!\n");
    printf("Please enter the file path for the image you want to classify: ");

    // read in file path
    char file_path[100];
    scanf("%s", file_path);

    // open image file
    FILE *fp;
    fp = fopen(file_path, "r");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    // read image metadata
    int width, height, color_depth;
    fscanf(fp, "%d %d %d", &width, &height, &color_depth);

    // read and process image data
    int pixel_count = width * height;
    int *r_values = (int *)malloc(pixel_count * sizeof(int));
    int *g_values = (int *)malloc(pixel_count * sizeof(int));
    int *b_values = (int *)malloc(pixel_count * sizeof(int));

    for (int i = 0; i < pixel_count; i++) {
        fscanf(fp, "%d %d %d", &r_values[i], &g_values[i], &b_values[i]);
    }

    // determine dominant color
    int r_sum = 0, g_sum = 0, b_sum = 0;
    for (int i = 0; i < pixel_count; i++) {
        r_sum += r_values[i];
        g_sum += g_values[i];
        b_sum += b_values[i];
    }

    int r_avg = r_sum / pixel_count;
    int g_avg = g_sum / pixel_count;
    int b_avg = b_sum / pixel_count;

    int max_color = r_avg;
    if (g_avg > max_color) {
        max_color = g_avg;
    }
    if (b_avg > max_color) {
        max_color = b_avg;
    }

    // output classification
    printf("The dominant color in this image is: ");
    if (max_color == r_avg) {
        printf("red.\n");
    } else if (max_color == g_avg) {
        printf("green.\n");
    } else {
        printf("blue.\n");
    }

    // cleanup
    fclose(fp);
    free(r_values);
    free(g_values);
    free(b_values);

    return 0;
}