//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("OMG! You won't believe what I just did!\n");
    printf("I created a new digital watermarking program!\n");
    printf("It's so cool, I can't wait to show you!\n");
    printf("Okay, okay, let me show you how it works.\n");

    //initialize variables
    int watermark, image, result;
    int size=100, i, j;

    //dynamically allocate memory for image and watermark arrays
    int *imgArray = (int *) malloc(size * sizeof(int));
    int *watermarkArray = (int *) malloc(size * sizeof(int));

    //get user input for image and watermark arrays
    for(i=0; i<size; i++){
        printf("Enter pixel value for image array[%d]: ", i);
        scanf("%d", &image);
        imgArray[i] = image;

        printf("Enter pixel value for watermark array[%d]: ", i);
        scanf("%d", &watermark);
        watermarkArray[i] = watermark;
    }

    //perform Digital Watermarking
    for(i=0; i < size; i++){
        result = watermarkArray[i] - imgArray[i];
        imgArray[i] = imgArray[i] + result/2;
    }

    printf("Digital Watermarking Completed Successfully!\n");

    //print the original image and the watermarked image
    printf("\nOriginal Image:\n");
    for(i=0; i<size; i++){
        printf("%d ", imgArray[i]);
    }

    printf("\nWatermarked Image:\n");
    for(i=0; i<size; i++){
        printf("%d ", watermarkArray[i]);
    }

    //free the dynamically allocated memory
    free(imgArray);
    free(watermarkArray);

    return 0;
}