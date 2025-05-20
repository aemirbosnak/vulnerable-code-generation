//FormAI DATASET v1.0 Category: Image Editor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

typedef struct image {
    Pixel *pixels;
    int width;
    int height;
} Image;

void printMenu() {
    printf("Welcome to the C Image Editor\n");
    printf("1. Load an image\n");
    printf("2. Flip image horizontally\n");
    printf("3. Invert colors\n");
    printf("4. Save image\n");
    printf("5. Exit\n");
}

void loadFile(char *filename, Image *image) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error loading file\n");
        return;
    }
    char p[3];
    fgets(p, 3, fp);  // read P6
    fscanf(fp, "%d %d", &image->width, &image->height);
    int maxVal;
    fscanf(fp, "%d", &maxVal);
    fgetc(fp);  // read single whitespace character
    image->pixels = malloc(sizeof(Pixel) * image->width * image->height);
    fread(image->pixels, sizeof(Pixel), image->width * image->height, fp);
    fclose(fp);
}

void flipImage(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            int index1 = i * image->width + j;
            int index2 = i * image->width + (image->width - j - 1);
            Pixel temp = image->pixels[index1];
            image->pixels[index1] = image->pixels[index2];
            image->pixels[index2] = temp;
        }
    }
}

void invertColors(Image *image) {
    for (int i = 0; i < image->height * image->width; i++) {
        Pixel *p = &image->pixels[i];
        p->r = 255 - p->r;
        p->g = 255 - p->g;
        p->b = 255 - p->b;
    }
}

void saveFile(char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error saving file\n");
        return;
    }
    fputs("P6\n", fp);
    fprintf(fp, "%d %d\n", image->width, image->height);
    fputs("255\n", fp);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, fp);
    fclose(fp);
}

int main() {
    Image image;
    int choice = 0;
    char filename[100];
    while (choice != 5) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", filename);
                loadFile(filename, &image);
                break;
            case 2:
                flipImage(&image);
                break;
            case 3:
                invertColors(&image);
                break;
            case 4:
                printf("Enter filename: ");
                scanf("%s", filename);
                saveFile(filename, &image);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }
    free(image.pixels);
    return 0;
}