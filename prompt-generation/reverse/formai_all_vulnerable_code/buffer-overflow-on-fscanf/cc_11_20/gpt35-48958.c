//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Declare variables
    FILE* inputFile;
    FILE* outputFile;
    char inputFileName[100];
    char outputFileName[100];
    int flipChoice, brightnessChange, contrastChange;
    int rows, cols, depth, maxVal, pixelValue, newPixelValue;

    //Prompt user for input and output file names
    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    //Open input file for reading
    inputFile = fopen(inputFileName, "r");

    //Read image header
    fscanf(inputFile, "P%d\n%d %d\n%d\n", &depth, &cols, &rows, &maxVal);

    //Allocate memory for image
    int image[rows][cols];

    //Read pixel values into image array
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            fscanf(inputFile, "%d ", &pixelValue);
            image[i][j] = pixelValue;
        }
    }

    //Close input file
    fclose(inputFile);

    //Prompt user for processing options
    printf("Enter 1 to flip the image horizontally, enter 2 to flip it vertically: ");
    scanf("%d", &flipChoice);
    printf("Enter a value between -255 and 255 to change image brightness: ");
    scanf("%d", &brightnessChange);
    printf("Enter a value between -100 and 100 to change image contrast: ");
    scanf("%d", &contrastChange);

    //Perform selected image processing tasks
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            //Flip image horizontally
            if(flipChoice == 1){
                newPixelValue = image[i][cols - j - 1];
            }
            //Flip image vertically
            else if(flipChoice == 2){
                newPixelValue = image[rows - i - 1][j];
            }
            //Otherwise, keep original pixel value
            else{
                newPixelValue = image[i][j];
            }

            //Adjust brightness
            newPixelValue += brightnessChange;

            //Clamp brightness value between 0 and 255
            if(newPixelValue < 0){
                newPixelValue = 0;
            }
            else if(newPixelValue > 255){
                newPixelValue = 255;
            }

            //Adjust contrast
            newPixelValue = ((newPixelValue - 128) * contrastChange / 100) + 128;

            //Clamp contrast value between 0 and 255
            if(newPixelValue < 0){
                newPixelValue = 0;
            }
            else if(newPixelValue > 255){
                newPixelValue = 255;
            }

            //Update image array with new pixel value
            image[i][j] = newPixelValue;
        }
    }

    //Open output file for writing
    outputFile = fopen(outputFileName, "w");

    //Write image header to output file
    fprintf(outputFile, "P%d\n%d %d\n%d\n", depth, cols, rows, maxVal);

    //Write pixel values to output file
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            fprintf(outputFile, "%d ", image[i][j]);
        }
        fprintf(outputFile, "\n");
    }

    //Close output file
    fclose(outputFile);

    //Print message to indicate program completion
    printf("Image processing complete. Output file saved as %s\n", outputFileName);

    return 0;
}