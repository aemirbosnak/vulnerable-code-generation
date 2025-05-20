//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

    //defining variables
    int width, height;
    char pixelChar;
    int color;
    
    //getting user input for dimensions and pixel character
    printf("Enter width of image: ");
    scanf("%d", &width);
    printf("Enter height of image: ");
    scanf("%d", &height);
    printf("Enter pixel character: ");
    scanf(" %c", &pixelChar);
    
    //setting random seed for color generation
    srand(time(NULL));
    
    //printing pixel art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            color = rand() % 16; //generating random color from 0-15
            switch (color) {
                case 0:
                    printf("\033[0;30m"); //black
                    break;
                case 1:
                    printf("\033[0;31m"); //red
                    break;
                case 2:
                    printf("\033[0;32m"); //green
                    break;
                case 3:
                    printf("\033[0;33m"); //yellow
                    break;
                case 4:
                    printf("\033[0;34m"); //blue
                    break;
                case 5:
                    printf("\033[0;35m"); //purple
                    break;
                case 6:
                    printf("\033[0;36m"); //cyan
                    break;
                case 7:
                    printf("\033[0;37m"); //white
                    break;
                case 8:
                    printf("\033[1;30m"); //bright black
                    break;
                case 9:
                    printf("\033[1;31m"); //bright red
                    break;
                case 10:
                    printf("\033[1;32m"); //bright green
                    break;
                case 11:
                    printf("\033[1;33m"); //bright yellow
                    break;
                case 12:
                    printf("\033[1;34m"); //bright blue
                    break;
                case 13:
                    printf("\033[1;35m"); //bright purple
                    break;
                case 14:
                    printf("\033[1;36m"); //bright cyan
                    break;
                case 15:
                    printf("\033[1;37m"); //bright white
                    break;
            }
            printf("%c ", pixelChar); //printing pixel character
            printf("\033[0m"); //resetting color
        }
        printf("\n"); //new line for next row
    }
    
    return 0;
}