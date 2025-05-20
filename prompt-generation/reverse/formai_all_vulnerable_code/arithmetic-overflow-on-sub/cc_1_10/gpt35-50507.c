//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printPixel(int colorValue) {
    switch(colorValue){
        case 0: printf("\033[40m  \033[0m"); break;
        case 1: printf("\033[41m  \033[0m"); break;
        case 2: printf("\033[42m  \033[0m"); break;
        case 3: printf("\033[43m  \033[0m"); break;
        case 4: printf("\033[44m  \033[0m"); break;
        case 5: printf("\033[45m  \033[0m"); break;
        case 6: printf("\033[46m  \033[0m"); break;
        case 7: printf("\033[47m  \033[0m"); break;
        default: printf("\033[40m  \033[0m");
    }
}

int main() {
    int row, col, color;
    clock_t start, end;
    double cpu_time_used;

    int pixelArt[10][10] = {
        {1, 2, 3, 4, 5, 6, 7, 0, 0, 0},
        {2, 3, 4, 5, 6, 7, 0, 1, 1, 1},
        {3, 4, 5, 6, 7, 0, 1, 2, 2, 2},
        {4, 5, 6, 7, 0, 1, 2, 3, 3, 3},
        {5, 6, 7, 0, 1, 2, 3, 4, 4, 4},
        {6, 7, 0, 1, 2, 3, 4, 5, 5, 5},
        {7, 0, 1, 2, 3, 4, 5, 6, 6, 6},
        {0, 1, 2, 3, 4, 5, 6, 7, 7, 7},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
    };

    /* Generate random pixel art */
    start = clock();
    srand(time(NULL));
    for(row=0; row<10; row++){
        for(col=0; col<10; col++){
            color = rand() % 8;
            pixelArt[row][col] = color;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time to generate random pixel art: %f seconds\n", cpu_time_used);

    /* Print pixel art */
    for(row=0; row<10; row++){
        for(col=0; col<10; col++){
            printPixel(pixelArt[row][col]);
        }
        printf("\n");
    }

    return 0;
}