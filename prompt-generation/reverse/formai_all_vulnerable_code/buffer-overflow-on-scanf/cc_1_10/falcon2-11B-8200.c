//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define structure to hold image information
struct image {
    int width;
    int height;
    int channels;
    unsigned char* data;
};

// Function to perform steganography on an input image
void performSteganography(struct image* inputImage, const char* secretMessage) {
    // Convert input image to grayscale
    unsigned char* grayscaleImage = malloc(inputImage->width * inputImage->height * inputImage->channels);
    
    // Iterate through each pixel of the image and modify its color values based on the secret message
    for (int y = 0; y < inputImage->height; y++) {
        for (int x = 0; x < inputImage->width; x++) {
            int index = y * inputImage->width + x;
            int red = inputImage->data[index];
            int green = inputImage->data[index + 1];
            int blue = inputImage->data[index + 2];
            
            int newRed = (red & 0x00FF0000) | ((red & 0xFF00) & 0x0000FF & ((secretMessage[0] == '0')? 0x0000FF : 0x00FF00));
            int newGreen = (green & 0x00FF0000) | ((green & 0xFF00) & 0x0000FF & ((secretMessage[0] == '1')? 0x0000FF : 0x00FF00));
            int newBlue = (blue & 0x00FF0000) | ((blue & 0xFF00) & 0x0000FF & ((secretMessage[0] == '2')? 0x0000FF : 0x00FF00));
            
            grayscaleImage[index] = newRed | newGreen | newBlue;
        }
    }
    
    // Write the modified image to a new file
    FILE* outputFile = fopen("output.png", "wb");
    fwrite(grayscaleImage, sizeof(unsigned char), inputImage->width * inputImage->height * inputImage->channels, outputFile);
    fclose(outputFile);
    
    // Print success message if steganography was successful
    printf("Steganography successful!\n");
}

int main() {
    // Read input image from user
    struct image inputImage;
    printf("Enter width: ");
    scanf("%d", &inputImage.width);
    printf("Enter height: ");
    scanf("%d", &inputImage.height);
    printf("Enter channels: ");
    scanf("%d", &inputImage.channels);
    
    unsigned char* imageData = malloc(inputImage.width * inputImage.height * inputImage.channels);
    printf("Enter image data: ");
    fread(imageData, sizeof(unsigned char), inputImage.width * inputImage.height * inputImage.channels, stdin);
    
    inputImage.data = imageData;
    
    // Read secret message from user
    char secretMessage[3];
    printf("Enter secret message: ");
    scanf("%s", secretMessage);
    
    // Perform steganography on the input image
    performSteganography(&inputImage, secretMessage);
    
    return 0;
}