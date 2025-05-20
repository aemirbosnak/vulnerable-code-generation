//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLOR 255

int main(){
    FILE *inFile, *outFile;
    int i, j, width, height, maxVal, count = 0;
    char magicNum[3];

    // Open image file using read binary mode
    inFile = fopen("input.ppm", "rb");
    if (inFile == NULL){
        printf("Error: Unable to open file.");
        return 1;
    }

    // Read image header information
    fscanf(inFile, "%s%d%d%d", magicNum, &width, &height, &maxVal);

    // Allocate memory for image data
    unsigned char *imageData = (unsigned char*) malloc(sizeof(unsigned char) * width * height * 3);

    // Read image data
    fread(imageData, sizeof(unsigned char), width * height * 3, inFile);

    // Close input file
    fclose(inFile);

    // Open output file using write binary mode
    outFile = fopen("output.ppm", "wb");
    if (outFile == NULL){
        printf("Error: Unable to open file.");
        return 1;
    }

    // Write image header information to output
    fprintf(outFile, "%s\n%d %d\n%d\n", magicNum, width, height, maxVal);

    // Flip image vertically
    for (i = 0; i < height; i++){
        for (j = 0; j < width; j++){
            fprintf(outFile, "%d %d %d ", (int) *(imageData + ((height - 1 - i) * width * 3) + (j * 3)), (int) *(imageData + ((height - 1 - i) * width * 3) + (j * 3) + 1), (int) *(imageData + ((height - 1 - i) * width * 3) + (j * 3) + 2));
            count++;

            // Insert newline character after every row
            if (count % (width * 3) == 0){
                fprintf(outFile, "\n");
            }
        }
    }

    // Change image brightness and contrast
    for (i = 0; i < height; i++){
        for (j = 0; j < width; j++){
            int r = *(imageData + (i * width * 3) + (j * 3));
            int g = *(imageData + (i * width * 3) + (j * 3) + 1);
            int b = *(imageData + (i * width * 3) + (j * 3) + 2);

            // Increase brightness by 50
            r += 50;
            g += 50;
            b += 50;

            // Clamp color values to range 0-255
            r = (r > MAX_COLOR ? MAX_COLOR : r);
            g = (g > MAX_COLOR ? MAX_COLOR : g);
            b = (b > MAX_COLOR ? MAX_COLOR : b);

            // Decrease contrast by 50%
            r = (r - MAX_COLOR / 2) * 0.5 + MAX_COLOR / 2;
            g = (g - MAX_COLOR / 2) * 0.5 + MAX_COLOR / 2;
            b = (b - MAX_COLOR / 2) * 0.5 + MAX_COLOR / 2;

            // Write modified color values to output file
            fprintf(outFile, "%d %d %d ", r, g, b);
            count++;

            // Insert newline character after every row
            if (count % (width * 3) == 0){
                fprintf(outFile, "\n");
            }
        }
    }

    // Close output file
    fclose(outFile);

    // Free memory
    free(imageData);

    return 0;
}