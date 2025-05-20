//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256
#define WATERMARK "WATERMARKED"

typedef struct {
    int width;
    int height;
    unsigned char* data; // Assuming RGB format for simplicity
} Image;

void printUsage() {
    printf("Usage: ./watermark [input_image.ppm] [output_image.ppm]\n");
}

Image* load_ppm(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file for reading");
        return NULL;
    }

    Image* img = (Image*)malloc(sizeof(Image));
    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P6") != 0) {
        fclose(file);
        fprintf(stderr, "Unsupported file format. Use P6 PPM.\n");
        return NULL;
    }
    fscanf(file, "%d %d", &img->width, &img->height);
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file); // Skip newline

    img->data = (unsigned char*)malloc(img->width * img->height * 3);
    fread(img->data, 3, img->width * img->height, file);
    fclose(file);

    return img;
}

void save_ppm(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, 3, img->width * img->height, file);
    fclose(file);
}

void embedWatermark(Image* img, const char* watermark) {
    int wm_length = strlen(watermark);
    for (int i = 0; i < wm_length && i < img->width; i++) {
        // Embed watermark into the first row
        img->data[i * 3] = (img->data[i * 3] & 0xFE) | (watermark[i] & 0x01); // Modify red channel
    }
}

void extractWatermark(Image* img, char* extracted_wm, int length) {
    for (int i = 0; i < length; i++) {
        extracted_wm[i] = (img->data[i * 3] & 0x01) ? '1' : '0';
    }
    extracted_wm[length] = '\0'; // Null-terminate string
}

void freeImage(Image* img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printUsage();
        return EXIT_FAILURE;
    }

    Image* original = load_ppm(argv[1]);
    if (!original) {
        return EXIT_FAILURE;
    }

    // Embed the watermark into the image
    embedWatermark(original, WATERMARK);

    // Save the watermarked image
    save_ppm(argv[2], original);

    // Extract watermark for verification
    char extracted_wm[MAX_SIZE];
    extractWatermark(original, extracted_wm, strlen(WATERMARK));

    printf("Extracted watermark: %s\n", extracted_wm);

    // Free allocated memory
    freeImage(original);

    return EXIT_SUCCESS;
}