//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Welcome Message
    printf("Welcome to the Digital Watermarking Program!\n");

    // Declare Variables
    char original_image[100];
    char watermarked_image[100];
    char watermark_text[50];

    // Ask User for File Names
    printf("Enter the name of the original image file: ");
    scanf("%s", original_image);
    printf("Enter the name of the watermarked image file: ");
    scanf("%s", watermarked_image);
    printf("Enter the text for the watermark: ");
    scanf("%s", watermark_text);

    // Open Files
    FILE *original_file = fopen(original_image, "r");
    FILE *watermarked_file = fopen(watermarked_image, "w");

    // Check If Files Opened Successfully
    if (original_file == NULL) {
        printf("Error: Could not open original image file!\n");
        return 1;
    }
    if (watermarked_file == NULL) {
        printf("Error: Could not open watermarked image file!\n");
        return 1;
    }

    // Write Watermark Text to Watermarked File
    fprintf(watermarked_file, "%s\n", watermark_text);

    // Copy Original Image to Watermarked Image
    char c;
    while ((c = fgetc(original_file)) != EOF) {
        fputc(c, watermarked_file);
    }

    // Close Files
    fclose(original_file);
    fclose(watermarked_file);

    // Watermarking Complete!
    printf("Watermarking complete!\n");

    return 0;
}