//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to convert the image into ASCII art
void convertToAscii(char *path){
    //Open the image file in binary mode
    FILE *imageFile = fopen(path, "rb");

    //Check if the file is opened successfully or not
    if(imageFile == NULL){
        printf("Could not open image file.\n");
        exit(1);
    }

    //Declare variables to hold the image dimensions
    int width, height;

    //Read the width and height from the image file header
    fscanf(imageFile, "%d %d", &width, &height);

    //Initialize a 2D array of characters to hold the ASCII art
    char asciiArt[height][width];

    //Declare variables to hold the RGB values of each pixel of the image
    unsigned char red, green, blue;

    //Loop through each pixel of the image and convert it to ASCII character
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            //Read the RGB values of the pixel from the image file
            fread(&red, 1, 1, imageFile);
            fread(&green, 1, 1, imageFile);
            fread(&blue, 1, 1, imageFile);

            //Calculate the brightness of the pixel by taking the average of the RGB values
            int brightness = (red + green + blue) / 3;

            //Map the brightness value to an ASCII character
            if(brightness >= 230){
                asciiArt[i][j] = ' ';
            }
            else if(brightness >= 200){
                asciiArt[i][j] = '.';
            }
            else if(brightness >= 180){
                asciiArt[i][j] = '*';
            }
            else if(brightness >= 160){
                asciiArt[i][j] = ':';
            }
            else if(brightness >= 130){
                asciiArt[i][j] = 'o';
            }
            else if(brightness >= 100){
                asciiArt[i][j] = '&';
            }
            else if(brightness >= 70){
                asciiArt[i][j] = '8';
            }
            else if(brightness >= 50){
                asciiArt[i][j] = '#';
            }
            else{
                asciiArt[i][j] = '@';
            }
        }
    }

    //Print the ASCII art to the console
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            printf("%c", asciiArt[i][j]);
        }
        printf("\n");
    }

    //Close the image file
    fclose(imageFile);
}

//Main function to test the ASCII art converter
int main(){
    //Prompt the user to enter the path of the image file
    printf("Enter the path of the image file: ");
    char path[100];
    scanf("%s", path);

    //Convert the image to ASCII art
    convertToAscii(path);

    return 0;
}