//FormAI DATASET v1.0 Category: Image Steganography ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTESIZE 8                      // number of bits in a byte

/*
    This program implements image steganography using least significant bit (LSB) method.
    1 byte is taken from the message, then each bit of the byte is stored in the LSB of each pixel (R,G,B) of the image.  
*/

struct pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

int main(int argc, char *argv[]) {
    if (argc < 3) {                     // check if enough arguments are provided
        printf("Usage: %s [cover image file] [message file]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // open cover image and message file
    FILE *coverFile = fopen(argv[1], "rb");
    if (!coverFile) {
        printf("Unable to open cover image file!\n");
        return EXIT_FAILURE;
    }

    FILE *msgFile = fopen(argv[2], "rb");
    if (!msgFile) {
        printf("Unable to open message file!\n");
        fclose(coverFile);
        return EXIT_FAILURE;
    }

    // read the message file
    fseek(msgFile, 0L, SEEK_END);
    long fsize = ftell(msgFile);        // size of message file
    rewind(msgFile);

    if (fsize == 0) {
        printf("Empty message file!\n");
        fclose(coverFile);
        fclose(msgFile);
        return EXIT_FAILURE;
    }

    unsigned char *msg = (unsigned char *) malloc(fsize);
    if (!msg) {
        printf("Out of memory!\n");
        fclose(coverFile);
        fclose(msgFile);
        return EXIT_FAILURE;
    }

    size_t elementsRead = fread(msg, fsize, 1, msgFile);
    if (elementsRead != 1) {
        printf("Unable to read from message file!\n");
        fclose(coverFile);
        fclose(msgFile);
        return EXIT_FAILURE;
    }

    fclose(msgFile);

    // read the cover image file
    int width, height;
    fread(&width, sizeof(int), 1, coverFile);
    fread(&height, sizeof(int), 1, coverFile);

    struct pixel image[height][width];

    int i, j, k = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fread(&image[i][j].r, sizeof(char), 1, coverFile);
            fread(&image[i][j].g, sizeof(char), 1, coverFile);
            fread(&image[i][j].b, sizeof(char), 1, coverFile);

            // check if message has been completely embedded in the image
            if (k == fsize) {
                fclose(coverFile);
                free(msg);
                return EXIT_SUCCESS;
            }

            // embed message in image
            unsigned char tempChar = msg[k++];
            for (int bit = 0; bit < BYTESIZE; bit++) {
                image[i][j].r = (image[i][j].r & ~(1 << bit)) | ((tempChar & 1) << bit);
                tempChar >>= 1;
                if (k == fsize) {
                    fclose(coverFile);
                    free(msg);
                    FILE *stegoFile = fopen("stego.bmp", "wb");
                    fwrite(&width, sizeof(int), 1, stegoFile);
                    fwrite(&height, sizeof(int), 1, stegoFile);
                    for (int h = 0; h < height; h++) {
                        for (int w = 0; w < width; w++) {
                            fwrite(&image[h][w].r, sizeof(char), 1, stegoFile);
                            fwrite(&image[h][w].g, sizeof(char), 1, stegoFile);
                            fwrite(&image[h][w].b, sizeof(char), 1, stegoFile);
                        }
                    }
                    fclose(stegoFile);
                    return EXIT_SUCCESS;
                }

                image[i][j].g = (image[i][j].g & ~(1 << bit)) | ((tempChar & 1) << bit);
                tempChar >>= 1;
                if (k == fsize) {
                    fclose(coverFile);
                    free(msg);
                    FILE *stegoFile = fopen("stego.bmp", "wb");
                    fwrite(&width, sizeof(int), 1, stegoFile);
                    fwrite(&height, sizeof(int), 1, stegoFile);
                    for (int h = 0; h < height; h++) {
                        for (int w = 0; w < width; w++) {
                            fwrite(&image[h][w].r, sizeof(char), 1, stegoFile);
                            fwrite(&image[h][w].g, sizeof(char), 1, stegoFile);
                            fwrite(&image[h][w].b, sizeof(char), 1, stegoFile);
                        }
                    }
                    fclose(stegoFile);
                    return EXIT_SUCCESS;
                }

                image[i][j].b = (image[i][j].b & ~(1 << bit)) | ((tempChar & 1) << bit);
                tempChar >>= 1;
                if (k == fsize) {
                    fclose(coverFile);
                    free(msg);
                    FILE *stegoFile = fopen("stego.bmp", "wb");
                    fwrite(&width, sizeof(int), 1, stegoFile);
                    fwrite(&height, sizeof(int), 1, stegoFile);
                    for (int h = 0; h < height; h++) {
                        for (int w = 0; w < width; w++) {
                            fwrite(&image[h][w].r, sizeof(char), 1, stegoFile);
                            fwrite(&image[h][w].g, sizeof(char), 1, stegoFile);
                            fwrite(&image[h][w].b, sizeof(char), 1, stegoFile);
                        }
                    }
                    fclose(stegoFile);
                    return EXIT_SUCCESS;
                }
            }
        }
    }

    // message size is too large to be embedded in the image
    printf("Image size too small to embed message!\n");
    fclose(coverFile);
    free(msg);
    return EXIT_FAILURE;
}