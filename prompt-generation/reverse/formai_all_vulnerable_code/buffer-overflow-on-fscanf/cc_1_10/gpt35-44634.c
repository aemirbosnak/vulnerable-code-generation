//FormAI DATASET v1.0 Category: Image Editor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_FILE_NAME 100

typedef struct {
    unsigned char red, green, blue;
} pixel;

void read_image(char *file_name, pixel **image, int *width, int *height) {
    FILE *fp = fopen(file_name, "rb");

    if (!fp) {
        printf("ERROR: File not found!\n");
        exit(1);
    }

    char type[3];
    int max_color;

    fscanf(fp, "%s\n", type);
    fscanf(fp, "%d %d\n", width, height);
    fscanf(fp, "%d\n", &max_color);

    *image = (pixel *) malloc((*width) * (*height) * sizeof(pixel));

    for (int i = 0; i < (*height); i++) {
        for (int j = 0; j < (*width); j++) {
            int index = i * (*width) + j;
            fscanf(fp, "%c%c%c", &((*image)[index].red), &((*image)[index].green), &((*image)[index].blue));
        }
    }

    fclose(fp);
}

void write_image(char *file_name, pixel *image, int width, int height) {
    FILE *fp = fopen(file_name, "wb");

    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", width, height);
    fprintf(fp, "255\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = i * width + j;
            fprintf(fp, "%c%c%c", image[index].red, image[index].green, image[index].blue);
        }
    }

    fclose(fp);
}

void grayscale(pixel **image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = i * width + j;
            unsigned char gray = (0.30 * (*image)[index].red) + (0.59 * (*image)[index].green) + (0.11 * (*image)[index].blue);
            (*image)[index].red = gray;
            (*image)[index].green = gray;
            (*image)[index].blue = gray;
        }
    }
}

void sepia(pixel **image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = i * width + j;
            unsigned char gray = (0.30 * (*image)[index].red) + (0.59 * (*image)[index].green) + (0.11 * (*image)[index].blue);
            (*image)[index].red = gray + 40;
            (*image)[index].green = gray + 20;
            (*image)[index].blue = gray - 20;
        }
    }
}

void invert(pixel **image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = i * width + j;
            (*image)[index].red = 255 - (*image)[index].red;
            (*image)[index].green = 255 - (*image)[index].green;
            (*image)[index].blue = 255 - (*image)[index].blue;
        }
    }
}

void mirror(pixel **image, int width, int height) {
    int half = width / 2;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < half; j++) {
            int index1 = i * width + j;
            int index2 = i * width + (width - j - 1);

            pixel temp = (*image)[index1];
            (*image)[index1] = (*image)[index2];
            (*image)[index2] = temp;
        }
    }
}

void blur(pixel **image, int width, int height, int radius) {
    pixel *blurImage = (pixel *) malloc(width * height * sizeof(pixel));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int red = 0, green = 0, blue = 0, count = 0;

            for (int x = i - radius; x <= i + radius; x++) {
                for (int y = j - radius; y <= j + radius; y++) {
                    if (x >= 0 && x < height && y >= 0 && y < width) {
                        int index = x * width + y;
                        red += (*image)[index].red;
                        green += (*image)[index].green;
                        blue += (*image)[index].blue;
                        count++;
                    }
                }
            }

            int index = i * width + j;
            blurImage[index].red = round((double) red / count);
            blurImage[index].green = round((double) green / count);
            blurImage[index].blue = round((double) blue / count);
        }
    }

    memcpy(*image, blurImage, width * height * sizeof(pixel));
}

int main(int argc, char **argv) {
    int choice, radius, width, height;
    char file_name[MAX_FILE_NAME];
    pixel *image = NULL;

    if (argc == 1) {
        printf("Enter file name: ");
        scanf("%s", file_name);
    } else {
        strcpy(file_name, argv[1]);
    }

    read_image(file_name, &image, &width, &height);

    printf("1. Grayscale\n");
    printf("2. Sepia\n");
    printf("3. Invert\n");
    printf("4. Mirror\n");
    printf("5. Blur\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            grayscale(&image, width, height);
            break;
        case 2:
            sepia(&image, width, height);
            break;
        case 3:
            invert(&image, width, height);
            break;
        case 4:
            mirror(&image, width, height);
            break;
        case 5:
            printf("Enter blur radius: ");
            scanf("%d", &radius);
            blur(&image, width, height, radius);
            break;
        default:
            printf("Invalid choice!\n");
            exit(1);
    }

    char *out_file_name = "output.ppm";
    write_image(out_file_name, image, width, height);

    printf("Image saved as %s!\n", out_file_name);

    free(image);
    return 0;
}