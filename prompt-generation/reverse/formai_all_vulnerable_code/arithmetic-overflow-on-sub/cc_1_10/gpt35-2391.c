//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} image;

image* load_bmp(char *filename);
void save_bmp(char *filename, image *img);
void flip(image *img);
void change_brightness(image *img, int value);
void change_contrast(image *img, float value);

int main() {
    char filename[100];
    printf("Enter the filename of the BMP image: ");
    scanf("%s", filename);
    printf("Loading image...\n");
    image *img = load_bmp(filename);
    if (img != NULL) {
        printf("Image loaded successfully!\n");
        int choice = 0;
        while (choice != 4) {
            printf("What would you like to do?\n");
            printf("1. Flip the image\n");
            printf("2. Change the brightness\n");
            printf("3. Change the contrast\n");
            printf("4. Save and exit\n");
            printf("> ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Flipping image...\n");
                    flip(img);
                    printf("Image flipped!\n");
                    break;
                case 2:
                    printf("Enter the brightness change value (from -255 to 255): ");
                    int brightness_value;
                    scanf("%d", &brightness_value);
                    printf("Changing brightness...\n");
                    change_brightness(img, brightness_value);
                    printf("Brightness changed!\n");
                    break;
                case 3:
                    printf("Enter the contrast change value (from 0.1 to 10.0): ");
                    float contrast_value;
                    scanf("%f", &contrast_value);
                    printf("Changing contrast...\n");
                    change_contrast(img, contrast_value);
                    printf("Contrast changed!\n");
                    break;
                case 4:
                    printf("Saving image and exiting...\n");
                    save_bmp(filename, img);
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
            }
        }
    }
    return 0;
}

image* load_bmp(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: unable to open file.\n");
        return NULL;
    }
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    unsigned int size = *(unsigned int*)&header[2];
    unsigned int offset = *(unsigned int*)&header[10];
    unsigned char *data = (unsigned char*) malloc(size);
    fseek(file, offset, SEEK_SET);
    fread(data, sizeof(unsigned char), size, file);
    fclose(file);
    image *img = (image*) malloc(sizeof(image));
    if (img == NULL) {
        printf("Error: unable to allocate memory.\n");
        return NULL;
    }
    img->width = width;
    img->height = height;
    img->data = data;
    return img;
}

void save_bmp(char *filename, image *img) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: unable to open file.\n");
        return;
    }
    unsigned char header[54] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0,
        54, 0, 0, 0, 40, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        1, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    *(int*)&header[2] = 54 + (img->width * 3 + img->width % 4) * img->height;
    *(int*)&header[18] = img->width;
    *(int*)&header[22] = img->height;
    fwrite(header, sizeof(unsigned char), 54, file);
    unsigned int padding = img->width % 4;
    if (padding > 0) padding = 4 - padding;
    unsigned int size = img->width * img->height * 3 + padding * img->height;
    unsigned char *data_out = (unsigned char*) malloc(size);
    if (data_out == NULL) {
        printf("Error: unable to allocate memory.\n");
        return;
    }
    for (int y = img->height - 1; y >= 0; y--) {
        unsigned char *row_in = &img->data[y * img->width * 3];
        unsigned char *row_out = &data_out[(img->height - 1 - y) * (img->width * 3 + padding)];
        for (int x = 0; x < img->width; x++) {
            row_out[3 * x + 0] = row_in[3 * x + 2];
            row_out[3 * x + 1] = row_in[3 * x + 1];
            row_out[3 * x + 2] = row_in[3 * x + 0];
        }
        for (int p = 0; p < padding; p++)
            row_out[img->width * 3 + p] = 0;
    }
    fwrite(data_out, sizeof(unsigned char), size, file);
    fclose(file);
    free(data_out);
}

void flip(image *img) {
    unsigned char *temp = (unsigned char*)malloc(img->width * 3);
    if (temp == NULL) {
        printf("Error: unable to allocate memory.\n");
        return;
    }
    for (int y = 0; y < img->height / 2; y++) {
        int y2 = img->height - 1 - y;
        unsigned char *row1 = &img->data[y * img->width * 3];
        unsigned char *row2 = &img->data[y2 * img->width * 3];
        memcpy(temp, row1, img->width * 3);
        memcpy(row1, row2, img->width * 3);
        memcpy(row2, temp, img->width * 3);
    }
    free(temp);
}

void change_brightness(image *img, int value) {
    for (int y = 0; y < img->height; y++) {
        unsigned char *row = &img->data[y * img->width * 3];
        for (int x = 0; x < img->width; x++) {
            int r = row[3 * x + 2] + value;
            int g = row[3 * x + 1] + value;
            int b = row[3 * x + 0] + value;
            if (r < 0) r = 0;
            if (g < 0) g = 0;
            if (b < 0) b = 0;
            if (r > 255) r = 255;
            if (g > 255) g = 255;
            if (b > 255) b = 255;
            row[3 * x + 2] = r;
            row[3 * x + 1] = g;
            row[3 * x + 0] = b;
        }
    }
}

void change_contrast(image *img, float value) {
    float factor = (259 * (value + 255)) / (255 * (259 - value));
    for (int y = 0; y < img->height; y++) {
        unsigned char *row = &img->data[y * img->width * 3];
        for (int x = 0; x < img->width; x++) {
            int r = (int)(factor * (row[3 * x + 2] - 128) + 128);
            int g = (int)(factor * (row[3 * x + 1] - 128) + 128);
            int b = (int)(factor * (row[3 * x + 0] - 128) + 128);
            if (r < 0) r = 0;
            if (g < 0) g = 0;
            if (b < 0) b = 0;
            if (r > 255) r = 255;
            if (g > 255) g = 255;
            if (b > 255) b = 255;
            row[3 * x + 2] = r;
            row[3 * x + 1] = g;
            row[3 * x + 0] = b;
        }
    }
}