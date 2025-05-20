//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define WIDTH 80
#define HEIGHT 40

// Function to convert pixel grayscale value to ASCII character
char pixToChar(int px)
{
    char ch;
    if(px < 25) ch = '@';
    else if(px < 50) ch = '#';
    else if(px < 75) ch = '8';
    else if(px < 100) ch = '&';
    else if(px < 125) ch = 'o';
    else if(px < 150) ch = ':';
    else if(px < 175) ch = '*';
    else if(px < 200) ch = '.';
    else if(px < 225) ch = ' ';
    else ch = ' ';
    return ch;
}

// Function to load grayscale image from file
void loadGrayscaleImage(char* filename, int image[][WIDTH])
{
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Failed to load image.\n");
        exit(1);
    }
    char ch;
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }
    fclose(fp);
}

// Function to print ASCII art
void printAsciiArt(int image[][WIDTH])
{
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            printf("%c", pixToChar(image[i][j]));
        }
        printf("\n");
    }
}

int main()
{
    int image[HEIGHT][WIDTH];
    loadGrayscaleImage("image.txt", image);
    printAsciiArt(image);
    return 0;
}