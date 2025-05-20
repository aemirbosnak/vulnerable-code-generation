//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: multiplayer
#include <stdio.h>
#include <string.h>

// Function to embed the watermark
void embedWatermark(char *image, char *watermark) {
    int pos = 0, wmLen = strlen(watermark);
    for (int i = 0; image[i] != '\0'; i++) {
        // Embed the watermark character by character
        if (pos < wmLen && i % 2 == 0) {
            image[i] = watermark[pos];
            pos++;
        }
    }
}

// Function to extract the watermark
void extractWatermark(char *image, int imgSize) {
    int pos = 0;
    char watermark[50];
    for (int i = 0; i < imgSize; i++) {
        if (i % 2 == 0) {
            watermark[pos] = image[i];
            pos++;
        }
    }
    watermark[pos] = '\0';
    printf("\nExtracted watermark: %s\n", watermark);
}

// Function to read the image from file
void readImageFromFile(char *image, char *filename) {
    FILE *fptr = fopen(filename, "r");
    char c;
    int i = 0;
    while ((c = fgetc(fptr)) != EOF) {
        image[i] = c;
        i++;
    }
    image[i] = '\0';
    fclose(fptr);
}

// Function to write the image to file
void writeImageToFile(char *image, char *filename) {
    FILE *fptr = fopen(filename, "w");
    fputs(image, fptr);
    fclose(fptr);
}

int main() {
    char image[2000], watermark[50];

    // Read the original image from file
    readImageFromFile(image, "originalImage.txt");
    printf("Original image: %s\n", image);

    // Get the watermark from user
    printf("\nEnter the watermark: ");
    scanf("%s", watermark);

    // Embed the watermark in the image
    embedWatermark(image, watermark);
    printf("Watermarked image: %s\n", image);

    // Write the watermarked image to file
    writeImageToFile(image, "watermarkedImage.txt");

    // Read the watermarked image from file
    readImageFromFile(image, "watermarkedImage.txt");

    // Extract the watermark from the image
    extractWatermark(image, strlen(image));

    return 0;
}