//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define HEIGHT 512
#define WIDTH 512

int main(){

    int **image, **new_image;
    int i,j,k;

    image = (int **)malloc(HEIGHT * sizeof(int *));
    for(i=0; i<HEIGHT; i++){
        image[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    printf("Enter the image elements:\n");

    for(i=0; i<HEIGHT; i++){
        for(j=0; j<WIDTH; j++){
            scanf("%d", &image[i][j]);
        }
    }

    new_image = (int **)malloc(HEIGHT * sizeof(int *));
    for(i=0; i<HEIGHT; i++){
        new_image[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    //Flipping the image
    for(i=0; i<HEIGHT; i++){
        for(j=0; j<WIDTH; j++){
            new_image[i][j] = image[HEIGHT-i-1][WIDTH-j-1];
        }
    }

    //Changing brightness
    double brightness = 1.5;
    for(i=0; i<HEIGHT; i++){
        for(j=0; j<WIDTH; j++){
            new_image[i][j] = (int)round(brightness*image[i][j]);
        }
    }

    //Changing contrast
    double contrast = 2;
    for(i=0; i<HEIGHT; i++){
        for(j=0; j<WIDTH; j++){
            new_image[i][j] = (int)round(contrast*(new_image[i][j]-127));
        }
    }

    //Displaying the new image
    printf("Enter the new image elements:\n");

    for(i=0; i<HEIGHT; i++){
        for(j=0; j<WIDTH; j++){
            printf("%d ", new_image[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<HEIGHT; i++){
        free(image[i]);
    }
    free(image);

    for(i=0; i<HEIGHT; i++){
        free(new_image[i]);
    }
    free(new_image);

    return 0;
}