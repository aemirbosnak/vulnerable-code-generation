//FormAI DATASET v1.0 Category: Image Editor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILTER_SIZE 10

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int rows, cols;
    pixel **data;
} img;

void read_image(char *filename, img *input) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file\n");
        return;
    }

    char buff[16];
    int max_color;

    // Read image format
    fgets(buff, sizeof(buff), fp);

    // Read image dimensions
    fscanf(fp, "%d %d\n", &input->cols, &input->rows);

    // Read max color value
    fscanf(fp, "%d\n", &max_color);

    // Allocate memory for image data
    input->data = (pixel **)malloc(input->rows * sizeof(pixel *));
    for (int i = 0; i < input->rows; i++) {
        input->data[i] = (pixel *)malloc(input->cols * sizeof(pixel));
    }

    // Read image data
    for (int i = 0; i < input->rows; i++) {
        for (int j = 0; j < input->cols; j++) {
            fscanf(fp, "%c%c%c", &input->data[i][j].r, &input->data[i][j].g, &input->data[i][j].b);
        }
        fscanf(fp, "\n");
    }

    fclose(fp);
    printf("Image loaded successfully!\n");
}

void write_image(char *filename, img *output) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file\n");
        return;
    }

    // Write image format
    fprintf(fp, "P3\n");

    // Write image dimensions
    fprintf(fp, "%d %d\n", output->cols, output->rows);

    // Write max color value
    fprintf(fp, "255\n");

    // Write image data
    for (int i = 0; i < output->rows; i++) {
        for (int j = 0; j < output->cols; j++) {
            fprintf(fp, "%d %d %d ", output->data[i][j].r, output->data[i][j].g, output->data[i][j].b);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    printf("Image saved successfully!\n");
}

void grayscale_filter(img *input, img *output) {
    output->cols = input->cols;
    output->rows = input->rows;

    output->data = (pixel **)malloc(output->rows * sizeof(pixel *));
    for (int i = 0; i < output->rows; i++) {
        output->data[i] = (pixel *)malloc(output->cols * sizeof(pixel));
    }

    unsigned char gray_intensity;
    for (int i = 0; i < input->rows; i++) {
        for (int j = 0; j < input->cols; j++) {
            gray_intensity = ceil((input->data[i][j].r + input->data[i][j].g + input->data[i][j].b) / 3.0);
            output->data[i][j].r = gray_intensity;
            output->data[i][j].g = gray_intensity;
            output->data[i][j].b = gray_intensity;
        }
    }

    printf("Grayscale filter applied successfully!\n");
}

void blur_filter(img *input, img *output, int filter_size) {
    output->cols = input->cols - filter_size + 1;
    output->rows = input->rows - filter_size + 1;

    output->data = (pixel **)malloc(output->rows * sizeof(pixel *));
    for (int i = 0; i < output->rows; i++) {
        output->data[i] = (pixel *)malloc(output->cols * sizeof(pixel));
    }

    int sum;
    for (int i = 0; i < output->rows; i++) {
        for (int j = 0; j < output->cols; j++) {
            sum = 0;
            for (int k = 0; k < filter_size; k++) {
                for (int l = 0; l < filter_size; l++) {
                    sum += input->data[i + k][j + l].r;
                }
            }
            output->data[i][j].r = sum / (filter_size * filter_size);
            output->data[i][j].g = sum / (filter_size * filter_size);
            output->data[i][j].b = sum / (filter_size * filter_size);
        }
    }

    printf("Blur filter applied successfully!\n");
}

int main() {
    char input_file[MAX_FILE_NAME_LENGTH];
    char output_file[MAX_FILE_NAME_LENGTH];
    img input_image, output_image;
    int choice, filter_size;

    printf("Enter input file name: ");
    scanf("%s", input_file);

    // Load input image
    read_image(input_file, &input_image);

    printf("\nSelect filter to apply\n");
    printf("1. Grayscale filter\n");
    printf("2. Blur filter\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Apply grayscale filter
            grayscale_filter(&input_image, &output_image);
            break;
        case 2:
            // Apply blur filter
            printf("Enter filter size (odd numbers only): ");
            scanf("%d", &filter_size);
            if (filter_size % 2 == 0) {
                printf("Error: Filter size should be odd\n");
                return 0;
            }
            blur_filter(&input_image, &output_image, filter_size);
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }

    printf("\nEnter output file name: ");
    scanf("%s", output_file);

    // Save output image
    write_image(output_file, &output_image);

    // Free memory
    for (int i = 0; i < input_image.rows; i++) {
        free(input_image.data[i]);
    }
    free(input_image.data);

    for (int i = 0; i < output_image.rows; i++) {
        free(output_image.data[i]);
    }
    free(output_image.data);

    return 0;
}