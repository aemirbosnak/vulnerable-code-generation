//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: relaxed
#include <stdio.h>

// Function to convert an image to ASCII art
void convertImageToAsciiArt(char imageFileName[], int outputWidth, char asciiCharSet[]) {
    // Open the image file
    FILE* filePointer = fopen(imageFileName, "rb");
    if (filePointer == NULL) {
        printf("Unable to open image file!\n");
        return;
    }

    // Get the dimensions of the image
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, filePointer);
    int imageWidth = *(int*)&header[18];
    int imageHeight = *(int*)&header[22];

    // Calculate the aspect ratio of the image
    float aspectRatio = (float)imageWidth / (float)imageHeight;

    // Calculate the height of the output image
    int outputHeight = (int)((float)outputWidth / aspectRatio);

    // Allocate memory for the input and output image
    unsigned char* inputImage = (unsigned char*)malloc(imageWidth * imageHeight * 3);
    unsigned char* outputImage = (unsigned char*)malloc(outputWidth * outputHeight * 3);

    // Read the input image
    fread(inputImage, sizeof(unsigned char), imageWidth * imageHeight * 3, filePointer);

    // Close the image file
    fclose(filePointer);

    // Loop through each pixel in the input image
    for (int i = 0; i < imageWidth * imageHeight * 3; i += 3) {
        // Calculate the average brightness of the pixel
        unsigned char pixelBrightness = (inputImage[i] + inputImage[i + 1] + inputImage[i + 2]) / 3;

        // Find the ASCII character that best represents the pixel
        int charIndex = (int)(pixelBrightness / 256.0 * strlen(asciiCharSet));
        char bestChar = asciiCharSet[charIndex];

        // Set the output pixel to the ASCII character
        int outputIndex = i / 3 * 3;
        outputImage[outputIndex] = bestChar;
        outputImage[outputIndex + 1] = bestChar;
        outputImage[outputIndex + 2] = bestChar;
    }

    // Open the output text file
    FILE* outputPointer = fopen("output.txt", "w");
    if (outputPointer != NULL) {
        // Loop through each row of the output image
        for (int y = 0; y < outputHeight; y++) {
            // Loop through each column of the output image
            for (int x = 0; x < outputWidth; x++) {
                // Print the character at the current position
                int index = y * outputWidth + x;
                fputc(outputImage[index * 3], outputPointer);
            }
            // Move to the next line
            fputc('\n', outputPointer);
        }

        // Close the output text file
        fclose(outputPointer);
    }

    // Free the memory
    free(inputImage);
    free(outputImage);
}

int main() {
    // Define the ASCII character set
    char asciiCharSet[] = "@#x+=:-. ";

    // Convert the image to ASCII art
    convertImageToAsciiArt("image.bmp", 100, asciiCharSet);

    return 0;
}