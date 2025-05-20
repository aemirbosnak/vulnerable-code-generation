//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image* loadPGM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open the image file");
        return NULL;
    }

    char buffer[16];
    int maxval;
    Image *img = malloc(sizeof(Image));
    
    if (!img) {
        perror("Unable to allocate memory for the image");
        fclose(file);
        return NULL;
    }

    // Read image type
    if (!fgets(buffer, sizeof(buffer), file)) {
        perror("Error reading image type");
        free(img);
        fclose(file);
        return NULL;
    }

    // Read image size information
    fscanf(file, "%d %d", &img->width, &img->height);

    // Read maximum pixel value
    fscanf(file, "%d", &maxval);
    fgetc(file);  // consume the newline

    // Allocate memory for the pixel data
    img->data = (unsigned char *)malloc(img->width * img->height);
    if (!img->data) {
        perror("Unable to allocate memory for pixel data");
        free(img);
        fclose(file);
        return NULL;
    }

    // Read pixel data
    fread(img->data, 1, img->width * img->height, file);
    fclose(file);
    return img;
}

void freeImage(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

double calculateMeanBrightness(Image *img) {
    long sum = 0;
    for (int i = 0; i < img->width * img->height; i++) {
        sum += img->data[i];
    }
    return (double)sum / (img->width * img->height);
}

const char* classifyImage(double meanBrightness) {
    // Simple threshold to classify images (this should be learned from real data)
    if (meanBrightness < 100) {
        return "Dog";
    } else {
        return "Cat";
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image_file.pgm>\n", argv[0]);
        return 1;
    }

    Image *img = loadPGM(argv[1]);
    if (!img) {
        return 1;
    }

    double meanBrightness = calculateMeanBrightness(img);
    const char *classification = classifyImage(meanBrightness);

    printf("The image is classified as: %s\n", classification);

    freeImage(img);
    return 0;
}