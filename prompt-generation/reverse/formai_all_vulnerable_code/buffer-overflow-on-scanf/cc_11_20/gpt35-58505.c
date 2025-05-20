//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int width, height, colors;
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    printf("Enter the number of colors (1-8): ");
    scanf("%d", &colors);
    
    // create image array
    int image[height][width];
    
    // fill image with random pixel values
    int i, j;
    for (i=0; i<height; i++) {
        for (j=0; j<width; j++) {
            image[i][j] = rand() % colors;
        }
    }
    
    // print image as ASCII art
    for (i=0; i<height; i++) {
        for (j=0; j<width; j++) {
            switch (image[i][j]) {
                case 0:
                    printf("██");
                    break;
                case 1:
                    printf("▓▓");
                    break;
                case 2:
                    printf("░░");
                    break;
                case 3:
                    printf("  ");
                    break;
                case 4:
                    printf("__");
                    break;
                case 5:
                    printf("^^");
                    break;
                case 6:
                    printf("//");
                    break;
                case 7:
                    printf("\\\\");
                    break;
            }
        }
        printf("\n");
    }
    
    return 0;
}