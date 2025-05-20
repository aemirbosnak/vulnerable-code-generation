//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: complete
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 1000  // Maximum size of the image array
#define MAXCHAR 100  // Maximum length of the text to be embedded

int main()
{
    char image[MAXSIZE][MAXSIZE];  // 2D array to store the image
    char text[MAXCHAR];  // Array to store the text to be embedded
    char watermark[] = "digitalwatermarking";  // Text to be embedded as a watermark
    int i, j, k=0;  // Loop variables
    int img_rows, img_cols; // Number of rows and columns in the image
    int text_len, watermark_len; // Length of the text and watermark
    
    // Open the image file and read the image into the array
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL){
        printf("Error opening image file.");
        return 1;
    }
    fseek(fp, 18, SEEK_SET); // Skip the first 18 bytes to reach the height and width of the image
    fread(&img_cols, sizeof(int), 1, fp); // Read the width of the image
    fread(&img_rows, sizeof(int), 1, fp); // Read the height of the image
    fseek(fp, 54, SEEK_SET); // Skip the first 54 bytes to reach the pixel data of the image
    for(i=0; i<img_rows; i++){
        for(j=0; j<img_cols; j++){
            fread(&image[i][j], sizeof(char), 1, fp);  // Read each pixel of the image
        }
    }
    fclose(fp); // Close the image file
    
    // Read the text to be embedded
    printf("Please enter the text to be embedded (Max Length %d): ", MAXCHAR);
    fgets(text, MAXCHAR, stdin);
    text_len = strlen(text);
    
    // Check if the text can be embedded into the image
    if (text_len > (img_rows * img_cols * 3)/8){
        printf("Error: Text is too long to be embedded into the image.");
        return 1;
    }
    
    // Embed the text into the image using LSB substitution
    k=0;
    for(i=0; i<img_rows; i++){
        for(j=0; j<img_cols; j++){
            if(k<text_len){
                image[i][j] = (image[i][j] & 0xFE) | (text[k] >> 7);
                image[i][j+1] = (image[i][j+1] & 0x7F) | ((text[k] & 0x7F) << 1);
                image[i][j+2] = (image[i][j+2] & 0xFE) | (text[k] & 0x01);
                k++;
            }else{
                break;
            }
        }
        if(k>=text_len){
            break;
        }
    }
    
    // Embed the watermark into the image using simple substitution
    watermark_len = strlen(watermark);
    for(i=0; i<img_rows; i++){
        for(j=0; j<img_cols; j++){
            if(k < (text_len + watermark_len)){
                image[i][j] = (image[i][j] ^ watermark[k-text_len]);
                k++;
            }else{
                break;
            }
        }
        if(k >= (text_len + watermark_len)){
            break;
        }
    }
    
    // Save the watermarked image
    fp = fopen("watermarked_image.bmp", "wb");
    fseek(fp, 0, SEEK_SET);
    fwrite(image, sizeof(char), img_rows*img_cols*3, fp);
    fclose(fp);
    
    printf("Watermarking done! The watermarked image has been saved in file watermarked_image.bmp");
    
    return 0;
}