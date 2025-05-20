//FormAI DATASET v1.0 Category: Image Steganography ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1000

/* A function to convert a decimal number to its binary representation */
void decToBin(int dec, int bin[])
{
    int i = 7;
    while (dec > 0) {
        bin[i--] = dec % 2;
        dec /= 2;
    }
    for (; i >= 0; i--)
        bin[i] = 0;
}

/* A function to convert a binary number to its decimal representation */
int binToDec(int bin[])
{
    int i, dec = 0;
    for (i = 0; i < 8; i++)
        dec = dec * 2 + bin[i];
    return dec;
}

/* A function to hide a message in an image */
void hideMessage(char message[], int len, char image[], int imgSize)
{
    int i, j, k = 0, bin[8], ascii;
    for (i = 0; i < len; i++) {
        ascii = (int) message[i];
        decToBin(ascii, bin);
        for (j = 0; j < 8; j++) {
            if (k >= imgSize) { /* Check if the image size is exceeded */
                printf("Error: Message size is too large to hide in the image.\n");
                return;
            }
            /* Modify the least significant bit of the image pixel */
            image[k] = (image[k] & 0xFE) + bin[j];
            k++;
        }
    }
}

/* A function to retrieve a message from an image */
void getMessage(char message[], int len, char image[], int imgSize)
{
    int i, j, k = 0, bin[8], ascii;
    for (i = 0; i < len; i++) {
        for (j = 0; j < 8; j++) {
            if (k >= imgSize) { /* Check if the image size is exceeded */
                printf("Error: Insufficient data in the image to retrieve the message.\n");
                return;
            }
            /* Extract the least significant bit from the image pixel */
            bin[j] = image[k] & 0x01;
            k++;
        }
        ascii = binToDec(bin);
        message[i] = (char) ascii;
    }
    message[len] = '\0';
}

/* An example program that demonstrates image steganography */
int main()
{
    char message[100], image[MAX_IMAGE_SIZE], imageName[30], option;
    int len, imgSize, i;

    printf("Enter the message to hide in the image (less than 100 characters):\n");
    fgets(message, 100, stdin);
    len = strlen(message);
    message[len - 1] = '\0'; /* Remove the newline character */

    printf("Enter the name of the image file (e.g. image.jpg):\n");
    scanf("%s", imageName);

    /* Read the image file contents into the image array */
    FILE *fp = fopen(imageName, "rb+");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    imgSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    if (imgSize > MAX_IMAGE_SIZE) {
        printf("Error: Image size exceeds maximum size limit.\n");
        exit(1);
    }
    fread(image, sizeof(char), imgSize, fp);
    fclose(fp);

    printf("Do you want to hide or retrieve the message? (h/r)\n");
    scanf(" %c", &option);

    if (option == 'h') {
        hideMessage(message, len, image, imgSize);
        fp = fopen(imageName, "wb");
        fwrite(image, sizeof(char), imgSize, fp);
        fclose(fp);
        printf("Message hidden in the image successfully.\n");
    }
    else if (option == 'r') {
        getMessage(message, len, image, imgSize);
        printf("Retrieved message from the image: %s\n", message);
    }
    else {
        printf("Invalid option selected.\n");
    }

    return 0;
}