//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

/* Function to read the image from a BMP file */
Image *read_bmp(char *filename) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return NULL;
    }

    /* Read the BMP header */
    unsigned char bmp_header[54];
    fread(bmp_header, sizeof(unsigned char), 54, f);
    int width = *(int*)&bmp_header[18];
    int height = *(int*)&bmp_header[22];
    int offset = *(int*)&bmp_header[10];

    /* Ignore the color table */
    fseek(f, offset - 54, SEEK_CUR);

    /* Read the image data */
    Pixel *data = (Pixel*) malloc(width * height * sizeof(Pixel));
    fread(data, sizeof(Pixel), width * height, f);

    fclose(f);

    /* Create the Image object */
    Image *img = (Image*) malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = data;
    return img;
}

/* Function to write the image to a BMP file */
int write_bmp(Image *img, char *filename) {
    FILE *f = fopen(filename, "wb");
    if (f == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return 0;
    }

    /* Write the BMP header */
    unsigned char bmp_header[54] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 40, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    int width = img->width;
    int height = img->height;
    int size = width * height * 3;
    bmp_header[2] = (unsigned char) (size);
    bmp_header[3] = (unsigned char) (size >> 8);
    bmp_header[4] = (unsigned char) (size >> 16);
    bmp_header[5] = (unsigned char) (size >> 24);
    bmp_header[18] = (unsigned char) (width);
    bmp_header[19] = (unsigned char) (width >> 8);
    bmp_header[20] = (unsigned char) (width >> 16);
    bmp_header[21] = (unsigned char) (width >> 24);
    bmp_header[22] = (unsigned char) (height);
    bmp_header[23] = (unsigned char) (height >> 8);
    bmp_header[24] = (unsigned char) (height >> 16);
    bmp_header[25] = (unsigned char) (height >> 24);
    fwrite(bmp_header, sizeof(unsigned char), 54, f);

    /* Write the image data */
    fwrite(img->data, sizeof(Pixel), width * height, f);

    fclose(f);
    return 1;
}

/* Function to flip the image horizontally */
void flip_h(Image *img) {
    int width = img->width;
    int height = img->height;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            Pixel tmp = img->data[y * width + x];
            img->data[y * width + x] = img->data[y * width + (width-1-x)];
            img->data[y * width + (width-1-x)] = tmp;
        }
    }
}

/* Function to change the brightness and contrast of the image */
void adjust_bc(Image *img, float brightness, float contrast) {
    int width = img->width;
    int height = img->height;
    for (int i = 0; i < width * height; i++) {
        Pixel *p = &img->data[i];
        p->r = (unsigned char) (brightness + contrast * (float) p->r);
        p->g = (unsigned char) (brightness + contrast * (float) p->g);
        p->b = (unsigned char) (brightness + contrast * (float) p->b);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input file> <output file> <brightness/contrast>\n", argv[0]);
        return 1;
    }

    /* Read the input image */
    Image *img = read_bmp(argv[1]);
    if (img == NULL) {
        return 1;
    }

    /* Apply the transformations */
    flip_h(img);
    float bc = atof(argv[3]);
    adjust_bc(img, bc, bc);

    /* Write the output image */
    if (!write_bmp(img, argv[2])) {
        return 1;
    }

    return 0;
}