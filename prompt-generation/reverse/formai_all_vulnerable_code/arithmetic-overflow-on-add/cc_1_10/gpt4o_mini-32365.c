//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    fseek(file, 18, SEEK_SET);
    Image *img = (Image *)malloc(sizeof(Image));
    fread(&img->width, sizeof(int), 1, file);
    fread(&img->height, sizeof(int), 1, file);
    
    img->pixels = malloc(img->width * img->height * sizeof(Pixel));
    fseek(file, 54, SEEK_SET); // Skip the BMP header
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
    
    fclose(file);
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    unsigned char bmpfileheader[54] = {
        'B', 'M',  // BMP signature
        0, 0, 0, 0, // File size (to be filled later)
        0, 0,      // Reserved1
        0, 0,      // Reserved2
        54, 0, 0, 0 // Start of pixel array
    };

    int pixelArraySize = img->width * img->height * 3;
    int filesize = 54 + pixelArraySize;

    // Fill in the file size
    bmpfileheader[2] = (unsigned char)(filesize);
    bmpfileheader[3] = (unsigned char)(filesize >> 8);
    bmpfileheader[4] = (unsigned char)(filesize >> 16);
    bmpfileheader[5] = (unsigned char)(filesize >> 24);

    fwrite(bmpfileheader, sizeof(unsigned char), 54, file);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    
    fclose(file);
}

void embed_watermark(Image *img, const char *watermark) {
    int len = strlen(watermark);
    for (int i = 0; i < len && i < img->width * img->height; i++) {
        Pixel *p = &img->pixels[i];
        // Modifying the red channel to embed watermark
        p->r = (p->r & 0xFE) | ((watermark[i] >> 7) & 0x01);
    }
}

char* extract_watermark(Image *img, int length) {
    char *watermark = (char *)malloc(length + 1);
    for (int i = 0; i < length; i++) {
        Pixel *p = &img->pixels[i];
        watermark[i] = ((p->r & 0x01) << 7);
    }
    watermark[length] = '\0';
    return watermark;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> <watermark>\n", argv[0]);
        return 1;
    }

    Image *img = load_image(argv[1]);
    if (!img) return 1;

    embed_watermark(img, argv[3]);
    save_image(argv[2], img);

    printf("Watermark embedded successfully!\n");

    // Extract the watermark for verification
    char *extracted = extract_watermark(img, strlen(argv[3]));
    printf("Extracted watermark: %s\n", extracted);

    free(extracted);
    free(img->pixels);
    free(img);
    
    return 0;
}