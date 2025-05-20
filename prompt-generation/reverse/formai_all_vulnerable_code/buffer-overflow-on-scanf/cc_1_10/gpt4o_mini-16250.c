//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_VALUE 255

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

// Function declarations
Image* loadPPM(const char *filename);
void savePPM(const char *filename, Image *img);
void invertColors(Image *img);
void convertToGrayscale(Image *img);
void freeImage(Image *img);
void printMenu();

int main() {
    char inputFile[256], outputFile[256];
    int choice;

    printf("Enter the input PPM file name: ");
    scanf("%s", inputFile);
    
    Image *img = loadPPM(inputFile);
    if (!img) {
        fprintf(stderr, "Failed to load the image.\n");
        return EXIT_FAILURE;
    }

    while (1) {
        printMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                invertColors(img);
                printf("Inverted colors successfully.\n");
                break;
            case 2:
                convertToGrayscale(img);
                printf("Converted to grayscale successfully.\n");
                break;
            case 3:
                printf("Enter output file name to save the modified image: ");
                scanf("%s", outputFile);
                savePPM(outputFile, img);
                printf("Image saved as %s.\n", outputFile);
                break;
            case 4:
                printf("Exiting the program.\n");
                freeImage(img);
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    freeImage(img);
    return EXIT_SUCCESS;
}

Image* loadPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    char header[3];
    fscanf(file, "%2s", header);

    if (strcmp(header, "P6") != 0) {
        fclose(file);
        fprintf(stderr, "Unsupported PPM format. Only P6 (binary) is supported.\n");
        return NULL;
    }

    Image *img = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file);  // consume the newline after maxval

    img->data = (Pixel *)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);

    fclose(file);
    return img;
}

void savePPM(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    fprintf(file, "P6\n%d %d\n%d\n", img->width, img->height, MAX_COLOR_VALUE);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);

    fclose(file);
}

void invertColors(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = MAX_COLOR_VALUE - img->data[i].r;
        img->data[i].g = MAX_COLOR_VALUE - img->data[i].g;
        img->data[i].b = MAX_COLOR_VALUE - img->data[i].b;
    }
}

void convertToGrayscale(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char gray = 0.299 * img->data[i].r + 0.587 * img->data[i].g + 0.114 * img->data[i].b;
        img->data[i].r = img->data[i].g = img->data[i].b = gray;
    }
}

void freeImage(Image *img) {
    free(img->data);
    free(img);
}

void printMenu() {
    printf("\nImage Editor Menu:\n");
    printf("1. Invert Colors\n");
    printf("2. Convert to Grayscale\n");
    printf("3. Save Image\n");
    printf("4. Exit\n");
}