//FormAI DATASET v1.0 Category: Image Editor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 100

void flip_horizontal(int width, int height, unsigned char image[][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            unsigned char temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

void flip_vertical(int width, int height, unsigned char image[][width]) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image[i][j];
            image[i][j] = image[height - i - 1][j];
            image[height - i - 1][j] = temp;
        }
    }
}

void grayscale(int width, int height, unsigned char image[][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char r = image[i][j] & 0xFF;
            unsigned char g = (image[i][j] >> 8) & 0xFF;
            unsigned char b = (image[i][j] >> 16) & 0xFF;

            unsigned char gray = (r + g + b) / 3;

            image[i][j] = (gray << 16) + (gray << 8) + gray;
        }
    }
}

void save_image(int width, int height, unsigned char image[][width], char *filename) {
    FILE *fp = fopen(filename, "wb");

    if (fp == NULL) {
        printf("Failed to save image to file %s\n", filename);
        return;
    }

    static unsigned char bmp_file_header[14] = {
        0x42, 0x4D, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x36, 0x00, 0x00, 0x00
    };

    static unsigned char bmp_info_header[40] = {
        0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x12, 0x0B, 0x00, 0x00, 0x12, 0x0B, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    int row_size = ((width * 3) + 3) & (~3);

    int file_size = row_size * height + 54;

    bmp_file_header[2] = (unsigned char)(file_size);
    bmp_file_header[3] = (unsigned char)(file_size >> 8);
    bmp_file_header[4] = (unsigned char)(file_size >> 16);
    bmp_file_header[5] = (unsigned char)(file_size >> 24);

    bmp_info_header[4] = (unsigned char)(width);
    bmp_info_header[5] = (unsigned char)(width >> 8);
    bmp_info_header[6] = (unsigned char)(width >> 16);
    bmp_info_header[7] = (unsigned char)(width >> 24);

    bmp_info_header[8] = (unsigned char)(height);
    bmp_info_header[9] = (unsigned char)(height >> 8);
    bmp_info_header[10] = (unsigned char)(height >> 16);
    bmp_info_header[11] = (unsigned char)(height >> 24);

    fwrite(bmp_file_header, 1, 14, fp);
    fwrite(bmp_info_header, 1, 40, fp);

    unsigned char *data = (unsigned char *)malloc(row_size * height);
    memset(data, 0, row_size * height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            data[i * row_size + j * 3] = image[i][j] & 0xFF;
            data[i * row_size + j * 3 + 1] = (image[i][j] >> 8) & 0xFF;
            data[i * row_size + j * 3 + 2] = (image[i][j] >> 16) & 0xFF;
        }
    }

    fwrite(data, 1, row_size * height, fp);

    fclose(fp);
    free(data);

    printf("Image saved to file %s\n", filename);
}

int main() {
    char filename[MAX_FILENAME_SIZE];

    printf("Enter the filename of the image you want to edit: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        return 1;
    }

    unsigned char bmp_file_header[14];
    unsigned char bmp_info_header[40];

    fread(bmp_file_header, 1, 14, fp);
    fread(bmp_info_header, 1, 40, fp);

    int width = *(int *)&bmp_info_header[4];
    int height = *(int *)&bmp_info_header[8];

    int row_size = ((width * 3) + 3) & (~3);

    unsigned char *data = (unsigned char *)malloc(row_size * height);

    fread(data, 1, row_size * height, fp);
    fclose(fp);

    unsigned char (*image)[width] = (unsigned char (*)[width])data;

    printf("What do you want to do with the image?\n");
    printf("1. Flip horizontally\n");
    printf("2. Flip vertically\n");
    printf("3. Convert to grayscale\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            flip_horizontal(width, height, image);
            break;
        case 2:
            flip_vertical(width, height, image);
            break;
        case 3:
            grayscale(width, height, image);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    printf("What do you want to name the edited image? (include .bmp extension)\n");

    char new_filename[MAX_FILENAME_SIZE];
    scanf("%s", new_filename);

    save_image(width, height, image, new_filename);

    return 0;
}