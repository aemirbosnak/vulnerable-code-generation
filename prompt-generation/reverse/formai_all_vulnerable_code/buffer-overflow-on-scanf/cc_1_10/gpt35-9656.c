//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawPixel(int pixelValue){
    if(pixelValue == 0){
        printf(" ");
    }
    else{
        printf("*");
    }
}

void drawImage(int image[8][8]){
    int i,j;

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            drawPixel(image[i][j]);
        }
        printf("\n");
    }
}

void generatePixelArt(int image[8][8], int seed){
    srand(seed);

    int i,j;

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            image[i][j] = rand() % 2;
        }
    }
}

int main(){
    int seed1, seed2;
    int image1[8][8];
    int image2[8][8];

    printf("Enter the first seed value: ");
    scanf("%d", &seed1);

    printf("Enter the second seed value: ");
    scanf("%d", &seed2);

    generatePixelArt(image1, seed1);
    generatePixelArt(image2, seed2);

    printf("Image 1:\n");
    drawImage(image1);

    printf("\nImage 2:\n");
    drawImage(image2);

    printf("\nThe pixel art of Romeo and Juliet:\n");

    int i, j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(image1[i][j]==1 && image2[i][j]==1){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}