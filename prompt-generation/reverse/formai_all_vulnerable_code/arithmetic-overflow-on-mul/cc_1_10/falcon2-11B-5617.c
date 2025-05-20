//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to embed a secret message into an image
void embed(unsigned char *img, int *img_size, unsigned char *secret, int secret_len) {
    unsigned char *pixels = (unsigned char *)malloc(3 * *img_size);
    int i;

    for (i = 0; i < *img_size; i++) {
        int j;
        for (j = 0; j < 3; j++) {
            int k;
            for (k = 0; k < 3; k++) {
                pixels[i * 3 + j] = ((pixels[i * 3 + j] & 0xF0) | (secret[i * 3 + j] & 0x0F));
            }
        }
    }

    *img_size = (*img_size + secret_len) / 3;
    *img = pixels;
}

// Function to extract the secret message from an image
unsigned char *extract(unsigned char *img, int *img_size) {
    unsigned char *pixels = (unsigned char *)malloc(3 * *img_size);
    int i;

    for (i = 0; i < *img_size; i++) {
        int j;
        for (j = 0; j < 3; j++) {
            int k;
            for (k = 0; k < 3; k++) {
                pixels[i * 3 + j] = ((pixels[i * 3 + j] & 0x0F) | (img[i * 3 + j] & 0xF0));
            }
        }
    }

    *img_size = (*img_size - *img_size / 3) / 3;
    *img = pixels;

    return *img;
}

int main() {
    unsigned char *img, *secret;
    int img_size, secret_len;

    // Load the image
    printf("Enter the path of the image file: ");
    scanf("%s", &img);
    FILE *f = fopen(img, "rb");
    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fseek(f, 0, SEEK_END);
    img_size = (int)ftell(f);
    fseek(f, 0, SEEK_SET);
    img = (unsigned char *)malloc(3 * img_size);
    if (fread(img, 1, img_size, f)!= img_size) {
        printf("Error reading file.\n");
        return 1;
    }
    fclose(f);

    // Embed the secret message
    printf("Enter the path of the secret message file: ");
    scanf("%s", &secret);
    FILE *sf = fopen(secret, "rb");
    if (sf == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fseek(sf, 0, SEEK_END);
    secret_len = (int)ftell(sf);
    fseek(sf, 0, SEEK_SET);
    secret = (unsigned char *)malloc(3 * secret_len);
    if (fread(secret, 1, secret_len, sf)!= secret_len) {
        printf("Error reading file.\n");
        return 1;
    }
    fclose(sf);
    embed(img, &img_size, secret, secret_len);

    // Save the modified image
    printf("Enter the path of the output file: ");
    scanf("%s", &secret);
    FILE *fout = fopen(secret, "wb");
    if (fout == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fwrite(img, 1, img_size, fout);
    fclose(fout);

    // Extract the secret message
    printf("Enter the path of the modified image file: ");
    scanf("%s", &secret);
    FILE *fin = fopen(secret, "rb");
    if (fin == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fseek(fin, 0, SEEK_END);
    secret_len = (int)ftell(fin);
    fseek(fin, 0, SEEK_SET);
    secret = (unsigned char *)malloc(3 * secret_len);
    if (fread(secret, 1, secret_len, fin)!= secret_len) {
        printf("Error reading file.\n");
        return 1;
    }
    fclose(fin);

    printf("The extracted secret message is:\n");
    for (int i = 0; i < secret_len; i++) {
        printf("%c", secret[i]);
    }

    free(img);
    free(secret);

    return 0;
}