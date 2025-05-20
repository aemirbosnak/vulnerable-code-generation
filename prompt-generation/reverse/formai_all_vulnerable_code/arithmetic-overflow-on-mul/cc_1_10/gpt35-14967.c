//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

typedef struct Pixel {
    int red;
    int green;
    int blue;
} Pixel;

char output[MAX_HEIGHT][MAX_WIDTH];

// The ASCII characters used to symbolize the pixel values
const char ASCII_CHARS[] = " .,:irsXA253hMHGS#9B&@";

// Function to convert RGB values to grayscale integer values
int toGrayscale(Pixel p) {
    return (int)(0.2989 * p.red + 0.5870 * p.green + 0.1140 * p.blue);
}

// Function to find the ASCII symbol corresponding with the intensity of a grayscale value
char getASCII(int intensity) {
    int charCount = strlen(ASCII_CHARS);
    int step = ceil(255.0/charCount);

    for(int i = 0; i < charCount; i++) {
        if(intensity < (i+1) * step) {
            return ASCII_CHARS[i];
        }
    }
    return ASCII_CHARS[charCount-1];
}

// Function that converts an image to ASCII art and writes the output to a file
void convertImageToFile(char* fileName) {
    FILE* imageFile = fopen(fileName, "rb"); // Open the image file
    if(imageFile == NULL) {
        perror("Error opening image file");
        return;
    }

    char header[54];
    fread(header, sizeof(char), 54, imageFile); // Read the header of the file

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int colorDepth = *(int*)&header[28];

    if(colorDepth != 24) { 
        printf("Invalid color depth. The program only supports 24-bit images.\n");
        return;
    }

    if(width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: The program supports images up to %d pixels in width and height.\n", MAX_WIDTH, MAX_HEIGHT);
        return;
    }

    Pixel image[width * height];
    fread(image, sizeof(Pixel), width * height, imageFile); // Read the pixel data

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            Pixel p = image[y * width + x]; // Get the pixel at the current position
            int intensity = toGrayscale(p); // Convert the pixel to grayscale

            // Get the ASCII symbol for the intensity and add it to the output character array
            output[y][x] = getASCII(intensity); 
        }
        output[y][width] = '\0'; // Add a null terminator at the end of each row
    }

    fclose(imageFile);

    // Write the output to a file
    char outputFilePath[50];
    sprintf(outputFilePath, "%s.txt", fileName);
    FILE* outputFile = fopen(outputFilePath, "w");
    for(int y = 0; y < height; y++) {
        fprintf(outputFile, "%s\n", output[y]);
    }
    fclose(outputFile);

    printf("Image converted to ASCII art. Output written to %s\n", outputFilePath);
}

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Please specify the name of the image file.\n");
        return 1;
    }

    convertImageToFile(argv[1]);

    return 0;
}