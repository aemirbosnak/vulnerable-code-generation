//FormAI DATASET v1.0 Category: Image Classification system ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define Constants for Image Width and Height
#define N 10
#define M 10

// Function to read the input image from a file
void read_input_image(float input_image[N][M], char *filename){
    FILE *input_file = fopen(filename, "r");
    if(input_file == NULL) {
        printf("Unable to open input file\n");
        exit(EXIT_FAILURE);
    }
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++){
            fscanf(input_file, "%f", &input_image[i][j]);
        }
    }
    fclose(input_file);
}

// Function to classify the image as either a circle or square
int classify_image(float input_image[N][M]){
    int i, j;
    float sum = 0;
    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++){
            sum += input_image[i][j];
        }
    }
    float average = sum / (N * M);
    if(average > 0.5){
        return 0; // Circle
    }
    else{
        return 1; // Square
    }
}

// Main Function
int main(){
    float input_image[N][M];
    char *filename = "input.txt";
    read_input_image(input_image, filename);
    int output = classify_image(input_image);
    if(output == 0){
        printf("The input image is a circle.\n");
    }
    else{
        printf("The input image is a square.\n");
    }
    return 0;
}