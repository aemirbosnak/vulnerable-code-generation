//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_BLOCK_SIZE 10 //adjust this for different output resolution
#define MAX_IMAGE_SIZE 10000 //maximum input image size
#define MAX_FILE_NAME_SIZE 50 //maximum input file name size

void printAsciiArt(char*, int);

int main() {

    char file_name[MAX_FILE_NAME_SIZE]; //stores the name of the input image file
    FILE* image_file; //file pointer for input image file
    unsigned char image[MAX_IMAGE_SIZE]; //stores the contents of the input image file

    printf("Enter input file name: ");
    scanf("%s",file_name);

    //open image file
    image_file = fopen(file_name, "rb");
    if(!image_file) {
        printf("Error: Could not open %s\n", file_name);
        return 1;
    }

    //read image data
    fread(image, sizeof(unsigned char), MAX_IMAGE_SIZE, image_file);
    fclose(image_file);

    int image_width, image_height;

    //read image dimensions
    memcpy(&image_width, &image[18], sizeof(int));
    memcpy(&image_height, &image[22], sizeof(int));

    //calculate size of image pixel data
    int image_pixel_start = image[10] + 256*image[11]; //location of image pixel data in file
    int image_pixel_size = image_width * image_height; //size of image pixel data

    char ascii_art[image_height/ASCII_BLOCK_SIZE+1][image_width/ASCII_BLOCK_SIZE+1]; //array for storing ASCII art

    int count = 0;
    for(int i = image_pixel_start; i < image_pixel_start + image_pixel_size; i += 3) {

        //calculate grayscale value of pixel
        unsigned char r = image[i];
        unsigned char g = image[i+1];
        unsigned char b = image[i+2];
        unsigned char gray = 0.21*r + 0.72*g + 0.07*b;

        //convert grayscale value to ASCII character
        if(gray > 230) {
            ascii_art[count/(image_width/ASCII_BLOCK_SIZE)][count%(image_width/ASCII_BLOCK_SIZE)] = ' '; //lightest character
        }
        else if(gray > 200) {
            ascii_art[count/(image_width/ASCII_BLOCK_SIZE)][count%(image_width/ASCII_BLOCK_SIZE)] = '`'; //slightly darker character
        }
        else if(gray > 180) {
            ascii_art[count/(image_width/ASCII_BLOCK_SIZE)][count%(image_width/ASCII_BLOCK_SIZE)] = '-'; //even darker character
        }
        else if(gray > 160) {
            ascii_art[count/(image_width/ASCII_BLOCK_SIZE)][count%(image_width/ASCII_BLOCK_SIZE)] = '='; //even darker character
        }
        else if(gray > 130) {
            ascii_art[count/(image_width/ASCII_BLOCK_SIZE)][count%(image_width/ASCII_BLOCK_SIZE)] = 'o'; //even darker character
        }
        else if(gray > 100) {
            ascii_art[count/(image_width/ASCII_BLOCK_SIZE)][count%(image_width/ASCII_BLOCK_SIZE)] = '*'; //darker character
        }
        else if(gray > 60) {
            ascii_art[count/(image_width/ASCII_BLOCK_SIZE)][count%(image_width/ASCII_BLOCK_SIZE)] = '+'; //even darker character
        }
        else {
            ascii_art[count/(image_width/ASCII_BLOCK_SIZE)][count%(image_width/ASCII_BLOCK_SIZE)] = '#'; //darkest character
        }
        count++;
    }

    //print ASCII art to console
    printAsciiArt(ascii_art, image_width/ASCII_BLOCK_SIZE+1);

    return 0;
}

//prints the ASCII art to console
void printAsciiArt(char *ascii_art, int width) {
    for(int i = 0; i < strlen(ascii_art); i++) {
        if(i%width==0) {
            printf("\n");
        }
        printf("%c",ascii_art[i]);
    }
}