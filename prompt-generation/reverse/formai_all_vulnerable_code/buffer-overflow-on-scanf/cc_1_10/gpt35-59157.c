//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// function to embed the watermark into the image
void embedWatermark(char *imageName, char *watermarkText) {
    FILE *imageFile, *watermarkFile, *outputFile;
    char tempChar, watermarkBit;
    int i, j, imageBit, watermarkIndex;

    // open the image file in binary mode
    imageFile = fopen(imageName, "rb");
    if(imageFile == NULL) {
        printf("Error: Could not open file %s\n", imageName);
        exit(1);
    }

    // open the watermark file in read mode
    watermarkFile = fopen(watermarkText, "r");
    if(watermarkFile == NULL) {
        printf("Error: Could not open file %s\n", watermarkText);
        exit(1);
    }

    // create the output file in binary mode
    outputFile = fopen("output.bmp", "wb");
    if(outputFile == NULL) {
        printf("Error: Could not create output file\n");
        exit(1);
    }

    // skip the header of the image file
    for(i=0; i<54; i++) {
        tempChar = getc(imageFile);
        putc(tempChar, outputFile);
    }

    // read one character at a time from the watermark file
    watermarkIndex = 0;
    while((tempChar = getc(watermarkFile)) != EOF) {
        // convert the character to 8 bits
        for(i=0; i<8; i++) {
            watermarkBit = (tempChar >> i) & 1;
            // embed the watermark bit into the image bit
            imageBit = getc(imageFile);
            imageBit = (imageBit & 254) | watermarkBit;
            putc(imageBit, outputFile);
        }
        watermarkIndex++;
    }

    // copy the rest of the image file
    while((tempChar = getc(imageFile)) != EOF) {
        putc(tempChar, outputFile);
    }

    // close all the files
    fclose(imageFile);
    fclose(watermarkFile);
    fclose(outputFile);

    printf("Watermark embedded successfully!\n");
}

// function to extract the watermark from the image
void extractWatermark(char *imageName) {
    FILE *imageFile, *outputFile;
    char tempChar, watermarkBit, watermarkChar=0;
    int i, j, imageBit, watermarkIndex;

    // open the image file in binary mode
    imageFile = fopen(imageName, "rb");
    if(imageFile == NULL) {
        printf("Error: Could not open file %s\n", imageName);
        exit(1);
    }

    // create the output file in write mode
    outputFile = fopen("extracted.txt", "w");
    if(outputFile == NULL) {
        printf("Error: Could not create output file\n");
        exit(1);
    }

    // skip the header of the image file
    for(i=0; i<54; i++) {
        tempChar = getc(imageFile);
    }

    // read one character at a time from the image file
    watermarkIndex = 0;
    while((tempChar = getc(imageFile)) != EOF) {
        // extract the least significant bit of the image byte
        for(i=0; i<8; i++) {
            imageBit = tempChar & 1;
            tempChar = tempChar >> 1;
            // combine the bits into a watermark character
            watermarkBit = imageBit << i;
            watermarkChar = watermarkChar | watermarkBit;
        }
        // write the watermark character to the output file
        putc(watermarkChar, outputFile);
        // reset the watermark character after every 8 bits
        if(watermarkIndex % 8 == 7) {
            watermarkChar = 0;
        }
        watermarkIndex++;
    }

    // close all the files
    fclose(imageFile);
    fclose(outputFile);

    printf("Watermark extracted successfully!\n");
}

int main() {
    int choice;
    char imageName[50], watermarkText[50];

    printf("Welcome to the Digital Watermarking Program!\n");

    while(1) {
        printf("Please choose an option:\n");
        printf("1. Embed watermark into image\n");
        printf("2. Extract watermark from image\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Please enter the name of the image file: ");
                scanf("%s", imageName);
                printf("Please enter the name of the text file containing the watermark: ");
                scanf("%s", watermarkText);
                embedWatermark(imageName, watermarkText);
                break;
            case 2:
                printf("Please enter the name of the image file: ");
                scanf("%s", imageName);
                extractWatermark(imageName);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}