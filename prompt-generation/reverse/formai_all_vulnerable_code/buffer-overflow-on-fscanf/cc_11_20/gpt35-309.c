//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: multivariable
#include <stdio.h>

/*This program converts an image file to ASCII art*/

int main(){

    FILE *fp;
    unsigned char image[500][500], grayscale[500][500];

    int n_rows, n_cols, max_pixel_val, gray_value, i, j; 

    fp = fopen("image.pgm", "r");

    /*Reads the image header*/
    fscanf(fp, "P5\n%d %d\n%d\n", &n_cols, &n_rows, &max_pixel_val);

    /*Reads the image pixel values*/
    fread(image, sizeof(unsigned char), n_rows*n_cols, fp);

    /*Converts the image to grayscale*/
    for (i=0; i<n_rows; i++){
        for (j=0; j<n_cols; j++){
            gray_value = (0.2989*image[i][j] + 0.5870*image[i][j+1] + 0.1140*image[i][j+2]);
            grayscale[i][j] = (unsigned char) gray_value;
        }
    }

    /*Prints the grayscale image as ASCII art*/
    for (i=0; i<n_rows; i++){
        for (j=0; j<n_cols; j++){
            if (grayscale[i][j] < 25){
                printf("@");
            } else if (grayscale[i][j] < 50){
                printf("#");
            } else if (grayscale[i][j] < 75){
                printf("$");
            } else if (grayscale[i][j] < 100){
                printf("o");
            } else if (grayscale[i][j] < 125){
                printf("=");
            } else if (grayscale[i][j] < 150){
                printf("+");
            } else if (grayscale[i][j] < 175){
                printf("-");
            } else if (grayscale[i][j] < 200){
                printf(":");
            } else if (grayscale[i][j] < 225){
                printf(".");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    fclose(fp);

    return 0;
}