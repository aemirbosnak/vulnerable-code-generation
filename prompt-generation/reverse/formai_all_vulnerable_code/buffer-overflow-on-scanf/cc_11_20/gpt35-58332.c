//FormAI DATASET v1.0 Category: Image compression ; Style: enthusiastic
//Welcome to the Image compression example program using C!

#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXELS 255
#define SCALE_FACTOR 2

int main(){
    int height, width;
    printf("Enter the height and width of the image: ");
    scanf("%d %d", &height, &width);

    int **image = (int**)malloc(sizeof(int*) * height);
    for(int i = 0; i < height; i++){
        image[i] = (int*)malloc(sizeof(int) * width);
    }

    printf("Enter the pixel values for the image: ");
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            scanf("%d", &image[i][j]);
        }
    }

    //Compression logic
    int compressed_height = height/SCALE_FACTOR;
    int compressed_width = width/SCALE_FACTOR;

    int **compressed_image = (int**)malloc(sizeof(int*) * compressed_height);
    for(int i = 0; i < compressed_height; i++){
        compressed_image[i] = (int*)malloc(sizeof(int) * compressed_width);
    }

    for(int i = 0; i < compressed_height; i++){
        for(int j = 0; j < compressed_width; j++){
            int sum = 0;
            for(int k = i*SCALE_FACTOR; k < i*SCALE_FACTOR+SCALE_FACTOR; k++){
                for(int l = j*SCALE_FACTOR; l < j*SCALE_FACTOR+SCALE_FACTOR; l++){
                    sum += image[k][l];
                }
            }
            compressed_image[i][j] = sum/(SCALE_FACTOR*SCALE_FACTOR);
        }
    }

    //Print the compressed image
    printf("Compressed image:\n");
    for(int i = 0; i < compressed_height; i++){
        for(int j = 0; j < compressed_width; j++){
            printf("%d ", compressed_image[i][j]);
        }
        printf("\n");
    }

    //Free memory
    for(int i = 0; i < height; i++){
        free(image[i]);
    }
    free(image);

    for(int i = 0; i < compressed_height; i++){
        free(compressed_image[i]);
    }
    free(compressed_image);

    printf("Thanks for using our image compression program!");
    return 0;
}