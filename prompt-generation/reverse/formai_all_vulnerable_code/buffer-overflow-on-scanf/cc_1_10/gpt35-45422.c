//FormAI DATASET v1.0 Category: Image Editor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void grayscale(char* filename);
void flip_horizontal(char* filename);
void negative(char* filename);
void blur(char* filename);

int main(){
    char filename[20];
    int choice;
    
    printf("\nWelcome to our Image Editor program!\n");
    
    do{
        printf("Please enter the name of the file you would like to edit (without extension): ");
        scanf("%s", filename);
        printf("\n");
        printf("Please choose the operation you would like to perform:\n");
        printf("1. Grayscale\n");
        printf("2. Flip Horizontal\n");
        printf("3. Negative\n");
        printf("4. Blur\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        // Switch statement based on user choice
        switch(choice){
            case 1:
                grayscale(filename);
                printf("\nGrayscale Operation completed!\n\n");
                break;
            case 2:
                flip_horizontal(filename);
                printf("\nFlip Horizontal Operation completed!\n\n");
                break;
            case 3:
                negative(filename);
                printf("\nNegative Operation completed!\n\n");
                break;
            case 4:
                blur(filename);
                printf("\nBlur Operation completed!\n\n");
                break;
            case 5:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid Choice! Please try again.\n\n");
                break;
        }
        
    }while(choice != 5);
    
    return 0;
}

// Function to convert an image to grayscale
void grayscale(char* filename){
    char grayscale_name[30];
    sprintf(grayscale_name, "%s_grayscale.ppm", filename);
    
    // Opening files
    FILE* in_file = fopen(strcat(filename, ".ppm"), "r");
    FILE* out_file = fopen(grayscale_name, "w");
    
    if(in_file == NULL){
        fprintf(stderr, "Unable to open %s file!", filename);
    }
    if(out_file == NULL){
        fprintf(stderr, "Unable to create %s_grayscale.ppm file!", filename);
    }
    
    // Reading image header
    char header[3];
    int width, height, max_value;
    fscanf(in_file, "%s", header);
    fscanf(in_file, "%d %d", &width, &height);
    fscanf(in_file, "%d", &max_value);
    
    // Writing image header
    fprintf(out_file, "%s\n", header);
    fprintf(out_file, "%d %d\n", width, height);
    fprintf(out_file, "%d\n", max_value);
    
    // Reading and converting pixel values
    int r, g, b;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            fscanf(in_file, "%d %d %d", &r, &g, &b);
            int gray_value = (r + g + b) / 3;
            fprintf(out_file, "%d %d %d ", gray_value, gray_value, gray_value);
        }
        fprintf(out_file, "\n");
    }
    
    // Closing files
    fclose(in_file);
    fclose(out_file);
}

// Function to flip an image horizontally
void flip_horizontal(char* filename){
    char flip_name[30];
    sprintf(flip_name, "%s_horizontal.ppm", filename);
    
    // Opening files
    FILE* in_file = fopen(strcat(filename, ".ppm"), "r");
    FILE* out_file = fopen(flip_name, "w");
    
    if(in_file == NULL){
        fprintf(stderr, "Unable to open %s file!", filename);
    }
    if(out_file == NULL){
        fprintf(stderr, "Unable to create %s_horizontal.ppm file!", filename);
    }
    
    // Reading image header
    char header[3];
    int width, height, max_value;
    fscanf(in_file, "%s", header);
    fscanf(in_file, "%d %d", &width, &height);
    fscanf(in_file, "%d", &max_value);
    
    // Writing image header
    fprintf(out_file, "%s\n", header);
    fprintf(out_file, "%d %d\n", width, height);
    fprintf(out_file, "%d\n", max_value);
    
    // Reading and flipping pixel values
    int r, g, b;
    for(int i = 0; i < height; i++){
        for(int j = width-1; j >= 0; j--){
            fscanf(in_file, "%d %d %d", &r, &g, &b);
            fprintf(out_file, "%d %d %d ", r, g, b);
        }
        fprintf(out_file, "\n");
    }
    
    // Closing files
    fclose(in_file);
    fclose(out_file);
}

// Function to convert an image to negative
void negative(char* filename){
    char neg_name[30];
    sprintf(neg_name, "%s_negative.ppm", filename);
    
    // Opening files
    FILE* in_file = fopen(strcat(filename, ".ppm"), "r");
    FILE* out_file = fopen(neg_name, "w");
    
    if(in_file == NULL){
        fprintf(stderr, "Unable to open %s file!", filename);
    }
    if(out_file == NULL){
        fprintf(stderr, "Unable to create %s_negative.ppm file!", filename);
    }
    
    // Reading image header
    char header[3];
    int width, height, max_value;
    fscanf(in_file, "%s", header);
    fscanf(in_file, "%d %d", &width, &height);
    fscanf(in_file, "%d", &max_value);
    
    // Writing image header
    fprintf(out_file, "%s\n", header);
    fprintf(out_file, "%d %d\n", width, height);
    fprintf(out_file, "%d\n", max_value);
    
    // Reading and converting pixel values
    int r, g, b;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            fscanf(in_file, "%d %d %d", &r, &g, &b);
            fprintf(out_file, "%d %d %d ", max_value-r, max_value-g, max_value-b);
        }
        fprintf(out_file, "\n");
    }
    
    // Closing files
    fclose(in_file);
    fclose(out_file);
}

// Function to blur an image
void blur(char* filename){
    char blur_name[30];
    sprintf(blur_name, "%s_blur.ppm", filename);
    
    // Opening files
    FILE* in_file = fopen(strcat(filename, ".ppm"), "r");
    FILE* out_file = fopen(blur_name, "w");
    
    if(in_file == NULL){
        fprintf(stderr, "Unable to open %s file!", filename);
    }
    if(out_file == NULL){
        fprintf(stderr, "Unable to create %s_blur.ppm file!", filename);
    }
    
    // Reading image header
    char header[3];
    int width, height, max_value;
    fscanf(in_file, "%s", header);
    fscanf(in_file, "%d %d", &width, &height);
    fscanf(in_file, "%d", &max_value);
    
    // Writing image header
    fprintf(out_file, "%s\n", header);
    fprintf(out_file, "%d %d\n", width, height);
    fprintf(out_file, "%d\n", max_value);
    
    // Reading and averaging pixel values
    int r, g, b;
    int window[3][3];
    for(int i = 0; i < height-2; i++){
        for(int j = 0; j < width-2; j++){
            fscanf(in_file, "%d %d %d", &window[0][0], &window[0][1], &window[0][2]);
            fscanf(in_file, "%d %d %d", &window[1][0], &window[1][1], &window[1][2]);
            fscanf(in_file, "%d %d %d", &window[2][0], &window[2][1], &window[2][2]);
            
            r = (window[0][0] + window[0][1] + window[0][2] + 
                 window[1][0] + window[1][1] + window[1][2] +
                 window[2][0] + window[2][1] + window[2][2]) / 9;
            g = (window[0][0] + window[0][1] + window[0][2] + 
                 window[1][0] + window[1][1] + window[1][2] +
                 window[2][0] + window[2][1] + window[2][2]) / 9;
            b = (window[0][0] + window[0][1] + window[0][2] + 
                 window[1][0] + window[1][1] + window[1][2] +
                 window[2][0] + window[2][1] + window[2][2]) / 9;
                 
            fprintf(out_file, "%d %d %d ", r, g, b);
        }
        fscanf(in_file, "%d %d %d", &r, &g, &b); // Skipping last two pixels in each row
        fscanf(in_file, "%d %d %d", &r, &g, &b);
    }
    
    // Closing files
    fclose(in_file);
    fclose(out_file);
}