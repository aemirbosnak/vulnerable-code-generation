//FormAI DATASET v1.0 Category: Image Editor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME 1000
#define MAX_SIZE 2048

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

// Function to read image from file
void read_image(pixel img[][MAX_SIZE], int *width, int *height) {
    char file_name[MAX_FILE_NAME];
    printf("Enter image file name: ");
    scanf("%s", file_name);
    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    fscanf(fp, "P3\n%d %d\n255\n", width, height);
    int i, j;
    for (i = 0; i < *height; i++) {
        for (j = 0; j < *width; j++) {
            fscanf(fp, "%hhu %hhu %hhu", &img[i][j].r, &img[i][j].g, &img[i][j].b);
        }
    }
    fclose(fp);
}

// Function to write image to file
void write_image(pixel img[][MAX_SIZE], int width, int height) {
    char file_name[MAX_FILE_NAME];
    printf("Enter output file name: ");
    scanf("%s", file_name);
    FILE *fp = fopen(file_name, "wb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    fprintf(fp, "P3\n%d %d\n255\n", width, height);
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fprintf(fp, "%d %d %d ", img[i][j].r, img[i][j].g, img[i][j].b);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

// Function to print menu
void print_menu() {
    printf("1. Invert colors\n");
    printf("2. Grayscale\n");
    printf("3. Brightness adjustment\n");
    printf("4. Contrast adjustment\n");
    printf("5. Gaussian blur\n");
    printf("6. Exit\n");
}

// Function to invert colors
void invert_colors(pixel img[][MAX_SIZE], int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            img[i][j].r = 255 - img[i][j].r;
            img[i][j].g = 255 - img[i][j].g;
            img[i][j].b = 255 - img[i][j].b;
        }
    }
}

// Function to convert to grayscale
void grayscale(pixel img[][MAX_SIZE], int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            unsigned char gray = (img[i][j].r + img[i][j].g + img[i][j].b) / 3;
            img[i][j].r = gray;
            img[i][j].g = gray;
            img[i][j].b = gray;
        }
    }
}

// Function to adjust brightness
void brightness(pixel img[][MAX_SIZE], int width, int height, int adjustment) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            img[i][j].r = img[i][j].r + adjustment;
            if (img[i][j].r > 255) {
                img[i][j].r = 255;
            } else if (img[i][j].r < 0) {
                img[i][j].r = 0;
            }
            img[i][j].g = img[i][j].g + adjustment;
            if (img[i][j].g > 255) {
                img[i][j].g = 255;
            } else if (img[i][j].g < 0) {
                img[i][j].g = 0;
            }
            img[i][j].b = img[i][j].b + adjustment;
            if (img[i][j].b > 255) {
                img[i][j].b = 255;
            } else if (img[i][j].b < 0) {
                img[i][j].b = 0;
            }
        }
    }
}

// Function to adjust contrast
void contrast(pixel img[][MAX_SIZE], int width, int height, double adjustment) {
    double factor = (259.0 * (adjustment + 255.0)) / (255.0 * (259.0 - adjustment));
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            img[i][j].r = (unsigned char) (factor * (img[i][j].r - 128) + 128);
            if (img[i][j].r > 255) {
                img[i][j].r = 255;
            } else if (img[i][j].r < 0) {
                img[i][j].r = 0;
            }
            img[i][j].g = (unsigned char) (factor * (img[i][j].g - 128) + 128);
            if (img[i][j].g > 255) {
                img[i][j].g = 255;
            } else if (img[i][j].g < 0) {
                img[i][j].g = 0;
            }
            img[i][j].b = (unsigned char) (factor * (img[i][j].b - 128) + 128);
            if (img[i][j].b > 255) {
                img[i][j].b = 255;
            } else if (img[i][j].b < 0) {
                img[i][j].b = 0;
            }
        }
    }
}

// Function to perform Gaussian blur
void gaussian_blur(pixel img[][MAX_SIZE], int width, int height) {
    double kernel[5][5] = {
            {0.0036, 0.0143, 0.0232, 0.0143, 0.0036},
            {0.0143, 0.0567, 0.0918, 0.0567, 0.0143},
            {0.0232, 0.0918, 0.1486, 0.0918, 0.0232},
            {0.0143, 0.0567, 0.0918, 0.0567, 0.0143},
            {0.0036, 0.0143, 0.0232, 0.0143, 0.0036}
    };
    int i, j, k, l;
    pixel tmp[MAX_SIZE][MAX_SIZE];
    for (i = 2; i < height - 2; i++) {
        for (j = 2; j < width - 2; j++) {
            double sum_r = 0;
            double sum_g = 0;
            double sum_b = 0;
            for (k = -2; k <= 2; k++) {
                for (l = -2; l <= 2; l++) {
                    sum_r += kernel[k + 2][l + 2] * img[i + k][j + l].r;
                    sum_g += kernel[k + 2][l + 2] * img[i + k][j + l].g;
                    sum_b += kernel[k + 2][l + 2] * img[i + k][j + l].b;
                }
            }
            tmp[i][j].r = (unsigned char) sum_r;
            tmp[i][j].g = (unsigned char) sum_g;
            tmp[i][j].b = (unsigned char) sum_b;
        }
    }
    for (i = 2; i < height - 2; i++) {
        for (j = 2; j < width - 2; j++) {
            img[i][j].r = tmp[i][j].r;
            img[i][j].g = tmp[i][j].g;
            img[i][j].b = tmp[i][j].b;
        }
    }
}

int main() {
    pixel img[MAX_SIZE][MAX_SIZE];
    int width, height;
    read_image(img, &width, &height);
    int choice;
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                invert_colors(img, width, height);
                break;
            case 2:
                grayscale(img, width, height);
                break;
            case 3:
                printf("Enter brightness adjustment (-255 to 255): ");
                int brightness_adjustment;
                scanf("%d", &brightness_adjustment);
                brightness(img, width, height, brightness_adjustment);
                break;
            case 4:
                printf("Enter contrast adjustment (-255 to 255): ");
                int contrast_adjustment;
                scanf("%d", &contrast_adjustment);
                double contrast_factor = ((double) (contrast_adjustment + 255)) / 255.0;
                contrast(img, width, height, contrast_factor);
                break;
            case 5:
                gaussian_blur(img, width, height);
                break;
            case 6:
                printf("Exiting program.");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
        if (choice != 6) {
            write_image(img, width, height);
        }
    } while (choice != 6);
    return 0;
}