//FormAI DATASET v1.0 Category: Image Steganography ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    FILE *imageFile, *secretFile, *outputFile;
    unsigned char *imageData, *secretData, *outputData;
    int imageWidth, imageHeight, imageSize, secretSize, outputSize;
    int i, j, k;

    /* Open image file for reading */
    imageFile = fopen("image.bmp", "rb");
    if (imageFile == NULL) {
        printf("Error opening image file\n");
        return 1;
    }

    /* Read image dimensions */
    fseek(imageFile, 18, SEEK_SET);
    fread(&imageWidth, sizeof(int), 1, imageFile);
    fread(&imageHeight, sizeof(int), 1, imageFile);

    /* Compute image size */
    imageSize = imageWidth * imageHeight * 3;

    /* Allocate memory for image data */
    imageData = (unsigned char *) malloc(imageSize);

    /* Read image data */
    fseek(imageFile, 54, SEEK_SET);
    fread(imageData, sizeof(unsigned char), imageSize, imageFile);

    /* Close image file */
    fclose(imageFile);

    /* Open secret file for reading */
    secretFile = fopen("secret.txt", "rb");
    if (secretFile == NULL) {
        printf("Error opening secret file\n");
        return 1;
    }

    /* Compute secret size */
    fseek(secretFile, 0, SEEK_END);
    secretSize = ftell(secretFile);
    fseek(secretFile, 0, SEEK_SET);

    /* Allocate memory for secret data */
    secretData = (unsigned char *) malloc(secretSize);

    /* Read secret data */
    fread(secretData, sizeof(unsigned char), secretSize, secretFile);

    /* Close secret file */
    fclose(secretFile);

    /* Compute output size */
    outputSize = imageSize;

    /* Allocate memory for output data */
    outputData = (unsigned char *) malloc(outputSize);

    /* Copy image data to output data */
    memcpy(outputData, imageData, imageSize);

    /* Encode secret data in output data */
    for (i = 0, j = 0; i < secretSize; i++, j += 3) {
        outputData[j] &= 0xFC;
        outputData[j] |= (secretData[i] >> 6) & 0x03;
        outputData[j+1] &= 0xFC;
        outputData[j+1] |= (secretData[i] >> 4) & 0x03;
        outputData[j+2] &= 0xFC;
        outputData[j+2] |= (secretData[i] >> 2) & 0x03;
    }

    /* Open output file for writing */
    outputFile = fopen("output.bmp", "wb");
    if (outputFile == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    /* Write image header */
    fwrite(imageData, sizeof(unsigned char), 54, outputFile);

    /* Write output data */
    fwrite(outputData, sizeof(unsigned char), outputSize, outputFile);

    /* Close output file */
    fclose(outputFile);

    /* Free memory */
    free(imageData);
    free(secretData);
    free(outputData);

    return 0;
}