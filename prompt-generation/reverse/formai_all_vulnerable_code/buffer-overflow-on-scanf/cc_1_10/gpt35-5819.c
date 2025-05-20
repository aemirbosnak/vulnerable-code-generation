//FormAI DATASET v1.0 Category: Image Editor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_PIXEL_VALUE 255

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    Pixel *pixels;
    int width;
    int height;
} Image;

void grayscale(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int index = i * img->width + j;
            unsigned char average = (img->pixels[index].red + img->pixels[index].green + img->pixels[index].blue) / 3;
            img->pixels[index].red = img->pixels[index].green = img->pixels[index].blue = average;
        }
    }
}

void invert(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int index = i * img->width + j;
            img->pixels[index].red = MAX_PIXEL_VALUE - img->pixels[index].red;
            img->pixels[index].green = MAX_PIXEL_VALUE - img->pixels[index].green;
            img->pixels[index].blue = MAX_PIXEL_VALUE - img->pixels[index].blue;
        }
    }
}

void blur(Image *img) {
    Image *temp = malloc(sizeof(Image));
    temp->pixels = malloc(sizeof(Pixel) * img->width * img->height);
    temp->width = img->width;
    temp->height = img->height;

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int index = i * img->width + j;
            int count = 0;
            int total_red = 0, total_green = 0, total_blue = 0;

            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int x = i + k;
                    int y = j + l;

                    if (x >= 0 && y >= 0 && x < img->height && y < img->width) {
                        int neighbor_index = x * img->width + y;
                        total_red += img->pixels[neighbor_index].red;
                        total_green += img->pixels[neighbor_index].green;
                        total_blue += img->pixels[neighbor_index].blue;
                        count++;
                    }
                }
            }

            temp->pixels[index].red = total_red / count;
            temp->pixels[index].green = total_green / count;
            temp->pixels[index].blue = total_blue / count;
        }
    }

    memcpy(img->pixels, temp->pixels, sizeof(Pixel) * img->width * img->height);
    free(temp->pixels);
    free(temp);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    Image *img = malloc(sizeof(Image));
    char header[54];
    fread(header, sizeof(char), 54, fp);
    img->width = *(int*)&header[18];
    img->height = *(int*)&header[22];
    int bpp = *(int*)&header[28];

    if (bpp != 24) {
        printf("Error: Unsupported bit depth.\n");
        return 1;
    }

    int padding = 4 - ((img->width * 3) % 4);
    if (padding == 4) padding = 0;

    img->pixels = malloc(sizeof(Pixel) * img->width * img->height);

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int index = i * img->width + j;
            Pixel p;
            fread(&p.blue, 1, 1, fp);
            fread(&p.green, 1, 1, fp);
            fread(&p.red, 1, 1, fp);
            img->pixels[index] = p;
        }

        fseek(fp, padding, SEEK_CUR);
    }

    fclose(fp);

    int choice = -1;

    while (choice != 4) {
        printf("\n1. Grayscale\n");
        printf("2. Invert\n");
        printf("3. Blur\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                grayscale(img);
                printf("Grayscale conversion successful.\n");
                break;
            case 2:
                invert(img);
                printf("Inversion successful.\n");
                break;
            case 3:
                blur(img);
                printf("Blurring successful.\n");
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    fp = fopen("output.bmp", "wb");
    fwrite(header, sizeof(char), 54, fp);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int index = i * img->width + j;
            fwrite(&img->pixels[index].blue, 1, 1, fp);
            fwrite(&img->pixels[index].green, 1, 1, fp);
            fwrite(&img->pixels[index].red, 1, 1, fp);
        }

        for (int j = 0; j < padding; j++) {
            fwrite("\0", 1, 1, fp);
        }
    }

    fclose(fp);
    free(img->pixels);
    free(img);

    return 0;
}