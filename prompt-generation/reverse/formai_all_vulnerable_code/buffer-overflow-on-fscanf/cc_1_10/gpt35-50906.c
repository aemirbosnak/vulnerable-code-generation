//FormAI DATASET v1.0 Category: Image Editor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 100

unsigned char *read_image(char *filename, int *width, int *height);
void write_image(char *filename, unsigned char *data, int width, int height);
void grayscale_filter(unsigned char *data, int width, int height);
void mirror_filter(unsigned char *data, int width, int height);
void invert_colors_filter(unsigned char *data, int width, int height);
void blur_filter(unsigned char *data, int width, int height);

int main() {
    int width, height;
    unsigned char *data;
    char filename[MAX_FILENAME];
    char menu_choice;

    printf("Enter the filename of the image to edit: ");
    scanf("%s", filename);

    data = read_image(filename, &width, &height);

    do {
        printf("Menu:\n");
        printf("1) Grayscale filter\n");
        printf("2) Mirror filter\n");
        printf("3) Invert colors filter\n");
        printf("4) Blur filter\n");
        printf("5) Save and exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &menu_choice);

        switch(menu_choice) {
            case '1': 
                grayscale_filter(data, width, height);
                printf("Grayscale filter applied.\n");
                break;
            case '2':
                mirror_filter(data, width, height);
                printf("Mirror filter applied.\n");
                break;
            case '3':
                invert_colors_filter(data, width, height);
                printf("Invert colors filter applied.\n");
                break;
            case '4':
                blur_filter(data, width, height);
                printf("Blur filter applied.\n");
                break;
            case '5':
                printf("Enter the filename to save the edited image to: ");
                scanf("%s", filename);
                write_image(filename, data, width, height);
                printf("Image saved to %s.\n", filename);
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (menu_choice != '5');

    free(data);
    return 0;
}

unsigned char *read_image(char *filename, int *width, int *height) {
    unsigned char *data;
    FILE *fp;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        exit(1);
    }

    // Read the format (BMP or PNM)
    char format[3];
    fscanf(fp, "%s", format);
    fseek(fp, 1, SEEK_CUR);

    // Read the width
    fscanf(fp, "%d", width);

    // Read the height
    fscanf(fp, "%d", height);

    // Skip any whitespace and read the maximum color value
    int max_color;
    while (fgetc(fp) != '\n');
    fscanf(fp, "%d", &max_color);

    // Allocate memory for the image data
    data = (unsigned char *) malloc((*width) * (*height) * 3);

    // Read the image data into the buffer
    fread(data, 1, (*width) * (*height) * 3, fp);

    // Close the file and return the image data
    fclose(fp);
    return data;
}

void write_image(char *filename, unsigned char *data, int width, int height) {
    FILE *fp;
    int i, j, k;

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        exit(1);
    }

    // Write the PNM header
    fprintf(fp, "P6\n%d %d\n255\n", width, height);

    // Write the image data to the file
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            for (k = 0; k < 3; k++) {
                fputc(data[(i * width + j) * 3 + k], fp);
            }
        }
    }

    // Close the file
    fclose(fp);
}

void grayscale_filter(unsigned char *data, int width, int height) {
    int i, j;
    unsigned char r, g, b, grayscale_value;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            r = data[(i * width + j) * 3];
            g = data[(i * width + j) * 3 + 1];
            b = data[(i * width + j) * 3 + 2];

            // Calculate grayscale value
            grayscale_value = 0.21 * r + 0.72 * g + 0.07 * b;

            // Set the pixel to the grayscale value
            data[(i * width + j) * 3] = grayscale_value;
            data[(i * width + j) * 3 + 1] = grayscale_value;
            data[(i * width + j) * 3 + 2] = grayscale_value;
        }
    }
}

void mirror_filter(unsigned char *data, int width, int height) {
    int i, j, k;
    unsigned char temp;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            for (k = 0; k < 3; k++) {
                // Swap pixels on either side of the image
                temp = data[(i * width + j) * 3 + k];
                data[(i * width + j) * 3 + k] = data[(i * width + (width - 1 - j)) * 3 + k];
                data[(i * width + (width - 1 - j)) * 3 + k] = temp;
            }
        }
    }
}

void invert_colors_filter(unsigned char *data, int width, int height) {
    int i, j;
    unsigned char r, g, b;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            r = data[(i * width + j) * 3];
            g = data[(i * width + j) * 3 + 1];
            b = data[(i * width + j) * 3 + 2];

            // Invert colors by subtracting each channel from 255
            data[(i * width + j) * 3] = 255 - r;
            data[(i * width + j) * 3 + 1] = 255 - g;
            data[(i * width + j) * 3 + 2] = 255 - b;
        }
    }
}

void blur_filter(unsigned char *data, int width, int height) {
    int i, j, k, l;
    unsigned char r, g, b;
    double blur_matrix[3][3] = {{0.0625, 0.125, 0.0625},
                                {0.125, 0.25, 0.125},
                                {0.0625, 0.125, 0.0625}};
    unsigned char *blurred_data = (unsigned char *) malloc(width * height * 3);

    // Loop over every pixel in the image
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // Initialize the color channels to zero
            r = 0;
            g = 0;
            b = 0;

            // Loop over each element in the blur matrix
            for (k = 0; k < 3; k++) {
                for (l = 0; l < 3; l++) {
                    // Get the color values of the pixel to blur
                    if (i + k - 1 < 0 || i + k - 1 >= height || j + l - 1 < 0 || j + l - 1 >= width) {
                        continue;
                    }
                    r += data[((i + k - 1) * width + (j + l - 1)) * 3] * blur_matrix[k][l];
                    g += data[((i + k - 1) * width + (j + l - 1)) * 3 + 1] * blur_matrix[k][l];
                    b += data[((i + k - 1) * width + (j + l - 1)) * 3 + 2] * blur_matrix[k][l];
                }
            }

            // Set the pixel in the blurred image
            blurred_data[(i * width + j) * 3] = r;
            blurred_data[(i * width + j) * 3 + 1] = g;
            blurred_data[(i * width + j) * 3 + 2] = b;
        }
    }

    // Copy the blurred image back into the original data buffer
    memcpy(data, blurred_data, width * height * 3);

    // Free the temporary buffer
    free(blurred_data);
}