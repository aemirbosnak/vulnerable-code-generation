//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;

void encode(uchar *img, int width, int height, uchar *msg, int msglen) {
    int i, j, k;
    for (i = 0; i < msglen; i++) {
        for (j = 7; j >= 0; j--) {
            for (k = 0; k < 3; k++) {
                if ((msg[i] >> j) & 1) {
                    img[(i * 3 * width * height) + (j * width * height) + (k * width) + height] |= 1;
                }
            }
        }
    }
}

int main() {
    uchar *img, *msg;
    int width, height, msglen;

    // Load image
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        perror("Error opening the image file");
        return 1;
    }
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    fseek(fp, 54, SEEK_SET);
    img = malloc(width * height * 3);
    fread(img, sizeof(uchar), width * height * 3, fp);
    fclose(fp);

    // Load message
    fp = fopen("message.txt", "rb");
    if (fp == NULL) {
        perror("Error opening the message file");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    msglen = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    msg = malloc(msglen);
    fread(msg, sizeof(uchar), msglen, fp);
    fclose(fp);

    // Encode message
    encode(img, width, height, msg, msglen);

    // Save image
    fp = fopen("stego_image.bmp", "wb");
    if (fp == NULL) {
        perror("Error opening the stego image file");
        return 1;
    }
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);
    fseek(fp, 54, SEEK_SET);
    fwrite(img, sizeof(uchar), width * height * 3, fp);
    fclose(fp);

    free(img);
    free(msg);

    return 0;
}