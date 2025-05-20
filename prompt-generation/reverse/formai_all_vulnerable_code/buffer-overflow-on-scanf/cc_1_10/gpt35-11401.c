//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePixelArt(int size, int colors){
    srand(time(NULL)); // seed random number generator with time
    
    int art[size][size];
    int i,j;
    
    // populate art array with random colors
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            art[i][j] = rand()%colors + 1;
        }
    }
    
    // print pixel art
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            switch(art[i][j]){
                case 1: printf("#"); break;
                case 2: printf("+"); break;
                case 3: printf("-"); break;
                case 4: printf("@"); break;
                case 5: printf("*"); break;
                default: printf(" ");
            }
        }
        printf("\n");
    }
}

int main(){
    int size, colors;
    printf("Enter size of pixel art (minimum 5): ");
    scanf("%d",&size);
    printf("Enter number of colors (maximum 5): ");
    scanf("%d",&colors);
    
    if(size < 5){
        printf("Invalid size entered, should be minimum 5. Exiting program.");
        return 0;
    }
    if(colors > 5){
        printf("Invalid number of colors entered, should be maximum 5. Exiting program.");
        return 0;
    }
    
    generatePixelArt(size,colors);
    
    return 0;
}