//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _image {
    unsigned char *data;
    int width;
    int height;
} Image;

typedef struct _watermark {
    unsigned char *data;
    int width;
    int height;
} Watermark;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fclose(fp);
        return NULL;
    }

    fseek(fp, 10, SEEK_SET);
    fread(&image->width, 4, 1, fp);
    fread(&image->height, 4, 1, fp);
    fseek(fp, 18, SEEK_SET);

    image->data = malloc(image->width * image->height);
    if (!image->data) {
        free(image);
        fclose(fp);
        return NULL;
    }

    fread(image->data, image->width * image->height, 1, fp);
    fclose(fp);

    return image;
}

void write_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        return;
    }

    fseek(fp, 10, SEEK_SET);
    fwrite(&image->width, 4, 1, fp);
    fwrite(&image->height, 4, 1, fp);
    fseek(fp, 18, SEEK_SET);

    fwrite(image->data, image->width * image->height, 1, fp);
    fclose(fp);
}

Watermark *read_watermark(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        return NULL;
    }

    Watermark *watermark = malloc(sizeof(Watermark));
    if (!watermark) {
        fclose(fp);
        return NULL;
    }

    fseek(fp, 10, SEEK_SET);
    fread(&watermark->width, 4, 1, fp);
    fread(&watermark->height, 4, 1, fp);
    fseek(fp, 18, SEEK_SET);

    watermark->data = malloc(watermark->width * watermark->height);
    if (!watermark->data) {
        free(watermark);
        fclose(fp);
        return NULL;
    }

    fread(watermark->data, watermark->width * watermark->height, 1, fp);
    fclose(fp);

    return watermark;
}

void write_watermark(const char *filename, Watermark *watermark) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        return;
    }

    fseek(fp, 10, SEEK_SET);
    fwrite(&watermark->width, 4, 1, fp);
    fwrite(&watermark->height, 4, 1, fp);
    fseek(fp, 18, SEEK_SET);

    fwrite(watermark->data, watermark->width * watermark->height, 1, fp);
    fclose(fp);
}

void embed_watermark(Image *image, Watermark *watermark) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            image->data[i * image->width + j] = (image->data[i * image->width + j] & 0xF0) | (watermark->data[i * watermark->width + j] & 0x0F);
        }
    }
}

void extract_watermark(Image *image, Watermark *watermark) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            watermark->data[i * watermark->width + j] = image->data[i * image->width + j] & 0x0F;
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s image watermark output\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        printf("Error reading image file %s\n", argv[1]);
        return 1;
    }

    Watermark *watermark = read_watermark(argv[2]);
    if (!watermark) {
        printf("Error reading watermark file %s\n", argv[2]);
        return 1;
    }

    if (image->width != watermark->width || image->height != watermark->height) {
        printf("Error: image and watermark must have the same dimensions\n");
        return 1;
    }

    embed_watermark(image, watermark);

    write_image(argv[3], image);

    printf("Watermarked image saved to %s\n", argv[3]);

    return 0;
}