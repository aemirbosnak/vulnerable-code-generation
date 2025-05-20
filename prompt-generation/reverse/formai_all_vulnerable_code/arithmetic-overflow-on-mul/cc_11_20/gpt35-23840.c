//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fpIn, *fpOut;
    char input[100], output[100];
    unsigned char pixel, *buffer;
    int row, col, numRows, numCols, brightness, choice;
    float contrast;

    printf("Enter the name of input file: ");
    scanf("%s", input);

    fpIn = fopen(input, "rb");

    if(fpIn == NULL){
        printf("Error opening file.\n");
        exit(0);
    }

    printf("Enter the name of output file: ");
    scanf("%s", output);

    fpOut = fopen(output, "wb");

    if(fpOut == NULL){
        printf("Error creating file.\n");
        exit(0);
    }

    printf("Enter the number of rows: ");
    scanf("%d", &numRows);

    printf("Enter the number of columns: ");
    scanf("%d", &numCols);

    printf("Enter brightness level (-255 to 255): ");
    scanf("%d", &brightness);

    printf("Enter contrast level (0.0 to 1.0): ");
    scanf("%f", &contrast);

    buffer = (unsigned char*)malloc(numRows * numCols * sizeof(unsigned char));

    fread(buffer, sizeof(unsigned char), numRows * numCols, fpIn);

    for(row=0 ; row<numRows ; row++){
        for(col=0 ; col<numCols ; col++){
            pixel = *(buffer + row * numCols + col) + brightness;
            pixel = (pixel - 128) * contrast + 128;

            if(pixel > 255){
                pixel = 255;
            }
            else if(pixel < 0){
                pixel = 0;
            }

            *(buffer + row * numCols + col) = pixel;
        }
    }

    printf("Choose option 1 or 2:\n");
    printf("1. Flip the image horizontally\n");
    printf("2. Flip the image vertically\n");
    scanf("%d", &choice);

    if(choice == 1){
        for(row=0 ; row<numRows ; row++){
            for(col=0 ; col<numCols/2 ; col++){
                pixel = *(buffer + row * numCols + col);
                *(buffer + row * numCols + col) = *(buffer + row * numCols + numCols - col - 1);
                *(buffer + row * numCols + numCols - col - 1) = pixel;
            }
        }
    }
    else if(choice == 2){
        for(row=0 ; row<numRows/2 ; row++){
            for(col=0 ; col<numCols ; col++){
                pixel = *(buffer + row * numCols + col);
                *(buffer + row * numCols + col) = *(buffer + (numRows - row - 1) * numCols + col);
                *(buffer + (numRows - row - 1) * numCols + col) = pixel;
            }
        }
    }
    else{
        printf("Invalid choice.\n");
        exit(0);
    }

    fwrite(buffer, sizeof(unsigned char), numRows * numCols, fpOut);

    printf("Image processing done.\n");

    free(buffer);
    fclose(fpIn);
    fclose(fpOut);

    return 0;
}