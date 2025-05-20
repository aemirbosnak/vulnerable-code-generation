//FormAI DATASET v1.0 Category: Image Classification system ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMG_SIZE 100 //maximum image size 
#define NUM_CLASSES 5 //number of classes 

//function to get user input for image 
void get_image(int image[MAX_IMG_SIZE][MAX_IMG_SIZE], int *size) {
    printf("Enter image size: ");
    scanf("%d", size);
    printf("Enter image (0 - background, 1 - object): \n");
    for(int i=0; i<*size; i++) {
        for(int j=0; j<*size; j++) {
            scanf("%d", &image[i][j]);
        }
    }
}

//function to classify image 
int classify_image(int image[MAX_IMG_SIZE][MAX_IMG_SIZE], int size) {
    int class_counts[NUM_CLASSES] = {0};
    int max_count = 0, max_class = -1;

    //count number of pixels of each class 
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            class_counts[image[i][j]]++;
        }
    }

    //find the class with highest count 
    for(int i=0; i<NUM_CLASSES; i++) {
        if(class_counts[i] > max_count) {
            max_count = class_counts[i];
            max_class = i;
        }
    }

    return max_class;
}

int main() {
    int image[MAX_IMG_SIZE][MAX_IMG_SIZE], size;

    printf("RETRO IMAGE CLASSIFIER\n\n");

    //get user input for image 
    get_image(image, &size);

    //classify image 
    int class = classify_image(image, size);

    //print result 
    printf("The image is classified as: Class %d\n", class);

    return 0;
}