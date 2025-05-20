//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

//Function to convert integer to binary
char *int_to_bin(int num, char *bin){
    int i = 0;
    while(num){
        *(bin+i++) = (num%2)+'0';
        num /= 2;
    }
    *(bin+i) = '\0';
    return bin;
}

//Function to convert binary to integer
int bin_to_int(char *bin){
    int num = 0, base = 1, len = strlen(bin), i;
    for(i=len-1; i>=0; i--){
        if(*(bin+i) == '1')
            num += base;
        base *= 2;
    }
    return num;
}

//Function to embed watermark into image
void embed_watermark(char *image_name, char *watermark){
    FILE *fp;
    char ch, *bin, temp[50];
    int i = 0, j = 0;
    fp = fopen(image_name, "rb+");
    if(fp == NULL){
        printf("Error: Cannot open file for embedding watermark.");
        exit(0);
    }
    while(1){
        ch = fgetc(fp);
        if(ch == EOF)
            break;
        bin = int_to_bin(ch, temp);
        if(i < strlen(watermark)){
            *(bin+7) = *(watermark+i++);
        }
        else{
            *(bin+7) = '0';
        }
        fputc(bin_to_int(bin), fp);
    }
    fclose(fp);
}

//Function to extract watermark from image
void extract_watermark(char *image_name, char *watermark){
    FILE *fp;
    char ch, *bin, temp[50];
    int i = 0, j = 0;
    fp = fopen(image_name, "rb");
    if(fp == NULL){
        printf("Error: Cannot open file for extracting watermark.");
        exit(0);
    }
    while(1){
        ch = fgetc(fp);
        if(ch == EOF)
            break;
        bin = int_to_bin(ch, temp);
        if(i < strlen(watermark)){
            *(watermark+i++) = *(bin+7);
        }
    }
    *(watermark+i) = '\0';
    fclose(fp);
}

//Main function
int main(){
    char image_name[50], watermark[50];
    printf("Enter name of image file: ");
    scanf("%s", image_name);

    printf("Enter a binary watermark to be embedded: ");
    scanf("%s", watermark);

    //Embedding watermark into image
    embed_watermark(image_name, watermark);
    printf("Watermark embedded successfully..!!\n");

    //Extracting watermark from the same image
    char extracted_watermark[50];
    extract_watermark(image_name, extracted_watermark);
    printf("Extracted watermark from the image: %s\n", extracted_watermark);

    return 0;
}