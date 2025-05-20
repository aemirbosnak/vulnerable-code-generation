//FormAI DATASET v1.0 Category: Image compression ; Style: bold
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    printf("\n\nBold Image Compression using C Programming Language\n");
    printf("----------------------------------------------------\n\n");

    /* Reading and displaying the original image */
    FILE *fp;
    fp = fopen("original_image.pgm", "rb");
    if(fp == NULL){
        printf("Error: Failed to open the file.\n");
        exit(1);
    }
    char format[4];
    int width, height, maxval;
    fscanf(fp, "%s %d %d %d", format, &width, &height, &maxval);
    int **image = (int**)malloc(height * sizeof(int*));
    int i, j;
    for(i=0; i<height; i++){
        image[i] = (int*)malloc(width * sizeof(int));
        for(j=0; j<width; j++){
            int pixel;
            fread(&pixel, sizeof(int), 1, fp);
            image[i][j] = pixel;
        }
    }
    fclose(fp);
    printf("Original Image:\n");
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    /* Performing Bold Image Compression */
    int threshold = maxval / 2;
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            if(image[i][j] >= threshold){
                image[i][j] = maxval;
            }
            else{
                image[i][j] = 0;
            }
        }
    }

    /* Writing the compressed image to file */
    fp = fopen("compressed_image.pgm", "wb");
    if(fp == NULL){
        printf("Error: Unable to open the file.\n");
        exit(1);
    }
    fprintf(fp, "P5\n%d %d\n%d\n", width, height, maxval);
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            fwrite(&image[i][j], sizeof(int), 1, fp);
        }
    }
    fclose(fp);
    printf("\n\nCompressed Image written to compressed_image.pgm successfully!\n");

    return 0;
}