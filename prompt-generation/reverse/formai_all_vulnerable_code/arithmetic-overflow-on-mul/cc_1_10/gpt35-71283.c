//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//define necessary global variables
const char asciiChar[] = {'#', '&', '$', '*', '+', '=', '-', ':', '.', ' '};
const int asciiCharLength = 10;

//returns the character representing the input pixel's grayscale intensity
char getPixelChar(int pixelIntensity, int maxIntensity){
    //find the index of the ascii character based on pixel intensity
    float intensityFraction = (float)pixelIntensity / maxIntensity;
    int index = intensityFraction * (asciiCharLength - 1);
    return asciiChar[index];
}

int main(int argc, char *argv[]){
    //initialize necessary variables
    char imageName[100];
    int pixelIntensity, width, height, maxIntensity;
    unsigned char *imageData;
    
    //get the filename of the image from user input
    printf("Enter the name of the image file: ");
    scanf("%s", imageName);

    //open the image file for reading
    FILE *imageFile = fopen(imageName, "rb");

    //check if file cannot be opened
    if(!imageFile){
        printf("Error: Unable to open file.\n");
        return 1;
    }

    //read in the header file
    char format[3];
    fscanf(imageFile, "%s", format);
    fscanf(imageFile, "%d %d", &width, &height);
    fscanf(imageFile, "%d", &maxIntensity);

    //allocate memory for the image data
    imageData = (unsigned char*)malloc(sizeof(unsigned char) * width * height);

    //read in the image data
    fread(imageData, sizeof(unsigned char), width * height, imageFile);

    //close the image file
    fclose(imageFile);

    //output the ASCII image art to the console
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            //get the grayscale intensity of the current pixel
            pixelIntensity = imageData[i * width + j];

            //generate the ASCII character that represents the pixel intensity
            char asciiChar = getPixelChar(pixelIntensity, maxIntensity);

            //output the ASCII character to the console
            printf("%c%c", asciiChar, asciiChar);
        }
        //move to the next line
        printf("\n");
    }

    //free allocated memory
    free(imageData);

    return 0;
}