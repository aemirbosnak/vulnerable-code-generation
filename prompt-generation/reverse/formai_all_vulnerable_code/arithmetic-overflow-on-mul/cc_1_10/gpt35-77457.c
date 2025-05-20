//FormAI DATASET v1.0 Category: Image Steganography ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} rgbpixel;

typedef struct {
    int width;
    int height;
    rgbpixel* data;
} rgbimage;

bool encode_text(unsigned char* text, int text_len, rgbimage* image) {
    if (text_len + 1 > (image->width * image->height)) {
        printf("Text too long to encode in image.\n");
        return false;
    }

    int pixel_idx = 0;
    for (int i = 0; i < text_len; i++, pixel_idx++) {
        image->data[pixel_idx].r &= 254; // clear the least significant bit of the red component
        image->data[pixel_idx].r |= ((text[i] & 128) >> 7); // set the most significant bit of the red component to the first bit of the text character
        image->data[pixel_idx].g &= 254; // clear the least significant bit of the green component
        image->data[pixel_idx].g |= ((text[i] & 64) >> 6); // set the most significant bit of the green component to the second bit of the text character
        image->data[pixel_idx].b &= 254; // clear the least significant bit of the blue component
        image->data[pixel_idx].b |= ((text[i] & 32) >> 5); // set the most significant bit of the blue component to the third bit of the text character
    }

    image->data[pixel_idx].r &= 254; // clear the least significant bit of the red component of the last pixel
    image->data[pixel_idx].r |= 1; // set the least significant bit of the red component to 1 to mark the end of the text

    return true;
}

unsigned char* decode_text(rgbimage* image) {
    int text_len = 0;
    unsigned char* text = NULL;

    for (int i = 0; i < (image->width * image->height); i++) {
        unsigned char ch = 0;
        ch |= (image->data[i].r & 1) << 7; // set the first bit of the current character to the least significant bit of the red component of the current pixel
        ch |= (image->data[i].g & 1) << 6; // set the second bit of the current character to the least significant bit of the green component of the current pixel
        ch |= (image->data[i].b & 1) << 5; // set the third bit of the current character to the least significant bit of the blue component of the current pixel

        if (ch == 0) { // end of the text
            break;
        }

        text_len++;
        text = (unsigned char*) realloc(text, text_len);
        text[text_len - 1] = ch;
    }

    return text;
}

int main() {
    char* filename = "image.bmp";
    rgbimage image = {0};

    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Cannot open %s.\n", filename);
        return 1;
    }

    // Check if the bitmap file format is valid
    char signature[2];
    fread(signature, 1, 2, fp);
    if (signature[0] != 'B' || signature[1] != 'M') {
        printf("Invalid file format.\n");
        fclose(fp);
        return 1;
    }
    fseek(fp, 8, SEEK_CUR);
    int data_offset = 0;
    fread(&data_offset, 4, 1, fp);
    fseek(fp, 4, SEEK_CUR);
    fread(&image.width, 4, 1, fp);
    fread(&image.height, 4, 1, fp);
    fseek(fp, data_offset, SEEK_SET);
    image.data = (rgbpixel*) malloc(image.width * image.height * sizeof(rgbpixel));
    fread(image.data, sizeof(rgbpixel), image.width * image.height, fp);
    fclose(fp);

    char* text = "Hello, world!";
    int text_len = strlen(text);
    if (encode_text(text, text_len, &image)) {
        printf("Text encoded successfully.\n");

        fp = fopen("output.bmp", "wb");
        if (!fp) {
            printf("Cannot create output file.\n");
            return 1;
        }

        fwrite(signature, 1, 2, fp);
        fseek(fp, 8, SEEK_CUR);
        fwrite(&data_offset, 4, 1, fp);
        fseek(fp, 4, SEEK_CUR);
        fwrite(&image.width, 4, 1, fp);
        fwrite(&image.height, 4, 1, fp);
        fseek(fp, data_offset, SEEK_SET);
        fwrite(image.data, sizeof(rgbpixel), image.width * image.height, fp);
        fclose(fp);

        printf("Wrote encoded image to output.bmp.\n");
    }

    unsigned char* decoded_text = decode_text(&image);
    printf("Decoded text: %s\n", decoded_text);

    free(image.data);
    free(decoded_text);

    return 0;
}