//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: artistic
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct {
    unsigned char r, g, b;
} pixel;

int main() {
    FILE *img_file, *msg_file, *output_file;
    int img_width, img_height, msg_len;
    pixel **img;
    char *msg;

    img_file = fopen("image.bmp", "rb");
    msg_file = fopen("message.txt", "rb");
    output_file = fopen("output.bmp", "wb");

    if (img_file == NULL || msg_file == NULL || output_file == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    // Read image dimensions
    fseek(img_file, 18, SEEK_SET);
    fread(&img_width, 4, 1, img_file);
    fread(&img_height, 4, 1, img_file);

    // Allocate memory for image data
    img = (pixel **)malloc(img_height * sizeof(pixel *));
    for (int i = 0; i < img_height; i++) {
        img[i] = (pixel *)malloc(img_width * sizeof(pixel));
    }

    // Read image data
    fseek(img_file, 54, SEEK_SET);
    fread(img[0], sizeof(pixel), img_width * img_height, img_file);

    // Read message length
    fseek(msg_file, 0, SEEK_END);
    msg_len = ftell(msg_file);

    // Allocate memory for message
    msg = (char *)malloc(msg_len + 1);

    // Read message
    fseek(msg_file, 0, SEEK_SET);
    fread(msg, 1, msg_len, msg_file);
    msg[msg_len] = '\0';

    // Hide message in image
    int msg_idx = 0;
    for (int i = 0; i < img_height && msg_idx < msg_len; i++) {
        for (int j = 0; j < img_width && msg_idx < msg_len; j++) {
            if (msg[msg_idx] == '0') {
                img[i][j].r &= ~1;
            } else {
                img[i][j].r |= 1;
            }
            msg_idx++;
        }
    }

    // Write modified image to output file
    fwrite(img[0], sizeof(pixel), img_width * img_height, output_file);

    // Free memory
    for (int i = 0; i < img_height; i++) {
        free(img[i]);
    }
    free(img);
    free(msg);

    fclose(img_file);
    fclose(msg_file);
    fclose(output_file);

    printf("Message hidden in image.\n");

    return 0;
}