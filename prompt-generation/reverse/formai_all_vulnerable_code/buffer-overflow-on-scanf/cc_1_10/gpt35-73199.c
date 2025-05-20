//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1000 // Maximum image width
#define MAX_HEIGHT 1000 // Maximum image height

int main(){

    FILE *input_file;
    FILE *output_file;
    char input_name[50];
    char output_name[50];
    int brightness, contrast, width, height;
    char img[MAX_HEIGHT][MAX_WIDTH];

    // Read input image file name
    printf("Enter input image file name: ");
    scanf("%s", input_name);

    // Open input image file
    input_file = fopen(input_name, "r");
    if(input_file == NULL){
        printf("Could not open input file.\n");
        return 1;
    }

    // Read image width and height
    fscanf(input_file, "%d %d", &width, &height);

    // Read image pixel values
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            fscanf(input_file, "%hhd", &img[i][j]);
        }
    }

    // Close input file
    fclose(input_file);

    // Ask for image manipulation options
    printf("Enter brightness and contrast values (-255 to 255): ");
    scanf("%d %d", &brightness, &contrast);

    // Manipulate image
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            img[i][j] = img[i][j] + brightness;
            img[i][j] = img[i][j] * (255.0 / (255.0 - contrast));
        }
    }

    // Ask for image output file name
    printf("Enter output image file name: ");
    scanf("%s", output_name);

    // Open output image file
    output_file = fopen(output_name, "w");
    if(output_file == NULL){
        printf("Could not open output file.\n");
        return 1;
    }

    // Write output image data
    fprintf(output_file, "%d %d\n", width, height);
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            fprintf(output_file, "%hhd ", img[i][j]);
        }
        fprintf(output_file, "\n");
    }

    // Close output file
    fclose(output_file);

    // Inform user of success
    printf("Image processed successfully!\n");

    return 0;
}