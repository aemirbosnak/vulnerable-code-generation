//FormAI DATASET v1.0 Category: Image Steganography ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_TO_BITS(x) (x * 8)

void hide_data_in_image(char *image_path, char *res_path, char *data) {
    FILE *image = fopen(image_path, "rb");
    FILE *res = fopen(res_path, "wb");

    if (!image || !res) {
        printf("Error opening files\n");
        return;
    }

    char header[54];
    fread(header, sizeof(char), 54, image);
    fwrite(header, sizeof(char), 54, res);

    int image_size = *(int*)&header[2];
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bits_per_pixel = *(int*)&header[28];

    if (bits_per_pixel != 24) {
        printf("Error: Unsupported image format\n");
        return;
    }

    int max_size = image_size - 54;
    int data_size = strlen(data);

    if (data_size > max_size) {
        printf("Error: Data size exceeds image capacity\n");
        return;
    }

    int bit_pos = 0;
    for (int i = 0; i < data_size; i++) {
        char c = data[i];
        for (int j = 0; j < 8; j++) {
            char bit = (c >> j) & 1;
            fseek(image, bit_pos++, SEEK_SET);
            char pixel;
            fread(&pixel, sizeof(char), 1, image);
            pixel &= ~(1UL << 0);
            pixel |= bit << 0;
            fwrite(&pixel, sizeof(char), 1, res);
        }
    }

    char eof = '\0';
    for (int i = 0; i < BYTES_TO_BITS(sizeof(eof)); i++) {
        char bit = (eof >> i) & 1;
        fseek(image, bit_pos++, SEEK_SET);
        char pixel;
        fread(&pixel, sizeof(char), 1, image);
        pixel &= ~(1UL << 0);
        pixel |= bit << 0;
        fwrite(&pixel, sizeof(char), 1, res);
    }

    char pixel;
    while (fread(&pixel, sizeof(char), 1, image)) {
        fwrite(&pixel, sizeof(char), 1, res);
    }

    fclose(image);
    fclose(res);

    printf("Data successfully hidden in image\n");
}

void extract_data_from_image(char *res_path, int data_size) {
    FILE *res = fopen(res_path, "rb");

    if (!res) {
        printf("Error opening files\n");
        return;
    }

    char header[54];
    fread(header, sizeof(char), 54, res);

    int image_size = *(int*)&header[2];
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bits_per_pixel = *(int*)&header[28];

    if (bits_per_pixel != 24) {
        printf("Error: Unsupported image format\n");
        return;
    }

    int bit_pos = 0;
    for (int i = 0; i < data_size; i++) {
        char c = '\0';
        for (int j = 0; j < 8; j++) {
            fseek(res, bit_pos++, SEEK_SET);
            char pixel;
            fread(&pixel, sizeof(char), 1, res);
            char bit = (pixel >> 0) & 1;
            c |= (bit << j);
        }
        printf("%c", c);
    }

    fclose(res);
}

int main() {
    char image_path[] = "image.bmp";
    char res_path[] = "hidden_image.bmp";
    char data_to_hide[] = "This is some hidden data in an image!";

    hide_data_in_image(image_path, res_path, data_to_hide);
    extract_data_from_image(res_path, strlen(data_to_hide));

    return 0;
}