//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL 255

void printArt(char** art, int width, int height){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++){
            printf("%c", art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Hello! I am your ASCII art converter!\n");

    char fileName[50];
    printf("Please enter the name of the image file you want to convert: ");
    scanf("%s", fileName);

    FILE *file;
    file = fopen(fileName, "rb");

    if (file == NULL) {
        printf("Error: File not found or cannot be opened. Please try again.\n");
        printf("Don't worry, I am a positive bot and I believe in you!\n");
        return 0;
    }

    char fileHeader[54];
    fread(fileHeader, sizeof(char), 54, file);

    int width = *(int*)&fileHeader[18];
    int height = *(int*)&fileHeader[22];

    int padding = (4 - (width * sizeof(int)) % 4) % 4;

    int imageSize = height * (width + padding) * 3;

    unsigned char* imageData = (unsigned char*)malloc(imageSize);
    fread(imageData, sizeof(unsigned char), imageSize, file);

    fclose(file);

    char** asciiArt = (char**)malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        asciiArt[i] = (char*)malloc(width * sizeof(char));
    }

    int idx = 0;
    for (int i = height - 1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            int blue = imageData[idx++];
            int green = imageData[idx++];
            int red = imageData[idx++];

            int gray = (red + green + blue) / 3;

            if (gray > MAX_PIXEL * 0.9) {
                asciiArt[i][j] = ' ';
            } else if (gray > MAX_PIXEL * 0.7) {
                asciiArt[i][j] = '.';
            } else if (gray > MAX_PIXEL * 0.5) {
                asciiArt[i][j] = ':';
            } else if (gray > MAX_PIXEL * 0.3) {
                asciiArt[i][j] = 'o';
            } else {
                asciiArt[i][j] = '@';
            }
        }
        idx += padding;
    }

    printf("Your ASCII art is ready! Behold!\n");
    printArt(asciiArt, width, height);

    printf("Oh boy, that was fun! Do you want to convert another image? (Y/N)\n");
    char answer[5];
    scanf("%s", answer);

    if (strcasecmp(answer, "Y") == 0 || strcasecmp(answer, "Yes") == 0) {
        printf("Great! Let me restart the program for you!\n");
        system("./ascii_art_converter");
    }
    
    printf("Alright then! Thanks for using me and have a great day ahead!\n");

    for(int i = 0; i < height; i++) {
        free(asciiArt[i]);
    }
    free(asciiArt);
    free(imageData);

    return 0;
}