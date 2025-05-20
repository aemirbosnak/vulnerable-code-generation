//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char red, green, blue;
} Pixel;

typedef struct {
    Pixel *data;
    int width, height;
} Image;

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

void flip(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width / 2; j++) {
            int k = img->width - j - 1;
            Pixel tmp = img->data[i * img->width + j];
            img->data[i * img->width + j] = img->data[i * img->width + k];
            img->data[i * img->width + k] = tmp;
        }
    }
}

void adjustBrightness(Image *img, int delta) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->data[i * img->width + j].red = max(0, min(255, img->data[i * img->width + j].red + delta));
            img->data[i * img->width + j].green = max(0, min(255, img->data[i * img->width + j].green + delta));
            img->data[i * img->width + j].blue = max(0, min(255, img->data[i * img->width + j].blue + delta));
        }
    }
}

void adjustContrast(Image *img, float factor) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->data[i * img->width + j].red = max(0, min(255, img->data[i * img->width + j].red * factor));
            img->data[i * img->width + j].green = max(0, min(255, img->data[i * img->width + j].green * factor));
            img->data[i * img->width + j].blue = max(0, min(255, img->data[i * img->width + j].blue * factor));
        }
    }
}

int main() {
    Image img;
    int choice;
    char filename[256];
    printf("Enter filename of image: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Unable to open file %s\n", filename);
        exit(1);
    }
    unsigned char header[54];
    if (fread(header, sizeof(unsigned char), 54, file) != 54) {
        printf("Unable to read header of file %s\n", filename);
        exit(1);
    }
    img.width = *(int*)&header[18];
    img.height = *(int*)&header[22];
    int dimensions = img.width * img.height;
    if (*(int*)&header[28] != 24 || dimensions > (1 << 20)) {
        printf("Unsupported image format or image size too large\n");
        exit(1);
    }
    img.data = (Pixel*)malloc(dimensions * sizeof(Pixel));
    if (!img.data) {
        printf("Unable to allocate memory for image data\n");
        exit(1);
    }
    unsigned char buffer[3];
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            fread(buffer, sizeof(unsigned char), 3, file);
            img.data[i * img.width + j].red = buffer[2];
            img.data[i * img.width + j].green = buffer[1];
            img.data[i * img.width + j].blue = buffer[0];
        }
    }
    fclose(file);
    printf("Select operation:\n");
    printf("1: Flip image horizontally\n");
    printf("2: Adjust brightness\n");
    printf("3: Adjust contrast\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            flip(&img);
            break;
        case 2:
            printf("Enter brightness delta: ");
            int delta;
            scanf("%d", &delta);
            adjustBrightness(&img, delta);
            break;
        case 3:
            printf("Enter contrast factor: ");
            float factor;
            scanf("%f", &factor);
            adjustContrast(&img, factor);
            break;
        default:
            printf("Invalid choice\n");
            exit(1);
    }
    sprintf(filename, "%s.out.bmp", filename);
    file = fopen(filename, "wb");
    if (!file) {
        printf("Unable to open output file %s\n", filename);
        exit(1);
    }
    if (fwrite(header, sizeof(unsigned char), 54, file) != 54) {
        printf("Unable to write header of output file %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            buffer[2] = img.data[i * img.width + j].red;
            buffer[1] = img.data[i * img.width + j].green;
            buffer[0] = img.data[i * img.width + j].blue;
            fwrite(buffer, sizeof(unsigned char), 3, file);
        }
    }
    fclose(file);
    free(img.data);
    return 0;
}