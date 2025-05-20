//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to print the matrix
void printMatrix(int matrix[1024][1024], int height, int width){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//Function to embed the watermark into the matrix
void embedWatermark(int matrix[1024][1024], int watermark[512][512], int height, int width, int w_height, int w_width){
    int count = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if(count < w_height*w_width){
                //Converting the watermark pixel value to binary
                int binPixel[8] = {0};
                int pixel = watermark[count/w_width][count%w_width];
                for(int k=0; k<8; k++) {
                    binPixel[k] = pixel & 0x1;
                    pixel = pixel >> 1;
                }
                //Embedding the watermark in the least significant bits of the matrix pixel values
                for(int k=0; k<8; k++){
                    matrix[i][j] = (matrix[i][j] & ~0x1) | binPixel[k];
                    if(j%2==0){
                        j++;
                    }
                    else{
                        j--;
                        if(i%2==0){
                            i++;
                        }
                        else{
                            i--;
                        }
                    }
                }
                count++;
            }
            else{
                return;
            }
        }
    }
}

//Function to extract the watermark from the matrix
void extractWatermark(int matrix[1024][1024], int watermark[512][512], int height, int width, int w_height, int w_width){
    int count = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if(count < w_height*w_width){
                //Extracting the watermark from the least significant bits of the matrix pixel values
                int binPixel[8] = {0};
                for(int k=0; k<8; k++){
                    binPixel[k] = matrix[i][j] & 0x1;
                    if(j%2==0){
                        j++;
                    }
                    else{
                        j--;
                        if(i%2==0){
                            i++;
                        }
                        else{
                            i--;
                        }
                    }
                }
                int pixel = 0;
                //Converting the binary value to integer
                for(int k=7; k>=0; k--){
                    pixel = pixel << 1;
                    pixel = pixel | binPixel[k];
                }
                watermark[count/w_width][count%w_width] = pixel;
                count++;
            }
            else{
                return;
            }
        }
    }
}

int main(){
    int matrix[1024][1024] = {0};
    int watermark[512][512] = {0};
    FILE* fp = fopen("image.txt", "r");
    int height = 0;
    int width = 0;
    if(fp){
        //Reading the image file
        fscanf(fp, "%d %d", &height, &width);
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                fscanf(fp, "%d", &matrix[i][j]);
            }
        }
        fclose(fp);
    }
    printf("The original image is:\n");
    printMatrix(matrix, height, width);
    FILE* fp1 = fopen("watermark.txt", "r");
    int w_height = 0;
    int w_width = 0;
    if(fp1){
        //Reading the watermark file
        fscanf(fp1, "%d %d", &w_height, &w_width);
        for(int i=0; i<w_height; i++){
            for(int j=0; j<w_width; j++){
                fscanf(fp1, "%d", &watermark[i][j]);
            }
        }
        fclose(fp1);
    }
    printf("The watermark to be embedded is:\n");
    printMatrix(watermark, w_height, w_width);
    embedWatermark(matrix, watermark, height, width, w_height, w_width);
    printf("The watermarked image is:\n");
    printMatrix(matrix, height, width);
    int decodedWatermark[512][512] = {0};
    extractWatermark(matrix, decodedWatermark, height, width, w_height, w_width);
    printf("The extracted watermark is:\n");
    printMatrix(decodedWatermark, w_height, w_width);
    return 0;
}