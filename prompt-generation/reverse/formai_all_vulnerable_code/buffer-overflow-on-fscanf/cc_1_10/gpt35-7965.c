//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

//C Image to ASCII art converter
//By futuristic artist K.O.

//Define the dimensions of the image
#define WIDTH 50
#define HEIGHT 30

//Function to map pixel values to ASCII characters
char pixelToChar(int pixel_value){
    //Return ASCII character based on pixel intensity
    if(pixel_value < 25){
        return '@';
    }
    else if(pixel_value < 50){
        return '#';
    }
    else if(pixel_value < 75){
        return '&';
    }
    else if(pixel_value < 100){
        return '$';
    }
    else if(pixel_value < 125){
        return '%';
    }
    else if(pixel_value < 150){
        return '*';
    }
    else if(pixel_value < 175){
        return '+';
    }
    else if(pixel_value < 200){
        return '=';
    }
    else if(pixel_value < 225){
        return '-';
    }
    else{
        return '.';
    }
}

//Function to read the pixel values from the image
void readImage(FILE* image_file, int image_array[][WIDTH]){
    int i, j, pixel_value;
    char pixel_char;
    //Read each row of pixels
    for(i=0; i<HEIGHT; i++){
        for(j=0; j<WIDTH; j++){
            //Read the pixel value from the file
            fscanf(image_file, "%d", &pixel_value);
            //Convert the pixel value to an ASCII character
            pixel_char = pixelToChar(pixel_value);
            //Save the character in the image array
            image_array[i][j] = pixel_char;
        }
    }
}

//Function to print the ASCII art image to the console
void printImage(int image_array[][WIDTH]){
    int i, j;
    //Print each row of the ASCII art image
    for(i=0; i<HEIGHT; i++){
        for(j=0; j<WIDTH; j++){
            //Print the character at this pixel location
            printf("%c", image_array[i][j]);
        }
        //Print a new line at the end of this row
        printf("\n");
    }
}

int main(int argc, char* argv[]){
    //Declare variables
    FILE* image_file;
    int image_array[HEIGHT][WIDTH];
    //Check if the user provided an image file
    if(argc < 2){
        printf("Error: no image file provided.\n");
        return 1;
    }
    //Open the image file
    image_file = fopen(argv[1], "r");
    if(image_file == NULL){
        printf("Error: failed to open image file.\n");
        return 1;
    }
    //Read the pixel values from the image file into the array
    readImage(image_file, image_array);
    //Close the image file
    fclose(image_file);
    //Print the ASCII art image to the console
    printImage(image_array);
    return 0;
}