//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char getChar(int x, int y);
void generatePixelArt();

int main(void){
    srand(time(NULL));
    generatePixelArt();
    return 0;
}

char getChar(int x, int y){
    char pixelChar;
    switch(rand()%4){
        case 0: pixelChar = '-';
            break;
        case 1: pixelChar = '|';
            break;
        case 2: pixelChar = '+';
            break;
        case 3: pixelChar = ' ';
            break;        
    }
    return pixelChar;
}

void generatePixelArt(){
    int width, height;
    printf("Enter the width:\n");
    scanf("%d", &width);
    printf("Enter the height:\n");
    scanf("%d", &height);

    if(width <= 0 || height <= 0){
        printf("Invalid input. Please enter positive integers.\n");
        generatePixelArt();
    }

    printf("Generating Pixel Art\n\n");

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            char c = getChar(x, y);
            printf("%c ", c);
        }
        printf("\n");
    }
}